#ifndef __control_loop_H
#define __control_loop_H

#include <cstdint>
#include <stdint.h>

#define DISTANCE_COMMAND 200    //centimeters


void recurrence_equation(double Error, double& Error_last, double& PWM_order, double& PWM_order_last, double Distance_to_target);  
void compensator_recurrence(bool init, double currentRightDistance, double currentLeftDistance, uint8_t& rightRearPwmCmd, uint8_t& leftRearPwmCmd);

#endif /*__ control_loop_H */