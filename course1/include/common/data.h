/**
 * @file data.h
 * @brief Basic data manipulation
 *
 * This header file provides basic data manipulation functions
 *
 * @author Mohamed Said
 * @date April 14 2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__
#include "platform.h"

/**
 * @brief converts integer to ASCII string
 *
 * This function converts an integer (ex, 1234) to ASCII string
 * representaion (ex, "1234"). It supports signed numbers and up
 * to base of 16 (Hexadecimal).
 *
 * @param   data  int32_t number to be converted
 * @param   ptr   uint8_t* pointer to memory space where ASCII
 *                string gets stored
 * @param   base  uint32_t number base. Ex, 2 (Binary), 10 (decimal)
 *
 * @return uint8_t   number of characters (including NULL character)
 *                    -1 if failed
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief converts ASCII string to integer
 *
 * This function converts an ASCII string (ex, "1234") to
 * integer (ex, 1234). It supports signed numbers and up
 * to base of 16 (Hexadecimal).
 *
 * @param   ptr   uint8_t* pointer ASCII string to be converted
 * @param  digits uint8_t number of digits in the ASCII string. sign is not counted.
 * @param   base  uint32_t number base. Ex, 2 (Binary), 10 (decimal)
 *
 * @return int32_t   integer value after conversion
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
#endif /* __DATA_H__ */
