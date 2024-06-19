
#pragma once

#include "XYZ.h"
#include "Ray.h"
#include "RayNet.h"



class Camera {

public:
	Camera(const Vector3& center, const Vector3& direction, const Vector3& up,
		double vfov, double flen, uint32_t height, uint32_t width);

private:
	void computeRayParameters();

public:
	const Vector3& deltaU() const;
	const Vector3& deltaV() const;
	const Vector3& P00() const;
	
	Ray getRay(const int row, const int col) const;
	Ray getRandomRay(const int row, const int col) const;
	void getRayList(const int row, const int col, std::vector<Ray>& ray_list, const int grid_size) const;

	void translate(const Vector3& delta);
	void pitch(const double theta);
	void yaw(const double theta);
	void roll(const double theta);

	const Vector3& center() const;
	const Vector3& direction() const;
	const Vector3& up() const;

	double vFov() const;
	double fLen() const;
	uint32_t width() const;
	uint32_t height() const;
	double aspectRatio() const;
	
private:
	Vector3 m_Center;
	Vector3 m_Direction;
	Vector3 m_Up;

	double m_UNorm;
	double m_VNorm;
	Vector3 m_DeltaU;
	Vector3 m_DeltaV;
	Vector3 m_P00;

	double m_VFov;
	double m_FLen;
	uint32_t m_Width;
	uint32_t m_Height;
	double m_AspectRatio;
	
};


