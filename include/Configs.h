
#pragma once



/* PERFORMANCE SETTINGS */
#define BENCHMARK					0		// Benchmark compute actions render loop
#define REAL_DISTANCE				1		// [0 | 1] [Don't | Do] use normaliced ray directions. Using them is more expensive 



/* MULTITHREADING SETTINGS */
#define MULTITHREAD_RENDER			1		// Enable multithreading to improve render time
#define MULTITHREAD_LOGGING			0		// Multithreaded logs (mutex cout so no data races)



/* DEBUGGING  */
#define ASSERTIONS					1		// Use assertions for bug finding
#define BOUNDS_CHECKING				1		// Array and vector bound checking
#define PRINT_KEYBOARD_ACTIONS		0		// Prints for keyboard acctionsand associated changes





