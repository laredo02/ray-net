
#include <memory>
#include "Triangle.h"


Triangle::Triangle(const Vector3& p1, const Vector3& p2, const Vector3& p3, shared_ptr<const Material> material) : m_p1{p1}, m_p2{p2} , m_p3{p3}, Hittable{material} { }

Triangle::~Triangle() = default;


bool Triangle::hit(const Ray& ray, const double tmin, const double tmax, HitTrace& trace) const {
    return false;
}

const Material& Triangle::material() const {
    return *p_Material;
}


