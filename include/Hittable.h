
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
	virtual ~Hittable()=default;
	
	virtual bool hit(const Ray& ray, const double tmin, const double tmax, HitTrace& trace) const=0;
	virtual const Material& material() const=0;
};




