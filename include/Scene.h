
#ifndef SCENE_H
#define SCENE_H

#include "RayNet.h"
#include "Sphere.h"

class Scene {
public:
	Scene();

private:
	vector<Sphere*> sphereList;
	
};

#endif /* SCENE_H */

