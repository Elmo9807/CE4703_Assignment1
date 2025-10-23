/**
* @file array_statistics.c
* @brief Implementation of array statistic functions
* @author Dylan O'Halloran
* @date 23/10/2025
*/

#include <stdlib.h>
#include <stdio.h>
#include "config.h"

/**
* @brief Accepts an array and its capacity as parameters, using MIN macro to determine and return minimum element of the array
*
* @param arr the integer array to acquire the minimum element from
* @param capacity the element limit of the array
*
* @return integer value with the minimum element of the array
* 
*/

int getMinimum(int arr[], int capacity) 
{
	/* 1. Initialise minimum value to first array element
    1.1 Set minimum = arr[0] */
	int min = arr[0];

	/* 2. Iterate through array comparing each used element with current minimum
    2.1 Initialise for loop from index 0, run to capacity - 1, step of 1 */
	for(int i = 0; i < capacity; i++) {

		/* 2.2 At each index, check if arr[i] equals UNUSED_MARKER */
		/* 2.3 If arr[i] is UNUSED_MARKER, break from loop (unused elements are at end) */
		if(arr[i] == UNUSED_MARKER) {
			break;
		}

		/* 2.4 Otherwise, use MIN macro to compare: minimum = MIN(minimum, arr[i]) */
		min = MIN(min, arr[i]);

		/* 2.5 Continue until break condition or i reaches capacity - 1 */
	}

	/* 3. Return the minimum value found
	3.1 Return minimum to caller */
	return min;
}

/**
* @brief Accepts an array and its capacity as parameters, using MAX macro to determine and return maximum element of the array
* 
* @param arr the integer array acquire the maximum element from
* @param capacity the element limit of the array
*
* @return integer value with the maximum element of the array
*
*/

int getMaximum(int arr[], int capacity)
{
	/* 1. Initialise maximum value to first array element
    1.1 Set maximum = arr[0] */
	int max = arr[0];

	/* 2. Iterate through array comparing each used element with current maximum
    2.1 Initialise for loop from index 0, run to capacity - 1, step of 1 */
	for (int i = 0; i < capacity; i++) {

		/* 2.3 If arr[i] is UNUSED_MARKER, break from loop (unused elements are at end) */
		if (arr[i] == UNUSED_MARKER) {
			break;
		}

		/* 2.4 Otherwise, use MAX macro to compare: maximum = MAX(maximum, arr[i]) */
		max = MAX(max, arr[i]);

		/* 2.5 Continue until break condition or i reaches capacity - 1 */
	}

	/* 3. Return the maximum value found
	3.1 Return maximum to caller */
	return max;
}

/**
* @brief Accepts an array and its capacity as parameters, calculates the average of the used elements in the array, then returns average as a double
*
* @param arr the integer array to calculate the average of
* @param capacity the element limit of the array
*
* @return double value with the average of the used elements of the array
*
*/

double getAverage(int arr[], int capacity)
{
	/* 1. Initialise divisor and total to zero
    1.1 Set divisor = 0
    1.2 Set total = 0 */

	int divisor = 0;
	int total = 0;

	/* 2. Iterate through array summing used elements and counting them
    2.1 Initialise for loop from index 0, run to capacity - 1, step of 1 */
	for (int i = 0; i < capacity; i++) {

		/*  2.2 At each index, check if arr[i] equals UNUSED_MARKER
		2.3 If arr[i] is UNUSED_MARKER, break from loop (unused elements are at end) */
		if (arr[i] == UNUSED_MARKER) {
			break;
		}

		/* 2.4 Otherwise, add arr[i] to total: total = total + arr[i]
		2.5 Increment divisor: divisor = divisor + 1 */
		total += arr[i];
		divisor++;

		/* 2.6 Continue until break condition or i reaches capacity - 1 */
	}

	/* 3. Calculate and return the average as a double
    3.1 If divisor equals 0, return 0.0 (avoid division by zero) */
	if (divisor == 0) {
		return 0.0;
	}

	/* 3.2 Cast total to double and divide by divisor
	3.3 Return (double)total / divisor to caller */
	return (double)total / divisor;
}

double getMedian(int arr[], int capacity) 
{

	/* 1. Count the number of used elements in the array
    1.1 Initialise used = 0 */

	int used = 0;
	
	/* 1.2 Initialise for loop from index 0 to capacity - 1, step of 1 */
	for (int i = 0; i < capacity; i++) {

		/* 1.3 At each index, check if arr[i] equal UNUSED_MARKER */
		if (arr[i] == UNUSED_MARKER) {

			/* 1.4 If arr[i] is UNUSED_MARKER, break from loop */
			break;
		}

		/* 1.5 Otherwise, increment used by 1 */
		used++;
	}

	/*	2. Dynamically allocate and populate a temporary sorted array
		2.1 Dynamically allocate memory: tempArr = malloc(used * sizeof(int))
		2.2 Check if allocation succeeded (tempArr != NULL)
        2.2.1 If tempArr is NULL, return 0.0 */

	// Dynamic allocation of memory for temporary array
	int* tempArr = (int*)malloc(used * sizeof(int));

	// Malloc check to see if it succeeded
	if (tempArr == NULL) {
		
		// Handle error if malloc fails
		return 0.0;
	}

	/*	2.3 Copy used elements from arr to tempArr
        2.3.1 Initialise for loop from i = 0 to used - 1, step of 1
        2.3.2 Set tempArr[i] = arr[i] */
	for (int i = 0; i < used; i++) {
		tempArr[i] = arr[i];
	}

	/* 2.4 Sort tempArr using bubble sort algorithm
        2.4.1 Initialise outer loop from i = 0 to used - 2, step of 1
        2.4.2 Initialise inner loop from j = 0 to used - i - 2, step of 1
        2.4.3 If tempArr[j] > tempArr[j+1], swap:
            2.4.3.1 temp = tempArr[j]
            2.4.3.2 tempArr[j] = tempArr[j+1]
            2.4.3.3 tempArr[j+1] = temp */

	for (int i = 0; i < used - 1; i++) {
		for (int j = 0; j < used - i - 1; j++) {
			if (tempArr[j] > tempArr[j + 1]) {
				int temp = tempArr[j];
				tempArr[j] = tempArr[j + 1];
				tempArr[j + 1] = temp;
			}
		}
	}

	/*	3. Calculate the median value
		3.1 Calculate middle index: middle = used / 2
		3.2 Declare median as double
		3.3 If used is odd (used % 2 == 1):
        3.3.1 Return tempArr[middle] as double
		3.4 If used is even (used % 2 == 0):
        3.3.1 Calculate average of two middle values
        3.3.2 median = (tempArr[middle - 1] + tempArr[middle]) / 2.0 */

	int middle = used / 2;
	double median;

	if (used % 2 == 1) {
		median = (double)tempArr[middle];
	}
	else {
		median = (tempArr[middle - 1] + tempArr[middle]) / 2.0;
	}

	/*	4. Free allocated memory and return the median
		4.1 Call free(tempArr) to release dynamically allocated memory
		4.2 Return median to caller */
	free(tempArr);

	return median;
}