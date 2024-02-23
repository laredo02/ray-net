
CC:=g++
OPT:=-Wall -Wextra -pedantic -O2 -g

# OBJS:=main.o SDL_Window.o Ray.o
# HEADRS:=include/math/XYZ.hpp include/ray/RGB_Image.hpp include/sdl/SDL_Window.hpp

run: ray-net
	./ray-net

clean:
	rm -rf build

ray-net: main.o Ray.o SDL_Window.o Splash.o
	$(CC) $(OPT) build/Splash.o build/Ray.o build/SDL_Window.o build/main.o -o ray-net

build_dir:
	mkdir -p build

main.o: src/main.cpp build_dir
	$(CC) -c src/main.cpp -o build/main.o

Ray.o: include/ray/Ray.cpp include/ray/Ray.hpp build_dir
	$(CC) -c include/ray/Ray.cpp -o build/Ray.o

SDL_Window.o: include/sdl/SDL_Window.cpp include/sdl/SDL_Window.hpp build_dir
	$(CC) -c include/sdl/SDL_Window.cpp -o build/SDL_Window.o

Splash.o: include/misc/Splash.cpp include/misc/Splash.hpp build_dir
	$(CC) -c include/misc/Splash.cpp -o build/Splash.o

