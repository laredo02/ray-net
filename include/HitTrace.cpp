
#include "RayNet.h"
#include "XYZ.h"
#include "HitTrace.h"

std::ostream& operator<<(std::ostream& os, const HitTrace& trace) {
    return os << "[t:" << trace.m_HitDistance << ", p:" << trace.m_Point << ", n:" << trace.m_Normal << "]";
}


