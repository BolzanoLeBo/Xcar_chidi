/* This file contains the code that pusblishes the messages depending on the us sensors data */
/*code created by https://github.com/EmelineDy/pivoane and used in our project*/

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

#include <chrono>
#include <cstdio>

#include "interfaces/msg/ultrasonic.hpp"
#include "interfaces/msg/obstacles.hpp"
#define LIM_US 70
#define LIM_LIDAR_FRONT 1.70
#define LIM_LIDAR_REAR 0.70

#include "../include/detection/detection_node.h"

using namespace std;
using placeholders::_1;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class detection: public rclcpp::Node {
  public:
    detection()
    : Node("detection_node")
    {
      publisher_obstacle_ = this->create_publisher<interfaces::msg::Obstacles>("obstacles", 10);

      subscription_ultrasonic_sensor_ = this->create_subscription<interfaces::msg::Ultrasonic>(
       "us_data", 10, std::bind(&detection::usDataCallback, this, _1));

      subscription_lidar_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "scan", 10, std::bind(&detection::lidarDataCallback, this, _1));

      timer_ = this->create_wall_timer(PERIOD_UPDATE_CMD, std::bind(&detection::DetectCom, this));
    
      RCLCPP_INFO(this->get_logger(), "detection_node READY");
    }

  private:

    //Counter of warnings
    int nb_warning = 0;
    
    //Speed variable
    uint8_t last_front_us_detect = 0;
    uint8_t last_rear_us_detect = 0;
    uint8_t last_us_error = 0;

    uint8_t last_front_lidar_detect = 0;
    uint8_t last_rear_lidar_detect = 0;

    uint8_t lidar_front =0;
    uint8_t lidar_rear =0;


    uint8_t us_front =0;
    uint8_t us_rear =0;


    int print_list = 0;
    //Publisher
    rclcpp::Publisher<interfaces::msg::Obstacles>::SharedPtr publisher_obstacle_;

    //Subscriber
    rclcpp::Subscription<interfaces::msg::Ultrasonic>::SharedPtr subscription_ultrasonic_sensor_;

    //Subscriber
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_lidar_;

    rclcpp::TimerBase::SharedPtr timer_;

    void usDataCallback(const interfaces::msg::Ultrasonic & ultrasonic){
      

      // Checking that the data sent by us sensors are normal
      if(ultrasonic.front_center < 600 && ultrasonic.front_left < 600 && ultrasonic.front_right < 600 && ultrasonic.rear_center < 600 && ultrasonic.rear_left < 600 && ultrasonic.rear_right < 600 && ultrasonic.front_center > 0 && ultrasonic.front_left > 0 && ultrasonic.front_right > 0 && ultrasonic.rear_center > 0 && ultrasonic.rear_right > 0 && ultrasonic.rear_left > 0){
        // nb_warning = 0;
        // obstacleMsg.us_error = 0;
        // Message of obstacle if there is one in front of the car at less than 75 cm
        if ((ultrasonic.front_center <= LIM_US)){
        us_front = 1;
        } 
        // Message of obstacle if there is one in at the left of the car at less than 20 cm
        else if((ultrasonic.front_left <= LIM_US)){
          us_front = 1;
        } 
        // Message of obstacle if there is one in at the right of the car at less than 20 cm
        else if((ultrasonic.front_right <= LIM_US)){
          us_front = 1; 
        }
        // No message of obstacle if none of those cases
        else{
          us_front = 0;
        }

        if ((ultrasonic.rear_center <= LIM_US)){
          us_rear = 1;
        } 
        // Message of obstacle if there is one in at the left of the car at less than 20 cm
        else if((ultrasonic.rear_left <= LIM_US)){
          us_rear = 1;
        } 
        // Message of obstacle if there is one in at the right of the car at less than 20 cm
        else if((ultrasonic.rear_right <= LIM_US)){
          us_rear = 1; 
        }
        // No message of obstacle if none of those cases
        else{
          us_rear= 0;
        }
 
      // } else if(nb_warning >= 5){
      //   //ERROR if strange value of the us_data (too far or negative value) 5 times in a row
      //   RCLCPP_ERROR(this->get_logger(), "Error : wrong us data for too long");
      //   // Adding the message when there is a problem with the us sensors
      //   obstacleMsg.us_error = 1;
      // } else{
        //WARNING if strange value of the us_data (too far or negative value)
        // RCLCPP_WARN(this->get_logger(), "Warning : wrong us data");
        // nb_warning += 1;
      //}
      // Changing last value of us_front_detect and publishing message of obstacle
      // if ((last_front_us_detect != obstacleMsg.us_front_detect) || last_rear_us_detect != obstacleMsg.us_rear_detect || last_us_error != obstacleMsg.us_error ) {   
      //   last_front_us_detect = obstacleMsg.us_front_detect;
      //   last_rear_us_detect = obstacleMsg.us_rear_detect;
      //   last_us_error = obstacleMsg.us_error;
      //   publisher_obstacle_->publish(obstacleMsg);
      // }
    }
    }

  void lidarDataCallback(const sensor_msgs::msg::LaserScan & scan){
      
      int size = (int)scan.ranges.size();
      int delta = size/8;
      if (!print_list)
      {
        for (int i = 0; i < size; i++)
        {
          RCLCPP_INFO(this->get_logger(),((to_string(i) + "  lidar  " + to_string(scan.ranges[i])).data()));
        }
        print_list = 1 ;

      }
      float front_min = 12.0; 
      float rear_min = 12.0;
      for (int i = 0;i<size;i++){
        if (i>=3*size/16 && i<(5*size)/16){
          if (scan.ranges[i]<front_min){
              front_min=scan.ranges[i];
          }
        }
        if (i<=(size*3/4) + delta && i >= (size*3/4) - delta){
          if (scan.ranges[i]<rear_min){
              rear_min=scan.ranges[i];
          }
        }
      }

      if (front_min<LIM_LIDAR_FRONT){
        lidar_front=1;
        //RCLCPP_INFO(this->get_logger(),(("  lidar  1 " + to_string(front_min)).data()));
      }
      else{
        lidar_front=0;
        //RCLCPP_INFO(this->get_logger(),(("  lidar  0 " + to_string(front_min)).data()));
      }

      if (rear_min<LIM_LIDAR_REAR){
        lidar_rear=1;
      }
      else{
        lidar_rear=0;
      }

      // Changing last value of lidar_front_detect and publishing message of obstacle
      //if ((last_front_lidar_detect != obstacleMsg.lidar_front_detect) || (last_rear_lidar_detect != obstacleMsg.lidar_rear_detect)) {   
      //last_front_lidar_detect = obstacleMsg.lidar_front_detect;
      //last_rear_lidar_detect = obstacleMsg.lidar_rear_detect
      //}
  }    

  void DetectCom(){
    auto obstacleMsg = interfaces::msg::Obstacles();
    if (lidar_front || us_front){
      obstacleMsg.front=1;
    }
    else{
    obstacleMsg.front=0;
    }
    if (lidar_rear || us_rear){
      obstacleMsg.rear=1;
    }
    else{
    obstacleMsg.rear=0;
    }

    publisher_obstacle_->publish(obstacleMsg);
  }
  
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<detection>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
