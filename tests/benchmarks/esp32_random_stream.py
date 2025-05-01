#!/usr/bin/env python3
import sys
import asyncio
import websockets
import time
from typing import Optional
import argparse

def parse_size(size_str: str) -> int:
    """Parse size string with K/M/G suffix into bytes"""
    units = {'K': 1024, 'M': 1024*1024, 'G': 1024*1024*1024}
    size_str = size_str.upper()
    if size_str[-1] in units:
        return int(float(size_str[:-1]) * units[size_str[-1]])
    return int(size_str)

async def get_random_bytes(websocket, chunk_size=1024) -> Optional[bytes]:
    """Get random bytes from ESP32 API via WebSocket"""
    try:
        await websocket.send(f"len={chunk_size}")
        random_bytes = await websocket.recv()
        if len(random_bytes) != chunk_size:
            print(f"Error: Got {len(random_bytes)} bytes, expected {chunk_size}", file=sys.stderr)
            return None
        return random_bytes
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        return None

async def stream_random_data(esp32_ip, total_bytes):
    """Stream random bytes to stdout using WebSocket"""
    uri = f"ws://{esp32_ip}/api/v1/esp_fill_random"
    bytes_remaining = total_bytes
    chunk_size = min(16384, total_bytes)
    request_count = 0
    consecutive_failures = 0
    MAX_RETRIES = 10
    start_time = time.time()

    async with websockets.connect(uri) as websocket:
        while bytes_remaining > 0:
            try:
                request_count += 1
                if request_count % 100 == 0:
                    elapsed = time.time() - start_time
                    mb_processed = (total_bytes - bytes_remaining) / (1024 * 1024)
                    print(f"Progress: {mb_processed:.2f}MB, Requests: {request_count}, Time: {elapsed:.1f}s", 
                          file=sys.stderr)

                random_bytes = await get_random_bytes(websocket, chunk_size)
                if random_bytes:
                    sys.stdout.buffer.write(random_bytes)
                    bytes_remaining -= len(random_bytes)
                    consecutive_failures = 0  # Reset on success
                else:
                    raise websockets.exceptions.WebSocketException("Failed to get random bytes")

            except websockets.exceptions.WebSocketException as e:
                consecutive_failures += 1
                print(f"WebSocket error: {e}. Attempt {consecutive_failures}/{MAX_RETRIES}", file=sys.stderr)
                
                if consecutive_failures >= MAX_RETRIES:
                    print(f"Error: Maximum retries ({MAX_RETRIES}) reached. Stopping application.", file=sys.stderr)
                    sys.exit(1)
                    
                await asyncio.sleep(1)  # Wait before retrying
                continue

        total_time = time.time() - start_time
        throughput = (total_bytes / 1024) / total_time
        print(f"\nTest completed. Throughput: {throughput:.2f} KB/s", file=sys.stderr)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Stream random data from ESP32')
    parser.add_argument('--size', default='4M', help='Test size (bytes, or with K/M/G suffix)')
    parser.add_argument('--ip', default='esp32-hrng.local', help='ESP32 IP address')
    args = parser.parse_args()
    
    total_bytes = parse_size(args.size)
    asyncio.run(stream_random_data(args.ip, total_bytes))