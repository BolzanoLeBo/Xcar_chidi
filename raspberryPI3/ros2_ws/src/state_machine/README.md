## Overview

This is a ROS2 (Robot Operating System 2) node written in C++ for a state machine controlling the behavior of a robot. The state machine transitions between different states based on user input from a joystick, web interface, and other sensor inputs.

## Dependencies

ROS2 (Foxy or later)
C++11 or later
sensor_msgs (ROS2 message package)
std_msgs (ROS2 message package)
interfaces (custom ROS2 message package)
rclcpp (ROS2 C++ client library)

## Compilation

Make sure you have sourced your ROS2 workspace and then compile the code using colcon:

'''bash
colcon build --packages-select your_package_name
'''
## Execution

Run the node after compilation:

'''bash
ros2 run your_package_name state_machine_node
'''
## Node Description

The state machine node subscribes to various topics for input, such as joystick commands, obstacle detection, and web interface commands. It publishes the current state, system check information, and joystick commands to other nodes in the system.

# Subscribed Topics

    joy (sensor_msgs/Joy): Joystick input for manual control.
    obstacles (interfaces/Obstacles): Information about obstacles detected by the robot.
    web_mode (interfaces/WebMode): Web interface commands for state transitions.
    motors_order2 (interfaces/MotorsOrder): Motor commands for determining the direction of the robot.
    user_lost (interfaces/UserLost): Information about the user's presence.

# Published Topics

    state (interfaces/State): Information about the current and previous states of the robot.
    system_check (interfaces/SystemCheck): Request to print the last system check report.
    joystick_order (interfaces/JoystickOrder): Commands for controlling the robot's propulsion and steering.

## Configuration

Adjust the deadzone values (DEADZONE_LT_RT, DEADZONE_LS_X_LEFT, DEADZONE_LS_X_RIGHT) and other constants based on your hardware and control requirements.
States

The state machine transitions between the following states:

    Idle
    Manual
    Autonomous
    Tracking
    Security
    Emergency

## Emergency Stop

Pressing the 'B' button on the joystick or triggering the emergency button in the web interface transitions the robot to the emergency state, where all other commands are ignored.
User Presence

The user_lost topic informs the state machine about the presence or absence of the user. If the user is lost, it can affect state transitions.
System Check

Pressing the D-pad left button triggers a request to print the last system check report.
Joystick Controls

    Left Stick (LS_X): Steering
    Right Trigger (RT): Move forward
    Left Trigger (LT): Move backward
    D-pad Bottom: Return to idle state

## Web Interface Controls

Web interface commands can be used for transitioning between states and controlling the robot.
