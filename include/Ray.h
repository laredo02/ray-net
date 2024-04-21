
#pragma once

#include "XYZ.h"

/*
 * @class Ray of the form: R(t) = O + t*D
 * @brief This object makes Ray Tracing possible, it is crucial for computing intersection with 3D objects
 */
class Ray {

public:
	Ray(const Vector3& origin, const Vector3& direction);

	const Vector3& origin() const;
	const Vector3& direction() const;

	Vector3 at(const double t) const;

private:
	Vector3 m_Origin;
	Vector3 m_Direction;

};

std::ostream& operator<<(std::ostream& os, const Ray& ray);
