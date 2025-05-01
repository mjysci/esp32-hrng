# ESP32 Hardware Random Number Generator API Server

A high-performance WebSocket server that provides cryptographically secure random numbers using ESP32's hardware RNG and CSPRNG capabilities. Ideal for cryptographic applications, scientific simulations, and secure random number generation.

## Features

- WebSocket server
- Multiple random number generation endpoints:
  - Hardware RNG (`/api/v1/random`) - HTTP/1.1
  - Hardware CSPRNG (`/api/v1/csprng`) - HTTP/1.1
  - Configurable-length random bytes (`/api/v1/esp_fill_random`) - WebSocket
  - Configurable-length CSPRNG (`/api/v1/csprng_fill_random`) - WebSocket
- LED heartbeat indicator for RNG operations (limited to `random` and `csprng`)
- mDNS support

## Requirements

- ESP-IDF v4.1 or later
- espressif/mdns library (v1.8.2 or later)
- Python 3.7+ (for testing)

## Building

1. Set up ESP-IDF development environment

2. Clone this repository

3. Configure WiFi and other settings:

    ```sh
    idf.py menuconfig
    # Navigate to "ESP32 HRNG Configuration" and set your WiFi credentials
    # Navigate to "HTTP Server" and enable "WebSocket server support"
    ```

4. Build, flash, and monitor:

    ```sh
    idf.py build flash monitor
    ```

## API Endpoints

### GET /api/v1/random

Returns a single 32-bit random number using ESP32's hardware RNG.

Example using curl:

```sh
curl http://esp32-hrng.local/api/v1/random
```

Browser: <http://esp32-hrng.local/api/v1/random>

Response:

```json
{
    "random": 1234567890
}
```

### GET /api/v1/csprng

Returns a single 32-bit random number using the hardware CSPRNG.

Response:

```json
{
    "random": 1234567890
}
```

### WS /api/v1/esp_fill_random

Returns random bytes of specified length using ESP32's hardware RNG.

WebSocket connection example:

```sh
python tests/ws_client.py ws://esp32-hrng.local/api/v1/esp_fill_random
```

### WS /api/v1/csprng_fill_random

Returns random bytes of specified length using the hardware CSPRNG.

## Testing

A Python benchmark script is included in esp32_random_stream.py that demonstrates streaming random data from the device.

To run the benchmark:

```sh
sudo apt install dieharder
pip install websockets
python tests/benchmarks/esp32_random_stream.py --size 1G > rng.bin
dieharder -a -g 201 -f rng.bin
```

Here's the result for [csprng](tests/benchmarks/README.md) and [esp_random](tests/benchmarks/esp_random_1g.md). It's recommended to use csprng for better quality random numbers.

## Troubleshooting

### Common Issues

1. Connection Refused
   - Verify ESP32 IP address (IP has better compatibility and is more stable than mDNS hostname.)
   - Check WiFi connection status
   - Ensure port 80 is not blocked

2. Low Throughput
   - Reduce physical distance to device
   - Check WiFi signal strength
   - Verify client's network capacity

### Debug Logging

Enable detailed logging in menuconfig:

```sh
idf.py menuconfig
# Component config → ESP32 HRNG → Debug level (set to 3)
```

## Configuration

Key configuration options in `menuconfig`:

- `CONFIG_LED_GPIO`: GPIO pin for heartbeat LED (default: 2)
- `CONFIG_DEBUG`: Debug log level (0-3)
  
## Security Considerations

- Random data is generated using hardware TRNG/CSPRNG
- Implementation follows ESP32 security best practices
- Rate limiting is applied to prevent DoS

## License

This project is licensed under the LGPL-2.1 License. See the LICENSE file for more information.

## Contributing

We welcome suggestions or bug reports! To submit a pull request:

1. Check the Issues tab; if there’s no relevant issue, feel free to create one.

2. Submit your PR and link it to a related issue.
