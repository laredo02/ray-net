
#pragma once

#include "RayNet.h"

#include "Hittable.h"
#include "Camera.h"

class Scene {

public:
	
	Scene(shared_ptr<Camera> camera);
	
	void addHittable(shared_ptr<Hittable> object);
	
	Hittable* operator[](size_t i); 
	
	
private:
	vector<shared_ptr<Hittable>> m_HittableList;

};



