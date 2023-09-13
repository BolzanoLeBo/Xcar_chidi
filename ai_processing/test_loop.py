import asyncio
import websockets.client
from img_converter import *
import time

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
