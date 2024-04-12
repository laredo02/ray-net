
#include <cassert>

#include "RayNet.h"
#include "Camera.h"

Camera::Camera(const Vector3& center, const Vector3& direction, const Vector3& up,
               double vfov, double flen, uint32_t height, uint32_t width)
: m_Center(center), m_Direction(direction), m_Up(up),
m_VFov(vfov), m_FLen(flen), m_AspectRatio(static_cast<double> (width)/height), m_Width{width}, m_Height{height}
{
    assert(dot(m_Direction, m_Up)*dot(m_Direction, m_Up)<=0.00001);
    m_Direction.toUnit();
    m_Up.toUnit();
    m_VNorm=2.0*m_FLen*tan(DEG_TO_RAD(m_VFov)/2.0);
    m_UNorm=m_VNorm*m_AspectRatio;
    computeRayParameters();
}

void Camera::computeRayParameters() {
    m_DeltaU=cross(m_Direction, m_Up)*(m_UNorm/m_Width);
    m_DeltaV= -m_Up*(m_VNorm/m_Height);
    m_P00=m_Center+m_Direction*m_FLen+(m_Up*(m_VNorm/2.0))+m_DeltaV*0.5+((cross(m_Up, m_Direction)*(m_UNorm/2.0)))+m_DeltaU*0.5;
}



const Vector3& Camera::deltaU() const {
    return m_DeltaU;
}

const Vector3& Camera::deltaV() const {
    return m_DeltaV;
}

const Vector3& Camera::P00() const {
    return m_P00;
}



void Camera::translate(const Vector3& delta) {
    Vector3 translation=delta.x()*cross(m_Direction, m_Up)+delta.y()*m_Up-delta.z()*m_Direction;
    m_Center+=translation;
    computeRayParameters();
}

void Camera::pitch(const double theta) {
    Vector3 axis = cross(m_Direction, m_Up);
    m_Direction.rotateAAxis(axis, theta);
    m_Up.rotateAAxis(axis, theta);
    computeRayParameters();
}

void Camera::yaw(const double theta) {
    m_Direction.rotateAAxis(m_Up, theta);    
    computeRayParameters();
}

void Camera::roll(const double theta) {
    m_Up.rotateAAxis(m_Direction, theta);
    computeRayParameters();
}





const Vector3& Camera::center() const {
    return m_Center;
}

const Vector3& Camera::direction() const {
    return m_Direction;
}

const Vector3& Camera::up() const {
    return m_Up;
}

double Camera::vFov() const {
    return m_VFov;
}

double Camera::fLen() const {
    return m_FLen;
}

uint32_t Camera::width() const {
    return m_Width;
}

uint32_t Camera::height() const {
    return m_Height;
}

double Camera::aspectRatio() const {
    return m_AspectRatio;
}



