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
uint8_t steeringPwmCmd = stopPWM;
uint8_t rightRearPwmCmd = 50;
uint8_t leftRearPwmCmd = 50;
int pas_fini = 1;

void timerCallback() {
    //if (turning) {
        // etat initiale
        steeringPwmCmd = 50;
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

void avoidTurn(bool left, bool big, bool avoidance, uint8_t *steeringPwmCmd_, uint8_t *rightRearPwmCmd_, int *pas_fini_, int *var) {
    *var = 0;
    *pas_fini_ = pas_fini; 
    *rightRearPwmCmd_ = rightRearPwmCmd;
    *steeringPwmCmd_ = steeringPwmCmd;
    
    if (avoidance) {
        *var = 1;
        if (left && !big) {
            *var = 2;
            //if ( 0<timer<6)
            // petit curve droit
            *steeringPwmCmd_ = 25;
            *rightRearPwmCmd_ = 75;
            //turning = true;

            //else if (6<timer<12)
            /* steeringPwmCmd = 25;
            rightRearPwmCmd = 75;
            leftRearPwmCmd = rightRearPwmCmd;
            turning = true; */

            // Reinitialiser le timer
            timer->reset();
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
