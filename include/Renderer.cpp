
#include <thread>
#include <mutex>

#include "RayNet.h"

#include "Renderer.h"

Vector3 pixelColor(const Ray& ray, const Sphere& sphere /*const Scene& world*/) {
    Vector3 color { 0.0, 0.0, 0.0 };
    auto t=sphere.hit(ray);
    if (t>=0.0) { // Draw hit
        Vector3 normal=(ray.at(t)-sphere.getCenter()).unit();
        Vector3 globalLight{ -1.0, -1.0, -1.0};
        double paral=(-dot(globalLight.unit(), normal.unit()));
        color=sphere.getMaterial().albedo * ((paral>0.0)? paral: 0.0);
    } else { // Draw miss
        color = Vector3{ 1.0, 1.0, 1.0 };
    }
    return color;
}

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
    auto rows_per_thread=height/(supported_threads-1);
    auto rows_for_last_thread=height%(supported_threads-1);
#if ASSERTIONS == 1
    assert(rows_per_thread*(supported_threads-1)+rows_for_last_thread==height);
#endif
    std::thread thread_list[supported_threads];
#if MULTITHREAD_LOGGING == 1
    std::mutex m1;
    NEWLINE
    LOG("SUPPORTED THREADS", supported_threads);
    LOG("ROWS PER THREAD", rows_per_thread);
    LOG("ROWS_FOR_LAST_THREAD", rows_for_last_thread);
    NEWLINE
#endif
#endif      
            auto render_fraction=[&](int ri, int rf) {
#if MULTITHREAD_RENDER == 1 && MULTITHREAD_LOGGING == 1
        m1.lock();
        NEWLINE
        LOG("THREAD", std::this_thread::get_id());
        LOG("RI", ri);
        LOG("RF", rf);
        NEWLINE
        m1.unlock();
#endif
        for (int i=ri; i<rf; i++) {
            for (int j=0; j<width; j++) {
                Ray ray = p_Camera->getRay(i, j);
                p_Image->setPixel(i, j, pixelColor(ray, *p_Sphere));
            }
        }
    };
#if MULTITHREAD_RENDER == 1
    // Begin all threads
    for (int i=0, begin=0; i<supported_threads-1; i++) {
        begin=i*rows_per_thread;
        thread_list[i]=std::thread(render_fraction, begin, begin+rows_per_thread);
    }
    int begin=(supported_threads-1)*rows_per_thread;
    thread_list[supported_threads-1]=std::thread(render_fraction, begin, begin+rows_for_last_thread);

    // Join all threads
    for (int i=0; i<supported_threads; i++) {
        thread_list[i].join();
    }
#if MULTITHREAD_LOGGING ==1
    LOG("JOINED ALL", "THREADS");
#endif

#else
    render_fraction(0, height);
#endif
}

void Renderer::saveRenderToFile(const string& name) const {
    p_Image->saveToFile(name);
}

Camera& Renderer::camera() const {
    return *p_Camera;
}
