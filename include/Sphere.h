
#ifndef SPHERE_H
#define SPHERE_H

#include "RayNet.h"

#include "XYZ.h"
#include "Ray.h"
#include "Sphere.h"
#include "Material.h"

class Sphere {

public:
	Sphere(const Vector3& center, const double radius, const Material& material);
	
	double hit(const Ray& ray) const;

	Vector3 getCenter() const;
	double getRadius() const;
	const Material& getMaterial() const;
	
private:
	Vector3 m_Center;
	double m_Radius;
	
	const Material* p_Material;
	
};

#endif /* SPHERE_H */


