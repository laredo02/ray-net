
#include "RayNet.h"

#include "Renderer.h"

Renderer::Renderer(Camera* camera, const Sphere* sphere, Image* img)
    : p_Camera(camera), p_Sphere(sphere), p_Image(img)
{
}

const Image& Renderer::getImage() const {
    return *p_Image;
}

void Renderer::render() const
{
    
    const vector<Ray> rays = p_Camera->computeRays(p_Image->width());
    
    for (size_t i{0}; i<p_Image->height(); i++)
    {
        for (size_t j{0}; j<p_Image->width(); j++)
        {
            Ray ray = rays.at(i*p_Image->width() + j);
            double t = p_Sphere->hit( ray );
            if (t >= 0.0) {                                                 // Draw hit                
                Vector3 normal = (ray.at(t) - p_Sphere->getCenter()).unit();
                Vector3 color = p_Sphere->getMaterial().albedo;
                p_Image->setPixel(i, j, color);
            } else {                                                        // Draw miss
                p_Image->setPixel(i, j, Vector3{ 0.32, 0.3, 0.5 } );
            }
        }
    }
    
}

void Renderer::saveRenderToFile(const string& name) const {
    p_Image->saveToFile(name);
}

Camera& Renderer::getCamera() const {
    return *p_Camera;
}
