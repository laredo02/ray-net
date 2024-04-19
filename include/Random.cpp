
#include <random>

#include "Random.h"

double randomDouble(double min, double max) {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<> rdist(min, max);
	return rdist(eng);
}

int randomInt(int min, int max) {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> rdist(min, max);
	return rdist(eng);
}
