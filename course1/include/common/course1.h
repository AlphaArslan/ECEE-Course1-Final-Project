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
 * test functions one by one
 *
 *
 * @return int8_t   0  if successfull
 *                  -1 if failed
 */
int8_t course1();

/**
 * @brief Tests non-overlapped memmove
 *
 * This function gives non-overlapping source and destination of
 * a data block to memmove() function [memory.h]
 *
 * @return int8_t   0  if successfull
 *                  -1 if failed
 */
int8_t test_memmove1();
int8_t test_memmove2();
int8_t test_memmove3();
int8_t test_memcopy();
int8_t test_memset();

#endif /* __COURSE1_H__ */
