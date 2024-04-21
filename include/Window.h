
#pragma once


#include <map>

#include <SDL2/SDL.h>

#include "Renderer.h"



/*
 * @class Window
 * @brief Representation of a Window object, it handles input and hosts the environment for a render Instance, it makes real time visualization possible
 */
class Window {

public:
	Window(string name, const size_t width, const size_t height, shared_ptr<Renderer> renderer);
	~Window();

	void update();

private:
	void handleInput();

private:
	std::map<char, bool> m_KeyActions{
		{ 'W', false}, // FORWARD
		{ 'S', false}, // BACKWARD
		{ 'D', false}, // RIGHT
		{ 'A', false}, // LEFT

		{ 'I', false}, // PITCH UP
		{ 'K', false}, // PITCH DOWN
		{ 'L', false}, // YAW RIGHT
		{ 'J', false}, // YAW LEFT
		{ 'O', false}, // ROLL RIGHT
		{ 'U', false}, // ROLL LEFT
	};

	size_t m_Width;
	size_t m_Height;
	double m_AspectRatio;

	const shared_ptr<Renderer> p_Renderer;

	SDL_Window* p_SDLWindow;
	SDL_Renderer* p_SDLRenderer;
	SDL_Texture* p_SDLTexture;

	bool m_Running;

};


