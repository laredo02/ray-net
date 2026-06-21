
## Description

A CPU path tracer written in C++ (spheres, triangles, basic materials, SDL2 for display), built as part of a bachelor's thesis. It renders at low resolution and uses a separate FSRGAN model (in [fsrgan/](fsrgan/)) to upscale the output, trading render time for image resolution.

## Features

- **Path-traced rendering**: Spheres and triangle meshes with diffuse/reflective/refractive materials, soft shadows, and depth of field.
- **SDL2 live preview**: Renders to a window while tracing.
- **Super-resolution upscaling**: A separately trained FSRGAN model (TensorFlow, see [fsrgan/](fsrgan/)) upscales low-resolution renders.

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

The renderer opens an SDL window and updates continuously while you move the camera.

### Controls

| Key            | Action                                   |
| -------------- | ---------------------------------------- |
| `W` / `S`      | Move forward / backward                  |
| `A` / `D`      | Move left / right                        |
| `Space` / `Shift` | Move up / down                        |
| `I` / `K`      | Pitch up / down                          |
| `J` / `L`      | Yaw left / right                         |
| `U` / `O`      | Roll left / right                        |
| `G`            | Save the current frame (PPM) to `fsrgan/source_images/` |
| `Q` / `Esc`    | Quit                                     |

<p align="center">
  <img src="https://github.com/laredo02/ray-net/blob/main/image.png">
</p>
