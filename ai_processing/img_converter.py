import cv2
import numpy as np
import json 
import base64

def img_to_bytes(img) : 
    _, buffer = cv2.imencode('.jpg', img)
    image_encoded = base64.b64encode(buffer).decode('utf-8')
    return image_encoded

def bytes_to_img(data) : 
    image_binary = base64.b64decode(data)
    image_np = np.frombuffer(image_binary, dtype=np.uint8)
    image = cv2.imdecode(image_np, cv2.IMREAD_COLOR)
    return image 

def info_to_msg(info, rect) :
    if len(rect) > 0 : 
         rect = f"{rect[0]},{rect[1]},{rect[2]},{rect[3]}"
    else : 
         rect = ""
    msg = (info, rect)
    json_message = json.dumps(msg)
    return json_message

def msg_to_info(msg) : 
	message_tuple = json.loads(msg)
	(info, data) = message_tuple
	img = bytes_to_img(data)
	return (info, img)
