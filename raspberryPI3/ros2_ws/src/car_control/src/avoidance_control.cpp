#include <stdint.h>
#include <unistd.h> // Include the necessary library for sleep function

void avoidTurn(bool left, bool big, bool avoidance, uint8_t &steeringPwmCmd, uint8_t& rightRearPwmCmd, uint8_t& leftRearPwmCmd) {
    const uint8_t maxPWM = 100;
    const uint8_t stopPWM = 50;
    const int turnTime = 3; // Time to turn in seconds

    if (avoidance) {
        if (left && !big) {
            // Short Right
            steeringPwmCmd = 75;
            rightRearPwmCmd = 0;
            leftRearPwmCmd = rightRearPwmCmd;

            // Implement the timer to turn for 3 seconds
            sleep(turnTime);

            // Set the steering back to straight
            steeringPwmCmd = 25;
            rightRearPwmCmd = 0;
            leftRearPwmCmd = rightRearPwmCmd;
            // Implement the timer to go straight for 3 seconds
            sleep(turnTime);
            steeringPwmCmd = 50;
            rightRearPwmCmd = 0;
            leftRearPwmCmd = rightRearPwmCmd;
            sleep(turnTime);
        } else if (!left && !big) {
            // Short Left
            steeringPwmCmd = 25;
            
            // Implement the timer to turn for 3 seconds
            sleep(turnTime);

            // Set the steering back to straight
            steeringPwmCmd = stopPWM;

            // Implement the timer to go straight for 3 seconds
            sleep(turnTime);
        } else if (big && left) {
            // Big Right
            steeringPwmCmd = 0;

            // Implement the timer to turn for 3 seconds
            sleep(turnTime);

            // Set the steering back to straight
            steeringPwmCmd = stopPWM;

            // Implement the timer to go straight for 3 seconds
            sleep(turnTime);
        } else if (big && !left) {
            // Big Left
            steeringPwmCmd = 100;

            // Implement the timer to turn for 3 seconds
            sleep(turnTime);

            // Set the steering back to straight
            steeringPwmCmd = stopPWM;

            // Implement the timer to go straight for 3 seconds
            sleep(turnTime);
        }
    }
}
