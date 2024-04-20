
#pragma once

#include "RayNet.h"
#include "Material.h"

struct HitTrace {
	
	double m_HitDistance = std::numeric_limits<double>::max();
	Vector3 m_Point;
	Vector3 m_Normal;
	
	shared_ptr<const Material> p_Material = nullptr;

#if REAL_DISTANCE == 1
#endif
	bool frontFace;
	
};

std::ostream& operator<<(std::ostream& os, const HitTrace& trace);


