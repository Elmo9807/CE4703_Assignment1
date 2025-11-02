/**
* @file menu.c
* @brief Implementation of menu functions
* @author Dylan O'Halloran
* @date 28/10/2025
*/

#include <stdio.h>
#include "menu.h"
#include "config.h"
#include "arrayio.h"
#include "arraymanipulation.h"
#include "array_statistics.h"

/**
* @brief Menu Function 1 - Demonstrates basic array operations
*
* Creates an array of capacity 10 and performs the following sequence:
* - Fills with 7 random numbers (range 10-20)
* - Prints used and all elements
* - Clears the array
* - Prints array state after clearing
* - Fills with 5 random numbers (range 20-30)
* - Sorts the array in ascending order
* - Displays minimum and maximum values
*
* All output is printed to stdout with descriptive labels.
*/

void menuFunction1(void) 
{
	/* 2 newlines */
	printf("\n\n");

	/* 1. Create array with capacity 10 */
	int arr[10];
	int capacity = 10;

	printf("Menu Function 1: Array Operations Demo\n");
	printf("========================================\n");

	/* 2. Call WF3 to fill array with 7 random numbers, range 10 to 20 */
	printf("\nFilling array with 7 random numbers (10-20 inclusive)...\n");
	fillArrayRandom(arr, 7, capacity, 10, 20);

	/* 3. Use WF7 to print only used elements */
	printf("Used elements: ");
	printUsed(arr, capacity);

	/* 4. Use WF8 to print all elements */
	printf("All elements: ");
	printAll(arr, capacity);

	/* 5. Use WF4 to clear array */
	printf("\nClearing array\n");
	clearArray(arr, capacity);

	/* 6. Use WF7 to print only used elements */
	printf("Used elements after clear: ");
	printUsed(arr, capacity);

	/* 7. Use WF8 to print all elements */
	printf("All elements after clear: ");
	printAll(arr, capacity);

	/* 8. Use WF3 to fill array with 5 random numbers in range 20 to 30 */
	printf("\nFilling array with 5 random numbers (20-30 inclusive)...\n");
	fillArrayRandom(arr, 5, capacity, 20, 30);

	/* 9. Use WF5 to sort array */
	printf("Sorting array...\n");
	sortArray(arr, capacity);

	/* 10. Use WF8 to print all elements */
	printf("All elements after sort: ");
	printAll(arr, capacity);

	/* 11. Print minimum and maximum values using WF9 and WF10 */
	int min = getMinimum(arr, capacity);
	int max = getMaximum(arr, capacity);
	printf("\nMinimum value: %d\n", min);
	printf("Maximum value: %d\n", max);

	/* End with 2 newlines */
	printf("\n\n");
}

/**
* @brief Menu Function 2 - Demonstrates array sorting and randomisation
*/

void menuFunction2(void)
{
	/* Start with 2 newlines */
	printf("\n\n");

	/* 1. Create an array with capacity 20 */
	int arr[20];
	int capacity = 20;

	printf("Menu Function 2: Sorting and Randomisation Demo\n");
	printf("================================================\n");

	/* 2. Use WF3 to fill array with 15 random numbers in range 10 to 20 */
	printf("\nFilling array with 15 random numbers (10-20)...\n");
	fillArrayRandom(arr, 15, capacity, 10, 20);

	/* 3. Use WF8 to print all elements */
	printf("All elements: ");
	printAll(arr, capacity);

	/* 4. Use WF5 to sort array */
	printf("\nSorting array...\n");
	sortArray(arr, capacity);

	/* 5. Use WF8 to print all elements */
	printf("All elements after sort: ");
	printAll(arr, capacity);

	/* 6. Use WF6 to randomise array */
	printf("\nRandomising array...\n");
	randomiseArray(arr, capacity);

	/* 7. Use WF8 to print all elements */
	printf("All elements after randomise: ");
	printAll(arr, capacity);

	/* End with 2 newlines */
	printf("\n\n");
}

/**
* @brief Menu Function 3 - Demonstrates keyboard input and statistical analysis
*/

void menuFunction3(void)
{
	/* Start with 2 newlines */
	printf("\n\n");

	/* 1. Create an array with capacity 100 */
	int arr[100];
	int capacity = 100;

	printf("Menu Function 3: Keyboard Input and Statistics\n");
	printf("===============================================\n");

	/* 2. Use WF2 to fill array with values from keyboard */
	printf("\nEnter integer values (negative number to stop):\n");
	fillFromKeyboard(arr, capacity);

	/* 3. Print minimum and maximum values using WF9 and WF10 */
	int min = getMinimum(arr, capacity);
	int max = getMaximum(arr, capacity);
	printf("\nMinimum value: %d\n", min);
	printf("Maximum value: %d\n", max);

	/* 4. Print average and median values using WF11 and WF12 */
	double avg = getAverage(arr, capacity);
	double median = getMedian(arr, capacity);
	printf("Array has average value %.2f and median value %.2f\n", avg, median);

	/* 5. Print variance and standard deviation using WF13, WF14, and WF15 */
	int usedCount = countUsedElements(arr, capacity);
	double variance = getVariance(arr, capacity);
	double stdDev = getStandardDeviation(arr, capacity);
	printf("Array with %d used elements has variance %.2f and standard deviation %.2f\n", usedCount, variance, stdDev);

	/* End with 2 newlines */
	printf("\n\n");
}