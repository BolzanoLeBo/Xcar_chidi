#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <functional>
#include <memory>

//#include "state_machne/srv/StateMemory.hpp"
#include "interfaces/msg/joystick_order.hpp"
#include "interfaces/msg/ultrasonic.hpp"
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

      subscription_ultrasonic_sensor_ = this->create_subscription<interfaces::msg::Ultrasonic>(
        "us_data", 10, std::bind(&state_machine::usCallback, this, _1));


      /*service_state_memory_ = this->create_service<state_machine::srv::StateMemory>(
        "state_service", std::bind(&state_machine::stateChanger, this, std::placeholders::_1, std::placeholders::_2));*/


    
    }

  private :

    //Publisher
    rclcpp::Publisher<interfaces::msg::State>::SharedPtr publisher_state_;

    //Subscriber
    rclcpp::Subscription<interfaces::msg::JoystickOrder>::SharedPtr subscription_joystick_order_;
    rclcpp::Subscription<interfaces::msg::Ultrasonic>::SharedPtr subscription_ultrasonic_sensor_;


    int joy_mode = 0; 
    int dir_av = 0;
    int dir_ar = 0;
    int obstacle_av = 0; 
    int obstacle_ar = 0; 
    int unavoidable = 0;
    int emergency_btn = 0;

    
    int connexion = 0; 
    int sensor = 0;


    int previous_state = -1; 
    int current_state = 0; 
    

    //Service
    //rclcpp::Service<state_machine::srv::StateMemory>::SharedPtr service_state_memory_;

    void joyCallback( const interfaces::msg::JoystickOrder &joyOrder)
    {
      
      joy_mode = joyOrder.mode;
      if (joy_mode == 3) 
      {
        emergency_btn = 1;
      }
      else
      {
        emergency_btn = 0; 
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
      stateChanger();
    }

    void usCallback(const interfaces::msg::Ultrasonic &ultrasonic)
    {
      
      if (ultrasonic.front_center <= 20)
      {
        obstacle_av = 1;
        obstacle_ar = 0;
      }
      else if (ultrasonic.rear_center <= 20)
      {
        obstacle_av = 0;
        obstacle_ar = 1;
      }
      else
      {
        obstacle_av = 0; 
        obstacle_ar = 0;
      }
      stateChanger();
    }

    void stateChanger()
    {
      auto stateMsg = interfaces::msg::State();

      //idle -> manual 
      if (current_state == 0 && joy_mode == 1  && !emergency_btn)
      {
        current_state = 3;
      }

      //manual -> security
      else if (current_state == 3 && ((dir_av && obstacle_av) || (dir_ar && obstacle_ar)) && !emergency_btn )
      {
        current_state = 4;
      }

      //security -> manual 
      else if (current_state == 4 && ((!obstacle_av && !obstacle_ar) || (dir_ar && obstacle_av) || (dir_av && obstacle_ar)) && !emergency_btn )
      {
        current_state = 3; 
      }
      if (previous_state != current_state)
      {
        stateMsg.current_state = current_state;
        publisher_state_->publish(stateMsg);
        previous_state = current_state;
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
