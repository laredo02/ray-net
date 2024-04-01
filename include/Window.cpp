
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
    p_SDLTexture = SDL_CreateTexture(p_SDLRenderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, width, height);
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

        if (m_Running)
            p_Renderer->render();
        
        const Image& image = p_Renderer->getImage();

        SDL_SetRenderDrawColor(p_SDLRenderer, 255, 0, 255, 255);
        SDL_RenderClear(p_SDLRenderer);
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
                    cout << "Saving image... ";
                    p_Renderer->saveRenderToFile("image.ppm");
                    cout << "OK\n";
                    break;


                case SDL_SCANCODE_ESCAPE:
                    m_Running = false;
                    //cout << "SDL_SCANCODE_ESCAPE\n";
                    break;
                case SDL_SCANCODE_Q:
                    m_Running = false;
                    //cout << "SDL_SCANCODE_Q\n";
                    break;
            }
        }
    }
}
