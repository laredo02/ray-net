
#pragma once

#include "RayNet.h"
#include "XYZ.h"
#include "Ray.h"
#include "Hittable.h"
#include "Material.h"
#include "HitTrace.h"



/*
 * @class Hittable
 * @brief Abstract class that represents a Hittable object, meaning an object that can intersect with a ray
 */
class Hittable {

public:
	Hittable(shared_ptr<const Material> material);
	virtual ~Hittable()=default;
	
	virtual bool hit(const Ray& ray, const double tmin, const double tmax, HitTrace& trace) const=0;
	virtual const Material& material() const=0;
	
protected:
	shared_ptr<const Material> p_Material;
	
};




