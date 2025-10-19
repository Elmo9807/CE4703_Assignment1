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

void fillFromKeyboard(int arr[], int capacity)
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

/**
* @brief Accepts an array and its capacity, then iterates through the elements, printing only used elements
*
* @param arr the integer array to fill
* @param capacity the element limit of the array
*/


/* 1. Receive array and capacity as parameters */
void printUsed(int arr[], int capacity) 
{
	/* 2. Print opening brace */

	/* 2.1 Output the character '{' */
	printf("{");

	/* 3. Iterate through array and print used elements with commas */

	/* 3.1 Initialise first as type int with value of 1 */
	int first = 1;

	/* 3.2 Iterate for i from index 0 to capacity - 1 */
	for (int i = 0; i < capacity; i++) {

		/* 3.3 For each element :
	    3.3.1 If element equals UNUSED_MARKER, break from loop
		3.3.2 If not first element, print comma and space
		3.3.3 Print the element value
		3.3.4 Set flag 'first' to 0 */
		if (arr[i] == UNUSED_MARKER)
			break;

		if (!first)
			printf(", ");
		printf("%d", arr[i]);
		first = 0;
	}

	/* 4. Print closing brace
	4.1 Output character '}'
	4.2 Output newline character */
	printf("}\n");
}