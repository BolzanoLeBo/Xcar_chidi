import asyncio
import websockets

async def forward_messages(local_port, remote_host, remote_port):
    local_uri = f"ws://localhost:{local_port}"
    remote_uri = f"ws://{remote_host}:{remote_port}"

    async with websockets.connect(local_uri) as local_ws, websockets.connect(remote_uri) as remote_ws:
        print(f"Connected to local websocket on port {local_port}")
        print(f"Connected to remote websocket on {remote_host}:{remote_port}")

        local_connection_open = True

        # Définir une fonction pour transférer les messages du local vers le distant
        async def forward_local_to_remote():
            nonlocal local_ws

            while True:
                try:
                    message = await local_ws.recv()
                    await remote_ws.send(message)
                except websockets.exceptions.ConnectionClosed as e:
                    if e.code == 1000:  # OK (normal closure)
                        break
                    else:
                        raise

        # Définir une fonction pour transférer les messages du distant vers le local
        async def forward_remote_to_local():
            nonlocal local_ws, local_connection_open

            while True:
                message = await remote_ws.recv()

                # Gérer la réception des messages "1" et "2" depuis le distant
                if message == "1" and local_connection_open:
                    local_connection_open = False
                    await local_ws.close()
                    local_ws = None
                    print("Connexion locale fermée en réponse à '1'")
                elif message == "2" and not local_connection_open:
                    local_connection_open = True
                    local_ws = await websockets.connect(local_uri)
                    print("Connexion locale ouverte en réponse à '2'")
                    asyncio.create_task(forward_local_to_remote())  # Nouvelle instance de la tâche
                elif local_ws and message not in ("1", "2"):
                    await local_ws.send(message)

        # Lancer les deux tâches de transfert de messages en parallèle
        await asyncio.gather(forward_local_to_remote(), forward_remote_to_local())

if __name__ == "__main__":
    # Remplacez les valeurs suivantes par celles de votre configuration
    local_port = 9090  # Port local (ROSBridge)
    remote_host = "loic-ras.freeboxos.fr"
    remote_port = "80"

    asyncio.get_event_loop().run_until_complete(forward_messages(local_port, remote_host, remote_port))
