
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
	Vector u = unit_vector(m_Direction);	// values from 0 to 1
	std::cout << "UNIT: " << u << '\n';
	Color c { 255.0*u.y()*u.y(), 255.0*u.y()*u.y(), 255.0*u.z()*u.z() };
	std::cout << "COLOR: " << (int) c.red << ' ' << (int) c.green << ' ' << (int) c.blue << "\n\n";
	return c;
}

std::ostream& operator<<(std::ostream& os, Ray& ray)
{
	return os << "(O:" << ray.origin() << ", D:" << ray.direction() << ")";
}


