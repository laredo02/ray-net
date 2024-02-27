
#include <iostream>

#include "../math/XYZ.hpp"
#include "Ray.hpp"

Ray::Ray(const Point& o, const Vector& d)
	: m_Origin(o), m_Direction(d)
{
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

Color Ray::color()
{
	Color color = vectorToColor(m_Direction);

	return color;
}

std::ostream& operator<<(std::ostream& os, Ray& ray)
{
	return os << "(O:" << ray.origin() << ", D:" << ray.direction() << ")";
}

