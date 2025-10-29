/**
* @file array_statistics.c
* @brief Implementation of array statistic functions
* @author Dylan O'Halloran
* @date 23/10/2025
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "config.h"
#include "array_statistics.h"

/**
 * @brief Count and return the number of used elements in an array
 *
 * @param arr the integer array to analyse
 * @param capacity the element limit of the array
 *
 * @return int the number of used (non-UNUSED_MARKER) elements
 *
 */

int countUsedElements(int arr[], int capacity)
{
	/* 1. Initialise counter for used elements */
	/* 1.1 Set used = 0 */
	int used = 0;

	/* 2. Iterate through array counting used elements */
	/* 2.1 Initialise for loop from index 0 to capacity - 1, step of 1 */
	for (int i = 0; i < capacity; i++) {

		/* 2.2 At each index, check if arr[i] = UNUSED_MARKER */
		/* 2.3 If arr[i] is UNUSED_MARKER, break from loop (unused elements are at end) */
		if (arr[i] == UNUSED_MARKER) {
			break;
		}

		/* 2.4 Otherwise, increment used by 1 */
		/* 2.5 Continue until break condition or i reaches capacity - 1 */
		used++;
	}

	/* 3. Return the count */
	/* 3.1 Return used to caller */
	return used;
}

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

	// error handling to check if element at arr[0] is unused, if so, return UNUSED MARKER
	if (arr[0] == UNUSED_MARKER) {
		fprintf(stderr, "Error, cannot find minimum of empty array\n");
		return UNUSED_MARKER;
	}

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

	if (arr[0] == UNUSED_MARKER) {
		fprintf(stderr, "Error, cannot find maximum of empty array\n");
		return UNUSED_MARKER;
	}

	int max = arr[0];

	/* 2. Iterate through array comparing each used element with current maximum
    2.1 Initialise for loop from index 0, run to capacity - 1, step of 1 */
	for (int i = 0; i < capacity; i++) {

		/* 2.2 At each index, check if arr[i] equals UNUSED_MARKER */
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


/**
* @brief Accepts an array and its capacity as parameters, calculates the median of the elements in the array, then returns the middle element if it is odd or the average of the middle elements if it is even
*
* @param arr the integer array to calculate the average of
* @param capacity the element limit of the array
*
* @return double value with median
*
*/

double getMedian(int arr[], int capacity) 
{

	/* 1. Count the number of used elements in the array
		1.1 Initialise used = countUsedElements(arr, capacity) */
	int used = countUsedElements(arr, capacity);

	// error handling in case of empty array
	if (used == 0) {
		return 0.0;
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
		2.4.3 Bounds check to satisfy Build+Intellisense
        2.4.4 If tempArr[j] > tempArr[j+1], swap:
            2.4.4.1 temp = tempArr[j]
            2.4.4.2 tempArr[j] = tempArr[j+1]
            2.4.4.3 tempArr[j+1] = temp */

	if (used > 1) {
		for (int i = 0; i < used - 1; i++) {
			for (int j = 0; j < used - i - 1; j++) {
				// bounds check due to Build+Intellisense analyser being unable to verify bounds
				if (j + 1 < used) {
					if (tempArr[j] > tempArr[j + 1]) {
						int temp = tempArr[j];
						tempArr[j] = tempArr[j + 1];
						tempArr[j + 1] = temp;
					}
				}
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

/**
* @brief Compute and return the variance of an array of integers
*
* Variance v of {n1, n2, n3, ..., nN} is calculated as:
* v = Σ(ni - avg}^2 / N
* where avg is the average value and N is the number of used elements
*
* @param arr the integer array to compute variance for
* @param capacity the element limit of the array
*
* @return the variance as a double, or 0.0 if no used elements exist
*
*/

double getVariance(int arr[], int capacity)
{
	/* 1.1 Initialise used as type int and set to return value of countUsedElements(arr, capacity) */
	int used = countUsedElements(arr, capacity);

	/* 1.2 If no used elements exist, return 0.0 */
	if (used == 0) {
		return 0.0;
	}

	/* 1.3 Initialise sum for calculating average */
	int sum = 0;

	/* 1.4 Initialise varianceSum for accumulating squared differences */
	double varianceSum = 0.0;

	/* 1.5 Initialise avg to store the average value */
	double avg;

	/* 2. Count the number of used elements in the array */

	/* 3. Calculate the average of used elements */

	/* 3.1 Iterate through used elements from 0 to used - 1 */
	for (int i = 0; i < used; i++) {

		/* 3.2 Add each element to sum */
		sum += arr[i];
	}

	/* 3.3 Calculate average by dividing sum by number of used elements */
	avg = (double)sum / used;

	/* 4. Calculate variance using the formula Σ(ni - avg)² / N */

	/* 4.1 Iterate through used elements from 0 to used - 1 */
	for (int i = 0; i < used; i++) {

		/* 4.2 Calculate difference between element and average */
		double difference = arr[i] - avg;

		/* 4.3 Square the difference and add to varianceSum */
		varianceSum += difference * difference;
	}

	/* 4.4 Calculate final variance by dividing sum of squared differences by count */
	return varianceSum / used;
}

/**
 * @brief Calculate and return the standard deviation of used elements in an array
 *
 * Standard deviation is calculated as: √(Σ(ni - avg)^2 / N)
 * where avg is the average value and N is the number of used elements
 *
 * @param arr the integer array to analyse
 * @param capacity the element limit of the array
 *
 * @return double the standard deviation of used elements, or 0.0 if no elements used
 *
 */


double getStandardDeviation(int arr[], int capacity)
{
	/* 1. Calculate variance using getVariance() */

	/* 1.1 Call getVariance(arr, capacity) and store result in variance */
	double variance = getVariance(arr, capacity);

	/* 2. Calculate and return standard deviation as square root of variance */

	/* 2.1 Calculate standardDeviation = sqrt(variance) */
	double standardDeviation = sqrt(variance);

	/* 2.2 Return standardDeviation */
	return standardDeviation;
}