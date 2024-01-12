// avoidance_control.h
#ifndef __avoidance_control_H
#define __avoidance_control_H

#include <stdint.h>
#include <string.h>  

void init_timer();
void avoidTurn(bool left, bool big, bool avoidance, uint8_t *steeringPwmCmd, uint8_t *rightRearPwmCmd, int *pas_fini, int *var);
void timerCallback(void);


#endif // __avoidance_control_H
