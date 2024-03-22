
#include "RayNet.h"

#include "Renderer.h"

Renderer::Renderer(const Camera* camera, const Sphere* sphere)
    : p_Camera(camera), p_Sphere(sphere)
{ 
}


void Renderer::render(Image& image)
{
    
    const vector<Ray> rays = p_Camera->computeRays(image.width());
    
    for (size_t i{0}; i<image.height(); i++)
    {
        for (size_t j{0}; j<image.width(); j++)
        {
            Ray ray = rays.at(i*image.width() + j);
            double t = p_Sphere->hit( ray );
            if (t >= 0.0) {                                                 // Draw hit
                
                Vector3 normal = (ray.at(t) - p_Sphere->getCenter()).unit();
                Vector3 globalLight { -1.0, 0.0, 0.0}; 
                globalLight.toUnit();
                
                double proj = dot(normal, globalLight);
                
                //proj = (proj + 1.0)/2.0;
                //cout << proj << endl;   
                
                Vector3 color = (1-proj)*p_Sphere->getMaterial().albedo;
                
                image.setPixel(i, j, color);
            } else {                                                        // Draw miss
                image.setPixel(i, j, Vector3{ 0.0, 0.0, 0.0 } );
            }
        }
    }
    
}





