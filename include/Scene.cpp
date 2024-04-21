
#include "Scene.h"

void Scene::addHittable(shared_ptr<Hittable> object) {
    m_HittableList.push_back(object);
}

Hittable& Scene::operator[](size_t i) const {
#if BOUNDS_CHECKING == 1
    return *(m_HittableList.at(i));
#else
    return m_HittableList[i];
#endif
}

size_t Scene::size() const {
    return m_HittableList.size();
}

bool Scene::isEmpty() const {
    return m_HittableList.empty();
}
