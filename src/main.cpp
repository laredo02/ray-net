
#include <iostream>
#include <fstream>

#include <unistd.h>
#include <sys/wait.h>

#include "../include/sdl/SDL_Window.hpp"
#include "../include/ray/RGB_Image.hpp"
#include "../include/ray/Ray.hpp"
#include "../include/ray/Viewport.hpp"
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

	{
		Benchmark bench{"asd"};

		Viewport viewport { 1000,  16.0/9.0, 1.0, 3.0 };
		std::cout << "=================================\n" << viewport << "\n=================================\n" << std::endl;

		Image final_render { viewport.getImageWidth(), viewport.getImageHeight() };
		viewport.render(final_render);
		final_render.saveToFile(image_path);

	}

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



