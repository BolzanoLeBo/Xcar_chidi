#include "interfaces/msg/avoidance_parameters.hpp"
#include "interfaces/msg/obstacles_id.hpp"
#include "interfaces/msg/side_obstacles.hpp"

#include "rclcpp/rclcpp.hpp"

#include "../include/avoidance/avoidance_node.h"
#include <fstream> 


using namespace std;
using placeholders::_1;


class avoidance : public rclcpp::Node {

public:
    avoidance()
    : Node("avoidance_node")
    {
        subscription_side_ = this->create_subscription<interfaces::msg::SideObstacles>(
        "side_obstacles", 10, std::bind(&avoidance::sideDataCallback, this, _1));

        subscription_id_ = this->create_subscription<interfaces::msg::ObstaclesId>(
        "obstacles_id", 10, std::bind(&avoidance::idDataCallback, this, _1));

        publisher_avoidance_param_= this->create_publisher<interfaces::msg::AvoidanceParameters>("avoidance_parameters", 10);

        timer_ = this->create_wall_timer(PERIOD_UPDATE_CMD, std::bind(&avoidance::updateParam, this));

        RCLCPP_INFO(this->get_logger(), "avoidance_node READY");
    }

    
private:


    /* Update the result of the Lidar analyse
    *
    *  This function is called when a message is published on the "/obstacle_side" topic
    */
    void sideDataCallback(const interfaces::msg::SideObstacles & side_obstacle) {
        lidar_left = side_obstacle.left_lidar;
        lidar_right = side_obstacle.right_lidar;
        left_min = side_obstacle.left_min;
        right_min = side_obstacle.right_min;
        obsatcletoavoid = side_obstacle.obstoavoid;
    }


    /* Update the result of the Ultrasonic Sensors analyse
    *
    *  This function is called when a message is published on the "/obstacle_id" topic
    */
    void idDataCallback(const interfaces::msg::ObstaclesId & id_obstacle) {
        us_left = id_obstacle.obstacle_left;
        us_right = id_obstacle.obstacle_right;
        us_middle = id_obstacle.obstacle_middle;
        us_big = id_obstacle.big_obstacle;
    }


    /* Update Avoidance parameters : right, left, big, small
    *
    * This function is called periodically by the timer [see PERIOD_UPDATE_CMD in "obstacle_avoidance_node.h"]
    * 
    */
    void updateParam(){

        auto avoidanceParam = interfaces::msg::AvoidanceParameters();
        avoidanceParam.big = false;
        avoidanceParam.obstacle= obsatcletoavoid;

        if (us_big){                                        /* Big obstacle */
            avoidanceParam.big = true;
        }

        if (lidar_left && !lidar_right){                    /* Harder to go by the left than the right : */
            if(us_left && !us_right && !us_middle){             // Obstacle on the left ->
                avoidanceParam.left = false;                    // Go by the right
            }
            
            else if(!us_left && us_right && !us_middle){        // Obstacle on the right ->    
                if (left_min >= AVOIDANCE_DISTANCE) {       
                    avoidanceParam.left = true;                 // + space on the left -> Go by the left 
                    avoidanceParam.big = false;
                }
                else{
                    avoidanceParam.left = false;                // + no space on the left -> Go by the right 
                    avoidanceParam.big = true;
                }
            }
             else if(us_middle){                                // Obstacle on the middle ->             
                avoidanceParam.left = false;                    // Go by the right
                avoidanceParam.big = true;
            }
        }
        else if(!lidar_left && lidar_right){                /* Harder to go by the right than the left : */
            if(us_left && !us_right && !us_middle){             // Obstacle on the left ->
               if (right_min >= AVOIDANCE_DISTANCE) {       
                    avoidanceParam.left = false;                 // + space on the right -> Go by the right 
                    avoidanceParam.big = false;
                }
                else{
                    avoidanceParam.left = true;                  // + no space on the right -> Go by the left 
                    avoidanceParam.big = true;
                }
            }
            else if(!us_left && us_right && !us_middle){       // Obstacle on the right ->             
                avoidanceParam.left = true;                     // Go by the left
            }
            else if(us_middle){                                // Obstacle on the middle ->             
                avoidanceParam.left = true;                    // Go by the left
                avoidanceParam.big = true;
            }

        }
 
        publisher_avoidance_param_->publish(avoidanceParam);
    }

     
    // ---- Private variables ----


    // The obstacle analyse with the Ultrasonic Sensors
    bool us_left;
    bool us_right;
    bool us_middle;
    bool us_big;

    // The obstacle analyse with the Lidar
    bool lidar_left;
    bool lidar_right;
    float left_min;
    float right_min;
    bool obsatcletoavoid;

    //Publishers
    rclcpp::Publisher<interfaces::msg::AvoidanceParameters>::SharedPtr publisher_avoidance_param_;

    //Subscribers
    rclcpp::Subscription<interfaces::msg::SideObstacles>::SharedPtr subscription_side_;
    rclcpp::Subscription<interfaces::msg::ObstaclesId>::SharedPtr subscription_id_;


    //Timer
    rclcpp::TimerBase::SharedPtr timer_;

};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<avoidance>();

  rclcpp::spin(node);


  rclcpp::shutdown();
  return 0;
}