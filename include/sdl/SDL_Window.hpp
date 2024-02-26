
#ifndef __HEADER_SDL_WINDOW__
#define __HEADER_SDL_WINDOW__

#include <string>
#include <SDL2/SDL.h>

class Window {

public:
	Window(const std::string n, const uint32_t w, const uint32_t h, const bool r);
	~Window();
	uint32_t init();

private:
	std::string name;
	uint32_t width;
	uint32_t height;
	bool resizable;
	SDL_Window* window;

};

#endif // __HEADER_SDL_WINDOW__

