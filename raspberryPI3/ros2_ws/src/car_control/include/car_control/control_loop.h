#ifndef __control_loop_H
#define __control_loop_H

#include <cstdint>
#include <stdint.h>

#define DISTANCE_COMMAND 1.5    //meters


void recurrence_equation(double Error, int& Error_last, double& PWM_order, double& PWM_order_last, int Distance_to_target);  
void compensator_recurrence(bool init, int currentRightDistance, int currentLeftDistance, uint8_t& rightRearPwmCmd, uint8_t& leftRearPwmCmd);

#endif /*__ control_loop_H */