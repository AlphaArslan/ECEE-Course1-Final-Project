/**
 * @file data.c
 * @brief Basic data manipulation operations
 *
 * This implementation file provides functions to convert data
 * from integer representaion to ASCII string and vice versa.
 *
 * @author Mohamed Said
 * @date April 14 2020
 *
 */
#include "data.h"
#define   POW(x, y)   pow((float)x,(float)y)

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  // check on the sign
  if(data > 0){                                   // positive
    uint8_t index = 0;                                  // indicating the memory location
    uint8_t gen_digit;                                  // generated digit .. holds temp data in calculation
    // find out how many digits
    int8_t digit_count = 0;
    int32_t temp = data;
    do{digit_count++; temp /= base;}while(temp != 0);
    // convert to desired base and store in ASCII representaion
    temp = data;
    for(digit_count -= 1; digit_count >= 0; digit_count--, index++){
      gen_digit = (uint8_t)temp / (uint8_t)POW(base, digit_count);
      if(gen_digit < 10){
        *(ptr + index) = 48 + gen_digit;                // '0' is 48 in ascii table
      }else{
        *(ptr + index) = 65 + gen_digit-10;             // 'A' is 65 in ascii table
      }
      temp %= (uint8_t)POW(base, digit_count);
    }
    *(ptr + index) = 0;                                 // Null character at the end
    return index+1;                                     // return string length
  }else{                                          // negative
    data *= -1;                                         // convert to positive
    // put a minus sign "-" at the start
    *ptr = 45;                                          // '-' is 45 in ascii table
    return my_itoa(data, ptr+1, base)+1;
  }
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  return 0;
}
