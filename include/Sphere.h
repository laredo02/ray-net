
#pragma once

#include "RayNet.h"

#include "XYZ.h"
#include "Ray.h"
#include "Sphere.h"
#include "Material.h"
#include "Hittable.h"

/*
 * @class Sphere
 * @brief Subclass of Hittable representing a sphere
 */
class Sphere : public Hittable {

public:
	/*
	 * @brief
	 * @details
	 * @param[in]
	 */
	Sphere(const Vector3& center, const double radius, shared_ptr<const Material> material);
	
	double hit(const Ray& ray) const;
	
	bool hit(const Ray& ray, const double tmin, const double tmax, HitTrace& trace) const override;
	
	

	Vector3 getCenter() const;
	double getRadius() const;
	const Material& material() const override;
	
	~Sphere() override {};
	
private:
	Vector3 m_Center;
	double m_Radius;
	
	shared_ptr<const Material> p_Material;
	
};



