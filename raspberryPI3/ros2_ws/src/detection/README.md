# Detection Node

This repository contains the code for a ROS2 (Robot Operating System 2) node named `detection_node`. The node processes data from ultrasonic sensors and a LIDAR scanner to detect obstacles in the environment and publishes corresponding messages.

## Overview

The `detection_node` subscribes to data from ultrasonic sensors (`us_data` topic), LIDAR scanner (`scan` topic), and a tracking camera (`tracking_pos_angle` topic). Based on this sensor data, the node determines the presence of obstacles and publishes messages on various topics, including `obstacles`, `side_obstacles`, `obstacles_id`, and `userdistance`.

## Dependencies

- ROS2 (Foxy Fitzroy or later)
- `rclcpp` (ROS C++ client library)
- `sensor_msgs` (ROS2 standard messages for sensors)
- `interfaces` (Custom message types for obstacle-related information)

## Installation

1. Clone the repository:

   '''bash
   git clone https://github.com/EmelineDy/pivoane.git
   colcon build
   '''

## Usage

1. Launch ROS2:

    '''bash
    ros2 run detection_node
    '''

The detection_node will start processing sensor data and publishing obstacle-related messages.

## Parameters

LIM_US: Threshold for ultrasonic sensors to detect obstacles (default: 70)
LIM_AVOID_US: Threshold for ultrasonic sensors to trigger obstacle avoidance (default: 60)
LIM_NON_AVOID_US: Threshold for ultrasonic sensors to detect non-avoidable obstacles (default: 50)
LIM_LIDAR_FRONT: Threshold for front-facing LIDAR to detect obstacles (default: 1.70)
LIM_LIDAR_REAR: Threshold for rear-facing LIDAR to detect obstacles (default: 0.70)
LIM_LIDAR_AVOID: Threshold for LIDAR to trigger obstacle avoidance (default: 1.50)
PERIOD_UPDATE_CMD: Time interval for updating obstacle detection (default: 1 second)

## Subscribed Topics

us_data: Ultrasonic sensor data (interfaces/msg/Ultrasonic)
scan: LIDAR scan data (sensor_msgs/msg/LaserScan)
tracking_pos_angle: Tracking camera data (interfaces/msg/TrackingPosAngle)

## Published Topics

obstacles: Detected obstacle information (interfaces/msg/Obstacles)
side_obstacles: Side-specific obstacle information (interfaces/msg/SideObstacles)
obstacles_id: Obstacle identification information (interfaces/msg/ObstaclesId)
userdistance: User distance information (interfaces/msg/Userdistance)

## Node Structure

The node is structured as a subclass of rclcpp::Node and includes callback functions for ultrasonic sensor data, LIDAR scan data, and tracking camera data. It utilizes timers to periodically update obstacle detection.

'''cpp

class detection : public rclcpp::Node {
   // ... (class definition)
};
'''

## Acknowledgments

This code was initially created by EmelineDy and has been adapted for use in our project.
License

This code is provided under the MIT License. Feel free to use, modify, and distribute it according to the terms of the license.
