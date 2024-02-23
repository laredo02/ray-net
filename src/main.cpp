
#include <iostream>

#include "../include/math/XYZ.hpp"
#include "../include/sdl/SDL_Window.hpp"
#include "../include/ray/RGB_Image.hpp"

int main(int argc, char* argv[])
{

	using std::cout;
	using std::endl;

	RGB_Image<double> img { 3, 3 };
	img.fill(60, 60, 60);
	img.randFill();

	img.resize(2, 2);

	std::cout << img << std::endl;



	return 0;
}

