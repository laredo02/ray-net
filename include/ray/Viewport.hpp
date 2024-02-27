
#ifndef __HEADER_VIEWPORT__
#define __HEADER_VIEWPORT__

#include <cstdlib>

#include "../math/XYZ.hpp"

class Viewport
{
    Viewport(size_t width, size_t height, double focal_length, double viewport_width);
    Viewport(size_t width, double aspect_ratio, double focal_length, double viewport_width);


    /*
        TO-DO

        Member functions that allow for viewport translation, rotation and parameter tunning

    */

public:


private:
    
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

}

#endif // __HEADER_VIEWPORT__

