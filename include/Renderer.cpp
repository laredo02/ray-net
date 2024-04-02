
#include "RayNet.h"

#include "Renderer.h"

Renderer::Renderer(Camera* camera, const Sphere* sphere, Image* img)
: p_Camera(camera), p_Sphere(sphere), p_Image(img) {
}

const Image& Renderer::getImage() const {
    return *p_Image;
}

void Renderer::render() const {
    auto rays = p_Camera->computeRays(p_Image->width());

    auto width { p_Image->width() };
    auto height { p_Image->height() };
    
    for (auto i{0}; i < height; i++) {
        
        for (auto j{0}; j < width; j++) {
            
            Ray ray = rays.at(i * width + j);
            auto t = p_Sphere->hit(ray);
            
            if (t >= 0.0) { // Draw hit
                Vector3 normal = (ray.at(t) - p_Sphere->getCenter()).unit();
                Vector3 color = (normal/2.0)+1.0;
                p_Image->setPixel(i, j, color);
            
            } else { // Draw miss
                double h { static_cast<double>(height) };
                Vector3 color { (double)i, (double)i, (double)i+height };
                color.toUnit();
                p_Image->setPixel(i, j, color);
                
            }
        }
    }

}

void Renderer::saveRenderToFile(const string& name) const {
    p_Image->saveToFile(name);
}

Camera& Renderer::camera() const {
    return *p_Camera;
}
