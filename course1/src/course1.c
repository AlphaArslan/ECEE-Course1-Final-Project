/**
 * @file cource1.c
 * @brief Testing all functionalities
 *
 * @author Mohamed Said
 * @date April 13 2020
 *
 */

#include "course1.h"
#include "memory.h"       // to test memory functions
#define LENGTH 5

int8_t course1(){
  return test_memmove1();
}

int8_t test_memmove1(){
    // non-overlapping data blocks
    uint8_t src_data[LENGTH] = {1, 2, 3, 4, 5};     // init with known values
    uint8_t dst_data[LENGTH];                       // no init [garbage]

    // moving src into dst
    if (my_memmove(src_data, dst_data, LENGTH) == NULL){
      return -1;                                    // my_memmove failed internally
    }
    // check if data moving is properly done. compare dst_data to safe_data
    for(int i = 0; i<LENGTH; i++){
      if(src_data[i] != dst_data[i]) return -1;     // my_memmove is not working properly
    }

    return 0 ;                                      // all is well
}
