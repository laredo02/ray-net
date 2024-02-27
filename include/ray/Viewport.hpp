
#ifndef __HEADER_VIEWPORT__
#define __HEADER_VIEWPORT__

#include <cstdlib>
#include <iostream>
#include <vector>

#include "../math/XYZ.hpp"
#include "../ray/Ray.hpp"
#include "../ray/RGB_Image.hpp"

class Viewport
{

public:
    Viewport(size_t width, double aspect_ratio, double focal_length, double viewport_width);
    ~Viewport();

    void render(Image& render);

    size_t getImageWidth();
    size_t getImageHeight();

    friend std::ostream& operator<<(std::ostream& os, const Viewport& view);

    /*
        TO-DO
        Member functions that allow for viewport translation, rotation and parameter tunning
    */

private:
    
    double m_AspectRatio;

    size_t m_PixelWidth;
    size_t m_PixelHeight;
    double m_PixelAspectRatio;

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

    std::vector<Ray>* m_Rays;
    Image* m_Render;

};

#endif // __HEADER_VIEWPORT__

