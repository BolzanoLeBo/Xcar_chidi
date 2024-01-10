#include <stdint.h>
#include <unistd.h> // Include the necessary library for sleep function

void avoidTurn(bool left, bool big, bool avoidance, uint8_t &steeringPwmCmd) {
    const uint8_t maxPWM = 100;
    const uint8_t stopPWM = 50;
    const int turnTime = 3; // Time to turn in seconds

    if (avoidance) {
        if (left && !big) {
            // Short Right
            steeringPwmCmd = 25;

            // Implement the timer to turn for 3 seconds
            sleep(turnTime);

            // Set the steering back to straight
            steeringPwmCmd = stopPWM;

            // Implement the timer to go straight for 3 seconds
            sleep(turnTime);
        } else if (!left && !big) {
            // Short Left
            steeringPwmCmd = 75;
            
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
