## Image Processing Node

This Python script represents a ROS2 (Robot Operating System 2) node for image processing. The node subscribes to raw camera image data and performs processing to detect and track a target in the image. The processed information, including the target's position and angles, is published on corresponding topics.
Dependencies

    ROS2: Ensure that you have ROS2 installed on your system.
    rclpy: ROS Python client library.
    sensor_msgs: ROS standard message types for sensor data.
    interfaces: Custom ROS messages for communication.
    websockets: Python library for WebSocket communication.
    asyncio: Python library for asynchronous I/O operations.
    cv_bridge: ROS package for converting between ROS Image messages and OpenCV images.
    numpy: Library for numerical operations in Python.

## Usage

Installing Dependencies: Install the required Python libraries using the following:

'''bash

pip install websockets asyncio opencv-python numpy

Building and Running: Source your ROS2 workspace and run the node.
'''

'''bash

    ros2 run <your_package_name> img_processing_node.py
'''

## Node Description

Node Name: img_processing_node

# Published Topics:
    /user_lost: Publishes information about whether the user is lost or not.
    /tracking_pos_angle: Publishes tracking information, including minimum and maximum angles, and camera angle.

# Subscribed Topics:
    /image_raw: Receives raw camera image data.
    /state: Receives the current state information.
    /init_button: Receives information about the initialization button state.

## Functionality

The node performs the following tasks:

    Initialization: Sets up subscriptions, publishers, and a timer during node initialization.

    Image Processing Loop: Periodically processes the received camera image and sends the processed information.

    Target Initialization: Handles target initialization based on an external initialization button.

    WebSocket Communication: Establishes WebSocket communication to send and receive information.

    Calculating Position: Calculates the position of the target in the camera image.

    Checking User Lost: Monitors whether the user is lost based on the received information.

    Publishing Information: Publishes information about user status and tracking angles.

## Building and Running Tests

To run tests, you can use the ROS2 testing framework. Ensure that you have a proper setup for testing in your ROS2 workspace.