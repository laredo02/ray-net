
#include "Window.h"

/*
 * @brief Window Creation
 * @details Creates the Window that will host the Renderer
 */
Window::Window(string name, const size_t width, const size_t height, shared_ptr<Renderer> renderer)
: m_Width(width), m_Height(height), m_AspectRatio(static_cast<double> (width)/height), p_Renderer(renderer) {
    p_SDLWindow=SDL_CreateWindow(
            name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height,
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );
    if (p_SDLWindow==nullptr) SDL_Quit();
    p_SDLRenderer=SDL_CreateRenderer(p_SDLWindow, -1, SDL_RENDERER_ACCELERATED);
    if (p_SDLRenderer==nullptr) {
        SDL_DestroyWindow(p_SDLWindow);
        SDL_Quit();
    }
    p_SDLTexture=SDL_CreateTexture(p_SDLRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
    if (p_SDLTexture==nullptr) {
        SDL_DestroyRenderer(p_SDLRenderer);
        SDL_DestroyWindow(p_SDLWindow);
        SDL_Quit();
    }
    m_Running=true;
}

/*
 * @brief Window Destruction
 * @details Destroys the window and its elements
 */
Window::~Window() {
    SDL_DestroyTexture(p_SDLTexture);
    SDL_DestroyRenderer(p_SDLRenderer);
    SDL_DestroyWindow(p_SDLWindow);
    SDL_Quit();
}


/*
 * @brief Loops until a window exit event occurs
 */
void Window::update() {    
    uint32_t period = 0;

    
    while (m_Running) {
        
        
#if BENCHMARK == 1
        Benchmark iterBench{"iteration took ", true};
        int64_t iterTime;
        int64_t renderTime;
        int64_t imageTime;
        int64_t eventTime;
#endif
        
        
////////////////////////////////////////////////////////////////////////////////
        if (m_Running) {
#if BENCHMARK == 1
            Benchmark renderBench{"render took ", true};
#endif
            Benchmark renderTime{"", false};
            p_Renderer->render();
            period = renderTime.lap();
            
            // LOG("time", 1000.0/(double) period)
            LOG("time", period)
#if BENCHMARK == 1
            renderTime = renderBench.lap();
#endif
        }
////////////////////////////////////////////////////////////////////////////////
        {
#if BENCHMARK == 1
            Benchmark imageBench{"image processing took ", true};
#endif
            const Image& image=p_Renderer->getImage();
            image.toTexture(p_SDLTexture);
            SDL_RenderClear(p_SDLRenderer);
            SDL_RenderCopy(p_SDLRenderer, p_SDLTexture, nullptr, nullptr);
            SDL_RenderPresent(p_SDLRenderer);
#if BENCHMARK == 1
            imageTime = imageBench.lap();
#endif
        }
////////////////////////////////////////////////////////////////////////////////
        {
#if BENCHMARK == 1
            Benchmark eventBench("handle events took ", true);
#endif
            this->handleInput();
            double rotationDelta= static_cast<double>(period)*CAMERA_ROTATION_SPEED;
            if (m_KeyActions['i']) p_Renderer->camera().pitch(rotationDelta);
            if (m_KeyActions['k']) p_Renderer->camera().pitch(-rotationDelta);
            if (m_KeyActions['l']) p_Renderer->camera().yaw(-rotationDelta);
            if (m_KeyActions['j']) p_Renderer->camera().yaw(rotationDelta);
            if (m_KeyActions['o']) p_Renderer->camera().roll(rotationDelta);
            if (m_KeyActions['u']) p_Renderer->camera().roll(-rotationDelta);
            
            double translationDelta = static_cast<double>(period) * CAMERA_TRANSLATION_SPEED;
            if (m_KeyActions['w']) p_Renderer->camera().translate(Vector3(0.0, 0.0, -translationDelta));
            if (m_KeyActions['s']) p_Renderer->camera().translate(Vector3(0.0, 0.0, translationDelta));
            if (m_KeyActions['d']) p_Renderer->camera().translate(Vector3(translationDelta, 0.0, 0.0));
            if (m_KeyActions['a']) p_Renderer->camera().translate(Vector3(-translationDelta, 0.0, 0.0));
            if (m_KeyActions[' ']) p_Renderer->camera().translate(Vector3(0.0, translationDelta, 0.0));
            if (m_KeyActions['S']) p_Renderer->camera().translate(Vector3(0.0, -translationDelta, 0.0));
#if PRINT_KEYBOARD_ACTIONS == 1
            LOG("CAMERA_LOCATION", p_Renderer->camera().center())
            LOG("CAMERA_DIRECTION", p_Renderer->camera().direction())
            NEWLINE
#endif      
#if BENCHMARK == 1
            eventTime = eventBench.lap();
#endif
        }
////////////////////////////////////////////////////////////////////////////////  
#if BENCHMARK == 1
        iterTime = iterBench.lap();
        float renderPer100 = ((double)renderTime/iterTime)*100.0;
        float imagePer100 = ((double)imageTime/iterTime)*100.0;
        float eventPer100 = ((double)eventTime/iterTime*100.0);
        LOG("RENDER%", renderPer100)
        LOG("IMAGE%", imagePer100)
        LOG("EVENT%", eventPer100)
        NEWLINE
#endif
    }
    
    

}

/*
 * @brief Handle Input from the user, mainly the keyboard
 * @details Handle SDL Events, Window Events, Keyboard events...
 */
void Window::handleInput() {
    
    SDL_Event event;
    while (SDL_PollEvent(&event)!=0) {                                      // On Event
        
        if (event.type==SDL_QUIT) {                                         // Exit Application
            m_Running=false;
        } else if (event.type==SDL_WINDOWEVENT) {
            switch (event.window.event) {                                   // Window Resized
                case SDL_WINDOWEVENT_RESIZED:
                    m_Width=event.window.data1;
                    m_Height=event.window.data2;
#if PRINT_KEYBOARD_ACTIONS == 1
                    cout<<"SDL_WINDOWEVENT_RESIZED ("<<m_Width<<'x'<<m_Height<<")\n";
#endif
                    break;
            }
        }
        
        if (event.type==SDL_KEYUP) {                                        // When Keys are Released...
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_I: m_KeyActions['i']=false; break;        // Pitch Up
                case SDL_SCANCODE_K: m_KeyActions['k']=false; break;        // Pitch Down
                case SDL_SCANCODE_L: m_KeyActions['l']=false; break;        // Yaw Right
                case SDL_SCANCODE_J: m_KeyActions['j']=false; break;        // Yaw Left
                case SDL_SCANCODE_O: m_KeyActions['o']=false; break;        // Roll Right
                case SDL_SCANCODE_U: m_KeyActions['u']=false; break;        // Roll Left
                case SDL_SCANCODE_W: m_KeyActions['w']=false; break;        // Forward
                case SDL_SCANCODE_S: m_KeyActions['s']=false; break;        // Backward
                case SDL_SCANCODE_D: m_KeyActions['d']=false; break;        // Right
                case SDL_SCANCODE_A: m_KeyActions['a']=false; break;        // Left
                case SDL_SCANCODE_SPACE: m_KeyActions[' ']=false; break;    // Up
                case SDL_SCANCODE_LSHIFT: m_KeyActions['S']=false; break;   // Down
            }
        }
        
        if (event.type==SDL_KEYDOWN) {
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_I: m_KeyActions['i']=true; break;         // Pitch Up
                case SDL_SCANCODE_K: m_KeyActions['k']=true; break;         // Pitch Down
                case SDL_SCANCODE_L: m_KeyActions['l']=true; break;         // Yaw Right
                case SDL_SCANCODE_J: m_KeyActions['j']=true; break;         // Yaw Left
                case SDL_SCANCODE_O: m_KeyActions['o']=true; break;         // Roll Right
                case SDL_SCANCODE_U: m_KeyActions['u']=true; break;         // Roll Left
                case SDL_SCANCODE_W: m_KeyActions['w']=true; break;         // Forward
                case SDL_SCANCODE_S: m_KeyActions['s']=true; break;         // Backward
                case SDL_SCANCODE_D: m_KeyActions['d']=true; break;         // Right
                case SDL_SCANCODE_A: m_KeyActions['a']=true; break;         // Left
                case SDL_SCANCODE_SPACE: m_KeyActions[' ']=true; break;     // Up
                case SDL_SCANCODE_LSHIFT: m_KeyActions['S']=true; break;    // Down
                case SDL_SCANCODE_G:                                        // Save render
#if PRINT_KEYBOARD_ACTIONS == 1
                    LOG("Saving image to ", "image.ppm")
#endif
#if BENCHMARK == 1 
                {
                    Benchmark bench("Saving the image to disk took ", true);
#endif
                    p_Renderer->saveRenderToFile("image.ppm");
#if BENCHMARK == 1
                }
#endif
#if PRINT_KEYBOARD_ACTIONS == 1
                    cout<<"OK\n";
#endif
                    break;
                
                case SDL_SCANCODE_ESCAPE:                                   // Exit Application
#if PRINT_KEYBOARD_ACTIONS == 1
                    PRINT("EXIT")
#endif
                    m_Running=false; break;
                case SDL_SCANCODE_Q:                                        // Exit Application
#if PRINT_KEYBOARD_ACTIONS == 1
                    PRINT("EXIT")
#endif
                    m_Running=false; break;
            
            }
        }
        
    }
    
}
