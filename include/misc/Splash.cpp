
#include <iostream>
#include <fstream>

#include "Splash.hpp"

bool splashScreen()
{	
	bool err = false;
	std::string path = "rsc/ascii-art/ray-net";
	std::ifstream is { path , std::ios::in };
	if (!is.is_open()) {
		std::cerr << "ERROR: Failed to open " << path << '\n';
		err = true;
	} else {
		std::string line;
		while (std::getline(is, line)) {
			std::cout << line << "\n";
		}
	}
	/*
	path = "rsc/ascii-art/ray-tracing-scheme";
	is = std::ifstream(path , std::ios::in);
	if (!is.is_open()) {
		std::cerr << "ERROR: Failed to open " << path << '\n';
		err = true;
	} else {
		std::string line;
		while (std::getline(is, line)) {
			std::cout << line << "\n";
		}
	}
	*/
	return err;
}


