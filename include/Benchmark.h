
#pragma once

#include <iostream>
#include <chrono>

class Benchmark {
public:

	Benchmark(const std::string& n, bool l) : name(n) {
		begin = std::chrono::steady_clock::now();
		laponly = l;
	}

	Benchmark(const Benchmark& bench) = delete;
	Benchmark& operator=(const Benchmark& bench) = delete;

	~Benchmark() {
		if (laponly)
			std::cout << name << " " << lap() << "ms" << std::endl;
	}

	int64_t lap() {
		auto diff = std::chrono::steady_clock::now() - begin;
		return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
	}
	

private:
	std::string name;
	std::chrono::steady_clock::time_point begin;
	bool laponly;
};

