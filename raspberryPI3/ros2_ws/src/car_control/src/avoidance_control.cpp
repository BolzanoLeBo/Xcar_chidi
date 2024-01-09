#include "../include/car_control/avoidance_control.h"


void avoidTurn(bool left, bool big,, bool obstacle, uint8_t& rightRearPwmCmd, uint8_t& leftRearPwmCmd) {
    const uint8_t maxPWM = 100;
    const uint8_t stopPWM = 50;

    if (obstacle)
    {
        if (left && !big) {
            // Trajectoire qui tourne à gauche
            rightRearPwmCmd = maxPWM;
            leftRearPwmCmd = stopPWM + 10;
        } else if (!left && !big) {
            // Trajectoire qui tourne à droite
            rightRearPwmCmd = 0;
            leftRearPwmCmd = maxPWM;
        } else if (big && left) {
            // Commande pour reculer et ensuite aller à gauche
            rightRearPwmCmd = stopPWM / 2;  // Exemple : demi-vitesse en marche arrière
            leftRearPwmCmd = 0;
        } else if (big && !left) {
            // Commande pour reculer et ensuite aller à droite
            rightRearPwmCmd = 0;
            leftRearPwmCmd = stopPWM / 2;  // Exemple : demi-vitesse en marche arrière
        }
    }
}
