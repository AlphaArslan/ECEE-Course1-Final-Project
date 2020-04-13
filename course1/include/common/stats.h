/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file:   stats.h
 * @brief:  perfoming statistical operations on an array (i.e. finding mean, median, max and min values),
 *          as well as sorting and printing the array.
 *
 * Extended Discribrion:
 *    - Provided an array of N elements, we do:
 *        - find the mean value.
 *        - find the median value.
 *        - find the max value.
 *        - find the min value.
 *        - sort the array from largest to smallest.
 *        - print the sorted array along with all statistical values mentioned above.
 *
 * @author: Mohamed Said
 * @date:   5 April, 2020
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief:  find the mean value.
 *
 * The mean value = sum of all elements / number of those elements
 *
 * @param:  pArray,    a pointer to a sorted array containing data [char*]
 * @param:  ArraySize, the number of array elements [char]
 *
 * @return: the mean value [unsigned char]
 */
unsigned char find_mean( unsigned char * pArray, char arraySize);

/**
 * @brief:  find the median value.
 *
 * The median is the value present at the centre of a sorted array
 *
 * @param:  pArray,    a pointer to a sorted array containing data [char*]
 * @param:  ArraySize, the number of array elements [char]
 *
 * @return: the median value [unsigned char]
 */
unsigned char find_median( unsigned char * pArray, char arraySize);

/**
 * @brief:  find the max value.
 *
 * finding the element of the largest value.
 *
 * @param:  pArray,    a pointer to a sorted array containing data [char*]
 * @param:  ArraySize, the number of array elements [char]
 *
 * @return: the maximum value [unsigned char]
 */
unsigned char find_max( unsigned char * pArray, char arraySize);

/**
 * @brief:  find the min value.
 *
 * finding the element of the smallest value.
 *
 * @param:  pArray,    a pointer to a sorted array containing data [char*]
 * @param:  ArraySize, the number of array elements [char]
 *
 * @return: the minimum value [unsigned char]
 */
unsigned char find_min( unsigned char * pArray, char arraySize);

/**
 * @brief:  sorting an array from largest to smallest
 *
 * sorting an array such as the zeroth Element should be the largest value, and the last element (n-1) should be the smallest value
 *
 * @param:  pArray,    a pointer to the array containing data [char*]
 * @param:  ArraySize, the number of array elements [char]
 *
 * @return: void / None
 */
void sort_array( unsigned char * pArray, char arraySize);

/**
 * @brief:  printing an array
 *
 * @param:  pArray,    a pointer to a sorted array containing data [char*]
 * @param:  ArraySize, the number of array elements [char]
 *
 * @return: void / None
 */
void print_array( unsigned char * pArray, char arraySize);

/**
 * @brief:  printing statisticalvalues of an array
 *
 * printing values of mean, median, max and min.
 *
 * @param:  pArray,    a pointer to a sorted array containing data [char*]
 * @param:  ArraySize, the number of array elements [char]
 *
 * @return: void / None
 */
void print_statistics( unsigned char * pArray, char arraySize);


#endif /* __STATS_H__ */

