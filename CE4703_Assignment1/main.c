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
#include "arraymanipulation.h"

int main(void) {
	printf("CE4703 Assignment 1 - Array Analysis Program\n");
	printf("=====================================\n");
	printf("Student: Dylan O'Halloran\n");
	printf("ID: Placeholder\n\n");

	printf("Project setup successful.\n");

	int myArray[20];
	int capacity = 20;
	int size = capacity; 
	int min = 15;
	int max = 20000;

	fillArrayRandom(myArray, size, capacity, min, max);

	sortArray(myArray, capacity);

	return EXIT_SUCCESS;
}