
#pragma once



/* PERFORMANCE SETTINGS */
#define REAL_DISTANCE				0		// [0 | 1] [Don't | Do] use normaliced ray directions. Using them is more expensive 
#define BENCHMARK					1		// Benchmark render loop



/* MULTITHREADING SETTINGS */
#define MULTITHREAD_RENDER			1		// Enable multithreading to improve render time



/* LOGGING  */
#define ASSERTIONS					0		// Use assertions for bug finding
#define PRINT_KEYBOARD_ACTIONS		0		// Prints for keyboard acctionsand associated changes
#define MULTITHREAD_LOGGING			0		// Multithreaded logs (mutex cout so no data races)



