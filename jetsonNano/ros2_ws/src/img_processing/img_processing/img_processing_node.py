import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo

from cv_bridge import CvBridge
import cv2

class ImgProcessing(Node):
    def __init__(self):
        super().__init__('img_processing')
        self.subscriber_ = self.create_subscription(Image, 'image_raw', self.image_callback)
    

    def image_callback(msg):
        self.get_logger().info("img callback")
        bridge = CvBridge()
        
        cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

        # Your image processing or display logic here
        #cv2.imshow("Received Image", cv_image)
        cv2.imwrite("img/img.png", cv_image)

    def run(self):
        # Main loop of the node
        self.get_logger().info("Run img processing")
        while rclpy.ok():
            # Your node's main functionality goes here
            rclpy.spin_once(self, timeout_sec=0.1)

        # Clean up when the node is shut down
        self.destroy_node()
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)

    img_processing = ImgProcessing()
    img_processing.run()

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    img_processing.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
