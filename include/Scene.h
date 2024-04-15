
#pragma once

#include "RayNet.h"

#include "Hittable.h"
#include "Camera.h"

class Scene {

public:
	
	Scene();
	Scene(const vector<Hittable>& hittable_lists, shared_ptr<Camera> camera);
	
private:
	
	vector<Hittable> hittable_list;

};



