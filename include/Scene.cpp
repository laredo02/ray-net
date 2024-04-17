

#include "Scene.h"


Scene::Scene(shared_ptr<Camera> camera) {
    
}

void Scene::addHittable(shared_ptr<Hittable> object) {
    m_HittableList.push_back(object);   
}

Hittable* Scene::operator[](size_t i) {
    
    
    return nullptr;
}


