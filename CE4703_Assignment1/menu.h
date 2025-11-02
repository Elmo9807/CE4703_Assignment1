/**
* @file menu.h
* @brief Menu functions that demonstrate array operations
* @author Dylan O'Halloran
* @date 28/10/2025
*/

#ifndef MENU_H
#define MENU_H

/**
* @brief Menu Function 1 - Demonstrates array creation, filling, clearing, sorting and min/max operations
* 
* Creates an array with capacity 10 and performs the following operations:
* - Fills array with 7 random numbers
* - Prints used and all elements
* - Clears array
* - Prints used and all elements again
* - Fills with 5 random numbers (20-30)
* - Sorts array
* - Prints all elements
* - Displays minimum and maximum values
* 
*/

void menuFunction1(void);

/**
* @brief Menu Function 2 - Demonstrates array sorting and randomisation
*
* Creates an array with capacity 20 and performs the following operations:
* - Fills array with 15 random numbers (10-20)
* - Prints all elements
* - Sorts array
* - Prints sorted array
* - Randomises array
* - Prints randomised array
* 
*/

void menuFunction2(void);

/**
* @brief Menu Function 3 - Demonstrates keyboard input and statistical analysis
*
* Creates an array with capacity 100 and performs the following operations:
* - Fills array with values from keyboard
* - Displays minimum and maximum values
* - Displays average and median values
* 
*/

void menuFunction3(void);

#endif
