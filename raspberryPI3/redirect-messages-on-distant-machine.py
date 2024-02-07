import asyncio
import websockets
import json


connected_clients = {}

async def send_message_to_clients(message):
    for client in connected_clients.values():
        await client.send(message)
        print(message)

async def handle_client(websocket, path):
    global connected_clients

    # Check the number of connected clients
    if len(connected_clients) >= 2:
        topic = '/some_topic'
        message = {"action": "redirect"}
        await websocket.send(json.dumps({"op": "publish", "topic": topic, "msg": message}))
        print("Trop de clients connectés. Fermeture de la connexion.")
        await websocket.close()
        return

    # Add the client to the list of connected clients
    connected_clients[websocket.remote_address] = websocket
    print(f"Client connecté: {websocket.remote_address}")

    try:
        # Check the number of connected clients again
        if len(connected_clients) == 1:
            # If there is only one client, send "1" to that client
            await websocket.send("1")
            print("1")
        elif len(connected_clients) == 2:
            # If there are two clients, send "2" to both clients
            await send_message_to_clients("2")

        # Wait for messages from the client
        async for message in websocket:
            print(f"Message reçu de {websocket.remote_address}: {message}")

            # Send the message to the other connected client
            other_client = next((client for addr, client in connected_clients.items() if addr != websocket.remote_address), None)
            if other_client:
                print(f"Transmission du message à {other_client.remote_address}")
                await other_client.send(message)
            else:
                print("Aucun autre client connecté pour transmettre le message.")
    finally:
        # Remove the client from the list when it disconnects
        del connected_clients[websocket.remote_address]
        print(f"Client déconnecté: {websocket.remote_address}")

        # Check if there is only one client remaining after disconnection
        if len(connected_clients) == 1:
            remaining_client = next(iter(connected_clients.values()))
            await remaining_client.send("1")
            print("1 envoyé au dernier client restant.")
        elif len(connected_clients) == 2:
            # If there are two clients, send "2" to both clients
            await send_message_to_clients("2")

async def main():
    server = await websockets.serve(handle_client, "0.0.0.0", 9080)

    print(f"Serveur WebSocket en attente sur {server.sockets[0].getsockname()}")

    # Keep the server running indefinitely
    await server.wait_closed()

if __name__ == "__main__":
    asyncio.run(main())
