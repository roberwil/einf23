#ifndef LOOP_H
#define LOOP_H

#include "types.h"
#include <stdlib.h>
#include <stdio.h>

// Types of number
typedef enum {
    Integer = 1,
    Float,
    Double  
} LoopNumberType;

Class {
    int (*range)(int min, int max, int* counter);
    int (*range_with_step)(int min, int max, int _step, int* counter);
    int (*each_int)(int* array, int size, int* value);
    int (*each_int_with_index)(int* array, int size, int* value, int* index); 
    int (*each_float)(float* array, int size, float* value);
    int (*each_float_with_index)(float* array, int size, float* value, int* index);
    int (*each_double)(double* array, int size, double* value);
    int (*each_double_with_index)(double* array, int size, double* value, int* index);
    int (*each_char)(String array, char* value);
    int (*each_char_with_index)(String array, char* value, int* index);   
} LoopClass;


/**
 * Creates a range deifned as follows: 
 * [min; max[, min and max are part of Z
 * counter(1) = min, counter(n) = counter(n-1) + 1 if min < max
 * counter(1) = min, counter(n) = counter(n-1) - 1 if min > max
 * @min: the minimum value
 * @max: the maximum value
 * @counter: each value of the range
 * @return TRUE if the range is in its limits, FALSE if not 
 */ 
int loop_range(int min, int max, int* counter);

/**
 * Creates a range deifned as follows: 
 * [min; max[, min and max are part of Z
 * counter(1) = min, counter(n) = counter(n-1) + step_value if min < max
 * counter(1) = min, counter(n) = counter(n-1) - step_value if min > max
 * @min: the minimum value
 * @max: the maximum value
 * @step_value: the increment value
 * @counter: each value of the range
 * @return TRUE if the range is in its limits, FALSE if not 
 */
int loop_range_with_step(int min, int max, int _step, int* counter);

/**
 * Iterates an array of integers
 * @array: the array of integers to be iterated
 * @size: the size of the array
 * @value: holds each value of the array as long as it is being iterated
 * @return: TRUE if the array has reached its end, FALSE if not
 */ 
int loop_each_int(int* array, int size, int* value);

/**
 * Iterates an array of integers
 * @array: the array of integers to be iterated
 * @size: the size of the array
 * @value: holds each value of the array as long as it is being iterated
 * @index: the index of each value of the array as long as it is being iterated
 * @return: TRUE if the array has reached its end, FALSE if not
 */ 
int loop_each_int_with_index(int* array, int size, int* value, int* index);

/**
 * Iterates an array of floats
 * @array: the array of floats to be iterated
 * @size: the size of the array
 * @value: holds each value of the array as long as it is being iterated
 * @return: TRUE if the array has reached its end, FALSE if not
 */ 
int loop_each_float(float* array, int size, float* value);

/**
 * Iterates an array of floats
 * @array: the array of floats to be iterated
 * @size: the size of the array
 * @value: holds each value of the array as long as it is being iterated
 * @index: the index of each value of the array as long as it is being iterated
 * @return: TRUE if the array has reached its end, FALSE if not
 */ 
int loop_each_float_with_index(float* array, int size, float* value, int* index);

/**
 * Iterates an array of doubles
 * @array: the array of doubles to be iterated
 * @size: the size of the array
 * @value: holds each value of the array as long as it is being iterated
 * @return: TRUE if the array has reached its end, FALSE if not
 */ 
int loop_each_double(double* array, int size, double* value);

/**
 * Iterates an array of doubles
 * @array: the array of doubles to be iterated
 * @size: the size of the array
 * @value: holds each value of the array as long as it is being iterated
 * @index: the index of each value of the array as long as it is being iterated
 * @return: TRUE if the array has reached its end, FALSE if not
 */ 
int loop_each_double_with_index(double* array, int size, double* value, int* index);

/**
 * Iterates an array of chars, which is string
 * @array: the string to be iterated
 * @value: holds each value of the string as long as it is being iterated
 * @return: TRUE if the array has reached its end, FALSE if not
 */ 
int loop_each_char(String array, char* value);

/**
 * Iterates an array of chars, which is string
 * @array: the string to be iterated
 * @value: holds each value of the string as long as it is being iterated
 * @index: the index of each value of the array as long as it is being iterated
 * @return: TRUE if the array has reached its end, FALSE if not
 */ 
int loop_each_char_with_index(String array, char* value, int* index);

#endif