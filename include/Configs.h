
#pragma once

/* PERFORMANCE SETTINGS */
#define BENCHMARK					0		// Benchmark compute actions render loop
#define REAL_DISTANCE				0		// [0 | 1] [Don't | Do] use normaliced ray directions. Using them is more expensive


/* MULTITHREADING SETTINGS */
#define MULTITHREAD_RENDER			1		// Enable multithreading to improve render time


/* DEBUGGING  */
#define ASSERTIONS					0		// Use assertions for bug finding
#define BOUNDS_CHECKING				0		// Array and vector bound checking
#define MULTITHREAD_LOGGING			0		// Multithreaded logs (mutex cout so no data races)
#define PRINT_KEYBOARD_ACTIONS		0		// Prints for keyboard acctionsand associated changes


/* RUNTIME PARAMETERS */
#define RENDER_REAL_TIME			1		// Render in realtime using sdl window
#define RENDER_DEPTH_MAP			0		// LIDAR View
#define RENDER_NORMALS				0		// Render Surcface Normals
#define GENERATE_DEPTH_DATASET		0		// Generate depth dataset
#define DEPTH_MAP_MAX_DISTANCE		70		// Maximum depth of map
#define GAMMA_CORRECTION			1		// Enable/Disable gamma correction

#define ANTIALIASING				0		// Enable/Disable Antialiasing
#define RAYS_PER_PIXEL				1		// Supersampling Antialias. Number of rays per pixel

#define ASPECT_RATIO				16.0/9.0
#define IMAGE_WIDTH					500
#define FOV							45.0	// Deg

#define CAMERA_TRANSLATION_SPEED	0.04		// u/ms
#define CAMERA_ROTATION_SPEED		0.06		// grad/ms
#define RAY_BOUNCE_DEPTH			5	// Number of bounces for each ray

#define FILENAME					"image1.ppm"





