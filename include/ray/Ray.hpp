
#ifndef __HEADER_RAY__
#define __HEADER_RAY__

#include "../math/XYZ.hpp"

class Ray {

public:
	Ray(const Point& origin=Point(0.0, 0.0, 0.0), const Vector& direction=Vector(0.0, 0.0, 0.0));

	Point origin() const;
	Vector direction() const;

	Point at(double t) const;
	
private:
	Point m_Origin;
	Vector m_Direction;

};

std::ostream& operator<<(std::ostream& os, Ray& ray);

#endif // __HEADER_RAY__


