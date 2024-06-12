
#pragma once

#include <XYZ.h>

/*
 * Helper function for simple interpolations
 */
inline double interpolate(double min, double max, double factor) {
	return min + factor*(max - min);
}


/*
 * Interpolates between to colors, factor is a value between 0 and 1. 0 = color1, 1 = color2, (0, 1) = something between 0 and 1
 */
Vector3 interpolateColors(const Vector3& color1, const Vector3& color2, double factor) {
	auto r = interpolate(color1[0], color2[0], factor);
	auto g = interpolate(color1[1], color2[1], factor);
	auto b = interpolate(color1[2], color2[2], factor);
	return Vector3{ r, g, b };
}
