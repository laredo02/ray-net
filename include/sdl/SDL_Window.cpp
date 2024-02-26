
#include <iostream>

#include "SDL_Window.hpp"

/*
Window::Window(const std::string n, const uint32_t w, const uint32_t h, const bool r = true)
    : name{n}, width(w), height(h), resizable(r), window(nullptr)
{

}

Window::~Window()
{
    SDL_DestroyWindow(window); SDL_Quit();
}

uint32_t Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
		std::cerr << "Unable to init SDL" << std::endl;
		return -1;
	}
	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | ((resizable)? SDL_WINDOW_RESIZABLE: 0) | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
	if (window == nullptr) {
		std::cerr << "Unable to init SDL" << std::endl;
		return -1;
	}
	return 0;
}
*/

