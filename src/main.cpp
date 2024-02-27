
#include <iostream>
#include <fstream>

#include <unistd.h>
#include <sys/wait.h>

#include "../include/sdl/SDL_Window.hpp"
#include "../include/ray/RGB_Image.hpp"
#include "../include/ray/Ray.hpp"
#include "../include/misc/Benchmark.hpp"
#include "../include/misc/Splash.hpp"

#include "../include/math/XYZ.hpp"

// #define __COMPILE_EOG__

/*
 *      ooooooooo.                                 ooooo      ooo               .
 *      `888   `Y88.                               `888b.     `8'             .o8
 *       888   .d88'  .oooo.   oooo    ooo          8 `88b.    8   .ooooo.  .o888oo
 *       888ooo88P'  `P  )88b   `88.  .8'           8   `88b.  8  d88' `88b   888
 *       888`88b.     .oP"888    `88..8'   8888888  8     `88b.8  888ooo888   888
 *       888  `88b.  d8(  888     `888'             8       `888  888    .o   888 .
 *      o888o  o888o `Y888""8o     .8'             o8o        `8  `Y8bod8P'   "888"
 *                             .o..P'
 *                             `Y8P'
 *
 *
 *  by: Miguel Laredo
 *	date: 23/02/2024
 *
 *	                                                                              Q
 *          ^                                                                     @@              ^
 *        Y |                                                                 (@  @    @@(        U
 *          |                                                              @@     @    *%&# ,@@
 *          |                                                           @#        @ @        @,   %@#
 *          |                                                       .@            @          ,(        @@.
 *          |__________>                                        #@                @           #             /@@
 *         /          Z                                       @@                  @ @        @/         ,@@#   &
 *      X /                                                @/                     @    #@@@.     (@@*          @
 *       /                                             *@                         @       %@@,    @@.          @@.
 *      %                                           %@                            @@@&         @#              @   @
 *                                               @&                        .@@%   @          (&                @     @
 *                                            @.                    (@@*          @         &.                 @      @
 *                                        (@                 &@@.                 @         @                  @       @
 *                                     @@            .@@&                         @         %                  @       @
 *      /,  &@@                     @(        *@@#                                @         @                  @      #,
 *    @   @@   @                .@     /@@/                                       @          @                 @     ,@
 *  .&           @ #@@       #@ &@@                                               @           @.               &    @
 *  .&  CAMERA   @@* @      .@@@                                                   @.           %@             # *@
 *  .&           @                  .@@@.                                            ,@             #@@%*.,#@@@/
 *  .&@@@@@@@@@@@                           .&@@*                                       &&                     #
 *                                                    %@@*                                  @*                 @
 *                                                            &@@*                             @               @
 *                                                                    %@@(                       #@            @  ^
 *                                                                            (@@%                  @(         @  V
 *                                                                                    *@@%             @       @
 *                                                                                            *@@&       /@    @
 *                                                                                                    ,@@@. @% @
 *                                                                                    VIEWPORT                 @
 *
 * */


int main(int argc, char* argv[])
{

	using std::cout;
	using std::endl;

	std::string image_path = "image.ppm";
	if (argc == 2)
		image_path = std::string(argv[1]);

	splashScreen();

	// Image
	const double ASPECT_RATIO = 16.0/9.0;
	const size_t IMAGE_WIDTH = 3840;
	const size_t IMAGE_HEIGHT = (static_cast<size_t>(IMAGE_WIDTH/ASPECT_RATIO) < 1)? 1 : static_cast<size_t>(IMAGE_WIDTH/ASPECT_RATIO);
	Image final_render { IMAGE_WIDTH, IMAGE_HEIGHT };

	// Camera
	const double FOCAL_LENGTH = 1.0;											// Distancia entre la Cámara y el Viewport
	const double VIEWPORT_HEIGHT = 2.0;											// Altura del Viewport
	const double VIEWPORT_WIDTH = VIEWPORT_HEIGHT * (static_cast<double>(IMAGE_WIDTH)/IMAGE_HEIGHT);	// Ancho del Viewport de acuerdo a la relación de aspecto
	const Point CAMERA_CENTER { 0.0, 0.0, 0.0 };
	const Vector VIEWPORT_U = Vector(VIEWPORT_WIDTH, 0.0, 0.0);					// Vector que indica el ancho del Viewport
	const Vector VIEWPORT_V = Vector(0.0, -VIEWPORT_HEIGHT, 0.0);				// Vector que indica el alto del Viewport
	const Vector DELTA_U = VIEWPORT_U/static_cast<double>(IMAGE_WIDTH);			// Diferencial Para cubrir con el tamaño del viewport y la restricción de resolución
	const Vector DELTA_V = VIEWPORT_V/static_cast<double>(IMAGE_HEIGHT);		// Diferencial Para cubrir con el tamaño del viewport y la restricción de resolución
	const Point VIEWPORT_ORIGIN = CAMERA_CENTER - Vector(0.0, 0.0, FOCAL_LENGTH) - VIEWPORT_U/2.0 - VIEWPORT_V/2.0;		// Q
	const Point PIXEL00 = VIEWPORT_ORIGIN + 0.5*(DELTA_U + DELTA_V);			// Pixel 00

	cout << "\n=============================\n" <<
			"Resolution: " << IMAGE_WIDTH << "x" << IMAGE_HEIGHT <<
			"\nFocal length: " << FOCAL_LENGTH <<
			"\nViewport size: " << VIEWPORT_WIDTH << 'x' << VIEWPORT_HEIGHT <<
			"\nViewport Origin: " << VIEWPORT_ORIGIN <<
			"\nU, V: " << VIEWPORT_U << ", " << VIEWPORT_V << "\ndU, dV: " << DELTA_U << ", " << DELTA_V << "\n=============================\n\n";

	// Render Image
	for (size_t i{0}; i<IMAGE_WIDTH; i++)
	{
		for (size_t j{0}; j<IMAGE_HEIGHT; j++)
		{
			auto ray_center = PIXEL00 + (static_cast<double>(i)*DELTA_U) + (static_cast<double>(j)*DELTA_V);
			auto ray_direction = ray_center - CAMERA_CENTER;

			Ray ray { CAMERA_CENTER, ray_direction };
			Color p_color = ray.color();

			final_render.setPixel(i, j,
				static_cast<uint8_t>(p_color.red),
				static_cast<uint8_t>(p_color.green),
				static_cast<uint8_t>(p_color.blue));
		}
	}
	final_render.saveToFile(image_path);





#ifdef __COMPILE_EOG__
	pid_t pid = fork();
	if (pid < 0)
		std::cerr << "ERROR: fork() failed." << std::endl;
	else if (pid == 0) {
		std::cout << "EOG: " << "/home/miguel/coding/ray-net/" << image_path << '\n';
		if(!execl("/usr/bin/eog", ("/home/miguel/coding/ray-net/" + image_path).c_str(), nullptr))	// Cambiar esto para que no funcione solo en mi ordenador
			std::cerr << "ERROR: Unable to open eog" << '\n';

		std::cerr << "ERROR: Failed to execute eog" << '\n';
		exit(EXIT_FAILURE);
	} else {
		int status;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status)) {
			int exit_status = WEXITSTATUS(status);
			std::cout << "Child exited with status: " << status << '\n';
		}
	}
#endif // __COMPILE_EOG__

	return 0;
}



