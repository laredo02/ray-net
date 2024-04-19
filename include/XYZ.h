
#pragma once

#include "RayNet.h"
#include "Random.h"



template<typename T> struct XYZ {

public:

	XYZ();
	XYZ(T x, T y, T z);

	const T& x() const;
	const T& y() const;
	const T& z() const;
	
	static XYZ<T> random(double min, double max);

	XYZ<T> operator-() const;
	T operator[](size_t i) const;
	T& operator[](size_t i);

	XYZ<T>& operator+=(const XYZ<T>& xyz);
	XYZ<T>& operator+=(const T& value);

	XYZ<T>& operator-=(const XYZ<T>& xyz);
	XYZ<T>& operator-=(const T& value);

	XYZ<T>& operator*=(const XYZ<T>& xyz);
	XYZ<T>& operator*=(const T& value);

	XYZ<T>& operator/=(const XYZ<T>& xyz);
	XYZ<T>& operator/=(const T& value);

	template<typename U> friend XYZ<U> operator+(const XYZ<U>& a, const XYZ<U>& b);
	template<typename U> friend XYZ<U> operator+(const XYZ<U>& a, const U b);
	template<typename U> friend XYZ<U> operator+(const U a, const XYZ<U>& b);

	template<typename U> friend XYZ<U> operator-(const XYZ<U>& a, const XYZ<U>& b);
	template<typename U> friend XYZ<U> operator-(const XYZ<U>& a, const U b);
	template<typename U> friend XYZ<U> operator-(const U a, const XYZ<U>& b);

	template<typename U> friend XYZ<U> operator*(const XYZ<U>& a, const XYZ<U>& b);
	template<typename U> friend XYZ<U> operator*(const XYZ<U>& a, U b);
	template<typename U> friend XYZ<U> operator*(const U a, const XYZ<U>& b);

	template<typename U> friend XYZ<U> operator/(const XYZ<U>& a, const XYZ<U>& b);
	template<typename U> friend XYZ<U> operator/(const XYZ<U>& a, U b);

	T norm() const;
	T normSquared() const;
	void toUnit();
	XYZ<T> unit() const;

	//	template<typename U> friend XYZ<U> abs(const XYZ<U>& v);
	template<typename U> friend U dot(const XYZ<U>& u, const XYZ<U>& v);
	template<typename U> friend XYZ<U> cross(const XYZ<U>& u, const XYZ<U>& v);

	XYZ<T>& rotateX(const XYZ<T>& center, const double alpha);
	XYZ<T>& rotateY(const XYZ<T>& center, const double beta);
	XYZ<T>& rotateZ(const XYZ<T>& center, const double gamma);
	XYZ<T>& rotateXYZ(const XYZ<T>& center, const double alpha, const double beta, const double gamma);
	XYZ<T>& rotateAAxis(const XYZ<T>& axisDir, const double theta);

	template<typename U> friend std::ostream& operator<<(std::ostream& out, const XYZ<U>& xyz);

private:

	T m_xyz[3];

};


using Vector3=XYZ<double>;


template<typename T> XYZ<T>::XYZ() : m_xyz{(T) 0, (T) 0, (T) 0}
{
}
template<typename T> XYZ<T>::XYZ(T x, T y, T z) : m_xyz{x, y, z}
{
}

template<typename T> static XYZ<T> random(double min, double max) {
	return XYZ<T>{ randomDouble(min, max), randomDouble(min, max), randomDouble(min, max) };
}

template<typename T> const T& XYZ<T>::x() const {
	return m_xyz[0];
}

template<typename T> const T& XYZ<T>::y() const {
	return m_xyz[1];
}

template<typename T> const T& XYZ<T>::z() const {
	return m_xyz[2];
}

template<typename T> XYZ<T> XYZ<T>::operator-() const {
	return XYZ<T>{ -m_xyz[0], -m_xyz[1], -m_xyz[2]};
}

template<typename T> T XYZ<T>::operator[](size_t i) const {
	return m_xyz[i];
}

template<typename T> T& XYZ<T>::operator[](size_t i) {
	return m_xyz[i];
}

template<typename T> inline XYZ<T>& XYZ<T>::operator+=(const XYZ<T>& xyz) {
	m_xyz[0]+=xyz.m_xyz[0];
	m_xyz[1]+=xyz.m_xyz[1];
	m_xyz[2]+=xyz.m_xyz[2];
	return *this;
}

template<typename T> inline XYZ<T>& XYZ<T>::operator+=(const T& value) {
	m_xyz[0]+=value;
	m_xyz[1]+=value;
	m_xyz[2]+=value;
	return *this;
}

template<typename T> inline XYZ<T>& XYZ<T>::operator-=(const XYZ<T>& xyz) {
	m_xyz[0]-=xyz.m_xyz[0];
	m_xyz[1]-=xyz.m_xyz[1];
	m_xyz[2]-=xyz.m_xyz[2];
	return *this;
}

template<typename T> inline XYZ<T>& XYZ<T>::operator-=(const T& value) {
	m_xyz[0]-=value;
	m_xyz[1]-=value;
	m_xyz[2]-=value;
	return *this;
}

template<typename T> inline XYZ<T>& XYZ<T>::operator*=(const XYZ<T>& xyz) {
	m_xyz[0]*=xyz.m_xyz[0];
	m_xyz[1]*=xyz.m_xyz[1];
	m_xyz[2]*=xyz.m_xyz[2];
	return *this;
}

template<typename T> inline XYZ<T>& XYZ<T>::operator*=(const T& value) {
	m_xyz[0]*=value;
	m_xyz[1]*=value;
	m_xyz[2]*=value;
	return *this;
}

template<typename T> inline XYZ<T>& XYZ<T>::operator/=(const XYZ<T>& xyz) {
	m_xyz[0]/=xyz.m_xyz[0];
	m_xyz[1]/=xyz.m_xyz[1];
	m_xyz[2]/=xyz.m_xyz[2];
	return *this;
}

template<typename T> inline XYZ<T>& XYZ<T>::operator/=(const T& value) {
	m_xyz[0]/=value;
	m_xyz[1]/=value;
	m_xyz[2]/=value;
	return *this;
}

template<typename U> inline XYZ<U> operator+(const XYZ<U>& a, const XYZ<U>& b) {
	return XYZ<U>(a.m_xyz[0] + b.m_xyz[0], a.m_xyz[1] + b.m_xyz[1], a.m_xyz[2] + b.m_xyz[2]);
}

template<typename U> inline XYZ<U> operator+(const XYZ<U>& a, const U b) {
	return XYZ<U>(a.m_xyz[0] + b, a.m_xyz[1] + b, a.m_xyz[2] + b);
}

template<typename U> inline XYZ<U> operator+(const U a, const XYZ<U>& b) {
	return XYZ<U>(a + b.m_xyz[0], a + b.m_xyz[1], a + b.m_xyz[2]);
}

template<typename U> inline XYZ<U> operator-(const XYZ<U>& a, const XYZ<U>& b) {
	return XYZ<U>(a.m_xyz[0] - b.m_xyz[0], a.m_xyz[1] - b.m_xyz[1], a.m_xyz[2] - b.m_xyz[2]);
}

template<typename U> inline XYZ<U> operator-(const XYZ<U>& a, const U b) {
	return XYZ<U>(a.m_xyz[0] + b, a.m_xyz[1] + b, a.m_xyz[2] + b);
}

template<typename U> inline XYZ<U> operator-(const U a, const XYZ<U>& b) {
	return XYZ<U>(a + b.m_xyz[0], a + b.m_xyz[1], a + b.m_xyz[2]);
}

template<typename U> inline XYZ<U> operator*(const XYZ<U>& a, const XYZ<U>& b) {
	return XYZ<U>(a.m_xyz[0] * b.m_xyz[0], a.m_xyz[1] * b.m_xyz[1], a.m_xyz[2] * b.m_xyz[2]);
}

template<typename U> inline XYZ<U> operator*(const XYZ<U>& a, U b) {
	return XYZ<U>(a.m_xyz[0] * b, a.m_xyz[1] * b, a.m_xyz[2] * b);
}

template<typename U> inline XYZ<U> operator*(const U a, const XYZ<U>& b) {
	return XYZ<U>(a * b.m_xyz[0], a * b.m_xyz[1], a * b.m_xyz[2]);
}

template<typename U> inline XYZ<U> operator/(const XYZ<U>& a, const XYZ<U>& b) {
	return XYZ<U>(a.m_xyz[0] / b.m_xyz[0], a.m_xyz[1] / b.m_xyz[1], a.m_xyz[2] / b.m_xyz[2]);
}

template<typename U> inline XYZ<U> operator/(const XYZ<U>& a, U b) {
	return XYZ<U>(a.m_xyz[0] / b, a.m_xyz[1] / b, a.m_xyz[2] / b);
}

template<typename T> T XYZ<T>::norm() const {
	return static_cast<T> (std::sqrt(m_xyz[0] * m_xyz[0] + m_xyz[1] * m_xyz[1] + m_xyz[2] * m_xyz[2]));
}

template<typename T> inline T XYZ<T>::normSquared() const {
	return m_xyz[0] * m_xyz[0] + m_xyz[1] * m_xyz[1] + m_xyz[2] * m_xyz[2];
}

template<typename T> void XYZ<T>::toUnit() {
	T norm=this->norm();
	if (norm != 0.0) {
		m_xyz[0]/=norm;
		m_xyz[1]/=norm;
		m_xyz[2]/=norm;
	} else {
		m_xyz[0]=0.0;
		m_xyz[1]=0.0;
		m_xyz[2]=0.0;
	}
}

template<typename U> inline XYZ<U> XYZ<U>::unit() const {
	U norm=this->norm();
	if (norm != 0.0)
		return XYZ<U>(m_xyz[0] / norm, m_xyz[1] / norm, m_xyz[2] / norm);
	else return XYZ<U>(0.0, 0.0, 0.0);
}

template<typename U> inline U dot(const XYZ<U>& u, const XYZ<U>& v) {
	return u.m_xyz[0] * v.m_xyz[0] + u.m_xyz[1] * v.m_xyz[1] + u.m_xyz[2] * v.m_xyz[2];
}

template<typename U> inline XYZ<U> cross(const XYZ<U>& u, const XYZ<U>& v) {
	return XYZ<U>{
				u.m_xyz[1] * v.m_xyz[2] - u.m_xyz[2] * v.m_xyz[1],
				u.m_xyz[2] * v.m_xyz[0] - u.m_xyz[0] * v.m_xyz[2],
				u.m_xyz[0] * v.m_xyz[1] - u.m_xyz[1] * v.m_xyz[0]};
}

template<typename T> XYZ<T>& XYZ<T>::rotateX(const XYZ<T>& center, const double theta) {
	double thetaRad=DEG_TO_RAD(theta);
	Vector3 centerToPoint{ *this -center};
	m_xyz[0]=center.x() + dot(centerToPoint, XYZ<T>{1.0, 0.0, 0.0});
	m_xyz[1]=center.y() + dot(centerToPoint, XYZ<T>{0.0, cos(thetaRad), -sin(thetaRad)});
	m_xyz[2]=center.z() + dot(centerToPoint, XYZ<T>{0.0, sin(thetaRad), cos(thetaRad)});
	return *this;
}

template<typename T> XYZ<T>& XYZ<T>::rotateY(const XYZ<T>& center, const double theta) {
	double thetaRad=DEG_TO_RAD(theta);
	Vector3 centerToPoint{ *this -center};
	m_xyz[0]=center.x() + dot(centerToPoint, XYZ<T>{cos(thetaRad), 0.0, sin(thetaRad)});
	m_xyz[1]=center.y() + dot(centerToPoint, XYZ<T>{0.0, 1.0, 0.0});
	m_xyz[2]=center.z() + dot(centerToPoint, XYZ<T>{-sin(thetaRad), 0.0, cos(thetaRad)});
	return *this;
}

template<typename T> XYZ<T>& XYZ<T>::rotateZ(const XYZ<T>& center, const double theta) {
	double thetaRad=DEG_TO_RAD(theta);
	Vector3 centerToPoint{ *this -center};
	m_xyz[0]=center.x() + dot(centerToPoint, XYZ<T>{cos(thetaRad), -sin(thetaRad), 0.0});
	m_xyz[1]=center.y() + dot(centerToPoint, XYZ<T>{sin(thetaRad), cos(thetaRad), 0.0});
	m_xyz[2]=center.z() + dot(centerToPoint, XYZ<T>{0.0, 0.0, 1.0});
	return *this;
}

template<typename T> XYZ<T>& XYZ<T>::rotateXYZ(const XYZ<T>& center, const double alpha, const double beta, const double gamma) {
	return this->rotateZ(center, gamma).rotateY(center, beta).rotateX(center, alpha);
}

template<typename T> XYZ<T>& XYZ<T>::rotateAAxis(const XYZ<T>& axis, const double theta) {
	double thetaRad=DEG_TO_RAD(theta);
	Vector3 axisCopy=axis.unit();
	Vector3 rotatedPoint=(*this) * cos(thetaRad) +
			(cross(axisCopy, *this) * sin(thetaRad)) +
			(axisCopy * dot(axisCopy, *this)*(1 - cos(thetaRad)));
	*this=rotatedPoint;
	return *this;
}

template<typename U> inline std::ostream& operator<<(std::ostream& out, const XYZ<U>& xyz) {
	return out << "[" << xyz.m_xyz[0] << ", " << xyz.m_xyz[1] << ", " << xyz.m_xyz[2] << "]";
}

