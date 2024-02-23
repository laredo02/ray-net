
#include <iostream>

#include "Ray.hpp"

Ray::Ray(const Point& o, const Vector& d)
	: m_Origin(o), m_Direction(d)
{
	std::cout << "RAYYY" << std::endl;
}

inline Point Ray::origin() const
{
	return m_Origin;
}

inline Vector Ray::direction() const
{
	return m_Direction;
}

Point Ray::at(double t) const
{
	Point p = m_Direction*t + m_Origin;
	return p;
}

std::ostream& operator<<(std::ostream& os, Ray& ray)
{
	return os << "(O:" << ray.origin() << ", D:" << ray.direction() << ")";
}



