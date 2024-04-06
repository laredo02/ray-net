
#include <stdlib.h>
#include <iostream>

#include "XYZ.h"

int main(int argc, char* argv[]) {
    
    std::cout << "Rotation Test -- Begin" << std::endl;
    
    Vector3 vec1 { 1.0, 0.0, 0.0 };
    std::cout << vec1 << std::endl;
    vec1.rotateX(Vector3{0.0, 0.0, 0.0}, 90.0);    
    std::cout << vec1 << std::endl;
    
    Vector3 vec2 { 0.0, 1.0, 0.0 };
    std::cout << vec2 << std::endl;
    vec2.rotateX(Vector3{0.0, 0.0, 0.0}, 90.0);    
    std::cout << vec2 << std::endl;
    
    Vector3 vec3 { 0.0, 0.0, 1.0 };
    std::cout << vec3 << std::endl;
    vec3.rotateX(Vector3{0.0, 0.0, 0.0}, 90.0);
    std::cout << vec3 << std::endl;
    
    std::cout << "Rotation Test -- End" << std::endl;
    
    return (EXIT_SUCCESS);
}

