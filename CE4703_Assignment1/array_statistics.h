#ifndef ARRAY_STATISTICS.h
#define ARRAY_STATISTICS.h

/**
* @file array_statistics.h
* @brief Function grouping that outputs statistical analysis of the array elements
* @author Dylan OHalloran
* @date 22/10/2025
*/

/**
* @brief Accepts an array and its capacity, then returns the element with the lowest value in the array
*
* @param arr the integer array to print
* @param capacity the element limit of the array
*
* @return Minimum value found in the array
*/

int getMinimum(int arr[], int capacity);

/**
* @brief Accepts an array and its capacity, then returns the element with the highest value in the array
*
* @param arr the integer array to print
* @param capacity the element limit of the array
*
* @return Maximum value found in the array
*/

int getMaximum(int arr[], int capacity);

#endif