# RNG Benchmark Report

## Generate 1 GB binary sample

```sh
python tests/benchmarks/esp32_random_stream.py --size 1G > rng.bin
```

## Dieharder

```sh
dieharder -a -g 201 -f rng.bin
```

## Results

[ESP32-WROOM-32UE](ESP32-WROOM-32UE.md)
[ESP32-C3](ESP32-C3.md)
