
CC:=g++
OPT:=-Wall -Wextra -pedantic -O2 -g

OBJS:=main.o RGB_Image.o SDL_Window.o
HEADRS:=include/math/XYZ.hpp include/ray/RGB_Image.hpp include/sdl/SDL_Window.hpp

ray-net: $(OBJS)
	$(CC) $(OPT) build/SDL_Window.o build/RGB_Image.o build/main.o -o ray-net


build_dir:
	mkdir -p build

main.o: src/main.cpp build_dir
	$(CC) -c src/main.cpp -o build/main.o

RGB_Image.o: include/ray/RGB_Image.cpp include/ray/RGB_Image.hpp build_dir
	$(CC) -c include/ray/RGB_Image.cpp -o build/RGB_Image.o

SDL_Window.o: include/sdl/SDL_Window.cpp include/sdl/SDL_Window.hpp build_dir
	$(CC) -c include/sdl/SDL_Window.cpp -o build/SDL_Window.o






