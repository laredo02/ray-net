
#include "Window.h"

Window::Window(const size_t width, const size_t height, string name)
    : m_Width(width), m_Height(height)
{
    p_Window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (p_Window == nullptr) {
        SDL_Quit();
    }
    p_Renderer = SDL_CreateRenderer(p_Window, -1, SDL_RENDERER_ACCELERATED);
    if (p_Renderer == nullptr) {
        SDL_DestroyWindow(p_Window);
        SDL_Quit();
    }
    p_Texture = SDL_CreateTexture(p_Renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, width, height);
    if (p_Texture == nullptr) {
        SDL_DestroyRenderer(p_Renderer);
        SDL_DestroyWindow(p_Window);
        SDL_Quit();
    }
}

Window::~Window()
{
    SDL_DestroyTexture(p_Texture);
    SDL_DestroyRenderer(p_Renderer);
    SDL_DestroyWindow(p_Window);
    SDL_Quit();
}

void Window::update(Image& image)
{
    
    SDL_Event event;
    running = true;
    
    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                    running = false;
            }
            else if (event.type == SDL_WINDOWEVENT) {
                switch (event.window.event) {
                    case SDL_WINDOWEVENT_RESIZED:
                        
                        
                        
                        break;
                }
            }
        }
        
        
        
        SDL_SetRenderDrawColor(p_Renderer, 255, 0, 255, 255);
        SDL_RenderClear(p_Renderer);
        SDL_RenderPresent(p_Renderer);
    }

}




