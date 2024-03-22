

#include "RayNet.h"
#include "Sphere.h"
#include "Ray.h"

Sphere::Sphere(const Vector3& center, const double radius, const Material& material)
    : m_Center(center), m_Radius(radius), p_Material(&material)
{
}

double Sphere::hit(const Ray& ray) const
{
    
    Vector3 oc = ray.direction()-m_Center;
    double a = ray.direction().normSquared(); // Equivalente a dot(ray.direction(), ray.direction());
    double b = dot(2.0*ray.direction(), oc);
    double c = oc.normSquared()-m_Radius*m_Radius; //Equivalente a dot(oc)-m_Radius;
    
    double d = b*b-4.0*a*c;
    
    if (d >= 0.0) {
        return (-b-sqrt(d))/(2.0*a);
    }
    return -1.0;
    
}

Vector3 Sphere::getCenter() const
{
    return m_Center;
}

double Sphere::getRadius() const
{
    return m_Radius;
}

const Material& Sphere::getMaterial() const
{

    return *p_Material;
}



