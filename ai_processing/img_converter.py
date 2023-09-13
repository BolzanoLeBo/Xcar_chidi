import cv2
import numpy as np

def img_to_bytes(img) : 
	_, bts = cv2.imencode('.jpg', img)
	bts = bts.tobytes()
	return bts

def bytes_to_img(data) : 
	buff = np.fromstring(data, np.uint8)
	buff = buff.reshape(1, -1)
	img = cv2.imdecode(buff, cv2.IMREAD_COLOR)
	return img