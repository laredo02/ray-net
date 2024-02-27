
#include "RGB_Color.hpp"

Color vectorToColor(const Vector& v)
{
	Vector unit = v.unit();

	Color ret { 120.0, 160.0, unit.y()*255.0 };

	return ret;
}

