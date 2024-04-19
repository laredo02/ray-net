
#ifndef WINDOW_H
#define WINDOW_H


#include <map>
#include <SDL2/SDL.h>

#include "RayNet.h"
#include "Image.h"
#include "Renderer.h"
#include "Camera.h"
#include "Sphere.h"


class Window {
public:
	Window(const size_t width, const size_t heigh, string name, const Renderer& renderer);
	~Window();
	
	void update();
	
private:
	void handleInput();
	
private:
	
	std::map<char, bool> m_KeyActions {
		{ 'W', false },		// FORWARD
		{ 'S', false },		// BACKWARD
		{ 'D', false },		// RIGHT
		{ 'A', false },		// LEFT
				
		{ 'I', false },		// PITCH UP
		{ 'K', false },		// PITCH DOWN
		{ 'L', false },		// YAW RIGHT
		{ 'J', false },		// YAW LEFT
		{ 'O', false },		// ROLL RIGHT
		{ 'U', false },		// ROLL LEFT
				
	};
	
	size_t m_Width;
	size_t m_Height;
	double m_AspectRatio;
	
	const Renderer* p_Renderer;
	
	SDL_Window* p_SDLWindow;
	SDL_Renderer* p_SDLRenderer;
	SDL_Texture* p_SDLTexture;
	
	bool m_Running;
	
};

#endif /* WINDOW_H */

