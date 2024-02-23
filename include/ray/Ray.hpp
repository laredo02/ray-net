
#ifndef __HEADER_RAY__
#define __HEADER_RAY__

#include "../math/XYZ.hpp"

using Point = XYZ<double>;
using Vector = XYZ<double>;

class Ray {

public:
	Ray();
	Ray(const Point& origin, const Vector& direction);
	
private:
	Point orig;
	Vector dir;

};

#endif // __HEADER_RAY__


