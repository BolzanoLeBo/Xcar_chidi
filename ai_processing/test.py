import asyncio
import websockets.client
from img_converter import *

async def send_message():
    cap = cv2.VideoCapture(0)
    ret, frame = cap.read()
    uri = "ws://localhost:9090"  # WebSocket server URI
    cv2.imwrite("frame.jpg", frame)
    print("save image")
    bts = img_to_bytes(frame)

    async with websockets.client.connect(uri) as websocket:
        print("send image")
        await websocket.send(bts)
        print("wait ack")
        # Wait for a response from the server
        response = await websocket.recv()
        print(f"Received response: {response}")

# Run the test code
asyncio.run(send_message())
