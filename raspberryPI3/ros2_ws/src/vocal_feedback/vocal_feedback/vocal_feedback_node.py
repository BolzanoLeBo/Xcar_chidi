import rclpy
from rclpy.node import Node

from std_msgs.msg import String # msg that contain 'topic'


class VocalFeedbackNode(Node):

    def __init__(self):
        super().__init__('vocal_feedback_node')
        self.subscription = self.create_subscription(String,'topic',self.listener_callback,10) #change 'topic' to the corespond topic in state machine 
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)


def main(args=None):
    rclpy.init(args=args)

    vocal_feedback_node = VocalFeedbackNode()

    rclpy.spin(vocal_feedback_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    vocal_feedback_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()