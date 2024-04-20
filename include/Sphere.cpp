

#include "RayNet.h"
#include "Sphere.h"
#include "Ray.h"

Sphere::Sphere(const Vector3& center, const double radius, shared_ptr<const Material> material)
        : m_Center(center), m_Radius(radius), p_Material(material) {}

Sphere::~Sphere() {};

bool Sphere::hit(const Ray& ray, const double tmin, const double tmax, HitTrace& trace) const {
    
    Vector3 oc = ray.origin()-m_Center;
    double a = ray.direction().normSquared(); // Equivalente a dot(ray.direction(), ray.direction());
    double b = dot(2.0*ray.direction(), oc);
    double c = oc.normSquared()-m_Radius*m_Radius; //Equivalente a dot(oc)-m_Radius;
    double d = b*b-4.0*a*c;

    if (d <= 0.0) {
        return false;
    }
    double t = (-b-sqrt(d))/(2.0*a);
    
    if (!CONTAINS(tmin, tmax, t)) {
        return false;
    }
    
    
    trace.m_HitDistance = t;
    trace.m_Point = ray.at(t);
    trace.m_Normal = (ray.at(trace.m_HitDistance)-m_Center).unit(); // Norm optimization
    trace.p_Material = p_Material;
    
    trace.frontFace = true; // TODO
    
    return true;
}

Vector3 Sphere::center() const
{
    return m_Center;
}

double Sphere::radius() const
{
    return m_Radius;
}

const Material& Sphere::material() const
{

    return *p_Material;
}



