
#include <thread>
#include <mutex>

#include "RayNet.h"

#include "Renderer.h"
#include "HitTrace.h"

Vector3 pixelColor(const Ray& ray, const Scene& scene, double tmin, double tmax) {

    Vector3 color{ 0.0, 0.0, 0.0};

    if (!scene.isEmpty()) {

        HitTrace closestHit;
        bool hit = scene[0].hit(ray, tmin, tmax, closestHit);
        for (auto i=1; i<scene.size(); i++) {
            HitTrace trace;
            if (scene[i].hit(ray, tmin, tmax, trace)) {
                hit = true;
                closestHit=(trace.m_HitDistance<closestHit.m_HitDistance) ? trace : closestHit;
            }
        }
        if (hit) {
            auto material=closestHit.p_Material;
            if (material) {
#if RENDER_NORMALS == 0
                Vector3 ray_dir { ray.direction() + 2*dot(ray.direction(), closestHit.m_Normal)*closestHit.m_Normal };
                ray_dir = closestHit.m_Normal;
                color=((material->m_Albedo + (pixelColor(Ray{closestHit.m_Point, ray_dir}, scene, tmin, tmax)) )/2.0);
#endif
#if RENDER_NORMALS == 1
                color=(closestHit.m_Normal+1.0)/2.0;
#endif                
                
            }
        } else {
            color = Vector3{ 1.0, 1.0, 1.0 };
        }

    }


    return color;
}

Renderer::Renderer(shared_ptr<Camera> camera, shared_ptr<Scene> scene, shared_ptr<Image> image)
: p_Camera(camera), p_Scene(scene), p_Image(image) {
 }

const Image& Renderer::getImage() const {
    return *p_Image;
}

void Renderer::render() const {

    if (p_Camera==nullptr||p_Image==nullptr) {
        LOG("ERROR: p_Camera", p_Camera);
        LOG("ERROR: p_Image", p_Image);
        exit(EXIT_FAILURE);
    }

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
                Ray ray=p_Camera->getRay(i, j);
                p_Image->setPixel(i, j, pixelColor(ray, *p_Scene, 0.1, std::numeric_limits<double>::max()));
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


