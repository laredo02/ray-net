
#include <memory>

#include "Camera.h"
#include "Scene.h"
#include "Sphere.h"
#include "Material.h"
#include "Image.h"
#include "Renderer.h"
#include "Window.h"

using std::shared_ptr;
using std::make_shared;

void run_real_time() {

    double aspectRatio=ASPECT_RATIO;
    uint32_t width=IMAGE_WIDTH;
    uint32_t height=static_cast<size_t> (width/aspectRatio);

    auto camera0=make_shared<Camera>(Vector3{0.0, 10.0, 0.0}, Vector3{0.0, 0.0, -1.0}
                                     .unit(), Vector3 {
                                     0.0, 1.0, 0.0
    }, FOV, 2.0, height, width);
    auto scene=make_shared<Scene>();

//    scene->addHittable(make_shared<Sphere>(Vector3{0.0, -500.0, 0.0}, 499.0,
//                                           make_shared<Material>(Vector3{0.0, 0.5, 0.0})));
//
//    scene->addHittable(make_shared<Sphere>(Vector3{10.0, 9.0, -40.0}, 10.0,
//                                           make_shared<Material>(Vector3{1.0, 0.0, 1.0})));
//
//    scene->addHittable(make_shared<Sphere>(Vector3{-11.0, 9.0, -40.0}, 10.0,
//                                           make_shared<Material>(Vector3{0.0, 0.0, 1.0})));
//
//    scene->addHittable(make_shared<Sphere>(Vector3{-10.0, 3.0, -20.0}, 4.0,
//                                           make_shared<Material>(Vector3{1.0, 1.0, 0.0})));
                                           
    
    for (int i=0; i<50; i++) {    
        Vector3 location { randomDouble(-50.0, 50.0), randomDouble(-50.0, 50.0), randomDouble(-50.0, -150.0) };
        Vector3 color;
        
        int random = randomInt(0, 5);
        if (random == 0) {
            color = Vector3{ 1.0, 0.0, 0.0 };
        } else {
            color = Vector3{ randomDouble(0.0, 1.0), randomDouble(0.0, 1.0), randomDouble(0.0, 1.0) };
        }
        
                scene->addHittable( make_shared<Sphere>(location, randomDouble(1.0, 15.0), make_shared<Material>(color)) );
    }                                           


    auto image=make_shared<Image>(height, width);
    auto renderer=make_shared<Renderer>(camera0, scene, image);
    Window win{ "Ray-Net", width, height, renderer};
    win.update();

}




void generate_depth_dataset() {
    
    double aspectRatio=ASPECT_RATIO;
    uint32_t width=IMAGE_WIDTH;
    
    uint32_t height=static_cast<size_t> (width/aspectRatio);
    auto camera0=make_shared<Camera>(Vector3{0.0, 0.0, 0.0}, Vector3{0.0, 0.0, -1.0} .unit(), Vector3 {0.0, 1.0, 0.0}, FOV, 2.0, height, width);
    
    auto scene=make_shared<Scene>();
    std::ofstream labels{"datasets/red_ball/aa-labels.txt"};
    
    for (int i=0; i<10; i++) {    
        Vector3 location { randomDouble(-5.0, 5.0), randomDouble(0.0, 5.0), randomDouble(-5.0, -15.0) };
        Vector3 color;
        
        int random = randomInt(0, 5);
        if (random == 0) {
            color = Vector3{ 1.0, 0.0, 0.0 };
            labels << "1\n";
        } else {
            color = Vector3{ randomDouble(0.0, 1.0), randomDouble(0.0, 1.0), randomDouble(0.0, 1.0) };
            labels << "0\n";
        }
        
        scene->addHittable(make_shared<Sphere>(Vector3{0.0, -500.0, 0.0}, 499.0, make_shared<Material>(Vector3{0.1, 0.7, 0.1})));
        scene->addHittable( make_shared<Sphere>(location, randomDouble(1.0, 5.0), make_shared<Material>(color)) );
        auto image=make_shared<Image>(height, width);
        auto renderer=make_shared<Renderer>(camera0, scene, image);
        renderer->render();
        renderer->saveRenderToFile("datasets/red_ball/image" + std::to_string(i) + ".ppm");
        scene->empty();
    }
    
    labels.close();

}

void generate_superres_dataset() {
    
    double aspectRatio=ASPECT_RATIO;
    uint32_t width=IMAGE_WIDTH;
    uint32_t height=static_cast<size_t> (width/aspectRatio);
    auto camera0=make_shared<Camera>(Vector3{0.0, 0.0, 0.0}, Vector3{0.0, 0.0, -1.0}.unit(), Vector3 {0.0, 1.0, 0.0}, FOV, 2.0, height, width);
    auto scene=make_shared<Scene>();
    
    std::ofstream labels{"datasets/red_ball/aa-labels.txt"};
    
    for (int i=0; i<10; i++) {    
        Vector3 location { randomDouble(-5.0, 5.0), randomDouble(0.0, 5.0), randomDouble(-5.0, -15.0) };
        Vector3 color;
        
        int random = randomInt(0, 5);
        if (random == 0) {
            color = Vector3{ 1.0, 0.0, 0.0 };
            labels << "1\n";
        } else {
            color = Vector3{ randomDouble(0.0, 1.0), randomDouble(0.0, 1.0), randomDouble(0.0, 1.0) };
            labels << "0\n";
        }
        
        scene->addHittable(make_shared<Sphere>(Vector3{0.0, -500.0, 0.0}, 499.0, make_shared<Material>(Vector3{0.1, 0.7, 0.1})));
        scene->addHittable( make_shared<Sphere>(location, randomDouble(1.0, 5.0), make_shared<Material>(color)) );
        auto image=make_shared<Image>(height, width);
        auto renderer=make_shared<Renderer>(camera0, scene, image);
        renderer->render();
        renderer->saveRenderToFile("datasets/red_ball/image" + std::to_string(i) + ".ppm");
        scene->empty();
    }
    
    labels.close();

}

void createSingleRender() {
        double aspectRatio=ASPECT_RATIO;
    uint32_t width=IMAGE_WIDTH;
    uint32_t height=static_cast<size_t> (width/aspectRatio);

    auto camera0=make_shared<Camera>(Vector3{0.0, 10.0, 0.0}, Vector3{0.0, 0.0, -1.0}
                                     .unit(), Vector3 {
                                     0.0, 1.0, 0.0
    }, FOV, 2.0, height, width);
    auto scene=make_shared<Scene>();

    scene->addHittable(make_shared<Sphere>(Vector3{0.0, -500.0, 0.0}, 499.0,
                                           make_shared<Material>(Vector3{0.0, 0.5, 0.0})));

    scene->addHittable(make_shared<Sphere>(Vector3{10.0, 9.0, -40.0}, 10.0,
                                           make_shared<Material>(Vector3{1.0, 0.0, 1.0})));

    scene->addHittable(make_shared<Sphere>(Vector3{-10.0, 9.0, -40.0}, 10.0,
                                           make_shared<Material>(Vector3{0.0, 1.0, 1.0})));

    scene->addHittable(make_shared<Sphere>(Vector3{-10.0, 3.0, -20.0}, 4.0,
                                           make_shared<Material>(Vector3{1.0, 1.0, 0.0})));

                                       

    auto image=make_shared<Image>(height, width);
    auto renderer=make_shared<Renderer>(camera0, scene, image);
    renderer->render();
    renderer->saveRenderToFile(FILENAME);

    
}

/*
 * @brief 
 * @details 
 * @param[in] 
 * @param[in] 
 */
int main(int argc, char* argv[]) {
    
    //createSingleRender();

#if RENDER_REAL_TIME == 1
    run_real_time();
#endif
    
#if GENERATE_DEPTH_DATASET == 1
    generate_depth_dataset();
#endif
    
    
    return EXIT_SUCCESS;
}



