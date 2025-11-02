/**
* @file arraymanipulation.h
* @brief Array manipulation function header file
* @author Dylan OHalloran
* @date 16/10/2025
*/

#ifndef ARRAYMANIPULATION_H
#define ARRAYMANIPULATION_H

/**
* @brief Fill array to size with random integers using generateRandomNumber
* 
* @param arr array of integers to be filled
* @param size amount of random numbers to be added to the array
* @param capacity element max of the array
* @param min Minimum value in random range (inclusive)
* @param max Maximum value in random range (inclusive)
* 
*/

void fillArrayRandom(int arr[], int size, int capacity, int min, int max);

/**
* @brief Accepts an array and the array capacity, then "clears" all index values by assigning them the UNUSED_MARKER
*
* @param arr the integer array to clear
* @param capacity the element limit of the array
*
*/

void clearArray(int arr[], int capacity);


/**
* @brief Accepts an array and the array capacity, differentiates between unused and used indices, then sorts the used indices in ascending order and the unused are sorted to the end of the array
*
* @param arr the integer array to sort
* @param capacity the element limit of the array
*
*/

void sortArray(int arr[], int capacity);

/**
* @brief Accepts an array and the array capacity, differentiates between unused and used indices, then applies Fisher-Yates shuffling algorithm to randomise the element positions
*
* @param arr the integer array to sort
* @param capacity the element limit of the array
*
*/

void randomiseArray(int arr[], int capacity);

#endif