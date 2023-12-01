import cv2
import numpy as np
from math import *



def detect_human(frame, net, layer_names, confidence_threshold=0.5):
	height, width = frame.shape[:2]

	# Create a blob from the frame and perform a forward pass
	blob = cv2.dnn.blobFromImage(frame, 1/255.0, (480, 480), swapRB=True, crop=False)
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
		if confidences[i] > max_confidence : 
			best_rect = (x,y,w,h)
			max_confidence = confidences[i]

	xmax, ymax, wmax, hmax = best_rect	
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
	yolo_weights = "../yolo/yolov3-tiny.weights"
	yolo_config = "../yolo/yolov3-tiny.cfg"
	yolo_classes = "../yolo/coco.names"

	height, width = frame.shape[:2]

	net	 = cv2.dnn.readNet(yolo_weights, yolo_config)
	layer_names = net.getUnconnectedOutLayersNames()
	target = ""

	# Detect humans in the current frame
	(rect, person_detected) = detect_human(frame, net, layer_names)
	
	#take the angle in the frame
	if person_detected :
		return (person_detected, get_angle(rect, width, radians(camera_angle), lidar_rotation, lidar_translation))
	else : 
		return (person_detected, (inf, inf))