import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy

from interfaces.msg import TrackingPosAngle

from cv_bridge import CvBridge
import cv2

class ImgProcessingNode(Node):
	def __init__(self):
		super().__init__('img_processing_node')
		qos_profile = QoSProfile(
			reliability=QoSReliabilityPolicy.RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT,
			history=QoSHistoryPolicy.RMW_QOS_POLICY_HISTORY_KEEP_LAST,
			depth=1
		)
		self.subscriber_ = self.create_subscription(Image, 'image_raw', self.image_callback,qos_profile = qos_profile)
		self.tracking_pos_angle_publisher_ = self.create_publisher(TrackingPosAngle,'tracking_pos_angle', 10)
		



	#here we define how to update the angle value of the tracking


	def image_callback(self,msg):
		bridge = CvBridge()
		tracking = TrackingPosAngle()
		tracking.min_angle = 1.0
		tracking.max_angle = 2.0
		
		cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

		# Your image processing or display logic here
		#cv2.imshow("Received Image", cv_image)
		#cv2.imwrite("/img.png", cv_image)

		# Publish the msg for angle
		self.tracking_pos_angle_publisher_.publish(tracking)

def main(args=None):
	rclpy.init(args=args)
	img_processing_node = ImgProcessingNode()
	rclpy.spin(img_processing_node)
	img_processing_node.destroy_node()
	rclpy.shutdown()


if __name__ == '__main__':
	main()
