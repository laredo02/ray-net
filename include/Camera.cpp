
#include <cassert>

#include "RayNet.h"

#include "Camera.h"

#define DEG_TO_RAD(deg) ((deg)*(M_PI/180.0))

Camera::Camera(const Vector3& center, const Vector3& direction, const Vector3& up, double vfov, double flen, double aspect_ratio)
    : m_Center(center), m_Direction(direction), m_Up(up), m_VFov(vfov), m_FLen(flen), m_AspectRatio(aspect_ratio)
{
    m_VNorm = 2.0*m_FLen*tan(DEG_TO_RAD(m_VFov)/2.0);
    m_UNorm = m_VNorm*m_AspectRatio;
}

const vector<Ray>& Camera::computeRays(const size_t width) const
{
    
    size_t height = static_cast<size_t>((double)width/m_AspectRatio);
    
    Vector3 delta_u = cross(m_Direction, m_Up)*(m_UNorm/width);
    Vector3 delta_v = -m_Up*(m_VNorm/(width/m_AspectRatio));
    
    Vector3 m_P00 = m_Direction*m_FLen + (m_Up*(m_VNorm/2.0))+delta_v*0.5 + ((cross(m_Up, m_Direction)*(m_UNorm/2.0)))+delta_u*0.5;
    
    for (size_t i{0}; i<height; i++)
    {
        for (size_t j{0}; j<width; j++)
        {
            Vector3 direction = Vector3{ (m_P00 + ((double) i * delta_v) + ((double) j * delta_u)) };
            direction.toUnit();
            m_Rays.push_back(Ray{ m_Center, direction});
        }
    }
    
    return m_Rays;
    
}

void Camera::translate(Vector3 delta)
{
    m_Center += delta;
}

void Camera::rotate(double xrot, double yrot, double zrot)
{
    
}

void Camera::setCenter(const Vector3& center)
{
    m_Center = center;
}

void Camera::setDirection(const Vector3& direction)
{
    m_Direction = direction;
}

void Camera::setUp(const Vector3& up)
{
    m_Up = up;
}

void Camera::setVFov(double vFov)
{
    m_VFov = vFov;
}

void Camera::setFLen(double fLen)
{
    m_FLen = fLen;
}

void Camera::setAspectRatio(double aspectRatio)
{
    m_AspectRatio = aspectRatio;
}

const Vector3& Camera::getCenter() const
{
    return m_Center;
}

const Vector3& Camera::getDirection() const
{
    return m_Direction;
}


const Vector3& Camera::getUp() const
{
    return m_Up;
}

double Camera::getVFov() const
{
    return m_VFov;
}

double Camera::getFLen() const
{
    return m_FLen;
}

double Camera::getAspectRatio() const
{
    return m_AspectRatio;
}







