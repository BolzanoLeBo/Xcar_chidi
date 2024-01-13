// avoidance_control.h
#ifndef __avoidance_control_H
#define __avoidance_control_H

#include <stdint.h>
#include <string.h>  

void init_timer();
void avoidTurn(bool left, bool big, bool avoidance, uint8_t& steeringPwmCmd_, uint8_t& rightRearPwmCmd_, uint8_t& pas_fini_, int *var);
void timerCallback(void);


#endif // __avoidance_control_H
