
#include "Viewport.hpp"

Viewport::Viewport(size_t width, size_t height, double focal_length, double viewport_width)
    : m_Width(width), m_Height(height), m_FocalLength(focal_length), m_ViewportWidth(viewport_width)
{

}

Viewport::Viewport(size_t width, double aspect_ratio, double focal_length, double viewport_width)
    : m_Width(width), m_AspectRatio(aspect_ratio), m_FocalLength(focal_length), m_ViewportWidth(viewport_width)
{

}
