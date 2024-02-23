
CC:=g++
OPT:=-Wall -Wextra -pedantic -O2 -g

OBJS:=main.o SDL_Window.o
HEADRS:=include/math/XYZ.hpp include/ray/RGB_Image.hpp include/sdl/SDL_Window.hpp

run: ray-net
	./ray-net

clean:
	rm -rf build

ray-net: $(OBJS)
	$(CC) $(OPT) build/SDL_Window.o build/main.o -o ray-net

build_dir:
	mkdir -p build

main.o: src/main.cpp build_dir
	$(CC) -c src/main.cpp -o build/main.o

SDL_Window.o: include/sdl/SDL_Window.cpp include/sdl/SDL_Window.hpp build_dir
	$(CC) -c include/sdl/SDL_Window.cpp -o build/SDL_Window.o





