
#include "Scene.h"

void Scene::addHittable(shared_ptr<Hittable> object) {
    m_HittableList.push_back(object);
}

void Scene::empty () {
    m_HittableList.clear();
}

Hittable& Scene::operator[](size_t i) const {
#if BOUNDS_CHECKING == 1
    return *(m_HittableList.at(i));
#else
    return *(m_HittableList[i]);
#endif
}

size_t Scene::size() const {
    return m_HittableList.size();
}

bool Scene::isEmpty() const {
    return m_HittableList.empty();
}

//void addSpheresFromFile(const std::string& filename, std::shared_ptr<Scene> scene) {
//    std::ifstream infile(filename);
//    if (!infile) {
//        std::cerr<<"Error opening file: "<<filename<<std::endl;
//        return;
//    }
//
//    std::string line;
//    while (std::getline(infile, line)) {
//        std::istringstream iss(line);
//        double radius, posX, posY, posZ, colorR, colorG, colorB;
//        if (!(iss>>radius>>posX>>posY>>posZ>>colorR>>colorG>>colorB)) {
//            std::cerr<<"Error reading line: "<<line<<std::endl;
//            continue;
//        }
//
//        Vector3 position{posX, posY, posZ};
//        Vector3 color{colorR, colorG, colorB};
//        auto material=std::make_shared<Material>(color);
//        auto sphere=std::make_shared<Sphere>(position, radius, material);
//
//        scene->addHittable(sphere);
//    }
//
//    infile.close();
//}