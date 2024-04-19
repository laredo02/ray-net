
#include <cstdlib>
#include <thread>

#include "RayNet.h"
#include "XYZ.h"
#include "Camera.h"
#include "Sphere.h"
#include "Image.h"
#include "Renderer.h"
#include "Material.h"
#include "Window.h"
#include "Random.h"

using namespace std;

/*
 * @brief 
 * @details 
 * @param[in] 
 * @param[in] 
 */
int main(int argc, char* argv[]) {

    {
        double aspectRatio=1.7;
        uint32_t width=500;
        uint32_t height=static_cast<size_t>(width/aspectRatio);
        
        auto camera = make_shared<Camera>( Vector3{ 0.0, 0.0, 0.0}, Vector3{ 0.0, 0.0, -1.0}, Vector3{ 0.0, 1.0, 0.0}, 40.0, 1.0, height, width );
        
        auto scene = make_shared<Scene>();        
        scene->addHittable(make_shared<Sphere>( Vector3{0.0, -1000.0, -200.0}, 1000.0,
                make_shared<Material>(Vector3{ 0.0, 1.0, 0.0 } )));
        scene->addHittable(make_shared<Sphere>( Vector3{-4.0, -2.0, -40.0}, 10.0,
                make_shared<Material>(Vector3{ 1.0, 0.0, 1.0 } )));
        scene->addHittable(make_shared<Sphere>(Vector3{1.0, 2.0, -25.0}, 2.1,
                make_shared<Material>( Vector3{ 1.0, 1.0, 0.0 } )));
        scene->addHittable(make_shared<Sphere>( Vector3{4.0, 1.0, -25.0}, 2.0,
                make_shared<Material>( Vector3{ 0.0, 1.0, 1.0 } )));
                        
        auto image = make_shared<Image>( height, width );
        
        Renderer renderer{ camera, scene, image };
        
        Window win{ width, height, "Ray-Net", renderer};
        win.update();
    }

    return EXIT_SUCCESS;
}



