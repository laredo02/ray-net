
#include "RayNet.h"

#include "Renderer.h"

Renderer::Renderer(Camera* camera, const Sphere* sphere, Image* img)
: p_Camera(camera), p_Sphere(sphere), p_Image(img) {
}

const Image& Renderer::getImage() const {
    return *p_Image;
}

void Renderer::render() const {
            
    auto deltaU { p_Camera->deltaU() };
    auto deltaV { p_Camera->deltaV() };
    auto P00 { p_Camera->P00() };

    auto width { p_Camera->width() };
    auto height { p_Camera->height() };
    
    for (int i=0; i < height; i++) {
        for (int j=0; j < width; j++) {
            Vector3 direction { (P00 + ((double) i * deltaV) + ((double) j * deltaU)) };
#if REAL_DISTANCE == 1
            direction.toUnit();
#endif
            Ray ray { p_Camera->center(), direction };
            auto t = p_Sphere->hit(ray);
            if (t >= 0.0) { // Draw hit
                Vector3 normal = (ray.at(t) - p_Sphere->getCenter()).unit();
                                
                Vector3 normal_color = (normal+1.0)/2.0;
                
                
   
                
                
                //Vector3 globalLight { -1.0, -1.0, -1.0 };
                //double paral = dot(globalLight, normal);
                //Vector3 color = p_Sphere->getMaterial().albedo;
                
                p_Image->setPixel(i, j, normal_color);
            
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
