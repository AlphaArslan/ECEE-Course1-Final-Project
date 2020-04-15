/**
 * @file course1.h
 * @brief Testing all functionalities
 *
 * This header file provides testing functions to verify the
 * working of other functions like, my_memmove, my_memcopy and others
 *
 * @author Mohamed Said
 * @date April 13 2020
 *
 */
#ifndef __COURSE1_H__
#define __COURSE1_H__
#include "platform.h"

/**
 * @brief Calls different test functions
 *
 * This function is called by main(), and on its turn calls other
 * test functions one at a time.
 *
 *
 * @return int8_t   0  if successfull
 *                 -1  if failed
 */
int8_t course1();

/**
 * @brief Test integer to ASCII conversion
 *
 * This function sends positive and negative integers
 * (for different bases) to my_itoa() [data.h] and print
 * the results.
 *
 * @return int8_t   0
 *
 */
int8_t test_data1();

/**
 * @brief Test ASCII to integer conversion
 *
 * This function sends strings of positive and negative integers
 * (for different bases) to my_atoi() [data.h] and compare
 * the results to an expected value.
 *
 * @return int8_t   0  if successfull
 *                 -1  if failed
 */
int8_t test_data2();

/**
 * @brief Sends non-overlapped data blocks to my_memmove()
 *
 * This function gives non-overlapping source and destination
 * data block to my_memmove() function [memory.h]
 *
 * @return int8_t   0  if successfull
 *                 -1  if failed
 */
int8_t test_memmove1();

/**
 * @brief Sends overlapped data blocks to my_memmove()
 *
 * overlapping happins at the end of destination and start of
 * the source data blocks
 *
 * @return int8_t   0  if successfull
 *                 -1  if failed
 */
int8_t test_memmove2();

/**
 * @brief Sends overlapped data blocks to my_memmove()
 *
 * overlapping happins at the start of destination and end of
 * the source data blocks
 *
 * @return int8_t   0  if successfull
 *                 -1  if failed
 */
int8_t test_memmove3();

/**
 * @brief Sends non-overlapped data blocks to my_memcopy()
 *
 * This function gives non-overlapping source and destination
 * data block to my_memcopy() function [memory.h]
 *
 * @return int8_t   0  if successfull
 *                 -1  if failed
 */
int8_t test_memcopy();

/**
 * @brief Sends a value to be written in all elements of
 * a data block
 *
 * This function tests my_memset() and my_memzero()
 * functions [memory.h]
 *
 * @return int8_t   0  if successfull
 *                 -1  if failed
 */
int8_t test_memset();

/**
 * @brief Sends a data block for the elements to be reversed
 * in order
 *
 * This function tests my_reverse() function [memory.h]
 *
 * @return int8_t   0  if successfull
 *                 -1  if failed
 */
int8_t test_reverse();

#endif /* __COURSE1_H__ */
