#include "../include/car_control/control_loop.h"


/* Calculate the recurrence equation based on the compensator to move the car forward and backward
*   RPM_order -> Desired Speed (RPM)
*   PWM_order -> I(k+1)
*   PWM_order_last -> I(k)
*   Error -> Erreur(k+1)
*   Error_last -> Erreur(k)
*/
void recurrence_equation(double Error, double& Error_last, double& PWM_order, double& PWM_order_last, double Distance_to_target){
    
    // Error that corresponds to the command - the distance from the car to the target
    Error=DISTANCE_COMMAND-Distance_to_target;  //centimeters
    // Si error > 0 then trop pres donc il faut reculer
    // Si error < 0 then trop loin donc il faut avancer
    Error = Error/100;

    // Corrected PWM 
    PWM_order = 100*Error;
    //PWM_order = PWM_order_last + 100*Error - 99.95*Error_last;


    // Error Update
    Error_last=Error;

    // Saturation 
    if (PWM_order > 50) {PWM_order=50;}
    if (PWM_order < -50) {PWM_order=-50;}

    // PWM Update
    PWM_order_last=PWM_order;
}

void compensator_recurrence(bool init,double currentRightDistance, double currentLeftDistance, uint8_t& rightRearPwmCmd, uint8_t& leftRearPwmCmd){   

    // Variable statique pour conserver la valeur entre les appels
    static double Left_PWM_order;
    static double Right_PWM_order;
    static double Left_PWM_order_last;
    static double Right_PWM_order_last;
    static double Left_Error_last;
    static double Right_Error_last;
    
    if (init)
    {
        Left_PWM_order = 0.0;
        Right_PWM_order = 0.0;
        Left_PWM_order_last = 0.0;
        Right_PWM_order_last = 0.0;
        Left_Error_last = 0.0;
        Right_Error_last = 0.0;
    }
        
    
    double Left_Error=0.0;
    double Right_Error=0.0;


    recurrence_equation(Right_Error, Right_Error_last, Right_PWM_order, Right_PWM_order_last, currentRightDistance);
    //recurrence_equation(Left_Error, Left_Error_last, Left_PWM_order, Left_PWM_order_last, currentLeftDistance);
    
    if(Right_Error > 0)
    {
        rightRearPwmCmd = Right_PWM_order + 50; 
        leftRearPwmCmd = Right_PWM_order + 50; 
    }
    else{
        rightRearPwmCmd = 50 - Right_PWM_order; 
        leftRearPwmCmd = 50 - Right_PWM_order; 
    }
    


}