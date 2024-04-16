
#include "RayNet.h"

#include "Camera.h"


int main(int argc, char** argv) {
    
    Camera camera { {0.0, 0.0, 0.0}, {0.0, 0.0, -1.0}, {0.0, 1.0, 0.0}, 90.0, 3.0, 100, 100 };
    
    for (int i=0; i<10; i++) {
        Ray r = camera.getRay( 0, 0 );
        LOG("Ray ", r)
    }
    
    return (EXIT_SUCCESS);
}

