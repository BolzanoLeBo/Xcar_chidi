import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
import websockets.client
import asyncio
import cv2
import numpy as np
from math import *

from interfaces.msg import UserLost
from interfaces.msg import TrackingPosAngle
from interfaces.msg import State


from cv_bridge import CvBridge
import cv2


def img_to_bytes(img) : 
	_, bts = cv2.imencode('.jpg', img)
	bts = bts.tobytes()
	return bts

def vector_rotation(v, theta): 
	x = v[0]
	y = v[1]
	return [x*cos(theta)+ y*sin(theta), -x*sin(theta)+y*cos(theta)]

def translation(v1,v2) : 
	return [v1[0] + v2[0], v1[1] + v2[1]]

def get_angle(rect, sc, a, phi, d) :
	#with :
	#a the angle between the right side of the screen and the left side in the camera basis 
	#sc the screen_width
	#phi the angle between the 0 degree of the lidar (right side of the car) and the 0 degree of the camera (front of the car) => ~ -pi/2
	#v the translation vector between the lidar and the camera for us v = (0, d)
	#coords of the left side of the screen in the camera basis  
	a_min =  [(sc/2)/tan(a/2), sc/2]
	#left side of the human, distance between the left side of the screen and the left side of the rectangle
	dh = rect[0]
	#width of the human
	w = rect[2]
	#coords in the camera basis of the human left and right
	'''if dh > sc/2 : 
		h2 = [a_min[0], a_min[1] - dh]
		h1 = [a_min[0], a_min[1] - dh - w]
	else : 
		h1 = [a_min[0], a_min[1] - dh]
		h2 = [a_min[0], a_min[1] - dh - w]	'''
	h1 = [a_min[0], a_min[1] - dh]
	h2 = [a_min[0], a_min[1] - dh - w]
	h_middle = [a_min[0], a_min[1] - dh - w/2]
	h_mid_unit = h_middle/np.linalg.norm(h_middle)
	if h_mid_unit[1] < 0 :
		theta_mid = -degrees(acos(np.dot(h_mid_unit, [1,0])))
	else : 
		theta_mid = degrees(acos(np.dot(h_mid_unit, [1,0])))
	#we have to find the angle between h1 and h2 in the lidar basis (rotation of lidar_angle and translation of lidar_distance)
	#rotate h1 and h2
	h1_rot = vector_rotation(h1, phi)
	h2_rot = vector_rotation(h2, phi)
	#put the translation vector into the rotated basis 
	d_rot = vector_rotation(d, phi)
	#translation into the new lidar location 
	h1_lid = translation(h1_rot, -np.array(d_rot))
	h2_lid = translation(h2_rot, -np.array(d_rot))

	#now we compute the angle between those two new points
	#compute the unit vectors
	h1_unit = h1_lid/np.linalg.norm(h1_lid)
	h2_unit = h2_lid/np.linalg.norm(h2_lid)
	if h1_unit[1] < 0 :
		theta1 = -degrees(acos(np.dot(h1_unit, [1,0])))
	else : 
		theta1 = degrees(acos(np.dot(h1_unit, [1,0])))
	if h2_unit[1] < 0 :
		theta2 = -degrees(acos(np.dot(h2_unit, [1,0])))
	else:
		theta2 = degrees(acos(np.dot(h2_unit, [1,0])))

	return (theta1, theta2, theta_mid)

class ImgProcessingNode(Node):
	
	def __init__(self):
		super().__init__('img_processing_node')
		# Run the test code
		qos_profile = QoSProfile(
			reliability=QoSReliabilityPolicy.RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT,
			history=QoSHistoryPolicy.RMW_QOS_POLICY_HISTORY_KEEP_LAST,
			depth=1
		)
		self.subscriber_ = self.create_subscription(Image, 'image_raw', self.image_callback,qos_profile = qos_profile)
		self.user_lost_publisher_ = self.create_publisher(UserLost,'user_lost', 10)
		self.state_subscriber_ = self.create_subscription(State, 'state', self.state_callback, 10)
		self.tracking_pos_angle_publisher_ = self.create_publisher(TrackingPosAngle,'tracking_pos_angle', 10)
		self.cv_image = []
		self.timer = self.create_timer(0.5, self.img_ai) 
		self.rectangle = []
		self.image_processed = False
		self.websocket_init = False
		self.state = 0
		self.lost_counter = 0


	#here we define how to update the angle value of the tracking
	async def send_message(self):
		uri = "ws://localhost:9090"  # WebSocket server URI 
		self.image_processed = False
		bts = img_to_bytes(self.cv_image)

		async with websockets.client.connect(uri) as websocket:
			await websocket.send(bts)

			# Wait for a response from the server
			response = await websocket.recv()
			#self.get_logger().info("resp : {} {} {}".format(response, type(response), response[0]))
			self.rectangle = list(response)
			# Removing brackets and splitting by comma
			numbers_str = response.strip("[]").split(",")

			# Converting each substring to an integer
			self.rectangle = [int(num.strip()) for num in numbers_str]
			#self.get_logger().info("rect : {}".format(self.rectangle))

			self.image_processed = True
				
	def state_callback(self,msg) : 
		self.state = msg.current_state


	def image_callback(self,msg):
		bridge = CvBridge()
		self.cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

		#self.get_logger().info("img_h : {}".format(rect[0]))
			

		# Your image processing or display logic here
		#cv2.imshow("Received Image", cv_image)
		


	def img_ai(self) : 
		lost_treshold = 2 
		lost_msg = UserLost()
		if self.cv_image != [] :
			asyncio.run(self.send_message())
			tracking = TrackingPosAngle()
			while not self.image_processed : 
				pass
			
			[x1,y1,x2,y2] = self.rectangle
			if self.rectangle != [0,0,0,0] : 
				height, width = self.cv_image.shape[:2]
				(a_min, a_max, a_cam) = get_angle([x1,y1, x2-x1, y2-y1], width, radians(55), radians(-90), [0,0])
				#self.get_logger().info("angle : {}".format(a_cam))
				if a_min >= a_max :
					tracking.min_angle = a_max
					tracking.max_angle = a_min
				else :
					tracking.min_angle = a_min
					tracking.max_angle = a_max
				tracking.cam_angle = float(round(a_cam))
				tracking.person_detected = True
				human_detected = True
			else : 
				tracking.person_detected = False 
				tracking.min_angle = float('inf') 
				tracking.max_angle = float('inf') 
				tracking.cam_angle = float('inf') 
				human_detected = False

			if (self.state == 3 or self.state == 4) : 
				if not human_detected :
					self.lost_counter = self.lost_counter + 1 
				else : 
					if self.lost_counter > lost_treshold : 
						lost_msg.lost = False
						self.user_lost_publisher_.publish(lost_msg)
					self.lost_counter = 0


				if self.lost_counter > lost_treshold : 
					lost_msg.lost = True
					self.user_lost_publisher_.publish(lost_msg)

			else : 
				self.lost_counter = 0 
			


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
