
#pragma once

#include "RayNet.h"

#include "XYZ.h"
#include "Ray.h"
#include "Sphere.h"
#include "Material.h"
#include "Hittable.h"



class Sphere : public Hittable {

public:
	Sphere(const Vector3& center, const double radius, shared_ptr<const Material> material);
	~Sphere() override;

	bool hit(const Ray& ray, const double tmin, const double tmax, HitTrace& trace) const override;

	Vector3 center() const;
	double radius() const;
	const Material& material() const override;
	
private:
	Vector3 m_Center;
	double m_Radius;
	
	//shared_ptr<const Material> p_Material;

};



