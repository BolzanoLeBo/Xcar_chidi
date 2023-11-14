#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <functional>
#include <memory>

//#include "state_machne/srv/StateMemory.hpp"
#include "interfaces/msg/joystick_order.hpp"
#include "interfaces/msg/state.hpp"

using namespace std;
using placeholders::_1;

class state_machine : public rclcpp::Node {

  public:
    state_machine()
    : Node("state_machine_node")
    {
      publisher_state_= this->create_publisher<interfaces::msg::State>("state", 10);
      
      subscription_joystick_order_ = this->create_subscription<interfaces::msg::JoystickOrder>(
        "joystick_order", 10, std::bind(&state_machine::stateCallback, this, _1));

    
    }

  private :

    //Publisher
    rclcpp::Publisher<interfaces::msg::State>::SharedPtr publisher_state_;

    //Subscriber
    rclcpp::Subscription<interfaces::msg::JoystickOrder>::SharedPtr subscription_joystick_order_;


    void stateCallback(const interfaces::msg::JoystickOrder &joyOrder)
    {
      auto stateMsg = interfaces::msg::State();
      if (joyOrder.mode == 0) 
      {
        stateMsg.current_state=2;
        publisher_state_->publish(stateMsg);
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
