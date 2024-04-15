
#pragma once

#include "XYZ.h"



class Ray {

public:
	Ray(const Vector3& origin, const Vector3& direction);

	const Vector3& origin() const;
	const Vector3& direction() const;

	Vector3 at(double t) const;

private:
	Vector3 m_Origin;
	Vector3 m_Direction;

};

std::ostream& operator<<(std::ostream& os, const Ray& ray);


