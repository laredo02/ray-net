
#include "RayNet.h"
#include "Window.h"

Window::Window(const size_t width, const size_t height, string name, const Renderer& renderer)
: m_Width(width), m_Height(height), m_AspectRatio(static_cast<double> (width)/height), p_Renderer(&renderer) {
    p_SDLWindow=SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN);
    if (p_SDLWindow==nullptr) {
        SDL_Quit();
    }
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

Window::~Window() {
    SDL_DestroyTexture(p_SDLTexture);
    SDL_DestroyRenderer(p_SDLRenderer);
    SDL_DestroyWindow(p_SDLWindow);
    SDL_Quit();
}

void Window::update() {

    while (m_Running) {

#if BENCHMARK == 1
        Benchmark iterBench("iteration took ", true);
        int64_t iterTime;
        int64_t renderTime;
        int64_t imageTime;
        int64_t eventTime;
#endif
        if (m_Running) {
#if BENCHMARK == 1
            Benchmark renderBench("render took ", true);
#endif
            p_Renderer->render();
#if BENCHMARK == 1
            renderTime = renderBench.lap();
#endif
        }

        {
#if BENCHMARK == 1
            Benchmark imageBench("image processing took ", true);
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


        {
#if BENCHMARK == 1
            Benchmark eventBench("handle events took ", true);
#endif
            this->handleInput();
            double rotationDelta=0.7;
            if (m_KeyActions['i']) {
                p_Renderer->camera().pitch(rotationDelta);
            }
            if (m_KeyActions['k']) {
                p_Renderer->camera().pitch(-rotationDelta);
            }
            
            if (m_KeyActions['l']) {
                p_Renderer->camera().yaw(-rotationDelta);
            }
            
            if (m_KeyActions['j']) {
                p_Renderer->camera().yaw(rotationDelta);
            }
            if (m_KeyActions['o']) {
                p_Renderer->camera().roll(rotationDelta);
            }
            if (m_KeyActions['u']) {
                p_Renderer->camera().roll(-rotationDelta);
            }

            double translationDelta=0.1;
            if (m_KeyActions['w']) {
                p_Renderer->camera().translate(Vector3(0.0, 0.0, -translationDelta));                
            }
            if (m_KeyActions['s']) {
                p_Renderer->camera().translate(Vector3(0.0, 0.0, translationDelta));
                
            }

            if (m_KeyActions['d']) {
                p_Renderer->camera().translate(Vector3(translationDelta, 0.0, 0.0));
            }
            if (m_KeyActions['a']) {
                p_Renderer->camera().translate(Vector3(-translationDelta, 0.0, 0.0));
            }

            if (m_KeyActions[' ']) {
                p_Renderer->camera().translate(Vector3(0.0, translationDelta, 0.0));
            }
            if (m_KeyActions['S']) {
                p_Renderer->camera().translate(Vector3(0.0, -translationDelta, 0.0));
            }
            
//            LOG("CAMERA_LOCATION", p_Renderer->camera().center())
//            LOG("CAMERA_DIRECTION", p_Renderer->camera().direction())
//            NEWLINE
                    
#if BENCHMARK == 1
            eventTime = eventBench.lap();
#endif
            
        }
#if BENCHMARK == 1
        iterTime = iterBench.lap();
#endif
        

#if BENCHMARK == 1
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

void Window::handleInput() {
    
    SDL_Event event;
    while (SDL_PollEvent(&event)!=0) {
        
        if (event.type==SDL_QUIT) {
            m_Running=false;
        } else if (event.type==SDL_WINDOWEVENT) {
            switch (event.window.event) {
                case SDL_WINDOWEVENT_RESIZED:
                    m_Width=event.window.data1;
                    m_Height=event.window.data2;
#if PRINT_KEYBOARD_ACTIONS == 1
                    cout<<"SDL_WINDOWEVENT_RESIZED ("<<m_Width<<'x'<<m_Height<<")\n";
#endif
                    break;
            }
        }
        if (event.type==SDL_KEYDOWN) {
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_I:
                    m_KeyActions['i']=true;
                    break;
                case SDL_SCANCODE_K:
                    m_KeyActions['k']=true;
                    break;
                case SDL_SCANCODE_L:
                    m_KeyActions['l']=true;
                    break;
                case SDL_SCANCODE_J:
                    m_KeyActions['j']=true;
                    break;
                case SDL_SCANCODE_O:
                    m_KeyActions['o']=true;
                    break;
                case SDL_SCANCODE_U:
                    m_KeyActions['u']=true;
                    break;

                case SDL_SCANCODE_W:
                    m_KeyActions['w']=true;
                    break;
                case SDL_SCANCODE_S:
                    m_KeyActions['s']=true;
                    break;
                case SDL_SCANCODE_D:
                    m_KeyActions['d']=true;
                    break;
                case SDL_SCANCODE_A:
                    m_KeyActions['a']=true;
                    break;
                case SDL_SCANCODE_SPACE:
                    m_KeyActions[' ']=true;
                    break;
                case SDL_SCANCODE_LSHIFT:
                    m_KeyActions['S']=true;
                    break;

                case SDL_SCANCODE_G:
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
                case SDL_SCANCODE_ESCAPE:
#if PRINT_KEYBOARD_ACTIONS == 1
                    PRINT("EXIT")
#endif
                            m_Running=false;
                    break;
                case SDL_SCANCODE_Q:
#if PRINT_KEYBOARD_ACTIONS == 1
                    PRINT("EXIT")
#endif
                            m_Running=false;
                    break;
            }
        }

        if (event.type==SDL_KEYUP) {
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_I:
                    m_KeyActions['i']=false;
                    break;
                case SDL_SCANCODE_K:
                    m_KeyActions['k']=false;
                    break;
                case SDL_SCANCODE_L:
                    m_KeyActions['l']=false;
                    break;
                case SDL_SCANCODE_J:
                    m_KeyActions['j']=false;
                    break;
                case SDL_SCANCODE_U:
                    m_KeyActions['u']=false;
                    break;
                case SDL_SCANCODE_O:
                    m_KeyActions['o']=false;
                    break;
                case SDL_SCANCODE_W:
                    m_KeyActions['w']=false;
                    break;
                case SDL_SCANCODE_S:
                    m_KeyActions['s']=false;
                    break;
                case SDL_SCANCODE_D:
                    m_KeyActions['d']=false;
                    break;
                case SDL_SCANCODE_A:
                    m_KeyActions['a']=false;
                    break;
                case SDL_SCANCODE_SPACE:
                    m_KeyActions[' ']=false;
                    break;
                case SDL_SCANCODE_LSHIFT:
                    m_KeyActions['S']=false;
                    break;
            }
        }
        
    }
    
}


