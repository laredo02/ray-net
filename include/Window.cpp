
#include "Window.h"

Window::Window(const size_t width, const size_t height, string name, const Renderer& renderer)
: m_Width(width), m_Height(height), m_AspectRatio(static_cast<double> (width) / height), p_Renderer(&renderer) {
    p_SDLWindow = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (p_SDLWindow == nullptr) {
        SDL_Quit();
    }
    p_SDLRenderer = SDL_CreateRenderer(p_SDLWindow, -1, SDL_RENDERER_ACCELERATED);
    if (p_SDLRenderer == nullptr) {
        SDL_DestroyWindow(p_SDLWindow);
        SDL_Quit();
    }
    p_SDLTexture = SDL_CreateTexture(p_SDLRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
    if (p_SDLTexture == nullptr) {
        SDL_DestroyRenderer(p_SDLRenderer);
        SDL_DestroyWindow(p_SDLWindow);
        SDL_Quit();
    }
    m_Running = true;
}

Window::~Window() {
    SDL_DestroyTexture(p_SDLTexture);
    SDL_DestroyRenderer(p_SDLRenderer);
    SDL_DestroyWindow(p_SDLWindow);
    SDL_Quit();
}

void Window::update() {
    
    while (m_Running) {
        
        if (m_Running) {
#if BENCHMARK == 1
            Benchmark bench("Render loop took ", true);
#endif
            p_Renderer->render();
        }
            
        const Image& image = p_Renderer->getImage();
        {
#if BENCHMARK == 1
            Benchmark bench("Saving the image to disk took ", true);
#endif
            p_Renderer->saveRenderToFile("image.ppm");
        }
        
        image.toTexture(p_SDLTexture);
        
        SDL_RenderClear(p_SDLRenderer);
        SDL_RenderCopy(p_SDLRenderer, p_SDLTexture, nullptr, nullptr);
        SDL_RenderPresent(p_SDLRenderer);

        this->handleInput();
    }

}

void Window::handleInput() {

    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            m_Running = false;
        } else if (event.type == SDL_WINDOWEVENT) {
            switch (event.window.event) {
                case SDL_WINDOWEVENT_RESIZED:
                    m_Width = event.window.data1;
                    m_Height = event.window.data2;
                    cout << "SDL_WINDOWEVENT_RESIZED (" << m_Width << 'x' << m_Height << ")\n";
                    break;
            }
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.scancode) {

                case SDL_SCANCODE_UP:
                    p_Renderer->camera().pitch(1);
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("CAMERA_DIRECTION", p_Renderer->camera().direction());
#endif
                    break;
                case SDL_SCANCODE_DOWN:
                    p_Renderer->camera().pitch(-1);
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("CAMERA_DIRECTION", p_Renderer->camera().direction());
#endif
                    break;
                case SDL_SCANCODE_RIGHT:
                    p_Renderer->camera().yaw(-1);
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("CAMERA_DIRECTION", p_Renderer->camera().direction());
#endif
                    break;
                case SDL_SCANCODE_LEFT:
                    p_Renderer->camera().yaw(1);
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("CAMERA_DIRECTION", p_Renderer->camera().direction());
#endif
                    break;

                    
                case SDL_SCANCODE_PAGEUP:
                    p_Renderer->camera().translate( Vector3(0.0, 0.1, 0.0) );
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("CAMERA_CENTER", p_Renderer->camera().center())
#endif
                    break;
                case SDL_SCANCODE_PAGEDOWN:
                    p_Renderer->camera().translate( Vector3(0.0, -0.1, 0.0) );
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("CAMERA_CENTER", p_Renderer->camera().center())
#endif
                    break;
                    
                    
                case SDL_SCANCODE_W:
                    p_Renderer->camera().translate( Vector3(0.0, 0.0, -0.1) );   
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("CAMERA_CENTER", p_Renderer->camera().center())
#endif
                    break;
                case SDL_SCANCODE_S:
                    p_Renderer->camera().translate( Vector3(0.0, 0.0, 0.1) );
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("CAMERA_CENTER", p_Renderer->camera().center())
#endif
                    break;
                case SDL_SCANCODE_D:
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("CAMERA_CENTER", p_Renderer->camera().center())
#endif
                    p_Renderer->camera().translate( Vector3(0.1, 0.0, 0.0) );
                    break;
                case SDL_SCANCODE_A:
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("CAMERA_CENTER", p_Renderer->camera().center())
#endif
                    p_Renderer->camera().translate( Vector3(-0.1, 0.0, 0.0) );
                    break;
                    
                    
                    
                case SDL_SCANCODE_G:
#if PRINT_KEYBOARD_ACTIONS == 1
                    cout << "Saving image... ";
#endif
                    p_Renderer->saveRenderToFile("image.ppm");
#if PRINT_KEYBOARD_ACTIONS == 1
                    cout << "OK\n";
#endif
                    break;


                case SDL_SCANCODE_ESCAPE:
                    m_Running = false;
                    break;
                case SDL_SCANCODE_Q:
                    m_Running = false;
                    break;
            }
        }
    }
}


