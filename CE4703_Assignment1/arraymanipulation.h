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
* @param arr array of integers to be filled
* @param size amount of random numbers to be added to the array
* @param capacity element max of the array
* @param min Minimum value in random range (inclusive)
* @param max Maximum value in random range (inclusive)
* @return Random integer in range [lowerLimit, upperLimit]
*/

void fillArrayRandom(int arr[], int size, int capacity, int min, int max);

#endif