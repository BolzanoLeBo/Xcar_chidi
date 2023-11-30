import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
from TrackingPosAngle.msg import TrackAngle

from cv_bridge import CvBridge
import cv2

class ImgProcessing(Node):
    def __init__(self):
        super().__init__('img_processing_node')
        qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT,
            history=QoSHistoryPolicy.RMW_QOS_POLICY_HISTORY_KEEP_LAST,
            depth=1
        )
        self.subscriber_ = self.create_subscription(Image, 'image_raw', self.image_callback,qos_profile = qos_profile)
        self.publisher_ = self.create_publisher(TrackAngle,'tracking_angles',qos_profile = qos_profile)

        #init value of angle
        self.TrackAngle.min_angle = 0
        self.TrackAngle.max_angle = 0




    #here we define how to update the angle value of the tracking


    def image_callback(self,msg):
        self.get_logger().info("img callback")
        bridge = CvBridge()
        
        cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

        # Your image processing or display logic here
        #cv2.imshow("Received Image", cv_image)
        cv2.imwrite("/img.png", cv_image)



        #update both value by 1/ CHANGE LATER
        self.TrackAngle.min_angle += 1
        self.TrackAngle.max_angle += 1

        # Publish the msg for angle
        self.publisher_.publish(self.TrackAngle)

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

    img_processing_node = ImgProcessing()
    img_processing_node.run()

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    img_processing_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
