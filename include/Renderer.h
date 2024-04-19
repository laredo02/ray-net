
#pragma once

#include <SDL2/SDL.h>

#include "RayNet.h"
#include "Camera.h"
#include "Sphere.h"
#include "Image.h"
#include "Scene.h"

/*
 * @breif Compute the color of the pixel that ray passes through.
 * @details 
 * @param[in] ray
 * @param[in] scene
 * @param[in] tmin
 * @param[in] tmax
 */
Vector3 pixelColor(const Ray& ray, const Scene& scene, double tmin, double tmax);


/*
 * @class Renderer represents a rendering object, it is capable of rendering images given a Camera, a Scene and an Image object
 */
class Renderer {

public:
	
	Renderer(shared_ptr<Camera> camera, shared_ptr<Scene> scene, shared_ptr<Image> image);
	void handleInput() const;
	void render() const;
	const Image& getImage() const;
	void saveRenderToFile(const string& name) const;
	Camera& camera() const;
	
private:
	shared_ptr<Camera> p_Camera;
	shared_ptr<Scene> p_Scene;
	shared_ptr<Image> p_Image;
};
