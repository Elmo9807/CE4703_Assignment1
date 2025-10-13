/**
* @file utility.c
* @brief Implementation of utility functions
* @author Dylan O'Halloran
* @date 10/10/2025
*/

#include <stdlib.h>
#include <time.h>
#include "utility.h"

/** 
* @brief Generates a random integer in the specified range [lowerLimit, upperLimit]
* @param lowerLimit minimum value incl.
* @param upperLimit maximum value incl.
* @return random integer between lowerLimit and upperLimit incl.
*/

int generateRandomNumber(int lowerLimit, int upperLimit) {

	/*
	* Pseudocode:
	* 1. Initialise RNG if not seeded
	* 2. Calculate range
	* 3. Generate and return random number
	*/

	/* Step 1: Initialise RNG if not already seeded */
	static int seeded = 0;
	if (!seeded) {
		srand((unsigned int)time(NULL));
		seeded = 1;
	}

	/* Step 2: Calculate range */
	int range = upperLimit - lowerLimit + 1;

	/* Step 3: Generate and return random number in range */
	return lowerLimit + (rand() % range);
}