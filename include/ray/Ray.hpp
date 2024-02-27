
#ifndef __HEADER_RAY__
#define __HEADER_RAY__

#include "../math/XYZ.hpp"
#include "RGB_Color.hpp"

class Ray {

public:
	Ray(const Point& origin, const Vector& direction);

	Point origin() const;
	Vector direction() const;

	Point at(double t) const;
	Color color();

private:
	Point m_Origin;
	Vector m_Direction;

};

std::ostream& operator<<(std::ostream& os, Ray& ray);

#endif // __HEADER_RAY__


