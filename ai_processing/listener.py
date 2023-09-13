import cv2
import numpy as np
import asyncio
import websockets
from img_converter import *
from stalker import *

init = False
(device, model, model2, preprocess) = init_models()
track_id = 1

async def handle_websocket(websocket, path):
	global init
	global device, model, model2, preprocess
	global track_id
	# This function will be called whenever a new WebSocket connection is established
	print(f"Client connected to {path}")

	try:
		while True:
			# Receive data from the client
			data = await websocket.recv()
			img = bytes_to_img(data)
			if not init : 
				print("initialize the target")
				init_target(img, model)
				init = True 
			(new_img, rect, track_id) = detect_human(img, device, model, model2, preprocess, track_id)
			print(rect)
			await websocket.send(str(rect))
			cv2.imwrite("results.jpg", new_img)

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
