import rclpy
from rclpy.node import Node

from interfaces.msg import Vocal

import os
import signal
import subprocess

current_process = None

def play_audio_mp3(file_path, file_name):
        global current_process
        if current_process:
            os.killpg(os.getpgid(current_process.pid), signal.SIGTERM)
            current_process = None
        audio_cmd = f"ffplay -v 0 -nodisp -autoexit {file_path}{file_name}"
        current_process = os.system(audio_cmd)

class VocalFeedbackNode(Node):

    def __init__(self):
        super().__init__('vocal_feedback_node')
        self.subscription = self.create_subscription(Vocal, 'vocal', self.listener_callback, 10)
        self.subscription  # prevent unused variable warning
        os.system("pacmd set-default-sink \"alsa_output.usb-Jieli_Technology_UACDemoV1.0_4150333236393504-00.analog-stereo\"")
        os.system("pacmd set-sink-volume \"alsa_output.usb-Jieli_Technology_UACDemoV1.0_4150333236393504-00.analog-stereo\" 55000")

    def listener_callback(self, msg):
        mp3_name = msg.vocal_feedback_message
        mp3_file = "~/arthur/Xcar_chidi/raspberryPI3/ros2_ws/src/audio/"
        play_audio_mp3(mp3_file, mp3_name)

def main(args=None):
    rclpy.init(args=args)
    vocal_feedback_node = VocalFeedbackNode()
    rclpy.spin(vocal_feedback_node)
    vocal_feedback_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
