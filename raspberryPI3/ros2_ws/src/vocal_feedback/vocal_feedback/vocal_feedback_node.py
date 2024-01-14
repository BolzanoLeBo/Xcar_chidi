import rclpy
from rclpy.node import Node

from interfaces.msg import Vocal

import os


class VocalFeedbackNode(Node):

    def play_audio_mp3(file_path, file_name):
    
        os.system(f"ffplay -v 0 -nodisp -autoexit {file_path}{file_name}") 

    def __init__(self):
        super().__init__('vocal_feedback_node')
        self.subscription = self.create_subscription(Vocal,'vocal',self.listener_callback,10) #change 'topic' to the corespond topic in state machine 
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        mp3_file = "~/arthur/Xcar_chidi/raspberryPI3/ros2_ws/src/audio/" #
        # si non fonctionnel 
        #mp3_file = os.path.expanduser("~/arthur/Xcar_chidi/raspberryPI3/ros2_ws/src/audio/")
        self.play_audio_mp3(mp3_file,mp3_name)


def main(args=None):
    rclpy.init(args=args)

    vocal_feedback_node = VocalFeedbackNode()
    rclpy.spin(vocal_feedback_node)
    vocal_feedback_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()