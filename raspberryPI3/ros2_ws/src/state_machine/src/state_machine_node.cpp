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


      //state_service_ = this->create_service<std_srvs::srv::Empty>(
      //"state_service", std::bind(&state_machine::stateCallback, this, std::placeholders::_1, std::placeholders::_2));


    
    }

  private :

    //Publisher
    rclcpp::Publisher<interfaces::msg::State>::SharedPtr publisher_state_;

    //Subscriber
    rclcpp::Subscription<interfaces::msg::JoystickOrder>::SharedPtr subscription_joystick_order_;
    rclcpp::Subscription<interfaces::msg::Ultrasonic>::SharedPtr subscription_ultrasonic_sensor_;

    int manual_button = 0; 
    int dir_av = 0; 
    int obstacle_av = 0; 

    //Service
    //rclcpp::Service<std_srvs::srv::Empty>::SharedPtr state_service_;

    void joyCallback( const interfaces::msg::JoystickOrder &joyOrder)
    {
      
      if (joyOrder.mode == 0) 
      {
        manual_button = 1; 
      }
      else 
      {
        manual_button = 0;
      }

      if (joyOrder.throttle>0)
      {
        dir_av = 1; 
      }
      else 
      {
        dir_av = 0;
      }
      stateCallback();
    }

    void usCallback(const interfaces::msg::Ultrasonic &ultrasonic)
    {
      
      if (ultrasonic.front_center <= 20)
      {
        obstacle_av = 1;
      }
      else
      {
        obstacle_av = 0;
      }
      stateCallback();
    }

    void stateCallback()
    {
      auto stateMsg = interfaces::msg::State();
      if (manual_button) 
      {
        stateMsg.current_state = 3;
      }
      else if (dir_av && obstacle_av)
      {
        stateMsg.current_state = 4;
      }
      publisher_state_->publish(stateMsg);
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
