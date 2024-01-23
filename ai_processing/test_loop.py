import asyncio
import websockets.client
import time
import cv2 
import json 


def img_to_bytes(img) : 
	_, bts = cv2.imencode('.jpg', img)
	bts = bts.tobytes()
	return bts

def msg_to_info(msg) : 
	message_tuple = json.loads(msg)
	(info, data) = message_tuple
	# Removing brackets and splitting by comma
	numbers_str = data.strip("[]").split(",")
	# Converting each substring to an integer
	rectangle = [int(num.strip()) for num in numbers_str]
	return (info, data)

def info_to_msg(info, img) : 
	bts = img_to_bytes(img)
	msg = (info, bts)
	json_message = json.dumps(msg)
	return json_message



async def send_message(frame):

    uri = "ws://localhost:9090"  # WebSocket server URI
    bts = img_to_bytes(frame)

    async with websockets.client.connect(uri) as websocket:
        print("send image")
        await websocket.send(bts)
        print("wait ack")
        # Wait for a response from the server
        response = await websocket.recv()
        print(f"Received response: {response}")

# Run the test code
cap = cv2.VideoCapture(0)
ret = True
while ret : 
    ret, frame = cap.read()
    asyncio.run(send_message(frame))
    time.sleep(0.1)
