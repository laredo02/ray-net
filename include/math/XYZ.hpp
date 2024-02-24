
#ifndef __HEADER_XYZ__
#define __HEADER_XYZ__

#include <iostream>
#include <cstdint>
#include <cmath>

template<typename T> struct XYZ {

public:

	XYZ();
	XYZ(T x, T y, T z);
	const T& x() const;
	const T& y() const;
	const T& z() const;
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
	T norm() const;
	T normSquared() const;

public:

	T m_xyz[3];

};

using Point = XYZ<double>;
using Vector = XYZ<double>;

template<typename T> XYZ<T>::XYZ()
	: m_xyz{ (T) 0, (T) 0, (T) 0 }
{
}
template<typename T> XYZ<T>::XYZ(T x, T y, T z)
	: m_xyz{ x, y, z }
{
}

template<typename T> const T& XYZ<T>::x() const {
	return m_xyz[0];
}
template<typename T> const T& XYZ<T>::y() const
{
	return m_xyz[1];
}

template<typename T> const T& XYZ<T>::z() const
{
	return m_xyz[2];
}


template<typename T> XYZ<T> XYZ<T>::operator-() const{
	return XYZ<T>{ -m_xyz[0], -m_xyz[1], -m_xyz[2] };
}
template<typename T> T XYZ<T>::operator[](size_t i) const
{
	return m_xyz[i];
}
template<typename T> T& XYZ<T>::operator[](size_t i)
{
	return m_xyz[i];
}


template<typename T> inline XYZ<T>& XYZ<T>::operator+=(const XYZ<T>& xyz)
{
	m_xyz[0] += xyz[0];
	m_xyz[1] += xyz[1];
	m_xyz[2] += xyz[2];
	return *this;
}
template<typename T> inline XYZ<T>& XYZ<T>::operator+=(const T& value)
{
	m_xyz[0] += value;
	m_xyz[1] += value;
	m_xyz[2] += value;
	return *this;
}


template<typename T> inline XYZ<T>& XYZ<T>::operator-=(const XYZ<T>& xyz)
{
	m_xyz[0] -= xyz[0];
	m_xyz[1] -= xyz[1];
	m_xyz[2] -= xyz[2];
	return *this;
}
template<typename T> inline XYZ<T>& XYZ<T>::operator-=(const T& value)
{
	m_xyz[0] -= value;
	m_xyz[1] -= value;
	m_xyz[2] -= value;
	return *this;
}


template<typename T> inline XYZ<T>& XYZ<T>::operator*=(const XYZ<T>& xyz)
{
	m_xyz[0] *= xyz[0];
	m_xyz[1] *= xyz[1];
	m_xyz[2] *= xyz[2];
	return *this;
}
template<typename T> inline XYZ<T>& XYZ<T>::operator*=(const T& value)
{
	m_xyz[0] *= value;
	m_xyz[1] *= value;
	m_xyz[2] *= value;
	return *this;
}


template<typename T> inline XYZ<T>& XYZ<T>::operator/=(const XYZ<T>& xyz)
{
	m_xyz[0] /= xyz[0];
	m_xyz[1] /= xyz[1];
	m_xyz[2] /= xyz[2];
	return *this;
}
template<typename T> inline XYZ<T>& XYZ<T>::operator/=(const T& value)
{
	m_xyz[0] /= value;
	m_xyz[1] /= value;
	m_xyz[2] /= value;
	return *this;
}


template<typename T> inline XYZ<T> operator+(const XYZ<T> a, const XYZ<T> b)
{
	return XYZ<T>(a.x()+b.x(), a.y()+b.y(), a.z()+b.z());
}
template<typename T> inline XYZ<T> operator+(const XYZ<T> a, const T b)
{
	return XYZ<T>(a.x()+b, a.y()+b, a.z()+b);
}
template<typename T> inline XYZ<T> operator+(const T a, const XYZ<T> b) {
	return XYZ<T>(a+b.x(), a+b.x(), a+b.z());
}

template<typename T> inline XYZ<T> operator-(const XYZ<T> a, const XYZ<T> b)
{
	return XYZ<T>(a.x()-b.x(), a.y()-b.y(), a.z()-b.z());
}
template<typename T> inline XYZ<T> operator-(const XYZ<T> a, const T b) {
	return XYZ<T>(a.x()-b, a.y()-b, a.z()-b);
}
template<typename T> inline XYZ<T> operator-(const T a, const XYZ<T> b) {
	return XYZ<T>(a-b.x(), a-b.x(), a-b.z());
}


template<typename T> inline XYZ<T> operator*(const XYZ<T> a, const XYZ<T> b)
{
	return XYZ<T>(a.x()*b.x(), a.y()*b.y(), a.z()*b.z());
}
template<typename T> inline XYZ<T> operator*(const XYZ<T> a, T b)
{
	return XYZ<T>(a.x()*b, a.y()*b, a.z()*b);
}
template<typename T> inline XYZ<T> operator*(const T a, const XYZ<T> b) {
	return XYZ<T>(a*b.x(), a*b.x(), a*b.z());
}


template<typename T> inline XYZ<T> operator/(const XYZ<T> a, const XYZ<T> b)
{
	return XYZ<T>(a.x()/b.x(), a.y()/b.y(), a.z()/b.z());
}
template<typename T> inline XYZ<T> operator/(const XYZ<T> a, T b)
{
	return XYZ<T>(a*(1/b));
}


template<typename T> inline T XYZ<T>::norm() const
{
	return std::sqrt(m_xyz[0]*m_xyz[0] + m_xyz[1]*m_xyz[1] + m_xyz[2]*m_xyz[2]);
}
template<typename T> inline T XYZ<T>::normSquared() const
{
	return m_xyz[0]*m_xyz[0] + m_xyz[1]*m_xyz[1] + m_xyz[2]*m_xyz[2];
}
template<typename T> inline T dot(const XYZ<T>& u, const XYZ<T>& v)
{
	return u.x()*v.x() + u.y()*v.y() + u.z()*v.z();
}
template<typename T> inline T cross(const XYZ<T>& u, const XYZ<T>& v)
{
}
template<typename T> inline T unit_vector(const XYZ<T>& u, const XYZ<T>& v)
{
}

template<typename T> inline std::ostream& operator<<(std::ostream& out, const XYZ<T>& xyz)
{
	out << "[" << xyz.x() << ", " << xyz.y() << ", " << xyz.z() << "]"; return out;
}

#endif //__HEADER_XYZ__

