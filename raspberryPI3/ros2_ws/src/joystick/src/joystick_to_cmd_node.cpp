#include <stdint.h>
#include <string.h>  
#include <map>

#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <functional>
#include <memory>

#include "sensor_msgs/msg/joy.hpp"
#include "interfaces/msg/joystick_order.hpp"
#include "interfaces/msg/system_check.hpp"
#include "interfaces/msg/web_mode.hpp"


using namespace std;
using placeholders::_1;

#define DEADZONE_LT_RT 0.15  // %
#define DEADZONE_LS_X_LEFT 0.4  // %
#define DEADZONE_LS_X_RIGHT 0.2  // %

#define STOP 0
#define CENTER 0


//Turns joystick buttons/axis into system commands
class joystick_to_cmd : public rclcpp::Node {

public:
    joystick_to_cmd()
    : Node("joystick_to_cmd_node")
    {
        mode = 0;
        start = false;
        systemCheckPrintRequest = false;
        reverse = false;
        requestedThrottle = STOP;
        requestedAngle = CENTER;
        
        axisMap.insert({"LS_X",0});    //Left Stick axis X  (full left) 1.0 > -1.0 (full right)
        axisMap.insert({"LS_Y",1});    //Left Stick axis Y  (full high) 1.0 > -1.0 (full bottom)
        axisMap.insert({"LT",2});      //LT  (high) 1.0 > -1.0 (bottom)
        axisMap.insert({"RS_X",3});    //Right Stick axis X  (full left) 1.0 > -1.0 (full right)
        axisMap.insert({"RS_Y",4});    //Right Stick axis Y  (full high) 1.0 > -1.0 (full bottom)
        axisMap.insert({"RT",5});      //RT  (high) 1.0 > -1.0 (bottom)
        axisMap.insert({"DPAD_X",6});  //(left) 1.0 > -1.0 (right)
        axisMap.insert({"DPAD_Y",7});  //(hight) 1.0 > -1.0 (bottom)

        buttonsMap.insert({"A",0});
        buttonsMap.insert({"B",1});
        buttonsMap.insert({"Y",2});
        buttonsMap.insert({"X",3});
        buttonsMap.insert({"LB",4});
        buttonsMap.insert({"RB",5});
        buttonsMap.insert({"START",6});
        buttonsMap.insert({"SELECT",7});
        buttonsMap.insert({"XBOX",8});
        buttonsMap.insert({"LS",9});   //Left Stick Button
        buttonsMap.insert({"RS",10});  //Right Stick Button


        publisher_joystick_order_= this->create_publisher<interfaces::msg::JoystickOrder>("joystick_order", 10);
        publisher_system_check_= this->create_publisher<interfaces::msg::SystemCheck>("system_check", 10);


        subscription_joy_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "joy", 10, std::bind(&joystick_to_cmd::joyCallback, this, _1));
        subscription_web_mode_ = this->create_subscription<interfaces::msg::WebMode>(
        "web_mode", 10, std::bind(&joystick_to_cmd::webCallback, this, _1));


        timer_ = this->create_wall_timer(1ms, std::bind(&joystick_to_cmd::updateCmd, this));
        
        RCLCPP_INFO(this->get_logger(), "joystick_to_cmd_node READY");
    }

    
private:

    //Update requestedThrottle, requestedAngle and reverse from the joystick
    void joyCallback(const sensor_msgs::msg::Joy & joy) {

        buttonStart = joy.buttons[buttonsMap.find("START")->second];
        buttonB = joy.buttons[buttonsMap.find("B")->second];    
        buttonA = joy.buttons[buttonsMap.find("A")->second];  
        buttonY = joy.buttons[buttonsMap.find("Y")->second]; 
        buttonX = joy.buttons[buttonsMap.find("X")->second]; 
        

        axisRT = joy.axes[axisMap.find("RT")->second];      //Motors (go forward)
        axisLT = joy.axes[axisMap.find("LT")->second];      //Motors (go backward)
        axisLS_X = joy.axes[axisMap.find("LS_X")->second];     //Steering

        if (joy.axes[axisMap.find("DPAD_Y")->second] == -1.0)
            buttonDpadBottom = true;
        else
            buttonDpadBottom = false;

        if (joy.axes[axisMap.find("DPAD_X")->second] == 1.0)
            buttonDpadLeft = true;
        else
            buttonDpadLeft = false;
        
        //Normalise values
        axisLS_X = -axisLS_X;   //axisLS_X : 1 .. -1  ;  steering_angle : -1 .. 1
        axisRT = (1.0-axisRT)/2.0;  //axisRT : 1 .. -1  ;  throttle : 0 .. 1
        axisLT = (1.0-axisLT)/2.0;  //axisLT : 1 .. -1  ;  throttle : 0 .. 1
    }

    void webCallback(const interfaces::msg::WebMode & web) {

        switch (web.button) {
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
            default:
                //RCLCPP_INFO(this->get_logger(), "unknown webButton pressed");
                break;
        }

        webSteering = web.steering;
        webThrottle = web.throttle;
        webReverse = web.reverse;
    }

    void updateCmd() {

        if (buttonA || buttonY || buttonStart || buttonDpadBottom || buttonB || buttonX || webButtonAutonomous|| webButtonManual || webButtonStart || webButtonReturn || webButtonEmergency || webButtonTracking ){

            if ((buttonY || webButtonManual) && mode==0) {
                mode = 1;
                start=true;
            }

            else if ((buttonA || webButtonAutonomous) && mode==0) {
                mode = 2;
                start=true;
            }

            else if ((buttonX || webButtonTracking) && mode==0) {
                mode = 4;
                start=true;
            }

            else if ((buttonDpadBottom || webButtonReturn) && (mode ==1 || mode ==2 || mode ==4)) {
                mode = 0;
                start=false;
            }

            else if ((buttonStart || webButtonStart) && mode == 3){
                mode = 0;
                start = false;
            }
            // ------ Start and Stop ------
            else if (buttonB || webButtonEmergency){       // B button -> Stop the car
                start = false;
                mode = 3;
            }
        }

        if (buttonDpadLeft && !systemCheckPrintRequest){ //Request to print the last system check report
            systemCheckPrintRequest = true;

            auto systemCheckMsg = interfaces::msg::SystemCheck();
            systemCheckMsg.print = true;
            publisher_system_check_->publish(systemCheckMsg); //Send print request to system_check_node
        }
        else
            systemCheckPrintRequest = false;


        // ------ Propulsion ------
        if (axisLT > DEADZONE_LT_RT && axisRT > DEADZONE_LT_RT){  //Incompatible orders : Stop the car
            requestedThrottle = STOP;
            RCLCPP_WARN(this->get_logger(), "Incompatible orders : LT = %f, RT = %f",axisLT,axisRT);

        } else if (axisLT < DEADZONE_LT_RT && axisRT < DEADZONE_LT_RT){ 
            requestedThrottle = STOP;
        
        }else if (axisLT > DEADZONE_LT_RT){ //Move backward
            reverse = true;
            requestedThrottle = axisLT;

        } else if (axisRT > DEADZONE_LT_RT){   //Move forward
            reverse = false;
            requestedThrottle = axisRT;
        }


        // ------ Steering ------
        if (axisLS_X > DEADZONE_LS_X_LEFT && axisLS_X < DEADZONE_LS_X_RIGHT){     //asymmetric deadzone (hardware : joystick LS)
            requestedAngle = CENTER;
        } else {
            requestedAngle = axisLS_X;    
        }


        //Proppulsion et steering avec interface web
        requestedThrottle = webThrottle;
        requestedAngle = webSteering;
        reverse = webReverse;
        

        auto joystickOrderMsg = interfaces::msg::JoystickOrder();
        joystickOrderMsg.start = start;
        joystickOrderMsg.mode = mode;
        joystickOrderMsg.throttle = requestedThrottle;
        joystickOrderMsg.steer  = requestedAngle;
        joystickOrderMsg.reverse = reverse;

        publisher_joystick_order_->publish(joystickOrderMsg); //Send order to the car_control_node

        webButtonEmergency = false;
        webButtonStart = false;
        webButtonAutonomous = false;
        webButtonManual = false;
        webButtonReturn = false;
        webButtonTracking = false;

    }

    //Joystick variables
    map<string,int> axisMap;
    map<string,int> buttonsMap;
    bool buttonB, buttonStart, buttonA, buttonY, buttonDpadBottom, buttonDpadLeft, buttonX ;
    bool webButtonEmergency, webButtonStart, webButtonAutonomous, webButtonManual, webButtonReturn, webButtonTracking ;
    
    float axisRT, axisLT, axisLS_X;

    //General variables
    bool start;
    int mode;
    bool systemCheckPrintRequest;


    //Manual mode variables
    float requestedAngle, requestedThrottle;
    bool reverse;
    float webSteering, webThrottle;
    bool webReverse;



    rclcpp::Publisher<interfaces::msg::JoystickOrder>::SharedPtr publisher_joystick_order_;
    rclcpp::Publisher<interfaces::msg::SystemCheck>::SharedPtr publisher_system_check_;

    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_joy_;
    rclcpp::Subscription<interfaces::msg::WebMode>::SharedPtr subscription_web_mode_;
    rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<joystick_to_cmd>();

  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}