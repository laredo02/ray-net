
#pragma once

#include <random>

template<typename T> T randomReal(T min, T max) {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<> rdist(min, max);
	return rdist(eng);
}

template<typename T> T randomInt(T min, T max) {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> rdist(min, max);
	return rdist(eng);
}
