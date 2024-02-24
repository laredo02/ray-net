
#ifndef __HEADER_COLOR__
#define __HEADER_COLOR__

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

using Color = RGB_Color<uint8_t>;

#endif // __HEADER_COLOR__



