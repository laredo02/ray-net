
#include "Viewport.hpp"

Viewport::Viewport(size_t width, double aspect_ratio, double focal_length, double viewport_width)
    : m_PixelWidth(width), m_AspectRatio(aspect_ratio), m_FocalLength(focal_length), m_ViewportWidth(viewport_width)
{
    m_PixelHeight = (static_cast<size_t>(m_PixelWidth/m_AspectRatio) < 1)? 1: static_cast<size_t>(m_PixelWidth/m_AspectRatio);
    m_PixelAspectRatio = static_cast<double>(m_PixelWidth)/m_PixelHeight;
    m_ViewportHeight = m_ViewportWidth/m_PixelAspectRatio;
    m_CameraCenter = Point { 0.0, 0.0, 0.0 };
    m_ViewportU = Vector(m_ViewportWidth, 0.0, 0.0);
    m_ViewportV = Vector(0.0, -m_ViewportHeight, 0.0);
    m_DeltaU = m_ViewportU/static_cast<double>(m_PixelWidth);
    m_DeltaV = m_ViewportV/static_cast<double>(m_PixelHeight);
    m_ViewportOrigin = m_CameraCenter - Vector(0.0, 0.0, m_FocalLength) - m_ViewportU/2.0 - m_ViewportV/2.0;
    m_Pixel0 = m_ViewportOrigin + 0.5*(m_DeltaU + m_DeltaV);

    m_Rays = new std::vector<Ray> { m_PixelWidth * m_PixelHeight, Ray( {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0} ) };
    m_Render = new Image { m_PixelWidth, m_PixelHeight };
}

Viewport::~Viewport()
{
    delete m_Rays;
    m_Rays = nullptr;
    delete m_Render;
    m_Render= nullptr;
}

void Viewport::render(Image& render)
{
    for (size_t i{0}; i<m_PixelWidth; i++)
    {
        for (size_t j{0}; j<m_PixelHeight; j++)
        {
            Point ray_center = m_Pixel0 + (static_cast<double>(i)*m_DeltaU + (static_cast<double>(j)*m_DeltaV));
            Vector ray_direction = ray_center - m_CameraCenter;

            Ray ray { m_CameraCenter, ray_direction };
            Color pixel_color = ray.color();

            render.setPixel(i, j, static_cast<uint8_t>(pixel_color.red), static_cast<uint8_t>(pixel_color.green), static_cast<uint8_t>(pixel_color.blue));
        }
    }
}

size_t Viewport::getImageWidth()
{
    return m_PixelWidth;
}

size_t Viewport::getImageHeight()
{
    return m_PixelHeight;
}

std::ostream& operator<<(std::ostream& os, const Viewport& view)
{
	return os << "Resolution: " << view.m_PixelWidth << "x" << view.m_PixelHeight <<
	            "\nFocal length: " << view.m_FocalLength <<
	            "\nViewport size: " << view.m_ViewportWidth << 'x' << view.m_ViewportHeight <<
                "\nViewport Origin: " << view.m_ViewportOrigin <<
	            "\nU, V: " << view.m_ViewportU << ", " << view.m_ViewportV << "\ndU, dV: " << view.m_DeltaU << ", " << view.m_DeltaV;
}

