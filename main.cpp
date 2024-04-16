
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

using namespace std;

int main(int argc, char* argv[]) {

    {
        double aspectRatio=1.0;
        uint32_t width=1000;
        uint32_t height=static_cast<size_t> (width/aspectRatio);

        Camera camera{ Vector3{ 0.0, 0.0, 0.0}, Vector3{ 0.0, 0.0, -1.0}, Vector3{ 0.0, 1.0, 0.0}, 80.0, 2.0, height, width};
        Material material{ Vector3{ 1.0, 0.0, 0.0}};
        Sphere sphere{ Vector3{ 0.0, 0.0, -20.0}, 5.0, material};
        Image image{ height, width};

        Renderer renderer{ &camera, &sphere, &image};
        Window win{ width, height, "Ray-Net", renderer};
        win.update();
    }

    return EXIT_SUCCESS;
}



