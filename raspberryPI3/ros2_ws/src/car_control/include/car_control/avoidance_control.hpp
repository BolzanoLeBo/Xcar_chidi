// your_class.hpp
#ifndef AVOIDANCE_CONTROL_HPP
#define AVOIDANCE_CONTROL_HPP

#include <rclcpp/rclcpp.hpp>
#include <chrono>

class YourClass : public rclcpp::Node {
public:
    YourClass();

    void avoidTurn(bool left, bool big, bool avoidance, uint8_t &steeringPwmCmd);

    void timerCallback();

private:
    rclcpp::TimerBase::SharedPtr timer_;
    const uint8_t maxPWM = 100;
    const uint8_t stopPWM = 50;
    const int turnTime = 2; // Time to turn in seconds
    bool turning = false;
    uint8_t steeringPwmCmd_;
    uint8_t rightRearPwmCmd;
    uint8_t leftRearPwmCmd;
};

#endif  // YOUR_CLASS_HPP
