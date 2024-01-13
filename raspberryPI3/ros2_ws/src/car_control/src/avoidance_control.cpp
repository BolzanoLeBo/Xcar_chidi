#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <iostream>

// Variáveis globais
rclcpp::Node::SharedPtr node;
rclcpp::TimerBase::SharedPtr timer;
const uint8_t maxPWM = 100;
const uint8_t stopPWM = 50;
const int turnTime = 3; // Temp
bool turning = false;
uint8_t steeringPwmCmd =50;
uint8_t rightRearPwmCmd =50;
uint8_t leftRearPwmCmd =50;
int pas_fini = 1;
int count = 0;

void timerCallback() {
    //if (turning) {
        // etat initiale
    steeringPwmCmd = 75;
    rightRearPwmCmd = 50;
    leftRearPwmCmd = rightRearPwmCmd;
    //turning = false;
    pas_fini = 0;
    //}
}

void init_timer() {
    node = std::make_shared<rclcpp::Node>("node_timer");
    timer = node->create_wall_timer(std::chrono::seconds(turnTime), timerCallback);
}

void avoidTurn(bool left, bool big, bool avoidance, uint8_t& steeringPwmCmd_, uint8_t& rightRearPwmCmd_, uint8_t& pas_fini_, int *var) {
    *var = 0;
    // Associar rightRearPwmCmd_ à variável global x
    rightRearPwmCmd_ = static_cast<uint8_t>(rightRearPwmCmd);
    steeringPwmCmd_ = static_cast<uint8_t>(steeringPwmCmd);
    pas_fini_ = static_cast<uint8_t>(pas_fini);
    // rightRearPwmCmd_ = &rightRearPwmCmd;
    // steeringPwmCmd_ = &steeringPwmCmd;
    
    if (avoidance) {
        *var = 1;
        if (left && !big) {
            *var = 2;
            //if ( 0<timer<6)
            // petit curve droit
            steeringPwmCmd = 25;
            rightRearPwmCmd = 75;
            count = count + 1;
            //turning = true;

            //else if (6<timer<12)
            /* steeringPwmCmd = 25;
            rightRearPwmCmd = 75;
            leftRearPwmCmd = rightRearPwmCmd;
            turning = true; */

            // Reinitialiser le timer
            if(count == 1){
                timer->reset();
            }
        } /* else if (!left && !big) {
            // petit curve gauche
            *steeringPwmCmd = 75;
            *rightRearPwmCmd = 75;
            *leftRearPwmCmd = *rightRearPwmCmd;
            turning = true;
            timer->reset();
        } else if (big && left) {
            // gros cruve droit
            *steeringPwmCmd = 0;
            *rightRearPwmCmd = 75;
            *leftRearPwmCmd = *rightRearPwmCmd;
            turning = true;
            timer->reset();
        } else if (big && !left) {
            // gros curve gauche
            *steeringPwmCmd = 100;
            *rightRearPwmCmd = 75;
            *leftRearPwmCmd = *rightRearPwmCmd;
            turning = true;
            timer->reset();
        } */
    }
}
