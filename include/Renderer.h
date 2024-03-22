
#ifndef RENDERER_H
#define RENDERER_H

#include "RayNet.h"

#include "Camera.h"
#include "Sphere.h"
#include "Image.h"

class Renderer {
	
public:
	Renderer(const Camera* camera, const Sphere* sphere);
 	
	void setGlobalLight();
	
	void render(Image& image);
	
private:
	const Camera* p_Camera;
	const Sphere* p_Sphere;
};

#endif /* RENDERER_H */


