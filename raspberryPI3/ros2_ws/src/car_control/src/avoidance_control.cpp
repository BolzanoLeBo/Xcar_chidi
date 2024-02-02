#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <iostream>
#include <time.h> 

// Variáveis globais
rclcpp::Node::SharedPtr node;
rclcpp::TimerBase::SharedPtr timer;

/******Définition du Timer**********/
/*rclcpp::Time start_time;
rclcpp::Duration ti = 3;
rclcpp::Duration ti2 = 6;*/
time_t start_time;


// void timerCallback() {
//     //if (turning) {
//         // etat initiale
//     steeringPwmCmd = 75;
//     rightRearPwmCmd = 50;
//     leftRearPwmCmd = rightRearPwmCmd;
//     //turning = false;
//     pas_fini = 0;
//     //}
// }

// void init_timer() {
//     node = std::make_shared<rclcpp::Node>("node_timer");
//     timer = node->create_wall_timer(std::chrono::seconds(turnTime), timerCallback);
// }

void avoidTurn(bool left, bool big, uint8_t& steeringPwmCmd, uint8_t& rightRearPwmCmd, uint8_t& pas_fini, uint8_t& step, uint8_t& sequence) {
    // Associar rightRearPwmCmd_ à variável global x
    //rightRearPwmCmd_ = static_cast<uint8_t>(rightRearPwmCmd);
    //steeringPwmCmd_ = static_cast<uint8_t>(steeringPwmCmd);
    //pas_fini_ = static_cast<uint8_t>(pas_fini);
    // rightRearPwmCmd_ = &rightRearPwmCmd;
    // steeringPwmCmd_ = &steeringPwmCmd;
    
    //rclcpp::Time current_time = rclcpp::Clock().now();
    time_t timer;

    if (pas_fini==1) {
        // PROBLEMEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE AVEC16 SEQUENCE
        if (left && sequence == 0) {
            sequence = 1;
        }
        else if (sequence == 0)
        {
            sequence = 2;
        }
        /*if (left && !big && sequence == 0) {
            sequence = 1;
        }
        else if (!left && !big && sequence ==0){
            sequence =2;
        }*/
        /*else if (left && big && sequence == 0){
            sequence =3;
        }
        else if (sequence == 0) {
            sequence =4;*/
        //else 16
        //{
        //    pas_fini = 0;
        //}


        //Obstacle pas gros et à gauche, on évite par la droite 
        if(sequence == 1)
        {
            // Reinitialiser le timer
            if(step == 0)
            {
                time(&start_time);
                step = 1;
            }
            // on se décale sur la droite
            if(step == 1)
            {
                if((time(&timer)-start_time) < 3)
                {
                    steeringPwmCmd = 0;
                    rightRearPwmCmd = 50; //Pb avec les valeurs 
                }
                else
                {                
                    step = 2;
                }
            }
            // On avance
            if(step == 2)
            {
                if((time(&timer)-start_time) < 7)
                {
                    steeringPwmCmd = 0;
                    rightRearPwmCmd = 75;
                }
                else
                {                
                    step = 3;
                }
            }

            if(step == 3)
            {
                if((time(&timer)-start_time) < 10)
                {
                    steeringPwmCmd = 75;
                    rightRearPwmCmd = 50;
                }
                else
                {                
                    step = 4;
                }
            }


            if(step == 4)
            {
                if((time(&timer)-start_time) < 12)
                {
                    steeringPwmCmd = 75;
                    rightRearPwmCmd = 75;
                }
                else
                {                
                    step = 5;
                }
            }

            if(step == 5)
            {
                if((time(&timer)-start_time) < 15)
                {
                    steeringPwmCmd = 50;
                    rightRearPwmCmd = 50;
                }
                else
                {                
                    step = 6;
                }
            }

            if(step == 6)
            {
                if((time(&timer)-start_time) < 18)
                {
                    steeringPwmCmd = 50;
                    rightRearPwmCmd = 75;
                }
                else
                {                
                    step = 7;
                }
            }
            // On stop la voiture
            if(step == 7)
            {
                steeringPwmCmd = 50;
                rightRearPwmCmd = 50;
                pas_fini = 0;
                step = 0;
                sequence =0;
            }
        }
        //obstacle pas gros  et à droite ,on évite par la gauche
        if(sequence == 2)
        {
            // Reinitialiser le timer
            if(step == 0)
            {
                time(&start_time);
                step = 1;
            }
            // on se décale sur la droite
            if(step == 1)
            {
                if((time(&timer)-start_time) < 3)
                {
                    steeringPwmCmd = 100;
                    rightRearPwmCmd = 50;
                }
                else
                {                
                    step = 2;
                }
            }
            // On se remet dans l'axe
            if(step == 2)
            {
                if((time(&timer)-start_time) < 7)
                {
                    steeringPwmCmd = 100;
                    rightRearPwmCmd = 75;
                }
                else
                {                
                    step = 3;
                }
            }

            if(step == 3)
            {
                if((time(&timer)-start_time) < 10)
                {
                    steeringPwmCmd = 25;
                    rightRearPwmCmd = 50;
                }
                else
                {                
                    step = 4;
                }
            }

            if(step == 4)
            {
                if((time(&timer)-start_time) < 12)
                {
                    steeringPwmCmd = 25;
                    rightRearPwmCmd = 75;
                }
                else
                {                
                    step = 5;
                }
            }


            if(step == 5)
            {
                if((time(&timer)-start_time) < 15)
                {
                    steeringPwmCmd = 50;
                    rightRearPwmCmd = 50;
                }
                else
                {                
                    step = 6;
                }
            }

            if(step == 6)
            {
                if((time(&timer)-start_time) < 18)
                {
                    steeringPwmCmd = 50;
                    rightRearPwmCmd = 75;
                }
                else
                {                
                    step = 7;
                }
            }
            // On stop la voiture
            if(step == 7)
            {
                steeringPwmCmd = 50;
                rightRearPwmCmd = 50;
                pas_fini = 0;
                step = 0;
                sequence =0;
            }
        }
    }
}
//*************************************************************PARTIE BIG***************************************************************************//
        //obstacle gros et à gauche, on évite par la droite
       /**if(sequence == 3)
        {
            // Reinitialiser le timer
            if(step == 0)
            {
                time(&start_time);
                step = 1;
            }
            // on se décale sur la droite
            if(step == 1)
            {
                if((time(&timer)-start_time) < 3)
                {
                    steeringPwmCmd = 50;
                    rightRearPwmCmd = 25;
                }
                else
                {                
                    step = 2;
                }
            }
            // On se remet dans l'axe
            if(step == 2)
            {
                if((time(&timer)-start_time) < 6)
                {
                    steeringPwmCmd = 0;
                    rightRearPwmCmd = 50;
                }
                else
                {                
                    step = 3;
                }
            }

            if(step == 3)
            {
                if((time(&timer)-start_time) < 12)
                {
                    steeringPwmCmd = 0;
                    rightRearPwmCmd = 75;
                }
                else
                {                
                    step = 4;
                }
            }


            if(step == 4)
            {
                if((time(&timer)-start_time) < 15)
                {
                    steeringPwmCmd = 100;
                    rightRearPwmCmd = 50;
                }
                else
                {                
                    step = 5;
                }
            }

            if(step == 5)
            {
                if((time(&timer)-start_time) < 21)
                {
                    steeringPwmCmd = 100;
                    rightRearPwmCmd = 75;
                }
                else
                {                
                    step = 6;
                }
            }
            // On stop la voiture
            if(step == 6)
            {
                steeringPwmCmd = 50;
                rightRearPwmCmd = 50;
                pas_fini = 0;
                step = 0;
                sequence =0;
            }
        }

        //obstacle gros et avoid par la droite 
        if(sequence == 4)
        {
            // Reinitialiser le timer
            if(step == 0)
            {
                time(&start_time);
                step = 1;
            }
            // on se décale sur la droite
            if(step == 1)
            {
                if((time(&timer)-start_time) < 3)
                {
                    steeringPwmCmd = 50;
                    rightRearPwmCmd = 25;
                }
                else
                {                
                    step = 2;
                }
            }
            // On se remet dans l'axe
            if(step == 2)
            {
                if((time(&timer)-start_time) < 9)
                {
                    steeringPwmCmd = 100;
                    rightRearPwmCmd = 50;
                }
                else
                {                
                    step = 3;
                }
            }

            if(step == 3)
            {
                if((time(&timer)-start_time) <12)
                {
                    steeringPwmCmd = 100;
                    rightRearPwmCmd = 75;
                }
                else
                {                
                    step = 4;
                }
            }


            if(step == 4)
            {
                if((time(&timer)-start_time) < 15)
                {
                    steeringPwmCmd = 0;
                    rightRearPwmCmd = 50;
                }
                else
                {                
                    step = 5;
                }
            }

            if(step == 5)
            {
                if((time(&timer)-start_time) < 21)
                {
                    steeringPwmCmd = 0;
                    rightRearPwmCmd = 75;
                }
                else
                {                
                    step = 6;
                }
            }
            // On stop la voiture
            if(step == 6)
            {
                steeringPwmCmd = 50;
                rightRearPwmCmd = 50;
                pas_fini = 0;
                step = 0;
                sequence =0;
            }
        }*/
        
        
        
        
        
        
        /* else if (!left && !big) {
            // petit curve gauche
            *steeringPwmCmd = 75;
            *rightRearPwmCmd = 75;
            *leftRearPwmCmd = *rightRearPwmCmd;
            turning = true;
            timer->reset();
        } else if (big && left) {
            // gros cruve droit
            *steeringPwmCmd = 0;
            *rightRearPwmCmd = 75;
            *leftRearPwmCmd = *rightRearPwmCmd;
            turning = true;
            timer->reset();
        } else if (big && !left) {
            // gros curve gauche
            *steeringPwmCmd = 100;
            *rightRearPwmCmd = 75;
            *leftRearPwmCmd = *rightRearPwmCmd;
            turning = true;
            timer->reset();
        } */