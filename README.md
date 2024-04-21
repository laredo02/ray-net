
# Ray-Net: Ray Tracing with AI

## Description

Ray-Net is an AI-powered ray tracing solution designed to generate photorealistic images. This project combines ray tracing techniques with deep learning algorithms to optimize performance and visual quality across various platforms.

## Features

- **Photorealistic Rendering**: Generates high-quality images with realistic lighting effects.
- **AI Optimization**: Significant improvement in rendering speed thanks to AI.
- **Multiplatform**: Compatible with various platforms and devices.

## Technologies Used

- **Languages:** C++
- **Libraries:** SDL
- **Tools:** Git, Make

## Prerequisites

- SDL
- Make
- g++

## Compile from Source Code

1. Install dependencies

```bash
sudo apt install git gcc g++ make libsdl2-2.0-0 libsdl2-dev
```
2. Clone el repositorio:

```bash
git clone https://github.com/laredo02/ray-net.git
```

3. Once the dependencies are installed, compile the code using the command:

```bash
g++ -O3 -Ofast -march=native -flto -funroll-loops -finline-functions -fomit-frame-pointer -ffast-math -I include includ
e/*.cpp main.cpp -lSDL2 -o ray-net
```

## Usage

To start the rendering program, execute:

```bash
./ray-net
```
<hr>

# Ray-Net: Ray Tracing con IA

## Descripción

Ray-Net es una solución de ray tracing potenciada por inteligencia artificial, diseñada para generar imágenes fotorrealistas. Este proyecto combina técnicas de ray tracing con algoritmos de Deep Learning para optimizar el rendimiento y la calidad visual en diversas plataformas.

## Características

- **Renderizado Fotorrealista**: Genera imágenes de alta calidad con efectos de iluminación realistas.
- **Optimización IA**: Mejora significativa en la velocidad de renderizado gracias a la IA.
- **Multiplataforma**: Compatible con diversas plataformas y dispositivos.

## Tecnologías Utilizadas

- **Lenguajes:** C++
- **Librerías:** SDL
- **Herramientas:** Git, Make

## Requisitos Previos

- SDL
- Make
- g++

## Compilar a partir del código fuente

1. Instalar dependencias

```bash
sudo apt install git gcc g++ make libsdl2-2.0-0 libsdl2-dev
```

2. Clone el repositorio:

```bash
git clone https://github.com/laredo02/ray-net.git
```

3. Una vez instaladas las dependencias toca compilar el código mediante el comando:

```bash
g++ -O3 -Ofast -march=native -flto -funroll-loops -finline-functions -fomit-frame-pointer -ffast-math -I include includ
e/*.cpp main.cpp -lSDL2 -o ray-net
```

## Uso

Para iniciar el programa de renderizado, ejecute:

```bash
./ray-net
```
