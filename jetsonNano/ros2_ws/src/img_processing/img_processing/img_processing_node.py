import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
import websockets.client
import asyncio
import cv2
import numpy as np
from math import *
import os
import base64

from interfaces.msg import UserLost
from interfaces.msg import TrackingPosAngle
from interfaces.msg import State
from interfaces.msg import InitButton
from interfaces.msg import TargetImage



from cv_bridge import CvBridge
import cv2
import json 

def img_to_bytes(img) : 
	_, buffer = cv2.imencode('.jpg', img)
	image_encoded = base64.b64encode(buffer).decode('utf-8')
	return image_encoded

def msg_to_info(msg) : 
	(info, data) = json.loads(msg)
	if data == "" : 
		rect = []
	else : 
		numbers_str = data.split(",")
		# Converting each substring to an integer
		rect = [int(num.strip()) for num in numbers_str]
	return (info, rect)


def info_to_msg(info, img) : 
	if info != "RESET" :
		bts = img_to_bytes(img)
	else : 
		bts = ""
	msg = (info, bts)
	json_message = json.dumps(msg)
	return json_message

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
		self.state_subscriber_ = self.create_subscription(State, 'state', self.state_callback, 10)
		self.init_button_subscriber_ = self.create_subscription(InitButton, 'init_button', self.init_button_callback, 10)

		self.tracking_pos_angle_publisher_ = self.create_publisher(TrackingPosAngle,'tracking_pos_angle', 10)
		self.user_lost_publisher_ = self.create_publisher(UserLost,'user_lost', 10)
		self.target_image_publisher_ = self.create_publisher(TargetImage,'target_image', 10)

		self.timer = self.create_timer(1, self.img_ai) 



		self.cv_image = []
		self.rectangle = []
		self.image_processed = False
		self.websocket_init = False
		self.state = 0
		self.lost_counter = 0
		self.init_target = False
		self.reset_ia = False
		self.init_button = False
		self.new_target = False

		

	def calcul_pos(self) : 
		#CALCUL POSTION 
		tracking = TrackingPosAngle()
		[x1,y1,x2,y2] = self.rectangle
		if self.rectangle != [0,0,0,0] : 
			height, width = self.cv_image.shape[:2]
			(a_min, a_max, a_cam) = get_angle([x1,y1, x2-x1, y2-y1], width, radians(55), radians(-90), [0,0])
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
		return (human_detected, tracking) 
	

				
	def state_callback(self,msg) : 
		self.state = msg.current_state

	def image_callback(self,msg):
		bridge = CvBridge()
		self.cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

	def init_button_callback(self, msg): 
		self.init_button = msg.button

	async def send_info(self, info):
		uri = "ws://localhost:9090"  # WebSocket server URI 
		
		async with websockets.client.connect(uri) as websocket:
			self.get_logger().info(f"send a {info} msg")
			img = self.cv_image
			msg = info_to_msg(info, img)
			await websocket.send(msg)
			
			if info != "RESET" : 
				response = await websocket.recv()
				(info_r, rect) = msg_to_info(response)
				self.get_logger().info(f"reiceive response {info_r}, {rect}")
				if info == "INIT" :  
					if info_r == "INIT" : 
						#the target is correctly initialized 
						self.new_target = True
						self.init_button = False
						self.init_target = True
						self.rectangle = rect

					elif info_r == "NOT_INIT" : 
						self.init_target = False 


					self.image_processed = True

				elif info == "IMG" :
					
					
					if info_r == "IMG_ACK" : 
						self.rectangle = rect
						
					elif info_r == "NOT_INIT" : 
						self.init_target = False
					
					self.image_processed = True
	


	def img_ai(self) : 
		lost_treshold = 2 
		lost_msg = UserLost()
		if self.new_target : 
			img_target = cv2.imread("target1.jpg")
			if not (img_target is None) :
				new_width = int(img_target.shape[1] * 0.5)
				new_height = int(img_target.shape[0] * 0.5)
				new_size = (new_width, new_height)
				# Resize the image
				img_target = cv2.resize(img_target, new_size, interpolation=cv2.INTER_AREA)

				target_msg = TargetImage() 
				target = img_to_bytes(img_target)
				target_msg.image = target
				self.target_image_publisher_.publish(target_msg)
				self.new_target = False
			else : 
				self.get_logger().info("Target image empty")

		if not self.reset_ia : 
			asyncio.run(self.send_info("RESET"))
			self.reset_ia = True
		#if we have an image comming from the camera 
		elif self.cv_image != [] :
			#We want to reinitialize the target 
			if self.init_button : 
				self.get_logger().info("Init button activated or init not resolved")
				asyncio.run(self.send_info("INIT"))

			#Otherwise we send an image
			else : 
				asyncio.run(self.send_info("IMG"))
			
			#wait the response and the processing 
			while not self.image_processed : 
				pass 
			
			#we take only rectangles where the target is initialized 
			if self.init_target : 
				human_detected, tracking = self.calcul_pos()
				#CHECK LOST COUNTER 
				if (True or self.state == 3 or self.state == 4) : 
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
