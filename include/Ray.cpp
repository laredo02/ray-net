
#include "Ray.h"

Ray::Ray(const Vector3& o, const Vector3& d)
	: m_Origin(o), m_Direction(d)
{
}

const Vector3& Ray::origin() const
{
	return m_Origin;
}

const Vector3& Ray::direction() const
{
	return m_Direction;
}

Vector3 Ray::at(double t) const
{
    return Vector3{ m_Direction*t + m_Origin };
}

std::ostream& operator<<(std::ostream& os, const Ray& ray)
{
	return os << "(O:" << ray.origin() << ", D:" << ray.direction() << ")";
}


