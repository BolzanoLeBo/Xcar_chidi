import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy

import cv2
import numpy as np
from math import *

from interfaces.msg import TrackingPosAngle


from cv_bridge import CvBridge
import cv2



def detect_human(frame, net, layer_names, confidence_threshold=0.5):
	height, width = frame.shape[:2]

	# Create a blob from the frame and perform a forward pass
	blob = cv2.dnn.blobFromImage(frame, 1/255.0, (416, 416), swapRB=True, crop=False)
	net.setInput(blob)
	outputs = net.forward(layer_names)

	boxes = []
	confidences = []
	class_ids = []

	for output in outputs:
		for detection in output:
			scores = detection[5:]
			class_id = np.argmax(scores)
			confidence = scores[class_id]

			if confidence > confidence_threshold and class_id == 0:  # Class 0 corresponds to 'person' in the COCO dataset
				center_x, center_y = int(detection[0] * width), int(detection[1] * height)
				w, h = int(detection[2] * width), int(detection[3] * height)
				x, y = int(center_x - w / 2), int(center_y - h / 2)

				boxes.append([x, y, w, h])
				confidences.append(float(confidence))
				class_ids.append(class_id)

	# Apply non-maximum suppression to eliminate redundant overlapping boxes
	indices = cv2.dnn.NMSBoxes(boxes, confidences, confidence_threshold, 0.3)
	best_rect = (0,0,0,0)
	max_confidence = 0
	for i in indices:
		#i = i[0]
		x, y, w, h = boxes[i]
		cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
		cv2.putText(frame, 'Person', (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
		if confidences[i] > max_confidence : 
			best_rect = (x,y,w,h)
			max_confidence = confidences[i]

	xmax, ymax, wmax, hmax = best_rect
	cv2.rectangle(frame, (xmax, ymax), (xmax+ wmax, ymax + hmax), (255, 0, 0), 2)		
	return (frame, best_rect, len(indices)>0)

def vector_rotation(v, theta): 
	x = v[0]
	y = v[1]
	return [x*cos(theta)+ y*sin(theta), -x*sin(theta)+y*cos(theta)]

def translation(v1,v2) : 
	return [v1[0] + v2[0], v1[1] + v2[1]]

def get_angle(rect, sc, a, phi, d) :
	#with :
	#a the angle between the middle of the screen and the left side in the camera basis 
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

	return (theta1, theta2)

def get_tracking_angle(frame, camera_angle, lidar_rotation, lidar_translation) : 
	# Load YOLOv3 model
	yolo_weights = "/root/Xcar_chidi/jetsonNano/ros2_ws/src/img_processing/img_processing/yolo/yolov3-tiny.weights"
	yolo_config = "/root/Xcar_chidi/jetsonNano/ros2_ws/src/img_processing/img_processing/yolo/yolov3-tiny.cfg"
	yolo_classes = "/root/Xcar_chidi/jetsonNano/ros2_ws/src/img_processing/img_processing/yolo/coco.names"

	height, width = frame.shape[:2]
	center_x, center_y = frame.shape[1] // 2, frame.shape[0] // 2
	cropped_frame = cv2.getRectSubPix(frame, (height, height), (center_x, center_y))
	net	 = cv2.dnn.readNet(yolo_weights, yolo_config)
	layer_names = net.getUnconnectedOutLayersNames()
	target = ""
	# Detect humans in the current frame
	(new_frame, rect, person_detected) = detect_human(cropped_frame, net, layer_names)
	cv2.imwrite("/root/Xcar_chidi/img.png", new_frame)
	#take the angle in the frame
	if person_detected :
		#we use height because the frame is a square
		return (person_detected, get_angle(rect, height, radians(camera_angle), radians(lidar_rotation), lidar_translation))
	else : 
		return (person_detected, (inf, inf))

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
		self.cv_image = []
		self.timer = self.create_timer(1, self.img_ai) #1 second


	#here we define how to update the angle value of the tracking


	def image_callback(self,msg):
		bridge = CvBridge()
		self.cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

		#self.get_logger().info("img_h : {}".format(rect[0]))
			

		# Your image processing or display logic here
		#cv2.imshow("Received Image", cv_image)
		


	def img_ai(self) : 
		if self.cv_image != [] :
			tracking = TrackingPosAngle()
			(human_detected, (a_min, a_max)) = get_tracking_angle(self.cv_image, 35, -90, [0,0])
			tracking.min_angle = a_min
			tracking.max_angle = a_max
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
