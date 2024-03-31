
#include "Window.h"

Window::Window(const size_t width, const size_t height, string name)
    : m_Width(width), m_Height(height), m_AspectRatio(static_cast<double>(width)/height)
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

void Window::update()
{
                        
    Camera camera { Vector3{ 0.0, 0.0, 0.0 }, Vector3{ 0.0, 0.0, -1.0 }, Vector3{ 0.0, 1.0, 0.0 }, 90.0, 2.0, m_AspectRatio };
    Sphere sphere { Vector3{ 0.0, 0.0, -3.0 }, 1.0, Material{ Vector3{ 1.0, 0.0, 0.0 } } };
    Renderer renderer { &camera, &sphere };
    
    Image img { m_Height, m_Width };
    
    
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
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {    
                    
                    case SDL_SCANCODE_UP:
                        cout << "SDL_SCANCODE_UP\n";
                        break;
                    case SDL_SCANCODE_DOWN:
                        cout << "SDL_SCANCODE_DOWN\n";
                        break;
                    case SDL_SCANCODE_RIGHT:
                        cout << "SDL_SCANCODE_RIGHT\n";
                        break;
                    case SDL_SCANCODE_LEFT:
                        cout << "SDL_SCANCODE_LEFT\n";
                        break;
                        

                    case SDL_SCANCODE_W:
                        cout << "SDL_SCANCODE_W\n";
                        break;
                    case SDL_SCANCODE_S:
                        cout << "SDL_SCANCODE_S\n";
                        break;
                    case SDL_SCANCODE_D:
                        cout << "SDL_SCANCODE_D\n";
                        break;
                    case SDL_SCANCODE_A:
                        cout << "SDL_SCANCODE_A\n";
                        break;

                    case SDL_SCANCODE_G:
                        img.saveToFile("image.ppm");
                        break;
                        
                    
                    case SDL_SCANCODE_Q:
                        running = false;
                        cout << "SDL_SCANDODE_Q\n";
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        running = false;
                        cout << "SDL_SCANDODE_ESCAPE\n";
                        break;
                
                }
            }
        }
        
        renderer.render(img);
        
        SDL_SetRenderDrawColor(p_Renderer, 255, 0, 255, 255);
        SDL_RenderClear(p_Renderer);
        SDL_RenderPresent(p_Renderer);
    }

}




