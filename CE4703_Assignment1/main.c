/**
* @file main.c
* @brief Main entry point for array analysis program
* @author Dylan O'Halloran
* @date 10/10/2025
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "arrayio.h"
#include "config.h"
#include "menu.h"
#include "arraymanipulation.h"

int main(int argc, char *argv[]) {
	printf("CE4703 Assignment 1 - Array Analysis Program\n");
	printf("=====================================\n");
	printf("Student: Dylan O'Halloran\n");
	printf("ID: 17238811\n\n");

	int choice;

	printf("Project setup successful.\n");

	/* Main menu loop */
	do {

		/* Display menu options as specified in assignment */
		printf("\n");
		printf("1. Perform MF1\n");
		printf("2. Perform MF2\n");
		printf("3. Perform MF3\n");
		printf("4. Terminate the program\n");
		printf("Enter your choice: ");

		/* Read user's menu choice */
		(void)scanf("%d", &choice);

		/* Process user choice */
		switch (choice) {
		case 1:
			menuFunction1();
			break;
		case 2:
			menuFunction2();
			break;
		case 3:
			menuFunction3();
			break;
		case 4:
			printf("\nTerminating program...\n");
			break;
		default:
			printf("\nInvalid choice. Please select 1-4.\n");
		}

	} while (choice != 4);

	return EXIT_SUCCESS;
}