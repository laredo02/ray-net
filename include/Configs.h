
#pragma once


/* PERFORMANCE SETTINGS */
#define BENCHMARK					0		// Benchmark compute actions render loop
#define REAL_DISTANCE				1		// [0 | 1] [Don't | Do] use normaliced ray directions. Using them is more expensive 


/* MULTITHREADING SETTINGS */
#define MULTITHREAD_RENDER			1		// Enable multithreading to improve render time


/* DEBUGGING  */
#define ASSERTIONS					0		// Use assertions for bug finding
#define BOUNDS_CHECKING				0		// Array and vector bound checking
#define MULTITHREAD_LOGGING			0		// Multithreaded logs (mutex cout so no data races)
#define PRINT_KEYBOARD_ACTIONS		0		// Prints for keyboard acctionsand associated changes


/* RUNTIME PARAMETERS */

#define RENDER_REAL_TIME			1		// Render in realtime using sdl window
#define GENERATE_DEPTH_DATASET		1		// Generate depth dataset

#define ASPECT_RATIO				1.0
#define IMAGE_WIDTH					500
#define FOV							90.0	// Deg
#define CAMERA_TRANSLATION_SPEED	1		// m/s
#define CAMERA_ROTATION_SPEED		45		// grad/s
#define RENDER_NORMALS				0		// Render Surcface Normals
#define RENDER_DEPTH_MAP			1		// LIDAR View
#define DEPTH_MAP_MAX_DISTANCE		200		// Maximum depth of map

