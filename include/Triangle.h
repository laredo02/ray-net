
#pragma once

#include "Hittable.h"
#include "Material.h"
#include "XYZ.h"


/*
 * @
 * @
 * @
 */
class Triangle : public Hittable {

public:
	
	Triangle(const Vector3& p1, const Vector3& p2, const Vector3& p3, shared_ptr<const Material> material);
	~Triangle() override;
	
	
	bool hit(const Ray& ray, const double tmin, const double tmax, HitTrace& trace) const override;
	const Material& material() const override;

private:
	
	Vector3 m_p1;
	Vector3 m_p2;
	Vector3 m_p3;
	 
	//shared_ptr<const Material> m_Material;
	
};
