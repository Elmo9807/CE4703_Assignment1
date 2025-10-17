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
	/* declare iterator value */
	int i;

	/* stores value returned by generateRandomNumber */
	int randomNumber;

	/* 1. Generate a random number between ranges of min and max */

	/* Begin a for loop at index 0, i < size AND i < capacity, with a step of 1 */
	for (i = 0; i < size && i < capacity; i++) {

		/* Call function generateRandomNumber with parameters(min, max) */
		randomNumber = generateRandomNumber(min, max);

		/* Store the generated value at arr[i] */
		arr[i] = randomNumber;
	}

	/* 2. Terminate random number generation and fill remaining slots with -1 */

	/* Move to next for loop, using previous iterator value as starting point, capacity - 1 as our termination, with a step of 1 */
	for (; i < capacity; i++) {

		/* Iterate through the remaining elements of the array, assigning UNUSED_MARKER to every available position */
		arr[i] = UNUSED_MARKER; 
	}

	for (int j = 0; j < capacity; j++) {
		printf("Value at index %d is %d\n", j, arr[j]);
	}
}

/**
* @brief Accepts an array and the array capacity, then "clears" all index values by assigning them the UNUSED_MARKER
*
* @param arr the integer array to clear
* @param capacity the element limit of the array
*
*/


/* 1. Receive array and capacity as parameters */
void clearArray(int arr[], int capacity) 
{
	/* 2. Iterate through each index from 0 to capacity - 1 */
	for (int i = 0; i < capacity; i++) {

		/* 3. Replace the value at each index with UNUSED_MARKER */
		arr[i] = UNUSED_MARKER;
	}
}

/**
* @brief Accepts an array and the array capacity, differentiates between unused and used indices, then sorts the used indices in ascending order and the unused are sorted to the end of the array
*
* @param arr the integer array to sort
* @param capacity the element limit of the array
*
*/


/* 1. Receive array and capacity as parameters */
void sortArray(int arr[], int capacity) 
{
	/* 1.1 Initialise used as type int, track used indices in array */
	int used = 0;
	
	/* 2. Iterate through each index from 0 to capacity - 1 */

	/* 2.1 Initialise for loop from index 0, run to capacity - 1, step of 1 */
	for (int i = 0; i < capacity; i++) {

		/* 2.2 At each index, compare element with UNUSED_MARKER, if the element is unused, break, else move to 2.3 */
		if (arr[i] == UNUSED_MARKER) break;

		/* 2.3 Increment used value by 1 */
		used++;
	}

	/* 3. Iterate through each index again from iterator i = 0 to used - 1 */
	for (int i = 0; i < used - 1; i++) {

		/* 3.1 Iterate through each index from iterator j = 0 to used - i - 1, step of 1 */
		for (int j = 0; j < used - i - 1; j++) {

			/* 3.2 Compare arr[j] with arr[j + 1], if arr[j] > arr[j + 1] move to step 3.3, else continue */
			if (arr[j] > arr[j + 1]) {

				/* 3.3 Set temporary storage variable = arr[j], arr[j] = arr[j + 1] and then arr[j + 1] = temp */
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}