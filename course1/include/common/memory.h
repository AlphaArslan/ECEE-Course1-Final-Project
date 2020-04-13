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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 * Modified by Mohamed Said, April,13,2020
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
#include "platform.h"

/**
 * @brief Sets a value of a data array
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero.
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves a block of Data
 *
 * Given a pointer to a uint8_t data block source address, the
 * size of the block, and the destination address, this will move
 * the data block to the new destination memory location
 *
 * @param src       Pointer to data black
 * @param dst       Pointer to new data black locaiton
 * @param length    number of elements in the data block
 * @return uint8_t* Pointer to new data black locaiton
 *                  or Null pointer if failed
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies a block of Data
 *
 * Given a pointer to a uint8_t data block source address, the
 * size of the block, and the destination address, this will copy
 * the data block to the new destination memory location
 *
 * @param src       Pointer to data black
 * @param dst       Pointer to new data black locaiton
 * @param length    number of elements in the data block
 * @return uint8_t* Pointer to new data black locaiton
 *                  or Null pointer if failed
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a block of Data to a value
 *
 * Given a pointer to a uint8_t data block source address, the
 * size of the block, this will set all data elements to the
 * desired uint8_t value
 *
 * @param src       Pointer to data black
 * @param length    number of elements in the data block
 * @param value     uint8_t value to be written in all elements
 *
 * @return uint8_t* Pointer to data black
 *                  or Null pointer if failed
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets a block of Data to a value
 *
 * Given a pointer to a uint8_t data block source address, the
 * size of the block, this will set all data elements to the
 * desired uint8_t value
 *
 * @param src       Pointer to data black
 * @param length    number of elements in the data block
 * @param value     uint8_t value to be written in all elements
 *
 * @return uint8_t* Pointer to data black
 *                  or Null pointer if failed
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets a block of Data to a Zero
 *
 * Given a pointer to a uint8_t data block source address, the
 * size of the block, this will set all data elements to Zero
 *
 * @param src       Pointer to data black
 * @param length    number of elements in the data block
 *
 * @return uint8_t* Pointer to data black
 *                  or Null pointer if failed
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of all of the elements
 *
 * Given a pointer to a uint8_t data block source address, the
 * size of the block, this will reverse the order of all of
 * the elements
 *
 * @param src       Pointer to data black
 * @param length    number of elements in the data block
 *
 * @return uint8_t* Pointer to data black
 *                  or Null pointer if failed
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates a number of words in dynamic memory
 *
 * Given the number of int32_t elements, this will reserve
 * space in dynamic memory and the return the address to
 * the first element
 *
 * @param length    number of elements
 *
 * @return int32_t* Pointer to reserved memory black
 *                  or Null pointer if failed
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees a dynamic memory allocation
 *
 * Given int32_t* pointer to memory location to be freed
 * this will free the memory location
 *
 * @param src       Pointer to memory location
 *
 * @return void.
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
