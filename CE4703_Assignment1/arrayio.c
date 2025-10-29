/**
* @file arrayio.c
* @brief Implementation of array input functions
* @author Dylan O'Halloran
* @date 10/10/2025
*/

#define _CRT_SECURE_NO_WARNINGS

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
	int input;
	int i;

	for (i = 0; i < capacity; i++) {
		printf("Please enter your number: \n");
		(void)scanf("%d", &input);

		if (input < 0) {
			break;
		}

		arr[i] = input;
	}

	for (int j = i; j < capacity; j++) {
		arr[j] = UNUSED_MARKER;

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
	    3.3.1 If element equals UNUSED_MARKER, break from loop */
		if (arr[i] == UNUSED_MARKER)
			break;

		/* 3.3.2 If not first element, print comma and space */
		if (!first) {
			printf(", ");
		}

		/* 3.3.3 Print the element value */
		printf("%d", arr[i]);

		/* 3.3.4 Set flag 'first' to 0 */
		first = 0;
	}

	/* 4. Print closing brace
		4.1 Output character '}'
		4.2 Output newline character */
	printf("}\n");
}

/* 1. Receive array and its capacity as parameters */
void printAll(int arr[], int capacity)
{
	/* 2. Print opening brace:
	2.1 Output character '{'*/
	printf("{");

	/* 3. Iterate through array and print each value
    3.1 Initialise first with type int with a value of 1 */
	int first = 1;

	/* 3.2 Iterate for i from index 0 to capacity - 1, with a step of 1 */
	for (int i = 0; i < capacity; i++) {

		/* 3.3 For each element */

		/* 3.3.1 If not first element, print comma and space */
		if (!first) {
			printf(", ");
		}

		/* 3.3.2 Print the element value */
		printf("%d", arr[i]);

		/* 3.3.3 Set flag 'first' to 0 */
		first = 0;
	}

	/* 4. Print closing brace
		4.1 Output character '}'
		4.2 Output newline character */
	printf("}\n");
}