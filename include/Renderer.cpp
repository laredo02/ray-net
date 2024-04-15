
#include <thread>
#include <mutex>

#include "RayNet.h"

#include "Renderer.h"

Renderer::Renderer(Camera* camera, const Sphere* sphere, Image* img)
: p_Camera(camera), p_Sphere(sphere), p_Image(img) { }

const Image& Renderer::getImage() const {
    return *p_Image;
}

void Renderer::render() const {

    auto deltaU{ p_Camera->deltaU()};
    auto deltaV{ p_Camera->deltaV()};
    auto P00{ p_Camera->P00()};

    auto width{ p_Camera->width()};
    auto height{ p_Camera->height()};


#if MULTITHREAD_RENDER == 1
    auto supported_threads=std::thread::hardware_concurrency();
    auto rows_per_thread = height/supported_threads;
    auto rows_for_last_thread = height%supported_threads;
#if ASSERTIONS == 1
    assert(rows_per_thread*supported_threads + rows_for_last_thread == height);
#endif
    std::thread thread_list[supported_threads];
#if MULTITHREAD_LOGGING == 1
    std::mutex m1;
    LOG("SUPPORTED THREADS", supported_threads);
    LOG("ROWS PER THREAD", rows_per_thread);
#endif

    auto render_fraction=[&](int ri, int rf) {
#if MULTITHREAD_LOGGING == 1
        m1.lock();
        LOG("THREAD", std::this_thread::get_id());
        LOG("RI", ri);
        LOG("RF", rf);
        m1.unlock();
#endif        
        
#if 1
        for (int i=ri; i<rf; i++) {
            for (int j=0; j<width; j++) {
                
                Vector3 direction { (P00 + ((double) i * deltaV) + ((double) j * deltaU)) };
#if REAL_DISTANCE == 1
                direction.toUnit();
#endif
                Ray ray { p_Camera->center(), direction };
      
                
                auto t = p_Sphere->hit(ray);
                if (t >= 0.0) { // Draw hit
                    Vector3 normal = (ray.at(t) - p_Sphere->getCenter()).unit();
                    Vector3 normal_color = (normal+1.0)/2.0;

                    Vector3 globalLight { -0.3, -1.0, -0.0 };
                    double paral = (-dot(globalLight.unit(), normal.unit()) + 1.0)/2.0;
                    Vector3 color = p_Sphere->getMaterial().albedo * paral;

                    p_Image->setPixel(i, j, color);
            
                } else { // Draw miss
                    double h { static_cast<double>(height) };
                    Vector3 color { (double)i, (double)i, (double)i+height };
                    color.toUnit();
                    p_Image->setPixel(i, j, color);
                }
                
                
            }
        }
#endif
       
    };

    // Begin all threads
    int i=0;
    int begin=0;
    for (i=0; i<supported_threads-1; i++) {
        begin = i*rows_per_thread;
        thread_list[i]=std::thread(render_fraction, begin, begin+rows_per_thread);
    }
    i += 1;
//    begin = i*rows_per_thread;
//    thread_list[i]=std::thread(render_fraction, begin, begin+rows_for_last_thread);
//    i = 0;
    
    // Join all threads
    for (i=0; i<supported_threads-1; i++) {
        thread_list[i].join();
    }
    
#if MULTITHREAD_LOGGING ==1
    LOG("JOINED ALL", "THREADS");
#endif
    
#elif MULTITHREAD_RENDER == 0
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            Vector3 direction{ (P00+((double) i*deltaV) + ((double) j*deltaU))};
#if REAL_DISTANCE == 1
            direction.toUnit();
#endif
            Ray ray{ p_Camera->center(), direction};
            auto t=p_Sphere->hit(ray);
            if (t>=0.0) { // Draw hit
                Vector3 normal=(ray.at(t)-p_Sphere->getCenter()).unit();

                Vector3 normal_color=(normal+1.0)/2.0;





                Vector3 globalLight{ -0.3, -1.0, -0.0};
                double paral=(-dot(globalLight.unit(), normal.unit())+1.0)/2.0;
                Vector3 color=p_Sphere->getMaterial().albedo * paral;

                p_Image->setPixel(i, j, color);

            } else { // Draw miss
                double h{ static_cast<double> (height)};
                Vector3 color{ (double) i, (double) i, (double) i+height};
                color.toUnit();
                p_Image->setPixel(i, j, color);

            }
        }
    }
#endif

}

void Renderer::saveRenderToFile(const string& name) const {
    p_Image->saveToFile(name);
}

Camera& Renderer::camera() const {
    return *p_Camera;
}
