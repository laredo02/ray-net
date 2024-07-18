
#pragma once


#include "RayNet.h"

struct RandomVector {

	static std::vector<double> randomValues;
	static int index;
	
	static void initialize(int size);
	
	static double getValue();

};








