/**
* @file arrayio.h
* @brief Array input output functions for filling an array
* @author Dylan O'Halloran
* @date 13/10/2025
*/

#ifndef ARRAYIO_H
#define ARRAYIO_H

/**
* @brief Fills an array with values from the keyboard inputs
* 
* Reads integer values from input and stores them in the array
* Input terminates when negative value or array capacity are encountered
* All remaining elements are marked as unused, if applicable (-1)
* 
* @param arr The integer array to fill
* @param capacity The maximum number of elements the array can hold
* 
*/

void fillFromKeyboard(int arr[], int capacity);

/**
* @brief Accepts an array and its capacity, then iterates through the elements, printing only used elements
*
* @param arr the integer array to print
* @param capacity the element limit of the array
* 
*/

void printUsed(int arr[], int capacity);

/**
* @brief Accepts an array and its capacity, then iterates through the elements, printing all elements
*
* @param arr the integer array to print
* @param capacity the element limit of the array
*
*/

void printAll(int arr[], int capacity);

#endif