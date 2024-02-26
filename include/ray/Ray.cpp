
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
	Vector u = m_Direction.unit();	// values from 0 to 1
	Color c { static_cast<uint8_t>(.0*u.y()),
		static_cast<uint8_t>(255.0*u.y()),
		static_cast<uint8_t>(255.0*u.z()) };
	Color purple { 0xdd, 0x2f, 0xff  };
	
	return purple;
}

std::ostream& operator<<(std::ostream& os, Ray& ray)
{
	return os << "(O:" << ray.origin() << ", D:" << ray.direction() << ")";
}


