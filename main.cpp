
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
        double aspectRatio=16.0/9.0;
        uint32_t width=720;
        uint32_t height=static_cast<size_t>(width/aspectRatio);
        
        
        auto camera0 = make_shared<Camera>( Vector3{ 0.0, 0.0, 0.0}, Vector3{ 0.0, 0.0, -1.0}.unit(), Vector3{ 0.0, 1.0, 0.0}, 90.0, 2.0, height, width );
//        auto camera0 = make_shared<Camera>( Vector3{ 0.0, 1.0, 0.0}, Vector3{ -1, 0.0, 0.0}.unit(), Vector3{ 0.0, 1.0, 0.0}, 90.0, 2.0, height, width );
//        auto camera1 = make_shared<Camera>( Vector3{ 30.0, 0.0, -20.0}, Vector3{ -1.0, 0.0, 0.0}, Vector3{ 0.0, 1.0, 0.0}, 40.0, 1.0, height, width );
//        auto camera2 = make_shared<Camera>( Vector3{ -30.0, 0.0, -20.0}, Vector3{ 1.0, 0.0, 0.0}, Vector3{ 0.0, 1.0, 0.0}, 40.0, 1.0, height, width );
//        auto camera3 = make_shared<Camera>( Vector3{ 0.0, 0.0, -100.0}, Vector3{ 0.0, 0.0, 1.0}, Vector3{ 0.0, 1.0, 0.0}, 40.0, 1.0, height, width );
        
        auto scene = make_shared<Scene>();
        
        scene->addHittable(make_shared<Sphere>( Vector3{0.0, -1000.0, -10.0}, 999.0,
                make_shared<Material>(Vector3{ 1.0, 0.0, 1.0 } )));
        scene->addHittable(make_shared<Sphere>(Vector3{10.0, 10.0, -40.0}, 10.0,
                make_shared<Material>( Vector3{ 1.0, 0.0, 0.0 } )));
        scene->addHittable(make_shared<Sphere>( Vector3{-10.0, 10.0, -40.0}, 10.0,
                make_shared<Material>(Vector3{ 0.0, 0.0, 1.0 } )));
        scene->addHittable(make_shared<Sphere>( Vector3{0.0, 0.0, -25.0}, 3.0,
                make_shared<Material>( Vector3{ 0.0, 1.0, 1.0 } )));
        
                        
        auto image = make_shared<Image>( height, width );
        
        Renderer renderer{ camera0, scene, image };
        
        Window win{ width, height, "Ray-Net", renderer};
        win.update();
    }

    return EXIT_SUCCESS;
}



