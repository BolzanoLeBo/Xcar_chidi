#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include "../include/car_control/avoidance_control.hpp"

class YourClass : public rclcpp::Node {
public:
    YourClass() : Node("your_node_name") {
        // Create a timer with a callback to handle turning and going straight
        timer_ = this->create_wall_timer(std::chrono::seconds(turnTime), std::bind(&YourClass::timerCallback, this));

        // Set initial steering value
        steeringPwmCmd_ = stopPWM;

        // Your other setup code here
    }

    void avoidTurn(bool left, bool big, bool avoidance, uint8_t &steeringPwmCmd) {
        if (avoidance) {
            if (left && !big) {
                // Short Right
                steeringPwmCmd_ = 25;
                rightRearPwmCmd = 75;
                leftRearPwmCmd = rightRearPwmCmd;
                turning = true;
                // Reset the timer for the next state change
                timer_->reset();
                avoidance = false;
            } else if (!left && !big) {
                // Short Left
                steeringPwmCmd_ = 75;
                turning = true;
                // Reset the timer for the next state change
                timer_->reset();
            } else if (big && left) {
                // Big Right
                steeringPwmCmd_ = 0;
                turning = true;
                // Reset the timer for the next state change
                timer_->reset();
            } else if (big && !left) {
                // Big Left
                steeringPwmCmd_ = 100;
                turning = true;
                // Reset the timer for the next state change
                timer_->reset();
            }
        }
    }

    void timerCallback() {
        if (turning) {
            // Set the steering back to straight
            steeringPwmCmd_ = 50;
            rightRearPwmCmd = 50;
            leftRearPwmCmd = rightRearPwmCmd;
            turning = false;
        }
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    const uint8_t maxPWM = 100;
    const uint8_t stopPWM = 50;
    const int turnTime = 2; // Time to turn in seconds
    bool turning = false;
    uint8_t steeringPwmCmd_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<YourClass>());
    rclcpp::shutdown();
    return 0;
}
