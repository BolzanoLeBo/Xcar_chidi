#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <functional>
#include <memory>

#include "interfaces/msg/motors_order.hpp"
#include "interfaces/msg/motors_feedback.hpp"
#include "interfaces/msg/steering_calibration.hpp"
#include "interfaces/msg/joystick_order.hpp"
#include "interfaces/msg/state.hpp"
#include "interfaces/msg/ultrasonic.hpp"


#include "std_srvs/srv/empty.hpp"

#include "../include/car_control/steeringCmd.h"
#include "../include/car_control/propulsionCmd.h"
#include "../include/car_control/control_loop.h"
#include "../include/car_control/car_control_node.h"

using namespace std;
using placeholders::_1;


class car_control : public rclcpp::Node {

public:
    car_control()
    : Node("car_control_node")
    {
        requestedThrottle = 0;
        requestedSteerAngle = 0;

    

        publisher_can_= this->create_publisher<interfaces::msg::MotorsOrder>("motors_order", 10);

        publisher_steeringCalibration_ = this->create_publisher<interfaces::msg::SteeringCalibration>("steering_calibration", 10);

        

        subscription_joystick_order_ = this->create_subscription<interfaces::msg::JoystickOrder>(
        "joystick_order", 10, std::bind(&car_control::joystickOrderCallback, this, _1));

        subscription_state_ = this->create_subscription<interfaces::msg::State>(
        "state", 10, std::bind(&car_control::stateCallback, this, _1));

        subscription_motors_feedback_ = this->create_subscription<interfaces::msg::MotorsFeedback>(
        "motors_feedback", 10, std::bind(&car_control::motorsFeedbackCallback, this, _1));        

        subscription_ultrasonic_sensor_ = this->create_subscription<interfaces::msg::Ultrasonic>(
        "us_data", 10, std::bind(&car_control::distanceCallback, this, _1));

        timer_ = this->create_wall_timer(PERIOD_UPDATE_CMD, std::bind(&car_control::updateCmd, this));

        
        RCLCPP_INFO(this->get_logger(), "car_control_node READY");
    }

    
private:

    /* Update start, mode, requestedThrottle, requestedSteerAngle and reverse from joystick order [callback function]  :
    *
    * This function is called when a message is published on the "/joystick_order" topic
    * 
    */
    void joystickOrderCallback(const interfaces::msg::JoystickOrder & joyOrder) {

        throttleValue = joyOrder.throttle;
        angleValue = joyOrder.steer;
        reverseValue = joyOrder.reverse;

        requestedThrottle = joyOrder.throttle;
        requestedSteerAngle = joyOrder.steer;
        reverse = joyOrder.reverse;
    }

    /* Update currentAngle from motors feedback [callback function]  :
    *
    * This function is called when a message is published on the "/motors_feedback" topic
    * 
    */
    void motorsFeedbackCallback(const interfaces::msg::MotorsFeedback & motorsFeedback){
        currentAngle = motorsFeedback.steering_angle;
        currentRightSpeed = motorsFeedback.right_rear_speed;
        currentLeftSpeed = motorsFeedback.left_rear_speed;
    }

    void distanceCallback(const interfaces::msg::Ultrasonic & ultrasonic) {
        currentRightDistance = ultrasonic.front_center;
        currentLeftDistance = currentRightDistance;
    }

    /* Update PWM commands : leftRearPwmCmd, rightRearPwmCmd, steeringPwmCmd
    *
    * This function is called periodically by the timer [see PERIOD_UPDATE_CMD in "car_control_node.h"]
    * 
    * In MANUAL mode, the commands depends on :
    * - requestedThrottle, reverse, requestedSteerAngle [from joystick orders]
    * - currentAngle [from motors feedback]
    */

    void stateCallback(const interfaces::msg::State & state_msg){
        state = state_msg.current_state;  
    }

    void updateCmd(){

        auto motorsOrder = interfaces::msg::MotorsOrder();
        //emergency idle or security
        if (state == 5 or state == 0 or state == 4){    //Car stopped
            leftRearPwmCmd = STOP;
            rightRearPwmCmd = STOP;
            steeringPwmCmd = STOP;
        }
        else{ //Car started

            //Manual Mode
            if (state == 1){
                
                manualPropulsionCmd(requestedThrottle, reverse, leftRearPwmCmd,rightRearPwmCmd);
                steeringCmd(requestedSteerAngle,currentAngle, steeringPwmCmd);
                reinit = 1;
            
            } 

            //Tracking Mode
            else if (state==2){

                compensator_recurrence(reinit ,RPM_order, reverse, currentRightDistance, currentLeftDistance, rightRearPwmCmd, leftRearPwmCmd);
                steeringPwmCmd = 50;
                reinit = 0;

            }

        }
        //Send order to motors
        motorsOrder.left_rear_pwm = leftRearPwmCmd;
        motorsOrder.right_rear_pwm = rightRearPwmCmd;
        motorsOrder.steering_pwm = steeringPwmCmd;

        publisher_can_->publish(motorsOrder);
    }


    
    // ---- Private variables ----

    int state = 0;
    int reinit;
    
    //Motors feedback variables
    float currentAngle;
    float currentLeftSpeed;
    float currentRightSpeed;

    //Manual Mode variables (with joystick control)
    float requestedThrottle;
    float requestedSteerAngle;
    bool reverse;
    
    bool reverseValue;
    float throttleValue;
    float angleValue;

    //Control variables
    uint8_t leftRearPwmCmd;
    uint8_t rightRearPwmCmd;
    uint8_t steeringPwmCmd;

    //Publishers
    rclcpp::Publisher<interfaces::msg::MotorsOrder>::SharedPtr publisher_can_;
    rclcpp::Publisher<interfaces::msg::SteeringCalibration>::SharedPtr publisher_steeringCalibration_;

    //Subscribers
    rclcpp::Subscription<interfaces::msg::JoystickOrder>::SharedPtr subscription_joystick_order_;
    rclcpp::Subscription<interfaces::msg::MotorsFeedback>::SharedPtr subscription_motors_feedback_;
    rclcpp::Subscription<interfaces::msg::SteeringCalibration>::SharedPtr subscription_steering_calibration_;
    rclcpp::Subscription<interfaces::msg::State>::SharedPtr subscription_state_;

    //Timer
    rclcpp::TimerBase::SharedPtr timer_;

    //Steering calibration Service
    rclcpp::Service<std_srvs::srv::Empty>::SharedPtr server_calibration_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<car_control>();

  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}