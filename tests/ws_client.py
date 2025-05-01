import asyncio
import websockets
import sys
import binascii

async def request_random_bytes(uri, num_bytes):
    """
    Connect to the ESP32 WebSocket server and request random bytes.
    
    Args:
        uri (str): The WebSocket URI (e.g., ws://esp32-hrng.local/api/v1/esp_fill_random)
        num_bytes (int): Number of random bytes to request (1-16384)
    """
    try:
        print(f"Connecting to {uri}...")
        async with websockets.connect(uri) as websocket:
            print("Connected! Requesting random bytes...")
            
            await websocket.send(str(num_bytes))
            print(f"Sent request for {num_bytes} bytes")
            
            response = await websocket.recv()
            
            if isinstance(response, str):
                print(f"Received text response: {response}")
            else:
                print(f"Received {len(response)} random bytes:")
                print(f"Hex representation: {binascii.hexlify(response).decode()}")
                
                if len(response) > 20:
                    print(f"First 10 bytes: {binascii.hexlify(response[:10]).decode()}")
                    print(f"Last 10 bytes: {binascii.hexlify(response[-10:]).decode()}")
                
    except Exception as e:
        print(f"Error: {e}")

async def interactive_mode(uri):
    """
    Run an interactive session where the user can repeatedly request random bytes.
    """
    while True:
        try:
            num_bytes = input("\nEnter number of random bytes to request (1-16384, or 'q' to quit): ")
            
            if num_bytes.lower() == 'q':
                print("Exiting...")
                break
                
            try:
                num_bytes = int(num_bytes)
                if num_bytes < 1 or num_bytes > 16384:
                    print("Please enter a number between 1 and 16384")
                    continue
            except ValueError:
                print("Please enter a valid number")
                continue
                
            await request_random_bytes(uri, num_bytes)
            
        except KeyboardInterrupt:
            print("\nExiting...")
            break

def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <websocket_uri> [num_bytes]")
        print("Example: python ws_client.py ws://esp32-hrng.local/api/v1/esp_fill_random 10")
        print("If num_bytes is not provided, interactive mode will be used.")
        return
    
    uri = sys.argv[1]
    
    if len(sys.argv) >= 3:
        try:
            num_bytes = int(sys.argv[2])
            if num_bytes < 1 or num_bytes > 16384:
                print("Please specify a number between 1 and 16384")
                return
        except ValueError:
            print("Please specify a valid number")
            return
            
        asyncio.run(request_random_bytes(uri, num_bytes))
    else:
        asyncio.run(interactive_mode(uri))

if __name__ == "__main__":
    main()
