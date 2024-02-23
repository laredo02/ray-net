
# Ray-Net: Ray Tracing con IA

## Descripción
Ray-Net es una innovadora solución de ray tracing potenciada por inteligencia artificial, \
diseñada para generar imágenes fotorrealistas. Este proyecto combina técnicas avanzadas de ray tracing con algoritmos de IA para optimizar el rendimiento y la calidad visual en diversas plataformas.

## Características
- **Renderizado Fotorrealista**: Genera imágenes de alta calidad con efectos de iluminación realistas.
- **Optimización IA**: Mejora significativa en la velocidad de renderizado gracias a la IA.
- **Multiplataforma**: Compatible con diversas plataformas y dispositivos.

## Tecnologías Utilizadas
- Lenguajes: C++, Python
- Librerías: PyTorch, CUDA, SDL
- Herramientas: Git

## Requisitos Previos
- GPU compatible con CUDA

## Compilar a partir del código fuente
1. Clone el repositorio:
```bash
git clone https://github.com/tu-usuario/ray-net.git`
```
2. Instalar dependencias
```bash
sudo apt install libsdl2-2.0-0 libsdl2-dev # libreria SDL
sudo apt install gcc make # Compiler dependencies
```
3. Una vez instaladas las dependencias toca compilar el código mediante el comando
```bash
make all
```
4. Si todo ha salido según lo esperado debería haber aparecido un fichero con el nombre 'ray-net'.
Para ejecutarlo:
```bash
./ray-net
```

## Uso
Para iniciar el renderizado, ejecute:
```bash
./ray-net
```

