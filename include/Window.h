
#ifndef WINDOW_H
#define WINDOW_H

#include "RayNet.h"
#include "Image.h"
#include "Renderer.h"
#include "Camera.h"
#include "Sphere.h"

#include <SDL2/SDL.h>

class Window {
public:
	Window(const size_t width, const size_t heigh, string name);
	~Window();
	
	void update();
	
private:
	size_t m_Width;
	size_t m_Height;
	double m_AspectRatio;
	
	SDL_Window* p_Window;
	SDL_Renderer* p_Renderer;
	SDL_Texture* p_Texture;
    

	
	bool running;
	
};

#endif /* WINDOW_H */

