#ifndef __avoidance_control_H
#define __avoidance_control_H

#include <cstdint>
#include <stdint.h>


void avoidTurn(bool left, bool big, uint8_t& rightRearPwmCmd, uint8_t& leftRearPwmCmd);

#endif /*__avoidance_control_H */