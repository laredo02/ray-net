
#include <iostream>
#include <fstream>

#include "../include/sdl/SDL_Window.hpp"

#include "../include/ray/RGB_Image.hpp"
#include "../include/ray/Ray.hpp"

#include "../include/misc/Splash.hpp"

/*
 *		ooooooooo.                                 ooooo      ooo               .   
 *		`888   `Y88.                               `888b.     `8'             .o8   
 *		 888   .d88'  .oooo.   oooo    ooo          8 `88b.    8   .ooooo.  .o888oo 
 *		 888ooo88P'  `P  )88b   `88.  .8'           8   `88b.  8  d88' `88b   888   
 * 		 888`88b.     .oP"888    `88..8'   8888888  8     `88b.8  888ooo888   888   
 *		 888  `88b.  d8(  888     `888'             8       `888  888    .o   888 . 
 *		o888o  o888o `Y888""8o     .8'             o8o        `8  `Y8bod8P'   "888" 
 *  							.o..P'                                               
 *  							`Y8P'                                                
 *
 *
 *  by: Miguel Laredo
 *	date: 23/02/2024
 *
 *
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
 *  .&           @@* @      .@@@                                                   @.           %@             # *@
 *  .&           @                  .@@@.                                            ,@             #@@%*.,#@@@/
 *  .&@@@@@@@@@@@                           .&@@*                                       &&                     #
 *                                                    %@@*                                  @*                 @
 *                                                            &@@*                             @               @
 *                                                                    %@@(                       #@            @
 *                                                                            (@@%                  @(         @
 *                                                                                    *@@%             @       @
 *                                                                                            *@@&       /@    @
 *                                                                                                    ,@@@. @% @
 *                                                                                                             @
 *
 * */

// Image
const double ASPECT_RATIO = 16.0/9.0;
const size_t WIDTH = 1000;
const size_t HEIGHT = (static_cast<size_t>(WIDTH/ASPECT_RATIO) < 1)? 1 : static_cast<size_t>(WIDTH/ASPECT_RATIO);

int main(int argc, char* argv[])
{

	using std::cout;
	using std::endl;

	// Print Splash Screen
	splashScreen();

	// Camera
	const double focal_length = 1.0;
	const double viewport_height = 2.0;
	const double viewport_width = viewport_height * (static_cast<double>(WIDTH/HEIGHT));
	const Vector viewport_u = Vector(0.0, 0.0, 0.0);
	const Vector viewport_v = Vector(0.0, 0.0, 0.0);



	return 0;
}

