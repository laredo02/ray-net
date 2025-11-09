
## Description

Ray-Net is an AI-powered ray tracing solution designed to generate photorealistic images. This project combines ray tracing techniques with deep learning algorithms to optimize performance and visual quality across various platforms.

## Features

- **Photorealistic Rendering**: Generates images with realistic lighting effects.
- **AI Optimization**: Significant improvement in rendering speed thanks to AI.
- **Multiplatform**: Compatible with various platforms and devices.

## Compile from Source Code

1. Install dependencies

```bash
sudo apt install git gcc g++ make libsdl2-2.0-0 libsdl2-dev
```
2. Clone the repository:

```bash
git clone https://github.com/laredo02/ray-net.git
```

3. Once the dependencies are installed, compile the code using the command:

```bash
g++ -I include main.cpp include/*.cpp -lSDL2 -O3 -Ofast -ffast-math -funroll-loops -finline-functions -fomit-frame-pointer -flto -march=native -o ray-net
```

## Usage

```bash
./ray-net
```

<p align="center">
  <img src="https://github.com/laredo02/ray-net/blob/main/image.png">
</p>
