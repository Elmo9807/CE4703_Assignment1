/**
* @file main.c
* @brief Main entry point for array analysis program
* @author Dylan O'Halloran
* @date 10/10/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include "arrayio.h"
#include "config.h"

int main(void) {
	printf("CE4703 Assignment 1 - Array Analysis Program\n");
	printf("=====================================\n");
	printf("Student: Dylan O'Halloran\n");
	printf("ID: Placeholder\n\n");

	printf("Project setup successful.\n");

	int capacity = 20;
	int testArray[20];

	fillArrayFromKeyboard(testArray, capacity);

	return EXIT_SUCCESS;
}