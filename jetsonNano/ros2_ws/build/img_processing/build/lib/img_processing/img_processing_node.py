import rclpy
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge
import cv2

def image_callback(msg):
    bridge = CvBridge()
    cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

    # Your image processing or display logic here
    #cv2.imshow("Received Image", cv_image)
    cv2.imwrite("img/img.png", cv_image)

def main():
    rclpy.init()

    node = rclpy.create_node('image_subscriber_node')
    subscription = node.create_subscription(
        Image, 'image_raw', image_callback, 10)
    # Adjust the queue size and topic according to your needs

    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()
