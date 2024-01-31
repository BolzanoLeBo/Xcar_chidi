## System Check Acknowledgment Node

This C++ program represents a ROS2 (Robot Operating System 2) node that acknowledges a system check request. The node listens for incoming SystemCheck messages, responds affirmatively, and publishes an acknowledgment message.
Dependencies

    ROS2: Ensure that you have ROS2 installed on your system.
    rclcpp: ROS C++ client library.
    interfaces: Custom ROS messages for communication.

## Usage

Building: Compile the program using your preferred C++ compiler. Make sure that your ROS2 workspace is sourced.

'''bash
colcon build --packages-select <your_package_name>
'''

Running: Run the compiled executable.

'''bash

    ros2 run <your_package_name> system_check_ack_node
'''

## Node Description

    Node Name: system_check_ack_node

    Published Topics:
        /system_check: Publishes acknowledgment messages for system check requests.

    Subscribed Topics:
        /system_check: Listens for system check requests.

## Functionality

The node performs the following tasks:

    Initialization: Sets up the ROS2 node, including publishers and subscribers.

    System Check Callback: Listens for incoming system check requests. If a request is received, the node responds with an acknowledgment message.

    Acknowledgment Message: Creates an acknowledgment message with a positive response and additional system information (e.g., Jetson status).

    Publishing Acknowledgment: Publishes the acknowledgment message on the /system_check topic.

## Building and Running Tests

To run tests, you can use the ROS2 testing framework. Ensure that you have a proper setup for testing in your ROS2 workspace.