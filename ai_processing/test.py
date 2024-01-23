import asyncio
import websockets.client
import time
import cv2 
import json 
import base64
import sys 


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
	bts = img_to_bytes(img)
	msg = (info, bts)
	json_message = json.dumps(msg)
	return json_message

async def send_message(info):
    cap = cv2.VideoCapture(0)
    ret, frame = cap.read()
    uri = "ws://localhost:9090"  # WebSocket server URI
    cv2.imwrite("frame.jpg", frame)
    print("save image")
    msg = info_to_msg(info, frame)

    async with websockets.client.connect(uri) as websocket:
        print(f"send image : {info}")
        await websocket.send(msg)
        print("wait ack")
        # Wait for a response from the server
        response = await websocket.recv()
        print(f"Received response: {msg_to_info(response)}")

# Run the test code
if len(sys.argv) > 1: 
    info = str(sys.argv[1]).upper() 
else : 
    info = "IMG" 
asyncio.run(send_message(info))
