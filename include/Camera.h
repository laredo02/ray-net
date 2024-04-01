
#ifndef CAMERA_H
#define CAMERA_H

#include "XYZ.h"
#include "Ray.h"
#include "RayNet.h"

class Camera {

public:
	Camera(const Vector3& center, const Vector3& direction, const Vector3& up, double vfov, double flen, double aspect_ratio);
	const vector<Ray>& computeRays(const size_t width) const;
	
	void translate(Vector3& delta);
	void rotate(double xrot, double yrot, double zrot);
	
	void setCenter(const Vector3& center);
	void setDirection(const Vector3& center);
	void setUp(const Vector3& center);
	void setVFov(double vFov);
	void setFLen(double fLen);
	void setAspectRatio(double aspectRatio);
	
	const Vector3& getCenter() const;
	const Vector3& getDirection() const;
	const Vector3& getUp() const;
	double getVFov() const;
	double getFLen() const;
	double getAspectRatio() const;
	
private:
	Vector3 m_Center;
	Vector3 m_Direction;
	Vector3 m_Up;
	
	double m_VFov;
	double m_FLen;
	double m_AspectRatio;
	
	double m_UNorm;
	double m_VNorm;
		
	mutable vector<Ray> m_Rays;
	
};

#endif /* CAMERA_H */

