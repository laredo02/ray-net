
#ifndef __HEADER_COLOR__
#define __HEADER_COLOR__

#include "../math/XYZ.hpp"

// TO-DO: Add range value (size_t)
template<typename T> struct RGB_Color {
	T red;
	T green;
	T blue;

	RGB_Color(T r, T g, T b)
		: red(r), green(g), blue(b)
	{
	}

};

template<typename T> std::ostream& operator<<(std::ostream& os, RGB_Color<T> color)
{
	return os << "[r: " << color.red << ", g: " << color.green << ", b: " << color.blue << ']';
}

using Color = RGB_Color<double>;

Color vectorToColor(const Vector& v);


#endif // __HEADER_COLOR__


