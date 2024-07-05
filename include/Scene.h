
#pragma once

#include "RayNet.h"

#include "Hittable.h"
#include "Camera.h"

using std::vector;

/*
 * @class Scene, container for scene elements
 * @brief List of Hittables, list of Light sources
 */
class Scene {

public:
	void addHittable(shared_ptr<Hittable> object);
	Hittable& operator[](size_t i) const;
	void empty();
	size_t size() const;
	bool isEmpty() const;

private:
	vector<shared_ptr<Hittable>> m_HittableList;

};

void addSpheresFromFile(const std::string& filename, std::shared_ptr<Scene> scene);