
#ifndef MATERIAL_H
#define MATERIAL_H

#include "RayNet.h"
#include "XYZ.h"

struct Material {
	
	Material(const Vector3& albedo);
	
	Vector3 m_Albedo;
};

#endif /* MATERIAL_H */

