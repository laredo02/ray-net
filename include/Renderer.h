
#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

#include "RayNet.h"

#include "Camera.h"
#include "Sphere.h"
#include "Image.h"



class Renderer {

public:
	Renderer(Camera* camera, const Sphere* sphere, Image* image);
	void handleInput() const;

	void render() const;
	const Image& getImage() const;
	void saveRenderToFile(const string& name) const;

	Camera& camera() const;

private:
	Camera* p_Camera;
	const Sphere* p_Sphere;
	Image* p_Image;
};

#endif /* RENDERER_H */


