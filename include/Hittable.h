
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
	/*
	 * @brief Destruct a Hittable object, declared virtual so all subclasses can implement their own
	 */
	virtual ~Hittable()=default;

	/*
	 * @brief Compute intersections between a Hittable object and a ray, saves the intersection result on a HitTrace instance
	 * @details
	 * @param[in] object 
	 * @paran[in] ray 
	 * @param[in] tmin 
	 * @param[in] tmax 
	 * @param[out] trace 
	 */
	virtual bool hit(const Ray& ray, const double tmin, const double tmax, HitTrace& trace) const=0;
	virtual const Material& material() const=0;

};




