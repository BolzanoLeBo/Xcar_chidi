## System Check Node

This C++ file represents a ROS2 (Robot Operating System 2) node designed for system monitoring and checking. The node subscribes to various sensor data topics and periodically performs system checks. It publishes a report based on the gathered data.
Dependencies

    ROS2: Ensure that you have ROS2 installed on your system.
    rclcpp: ROS C++ client library.
    sensor_msgs: ROS standard message types for sensor data.
    interfaces: Custom ROS messages for communication.
    unistd.h: Provides access to the POSIX operating system API.

## Usage

    Building: Compile the code using a ROS2 workspace.

    '''bash

colcon build --packages-select <your_package_name>
'''

Running the Node: Launch the ROS2 system and run the node.

'''bash

    ros2 run <your_package_name> system_check_node
'''

## Node Description

    Node Name: system_check_node
    Published Topics:
        /system_check: Publishes system check reports.
    Subscribed Topics:
        /system_check: Receives communication ACK and print requests.
        /gnss_data: GNSS (Global Navigation Satellite System) data.
        /imu/raw_data: Raw IMU (Inertial Measurement Unit) data.
        /imu/mag: Magnetic field data.
        /us_data: Ultrasonic sensor data.
        /general_data: General system data.
        /scan: Lidar scan data.
        /image_raw: Raw camera image data.

## Functionality

The node performs the following tasks:

    Initialization: Sets up publishers, subscribers, and timers during node initialization.

    System Check Loop: Periodically checks the system health and updates variables based on received data.

    Communication Check: Verifies communication status with different components.

    Battery Check: Monitors battery voltage and reports status.

    Sensors Check: Checks the status of various sensors, including ultrasonics, GPS, IMU, Lidar, and camera.

    Report Generation: Generates a detailed report based on the collected data.

    Report Publishing: Publishes the generated system check report on the /system_check topic.

Building and Running Tests

To build tests:

'''bash

colcon build --packages-select <your_package_name> --cmake-target tests
'''

To run tests:

'''bash

colcon test --packages-select <your_package_name> --event-handlers console_
'''