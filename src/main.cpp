
#include <iostream>
#include <fstream>

#include "../include/sdl/SDL_Window.hpp"

#include "../include/ray/RGB_Image.hpp"
#include "../include/ray/Ray.hpp"

#include "../include/misc/Benchmark.hpp"
#include "../include/misc/Splash.hpp"

/*
 *		ooooooooo.                                 ooooo      ooo               .   
 *		`888   `Y88.                               `888b.     `8'             .o8   
 *		 888   .d88'  .oooo.   oooo    ooo          8 `88b.    8   .ooooo.  .o888oo 
 *		 888ooo88P'  `P  )88b   `88.  .8'           8   `88b.  8  d88' `88b   888   
 * 		 888`88b.     .oP"888    `88..8'   8888888  8     `88b.8  888ooo888   888   
 *		 888  `88b.  d8(  888     `888'             8       `888  888    .o   888 . 
 *		o888o  o888o `Y888""8o     .8'             o8o        `8  `Y8bod8P'   "888" 
 *                              .o..P'                                               
 *                              `Y8P'                                                
 *
 *
 *  by: Miguel Laredo
 *	date: 23/02/2024
 *
 *																					  Q
 *          ^                                                                     @@			  ^
 *        y |                                                                 (@  @    @@(		  U
 *          |                                                              @@     @    *%&# ,@@
 *          |                                                           @#        @ @        @,   %@#
 *          |                                                       .@            @          ,(        @@.
 *          |__________>                                        #@                @           #             /@@
 *         /          X                                       @@                  @ @        @/         ,@@#   &
 *      Z /                                                @/                     @    #@@@.     (@@*          @
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

	// Print Splash Screen
	splashScreen();

	// Image
	const double ASPECT_RATIO = 16.0/9.0;
	const size_t IMAGE_WIDTH = 1000;
	const size_t IMAGE_HEIGHT = (static_cast<size_t>(IMAGE_WIDTH/ASPECT_RATIO) < 1)? 1 : static_cast<size_t>(IMAGE_WIDTH/ASPECT_RATIO);

	// Camera
	const double FOCAL_LENGTH = 1.0;											// Distancia entre la Cámara y el Viewport
	const double VIEWPORT_HEIGHT = 2.0;											// Altura del Viewport
	const double VIEWPORT_WIDTH = VIEWPORT_HEIGHT * (static_cast<double>(IMAGE_WIDTH/IMAGE_HEIGHT));	// Ancho del Viewport de acuerdo a la relación de aspecto
	const Point CAMERA_CENTER { 0.0, 0.0, 0.0 };
	const Vector VIEWPORT_U= Vector(VIEWPORT_WIDTH, 0.0, 0.0);					// Vector que indica el ancho del Viewport
	const Vector VIEWPORT_V = Vector(0.0, -VIEWPORT_HEIGHT, 0.0);				// Vector que indica el alto del Viewport
	const Vector DELTA_U = VIEWPORT_U/static_cast<double>(IMAGE_WIDTH);			// Diferencial Para cubrir con el tamaño del viewport y la restricción de resolución
	const Vector DELTA_V = VIEWPORT_V/static_cast<double>(IMAGE_HEIGHT);		// Diferencial Para cubrir con el tamaño del viewport y la restricción de resolución

	// const auto VIEWPORT_ORIGIN = CAMERA_CENTER - Vector(0, 0, FOCAL_LENGTH - VIEWPORT_U/2.0 -);


	return 0;
}


