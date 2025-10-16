/**
* @file arraymanipulation.c
* @brief Implementation of array manipulation functions
* @author Dylan O'Halloran
* @date 16/10/2025
*/

#include <stdlib.h>
#include <stdio.h>
#include "config.h"
#include "arraymanipulation.h"
#include "utility.h"

/**
* @brief Accepts parameters to fill an array using either a combination of random numbers in range and UNUSED_MARKER or exclusively one of those values
* 
* @param arr the integer array to fill
* @param capacity the element limit of the array
* @param size the amount of random numbers to add to the array
* @param min the minimum value that can be randomly generated inclusive
* @param max the maximum value that can be randomly generated inclusive
* 
*/


void fillArrayRandom(int arr[], int size, int capacity, int min, int max)
{
	int i; // declare iterator value
	int randomNumber; // stores value returned by generateRandomNumber

	// 1. Generate a random number between ranges of min and max
	for (i = 0; i < size && i < capacity; i++) { // Begin a for loop at index 0, i < size AND i < capacity, with a step of 1
		randomNumber = generateRandomNumber(min, max); // Call function generateRandomNumber with parameters (min, max)
		arr[i] = randomNumber; // Store the generated value at arr[i]
	}

	// 2. Terminate random number generation and fill remaining slots with -1
	for (; i < capacity; i++) { // Move to next for loop, using previous iterator value as starting point, capacity-1 as our termination, with a step of 1
		arr[i] = UNUSED_MARKER; // Iterate through the remaining elements of the array, assigning UNUSED_MARKER to every available position
	}
}