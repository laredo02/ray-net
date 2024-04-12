
#pragma once



class HitTrace {
	Vector3 point;
	Vector3 normal;
	Vector3 color;
};



class Hittable {

protected:
	virtual ~Hittable();
	virtual void hit(const Hittable object, const Ray& ray, const double tmin, const double tmax, HitTrace& trace);
};




