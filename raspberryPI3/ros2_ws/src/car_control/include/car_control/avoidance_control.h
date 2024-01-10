#ifndef __avoidance_control_H
#define __avoidance_control_H

#include <cstdint>
#include <stdint.h>


void avoidTurn(bool left, bool big, bool avoidance, uint8_t& steeringPwmCmd);

#endif /*__avoidance_control_H */