#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <fstream>


//#include "state_machne/srv/StateMemory.hpp"
#include "interfaces/msg/joystick_order.hpp"
#include "interfaces/msg/obstacles.hpp"
#include "interfaces/msg/state.hpp"


using namespace std;
using placeholders::_1;
using placeholders::_2;

class state_machine : public rclcpp::Node {

  public:
    state_machine()
    : Node("state_machine_node")
    {
      publisher_state_= this->create_publisher<interfaces::msg::State>("state", 10);
      
      subscription_joystick_order_ = this->create_subscription<interfaces::msg::JoystickOrder>(
        "joystick_order", 10, std::bind(&state_machine::joyCallback, this, _1));

      subscription_obstacles_ = this->create_subscription<interfaces::msg::Obstacles>(
        "obstacles", 10, std::bind(&state_machine::obstacleCallback, this, _1));

      timer_ = this->create_wall_timer(1ms, std::bind(&state_machine::stateChanger, this));

      //file_stream_.open("output.txt", std::ios::out);  // open .txt

      /*service_state_memory_ = this->create_service<state_machine::srv::StateMemory>(
        "state_service", std::bind(&state_machine::stateChanger, this, std::placeholders::_1, std::placeholders::_2));*/

    }

  private :

    //Publisher
    rclcpp::Publisher<interfaces::msg::State>::SharedPtr publisher_state_;
    
    //Subscriber
    rclcpp::Subscription<interfaces::msg::JoystickOrder>::SharedPtr subscription_joystick_order_;
    rclcpp::Subscription<interfaces::msg::Obstacles>::SharedPtr subscription_obstacles_;
    //Timer
    rclcpp::TimerBase::SharedPtr timer_;
  


    int joy_mode = 0; 
    int dir_av = 0;
    int dir_ar = 0;
    int obstacle_av = 0; 
    int obstacle_ar = 0; 
    int unavoidable = 0;
    int emergency_btn = 1;

    int start = 0; 

    int connexion = 0; 
    int sensor = 0;

    //rclcpp::TimerBase::SharedPtr timer_;


    std::string state_names[6] = {"idle", "Manual", "Autonomous", "Tracking", "Security", "Emergency"};
    std::string obstacle_detect[2] = {"No obstacle", "Obstacle on the way"};
    int previous_state = -1; 
    int current_state = 0; 
    
    int obstacle = 0;

    //std::ofstream file_stream_;

    //Service
    //rclcpp::Service<state_machine::srv::StateMemory>::SharedPtr service_state_memory_;
    void stateChanger()
    {
      auto stateMsg = interfaces::msg::State();
      //emergency stop
      //emergency btn is inversed in case of a shutdown 
      if (!emergency_btn)
      {
        current_state = 5;
      }

      // not emergency 
      else 
      {
        //emergency stop -> idle
        if (current_state == 5 && joy_mode == 0)
        {
          current_state = 0; 
          RCLCPP_INFO(this->get_logger(),("emergency->manual"));
        }

        //idle -> ?
        else if (current_state == 0)
        {
          // -> manual 
          if (joy_mode == 1)
          {
            current_state = 1;
            RCLCPP_INFO(this->get_logger(),("idle->manual"));
          }
          // -> autonomous 
          else if (joy_mode == 2)
          {
            current_state = 2;
            RCLCPP_INFO(this->get_logger(),("idle->auto"));
          }
          // -> tracking
          else if (joy_mode == 4)
          {
            current_state = 3;
            RCLCPP_INFO(this->get_logger(),("idle->tracking"));
          }
        }

        //manual -> ? 
        else if (current_state == 1) 
        {
          // -> idle
          if (joy_mode == 0)
          {
            current_state = 0;
            RCLCPP_INFO(this->get_logger(),("manual->idle"));
          }

          // -> security
          else if ((dir_av && obstacle_av) || (dir_ar && obstacle_ar))
          {
            current_state = 4;
            RCLCPP_INFO(this->get_logger(),("manual->security"));
          }
        }

        //autonomous -> ? 
        else if (current_state == 2)
        {
          // -> idle
          if (joy_mode == 0)
          {
            current_state = 0;
            RCLCPP_INFO(this->get_logger(),("autonomous->idle"));
          }
        }

        //tracking -> ? 
        else if (current_state == 3)
        {
          // -> idle
          if (joy_mode == 0)
          {
            current_state = 0;
            RCLCPP_INFO(this->get_logger(),("tracking->idle"));
          }
        }
        //security -> manual 
        else if (current_state == 4 && ((!obstacle_av && !obstacle_ar) || (dir_ar && !obstacle_ar) || (dir_av && !obstacle_av)))
        {
          current_state = 1; 
          RCLCPP_INFO(this->get_logger(),("sec->man"));
        }
        else {
          current_state=current_state;
        }
      }
          //-------------------------------STATE CHANGE------------------------------------------------
      if (previous_state != current_state)
      {

        stateMsg.current_state = current_state;
        stateMsg.state_name = state_names[current_state];
        stateMsg.obstacle_detect = obstacle_detect[obstacle];
        publisher_state_->publish(stateMsg);
        RCLCPP_INFO(this->get_logger(),("From : "  + state_names[previous_state] + "Switching to another state : " + state_names[current_state]).data());
        RCLCPP_INFO(this->get_logger(), ("change because obstacle ? " + obstacle_detect[obstacle]).data());
        previous_state = current_state;
        

        // Save file
        //file_stream_ << "\n\nMode: " << state_names[current_state] << ", Obstacle: " << obstacle_detect[obstacle] << "\n\n" << std::endl;
        
        
      }
    }

    void joyCallback( const interfaces::msg::JoystickOrder &joyOrder)
    {
      
      joy_mode = joyOrder.mode;
      if (joy_mode == 3) 
      {
        emergency_btn = 0;
      }

      else if (joy_mode != 3 && emergency_btn == 0)
      {
        emergency_btn = 1; 
      }

      //Direction control 
      if (joyOrder.throttle>0 && !joyOrder.reverse)
      {
        dir_av = 1; 
        dir_ar = 0;
      }
      else if (joyOrder.throttle>0 && joyOrder.reverse)
      {
        dir_av = 0;
        dir_ar = 1;
      }
      else
      {
        dir_av = 0; 
        dir_ar = 0;
      }
    }

    void obstacleCallback(const interfaces::msg::Obstacles &obstacle_msg)
    {
      
      if (obstacle_msg.us_front_detect)
      {
        obstacle_av = 1;
        obstacle = 1;
      }
      else {
        obstacle_av = 0 ;
      }
      if (obstacle_msg.us_rear_detect)
      {
        obstacle_ar = 1;
        obstacle = 1;
      }
      else {
        obstacle_ar = 0;
      }
    }




}; 

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<state_machine>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
