#ifndef CONFIG_H
#define CONFIG_H

/**
* @file config.h
* @brief Configuration macros and constants for array analysis program
* @author Dylan OHalloran
* @date 10/10/2025
*/

/* Preprocessor Macro - Marks unused array positions */
#define UNUSED_MARKER -1

/* Maximum array capacity */
#define MAX_CAPACITY 1000

/* Preprocessor Macros with Parameters */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#endif