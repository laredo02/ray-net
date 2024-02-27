
#include "Viewport.hpp"

/*
    double m_AspectRatio;
    size_t m_Height;
    size_t m_Width;
    double m_RealAspectRatio;

    double m_FocalLength;
    double m_ViewportWidth;
    double m_ViewportHeight;

    Point m_CameraCenter;
    Vector m_ViewportU; // Width
    Vector m_ViewportV; // Height
    Vector m_DeltaU;
    Vector m_DeltaV;

    Point m_ViewportOrigin; // Q
    Point m_Pixel0;
*/

Viewport::Viewport(size_t width, size_t height, double focal_length, double viewport_width)
    : m_Width(width), m_Height(height), m_FocalLength(focal_length), m_ViewportWidth(viewport_width)
{
    m_AspectRatio = static_cast<double>(width)/height;
    m_RealAspectRatio = m_AspectRatio;

}

Viewport::Viewport(size_t width, double aspect_ratio, double focal_length, double viewport_width)
    : m_Width(width), m_AspectRatio(aspect_ratio), m_FocalLength(focal_length), m_ViewportWidth(viewport_width)
{

}






