/**
* @file array_statistics.h
* @brief Function grouping that outputs statistical analysis of the array elements
* @author Dylan OHalloran
* @date 22/10/2025
*/

#ifndef ARRAY_STATISTICS_H
#define ARRAY_STATISTICS_H

/**
 * @brief Count and return the number of used elements in an array
 *
 * @param arr the integer array to analyse
 * @param capacity the element limit of the array
 *
 * @return int the number of used (non-UNUSED_MARKER) elements
 *
 */

int countUsedElements(int arr[], int capacity);

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

/**
* @brief Accepts an array and its capacity as parameters, calculates the average of the used elements in the array, then returns average as a double
*
* @param arr the integer array to calculate the average of the elements of the array
* @param capacity the element limit of the array
*
* @return double value with the average of the used elements of the array
*
*/

double getAverage(int arr[], int capacity);

/**
* @brief Accepts an array and its capacity as parameters, calculates the median of the elements in the array, then returns the middle element if it is odd or the average of the middle elements if it is even
*
* @param arr the integer array to calculate the average of
* @param capacity the element limit of the array
*
* @return double value with median
*
*/

double getMedian(int arr[], int capacity);

/**
* @brief Compute and return the variance of an array of integers
* 
* Variance v of {n1, n2, n3, ..., nN} is calculated as:
* v = Σ(ni - avg}^2 / N
* where avg is the average value and N is the number of used elements
* 
* @param arr the integer array to compute variance for
* @param capacity the element limit of the array
* 
* @return the variance as a double, or 0.0 if no used elements exist
* 
*/

double getVariance(int arr[], int capacity);

/**
 * @brief Calculate and return the standard deviation of used elements in an array
 *
 * Standard deviation is calculated as: √(Σ(ni - avg)^2 / N)
 * where avg is the average value and N is the number of used elements
 *
 * @param arr the integer array to analyse
 * @param capacity the element limit of the array
 * 
 * @return double the standard deviation of used elements, or 0.0 if no elements used
 * 
 */


double getStandardDeviation(int arr[], int capacity);

#endif