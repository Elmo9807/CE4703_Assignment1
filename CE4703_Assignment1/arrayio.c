/**
* @file arrayio.c
* @brief Implementation of array input functions
* @author Dylan O'Halloran
* @date 10/10/2025
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arrayio.h"
#include "config.h"

/**
* @brief Accepts keyboard input from user to populate an array, terminating on capacity reach or negative input
* 
* @param arr the integer array to fill
* @param capacity the element limit of the array
*/

void fillArrayFromKeyboard(int arr[], int capacity)
{
	int i = 0;
	int input;

	for (i; i < capacity; i++) {
		printf("Please enter your number: \n");
		scanf_s("%d", &input);

		if (input < 0) {
			break;
		}

		arr[i] = input;
	}

	for (int j = i; j < capacity; j++) {
		arr[j] = UNUSED_MARKER;

	}

	for (int z = 0; z < capacity; z++) {
		printf("Value at index %d is %d\n", z, arr[z]);
	}
}