import cv2
import numpy as np
from ultralytics import YOLO
import asyncio
import websockets
from img_converter import *
import argparse
import torch  	#1.13.0a0+git7c98e70
model = YOLO('yolov8n.pt')
model.to('cuda')

def detect_human(frame):
	conf_treshold = 0.5
	results = model.predict(source=frame, classes=0, device=0)
	result = results[0]
	max_conf = 0
	max_rect = [0,0,0,0]
	#check all the result 
	for box in result.boxes:
		class_id = result.names[box.cls[0].item()]
		coords = box.xyxy[0].tolist()
		coords = [round(x) for x in coords]
		[x1,y1,x2,y2] = coords
		conf = round(box.conf[0].item(), 2)
		if conf > 0.5 : 
			cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
			cv2.putText(frame, "{} : {}".format(class_id, conf), (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

		if conf > max_conf :
			max_conf = conf
			max_rect = [x1,y1,x2,y2]
	
		
	cv2.rectangle(frame, (max_rect[0], max_rect[1]), (max_rect[2], max_rect[3]), (0, 0, 255), 2)
	return (frame, max_rect) 

async def handle_websocket(websocket, path):
	# This function will be called whenever a new WebSocket connection is established
	print(f"Client connected to {path}")

	try:
		while True:
			# Receive data from the client
			data = await websocket.recv()
			img = bytes_to_img(data)
			(new_img, rect) = detect_human(img)
			print(rect)
			await websocket.send(str(rect))
			cv2.imwrite("new_img.jpg", new_img)

	except websockets.exceptions.ConnectionClosed:
		print(f"Client disconnected from {path}")

# Set up the WebSocket server
start_server = websockets.serve(handle_websocket, "localhost", 9090)

# Start the event loop
async def main():
	await start_server
	print('cuda is'  + str(torch.cuda.is_available()))
	print("WebSocket server listening on port 9090...")
	await asyncio.Future()  # run forever

if __name__ == "__main__":
	loop = asyncio.get_event_loop()
	try:
		loop.run_until_complete(main())
	finally:
		loop.run_until_complete(loop.shutdown_asyncgens())
		loop.close()
