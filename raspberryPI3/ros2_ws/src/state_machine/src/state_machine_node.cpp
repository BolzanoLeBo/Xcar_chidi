#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <fstream>
#include <stdint.h>
#include <string.h>
#include <map>

// #include "state_machne/srv/StateMemory.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "std_msgs/msg/int32.hpp"
#include "interfaces/msg/obstacles.hpp"
#include "interfaces/msg/state.hpp"
#include "interfaces/msg/system_check.hpp"
#include "interfaces/msg/joystick_order.hpp"
#include "interfaces/msg/web_mode.hpp" 
#include "interfaces/msg/motors_order.hpp"
#include "interfaces/msg/user_lost.hpp"

#define DEADZONE_LT_RT 0.15     // %
#define DEADZONE_LS_X_LEFT 0.4  // %
#define DEADZONE_LS_X_RIGHT 0.2 // %

#define STOP 0
#define CENTER 0

const std::string state_names[6] = {"idle", "Manual", "Autonomous", "Tracking", "Security", "Emergency"};
const std::string obstacle_detect[2] = {"No obstacle", "Obstacle on the way"};

int dir_av = 0;
int dir_ar = 0;
int obstacle_av = 0;
int obstacle_ar = 0;
int unavoidable = 0;
int emergency_btn = 1;
int connexion = 0;
int sensor = 0;
//int tab[1] = {0};


int previous_state = -1;
int stock_previous_state = -1;
int current_state = 0;

int obstacle = 0;
bool human_lost = false;

using namespace std;
using placeholders::_1;
using placeholders::_2;

class state_machine : public rclcpp::Node
{

public:
  state_machine()
      : Node("state_machine_node")
  {
    publisher_state_ = this->create_publisher<interfaces::msg::State>("state", 10);
    publisher_system_check_ = this->create_publisher<interfaces::msg::SystemCheck>("system_check", 10);
    publisher_joystick_order_ = this->create_publisher<interfaces::msg::JoystickOrder>("joystick_order", 10);

    subscription_joy_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "joy", 10, std::bind(&state_machine::joyCallback, this, _1));
    subscription_obstacles_ = this->create_subscription<interfaces::msg::Obstacles>(
        "obstacles", 10, std::bind(&state_machine::obstacleCallback, this, _1));
    subscription_web_mode_ = this->create_subscription<interfaces::msg::WebMode>(
        "web_mode", 10, std::bind(&state_machine::webCallback, this, _1));
    subscription_motors_order_ = this->create_subscription<interfaces::msg::MotorsOrder>(
        "motors_order2", 10, std::bind(&state_machine::motorsOrderCallback, this, _1));
    subscription_user_lost_ = this->create_subscription<interfaces::msg::UserLost>(
        "user_lost", 10, std::bind(&state_machine::userLostCallback, this, _1));
    client_count_sub = this->create_subscription<std_msgs::msg::Int32>(
        "client_count", 10, std::bind(&state_machine::clientCountCallback, this, _1));

    timer_ = this->create_wall_timer(1ms, std::bind(&state_machine::stateChanger, this));
    //disconnect_timer = this->create_wall_timer(std::chrono::seconds(1), std::bind(&state_machine::changeModeCallback, this));

    // file_stream_.open("output.txt", std::ios::out);  // open .txt

    /*service_state_memory_ = this->create_service<state_machine::srv::StateMemory>(
      "state_service", std::bind(&state_machine::stateChanger, this, std::placeholders::_1, std::placeholders::_2));*/

    axisMap.insert({"LS_X", 0});   // Left Stick axis X  (full left) 1.0 > -1.0 (full right)
    axisMap.insert({"LS_Y", 1});   // Left Stick axis Y  (full high) 1.0 > -1.0 (full bottom)
    axisMap.insert({"LT", 2});     // LT  (high) 1.0 > -1.0 (bottom)
    axisMap.insert({"RS_X", 3});   // Right Stick axis X  (full left) 1.0 > -1.0 (full right)
    axisMap.insert({"RS_Y", 4});   // Right Stick axis Y  (full high) 1.0 > -1.0 (full bottom)
    axisMap.insert({"RT", 5});     // RT  (high) 1.0 > -1.0 (bottom)
    axisMap.insert({"DPAD_X", 6}); //(left) 1.0 > -1.0 (right)
    axisMap.insert({"DPAD_Y", 7}); //(hight) 1.0 > -1.0 (bottom)

    buttonsMap.insert({"A", 0});
    buttonsMap.insert({"B", 1});
    buttonsMap.insert({"Y", 2});
    buttonsMap.insert({"X", 3});
    buttonsMap.insert({"LB", 4});
    buttonsMap.insert({"RB", 5});
    buttonsMap.insert({"START", 6});
    buttonsMap.insert({"SELECT", 7});
    buttonsMap.insert({"XBOX", 8});
    buttonsMap.insert({"LS", 9});  // Left Stick Button
    buttonsMap.insert({"RS", 10}); // Right Stick Button

    systemCheckPrintRequest = false;
    reverse = false;
    requestedThrottle = STOP;
    requestedAngle = CENTER;
  }

private:
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr client_count_sub;
  //rclcpp::TimerBase::SharedPtr disconnect_timer;
  // Publisher
  rclcpp::Publisher<interfaces::msg::State>::SharedPtr publisher_state_;
  rclcpp::Publisher<interfaces::msg::SystemCheck>::SharedPtr publisher_system_check_;
  rclcpp::Publisher<interfaces::msg::JoystickOrder>::SharedPtr publisher_joystick_order_;

  // Subscriber
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_joy_;
  rclcpp::Subscription<interfaces::msg::Obstacles>::SharedPtr subscription_obstacles_;
  rclcpp::Subscription<interfaces::msg::WebMode>::SharedPtr subscription_web_mode_;
  rclcpp::Subscription<interfaces::msg::MotorsOrder>::SharedPtr subscription_motors_order_;
  rclcpp::Subscription<interfaces::msg::UserLost>::SharedPtr subscription_user_lost_;
  // Timer
  rclcpp::TimerBase::SharedPtr timer_;

  // Joystick variables
  map<string, int> axisMap;
  map<string, int> buttonsMap;
  bool buttonB, buttonStart, buttonA, buttonY, buttonDpadBottom, buttonDpadLeft, buttonX;
  bool webButtonEmergency, webButtonStart, webButtonAutonomous, webButtonManual, webButtonReturn, webButtonTracking, webButtonJoystick;

  float axisRT, axisLT, axisLS_X;

  // General variables
  int mode;
  bool systemCheckPrintRequest;

  // Manual mode variables
  float requestedAngle, requestedThrottle;
  bool reverse;
  float webSteering, webThrottle;
  bool webReverse;

  // std::ofstream file_stream_;

  // Service
  // rclcpp::Service<state_machine::srv::StateMemory>::SharedPtr service_state_memory_;
  void stateChanger()
  {
    // ------ Propulsion ------
    if (axisLT > DEADZONE_LT_RT && axisRT > DEADZONE_LT_RT)
    { // Incompatible orders : Stop the car
      requestedThrottle = STOP;
      RCLCPP_WARN(this->get_logger(), "Incompatible orders : LT = %f, RT = %f", axisLT, axisRT);
    }
    else if (axisLT < DEADZONE_LT_RT && axisRT < DEADZONE_LT_RT)
    {
      requestedThrottle = STOP;
    }
    else if (axisLT > DEADZONE_LT_RT)
    { // Move backward
      reverse = true;
      requestedThrottle = axisLT;
    }
    else if (axisRT > DEADZONE_LT_RT)
    { // Move forward
      reverse = false;
      requestedThrottle = axisRT;
    }

    // ------ Steering ------
    if (axisLS_X > DEADZONE_LS_X_LEFT && axisLS_X < DEADZONE_LS_X_RIGHT)
    { // asymmetric deadzone (hardware : joystick LS)
      requestedAngle = CENTER;
    }
    else
    {
      requestedAngle = axisLS_X;
    }

    // Propulsion et steering avec interface web
    if (requestedThrottle == 0 && requestedAngle == CENTER)
    {
      requestedThrottle = webThrottle;
      requestedAngle = webSteering;
      reverse = webReverse;
    }

    /*// Direction control
    if (requestedThrottle > 0 && !reverse)
    {
      dir_av = 1;
      dir_ar = 0;
    }
    else if (requestedThrottle > 0 && reverse)
    {
      dir_av = 0;
      dir_ar = 1;
    }
    else
    {
      dir_av = 0;
      dir_ar = 0;
    } */
    

    auto stateMsg = interfaces::msg::State();
    // emergency stop
    // emergency btn is inversed in case of a shutdown
    if (buttonB || webButtonEmergency)
    {
      current_state = 5;
    }

    // not emergency
    else
    {
      // emergency stop -> idle
      if (current_state == 5 && (buttonStart || webButtonReturn || !(connexion)))
      {
        current_state = 0;
        RCLCPP_INFO(this->get_logger(), ("emergency->manual"));
      }

      // idle -> ?
      else if (current_state == 0)
      {
        // -> manual
        if (buttonY || webButtonManual)
        {
          current_state = 1;
          RCLCPP_INFO(this->get_logger(), ("idle->manual"));
        }
        // -> autonomous
        else if (buttonA || webButtonAutonomous)
        {
          current_state = 2;
          RCLCPP_INFO(this->get_logger(), ("idle->auto"));
        }
        // -> tracking
        else if (buttonX || webButtonTracking)
        {
          current_state = 3;
          RCLCPP_INFO(this->get_logger(), ("idle->tracking"));
        }
      }

      // manual -> ?
      else if (current_state == 1)
      {
        // -> idle
        if (buttonDpadBottom || webButtonReturn || !(connexion))
        {
          current_state = 0;
          RCLCPP_INFO(this->get_logger(), ("manual->idle"));
        }

        // -> security
        else if ((dir_av && obstacle_av) || (dir_ar && obstacle_ar))
        {
          current_state = 4;
          RCLCPP_INFO(this->get_logger(), ("manual->security"));
        }

        // -> tracking
        else if (buttonX || webButtonTracking)
        {
          current_state = 3;
          RCLCPP_INFO(this->get_logger(), ("manual->tracking"));
        }

        // -> autonomous
        else if (buttonA || webButtonAutonomous)
        {
          current_state = 2;
          RCLCPP_INFO(this->get_logger(), ("manual->auto"));
        }
      }

      // autonomous -> ?
      else if (current_state == 2)
      {
        // -> idle
        if (buttonDpadBottom || webButtonReturn || !(connexion))
        {
          current_state = 0;
          RCLCPP_INFO(this->get_logger(), ("autonomous->idle"));
        }

        // -> manual
        else if (buttonY || webButtonManual)
        {
          current_state = 1;
          RCLCPP_INFO(this->get_logger(), ("auto->manual"));
        }

        // -> tracking
        else if (buttonX || webButtonTracking)
        {
          current_state = 3;
          RCLCPP_INFO(this->get_logger(), ("auto->tracking"));
        }
      }

      // tracking -> ?
      else if (current_state == 3)
      {
        // -> idle
        if (buttonDpadBottom || webButtonReturn || !(connexion))
        {
          current_state = 0;
          RCLCPP_INFO(this->get_logger(), ("tracking->idle"));
        }

        else if ((dir_av && obstacle_av) || (dir_ar && obstacle_ar) || (human_lost))
        {
          current_state = 4;
          RCLCPP_INFO(this->get_logger(), ("tracking->security"));
        }
        // -> autonomous
        else if (buttonA || webButtonAutonomous)
        {
          current_state = 2;
          RCLCPP_INFO(this->get_logger(), ("tracking->auto"));
        }

        // -> manual
        else if (buttonY || webButtonManual)
        {
          current_state = 1;
          RCLCPP_INFO(this->get_logger(), ("tracking->manual"));
        }
      }
      // security -> manual
      else if (current_state == 4)
      {
        if (((!obstacle_av && !obstacle_ar) || (dir_ar && !obstacle_ar) || (dir_av && !obstacle_av)) && connexion && (stock_previous_state==1)) {
          current_state = 1;
          RCLCPP_INFO(this->get_logger(), ("sec->man"));
        }
        else if (((!obstacle_av && !obstacle_ar) || (dir_ar && !obstacle_ar) || (dir_av && !obstacle_av)) && connexion &&  (stock_previous_state==3) && !(human_lost)) {
          current_state = 3;
          RCLCPP_INFO(this->get_logger(), ("sec->track"));
        }
        else if ((!connexion)) {
          current_state = 0;
          RCLCPP_INFO(this->get_logger(), ("security->idle"));
        }

      }
      else
      {
        current_state = current_state;
      }
    }
    //-------------------------------STATE CHANGE------------------------------------------------
    if (previous_state != current_state)
    {

      stateMsg.current_state = current_state;
      stateMsg.previous_state = previous_state;
      stock_previous_state = previous_state;
      stateMsg.state_name = state_names[current_state];
      stateMsg.obstacle_detect = obstacle_detect[obstacle];
      publisher_state_->publish(stateMsg);
      RCLCPP_INFO(this->get_logger(), ("From : " + state_names[previous_state] + "Switching to another state : " + state_names[current_state]).data());
      RCLCPP_INFO(this->get_logger(), ("change because obstacle ? " + obstacle_detect[obstacle]).data());
      previous_state = current_state;

      // Save file
      // file_stream_ << "\n\nMode: " << state_names[current_state] << ", Obstacle: " << obstacle_detect[obstacle] << "\n\n" << std::endl;
    }

    if (buttonDpadLeft && !systemCheckPrintRequest)
    { // Request to print the last system check report
      systemCheckPrintRequest = true;

      auto systemCheckMsg = interfaces::msg::SystemCheck();
      systemCheckMsg.print = true;
      publisher_system_check_->publish(systemCheckMsg); // Send print request to system_check_node
    }
    else
      systemCheckPrintRequest = false;

    auto joystickOrderMsg = interfaces::msg::JoystickOrder();
    joystickOrderMsg.throttle = requestedThrottle;
    joystickOrderMsg.steer = requestedAngle;
    joystickOrderMsg.reverse = reverse;

    publisher_joystick_order_->publish(joystickOrderMsg); // Send order to the car_control_node

    webButtonEmergency = false;
    webButtonStart = false;
    webButtonAutonomous = false;
    webButtonManual = false;
    webButtonReturn = false;
    webButtonTracking = false;
    webButtonJoystick = false;
  }

  void obstacleCallback(const interfaces::msg::Obstacles &obstacle_msg)
  {

    if (obstacle_msg.front)
    {
      obstacle_av = 1;
      obstacle = 1;
    }
    else
    {
      obstacle_av = 0;
    }
    if (obstacle_msg.rear)
    {
      obstacle_ar = 1;
      obstacle = 1;
    }
    else
    {
      obstacle_ar = 0;
    }
    //RCLCPP_INFO(this->get_logger(), "Publishing: %d", obstacle_ar);
  }

  // Update requestedThrottle, requestedAngle and reverse from the joystick
  void joyCallback(const sensor_msgs::msg::Joy &joy)
  {

    buttonStart = joy.buttons[buttonsMap.find("START")->second];
    buttonB = joy.buttons[buttonsMap.find("B")->second];
    buttonA = joy.buttons[buttonsMap.find("A")->second];
    buttonY = joy.buttons[buttonsMap.find("Y")->second];
    buttonX = joy.buttons[buttonsMap.find("X")->second];

    axisRT = joy.axes[axisMap.find("RT")->second];     // Motors (go forward)
    axisLT = joy.axes[axisMap.find("LT")->second];     // Motors (go backward)
    axisLS_X = joy.axes[axisMap.find("LS_X")->second]; // Steering

    if (joy.axes[axisMap.find("DPAD_Y")->second] == -1.0)
      buttonDpadBottom = true;
    else
      buttonDpadBottom = false;

    if (joy.axes[axisMap.find("DPAD_X")->second] == 1.0)
      buttonDpadLeft = true;
    else
      buttonDpadLeft = false;

    // Normalise values
    axisLS_X = -axisLS_X;          // axisLS_X : 1 .. -1  ;  steering_angle : -1 .. 1
    axisRT = (1.0 - axisRT) / 2.0; // axisRT : 1 .. -1  ;  throttle : 0 .. 1
    axisLT = (1.0 - axisLT) / 2.0; // axisLT : 1 .. -1  ;  throttle : 0 .. 1
  }

  void webCallback(const interfaces::msg::WebMode &web)
  {

    switch (web.button)
    {
    case 0:
      webButtonReturn = true;
      break;
    case 1:
      webButtonManual = true;
      break;
    case 2:
      webButtonAutonomous = true;
      break;
    case 3:
      webButtonTracking = true;
      break;
    case 4:
      webButtonEmergency = true;
      break;
    case 5:
      webButtonStart = true;
      break;
    case 7:
      webButtonJoystick = true;
      break;
    default:
      // RCLCPP_INFO(this->get_logger(), "unknown webButton pressed");
      break;
    }

    webSteering = web.steering;
    webThrottle = web.throttle;
    webReverse = web.reverse;
  }

  void motorsOrderCallback(const interfaces::msg::MotorsOrder &motorsOrder){
    if (((motorsOrder.right_rear_pwm + motorsOrder.left_rear_pwm) / 2) > 50 ) {
      dir_av = 1;
      dir_ar = 0;
    }
    else if (((motorsOrder.right_rear_pwm + motorsOrder.left_rear_pwm) / 2) < 50 ) {
      dir_av = 0;
      dir_ar = 1;
    }
    else {
      dir_av = 0;
      dir_ar = 0;
    }
  }
  void clientCountCallback(const std_msgs::msg::Int32 &msg)
  {
    // Réinitialiser le timer chaque fois qu'une nouvelle personne se connecte
    if (msg.data > 0)
    {
      //disconnect_timer->cancel();
      connexion=1;
    }
    else
    {
      connexion=0;
      // Démarrer le timer si personne n'est connecté
      //if (disconnect_timer->is_canceled())
      //{
      //  disconnect_timer->reset();
      //}
    }
  }

  void userLostCallback(const interfaces::msg::UserLost &userLost)
  {
    human_lost = userLost.lost;
  } 
  //void changeModeCallback()
  //{
  //  connexion=0;
  //  disconnect_timer->cancel();
  //}
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<state_machine>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
