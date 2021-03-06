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
#include "data.h"         // to test data functions

// if you change any of LENGTH or OVRLAP, make sure you change array initialization values
#define LENGTH 5          // number of elements of src (or dst)
#define OVRLAP 3          // number of elements overlapped by src and dst
#define VALUE  21         // used in test_memset
#define BUFFER 20         // used in test_data1, test_data2

/***********************************************************
 Function Definitions
***********************************************************/
int8_t course1(){
  return test_data1();        // replace test_data1 with any other test function
}

int8_t test_data1(){
  // buffer is where we store the result string
  uint8_t buffer[BUFFER];
  // change num and base to get different test combinations
  int32_t num = -100;
  uint32_t base = 16;
  my_itoa(num, buffer, base);                 // this line is to avoid variable-unused warning
                                              // when building for MSP432 target
  PRINTF("num: %d ,base %d\n", num, base);
  PRINTF("string length: %d\n", my_itoa(num, buffer, base));
  PRINTF("buffer: %s\n", buffer);
  return 0;
}

int8_t test_data2(){
  // change str, base, digits and expected to get different test combinations
  char * str       = "-1A" ;
  uint32_t base    =  16 ;
  uint8_t digits   =  2 ;                     // the sign is not counted
  int32_t expected = -26 ;
  if(my_atoi((uint8_t*)str, digits, base) == -26){
    return 0;
  }else{
    return -1;
  }
}

int8_t test_memmove1(){
    // non-overlapping data blocks
    uint8_t src_data[LENGTH] = {1, 2, 3, 4, 5};     // init with known values
    uint8_t dst_data[LENGTH];                       // no init [garbage]
    // moving src into dst
    if (my_memmove(src_data, dst_data, LENGTH) == NULL){
      return -1;                                    // my_memmove failed internally
    }
    // check if data moving is properly done. compare dst_data to src_data
    for(int i = 0; i<LENGTH; i++){
      if(src_data[i] != dst_data[i]) return -1;     // my_memmove is not working properly
    }
    return 0 ;                                      // all is well
}

int8_t test_memmove2(){
  //overlap happens at the end of dst and the start of src
  /* create a unity block of src and dst ( src U dst )
  * the size will be 2*LENGTH-OVRLAP
  *     --------dst--------         |   0 0 0 0 0         (i will init dst as zeros)
  *            --------src--------  |       1 2 3 4 5     (src overwrites dst)
  *     ----------unity-----------  |   0 0 1 2 3 4 5     (so we start with this unity)
  *
  * if done correctly,
  *            --------src--------  |       1 2 3 4 5     (older values of src)
  *     --------dst--------         |   1 2 3 4 5         (dst will clone src and overwrite it)
  *     ----------unity-----------  |   1 2 3 4 5 4 5     (and the new unity should be like so)
  */
  uint8_t start_unity[2*LENGTH-OVRLAP] = {0, 0, 1, 2, 3, 4, 5};
  uint8_t expected_unity[2*LENGTH-OVRLAP] = {1, 2, 3, 4, 5, 4, 5};
  // assign addresses of src and dst as subsets of start_unity
  uint8_t * src = start_unity + LENGTH - OVRLAP;
  uint8_t * dst = start_unity;
  // moving src into dst
  if (my_memmove(src, dst, LENGTH) == NULL){
    return -1;                                    // my_memmove failed internally
  }
  // check if data moving is properly done. compare start_unity to expected_unity
  for(int i = 0; i<LENGTH; i++){
    if(start_unity[i] != expected_unity[i]) return -1;     // my_memmove is not working properly
  }
  return 0 ;                                      // all is well
}


int8_t test_memmove3(){
  //overlap happens at the end of src and the start of dst
  /* create a unity block of src and dst ( src U dst )
  * the size will be 2*LENGTH-OVRLAP
  *            --------dst--------  |       0 0 0 0 0    (i will init dst as zeros)
  *     --------src--------         |   1 2 3 4 5        (src overwrites dst)
  *     ----------unity-----------  |   1 2 3 4 5 0 0    (so we start with this unity)
  *
  * if done correctly,
  *     --------src--------         |   1 2 3 4 5         (older values of src)
  *            --------dst--------  |       1 2 3 4 5     (dst will clone src and overwrite it)
  *     ----------unity-----------  |   1 2 1 2 3 4 5     (and the new unity should be like so)
  */
  uint8_t start_unity[2*LENGTH-OVRLAP] = {1, 2, 3, 4, 5, 0, 0};
  uint8_t expected_unity[2*LENGTH-OVRLAP] = {1, 2, 1, 2, 3, 4, 5};
  // assign addresses of src and dst as subsets of start_unity
  uint8_t * src = start_unity;
  uint8_t * dst = start_unity + LENGTH - OVRLAP;
  // moving src into dst
  if (my_memmove(src, dst, LENGTH) == NULL){
    return -1;                                    // my_memmove failed internally
  }
  // check if data moving is properly done. compare start_unity to expected_unity
  for(int i = 0; i<LENGTH; i++){
    if(start_unity[i] != expected_unity[i]) return -1;     // my_memmove is not working properly
  }
  return 0 ;                                      // all is well
}

int8_t test_memcopy(){
  // we test on none overlapping data only as we know it will fail otherwise
  // non-overlapping data blocks
  uint8_t src_data[LENGTH] = {1, 2, 3, 4, 5};     // init with known values
  uint8_t dst_data[LENGTH];                       // no init [garbage]
  // moving src into dst
  if (my_memcopy(src_data, dst_data, LENGTH) == NULL){
    return -1;                                    // my_memcopy failed internally
  }
  // check if data copying is properly done. compare dst_data to src_data
  for(int i = 0; i<LENGTH; i++){
    if(src_data[i] != dst_data[i]) return -1;     // my_memcopy is not working properly
  }
  return 0 ;                                      // all is well
}

int8_t test_memset(){
  // create a data block but don't initialize
  uint8_t src_data[LENGTH];                       // no init [garbage]
  // setting src_data to VALUE
  if (my_memset(src_data, LENGTH, VALUE) == NULL){
    return -1;                                    // my_memset failed internally
  }
  // check if data setting is properly done.
  for(int i = 0; i<LENGTH; i++){
    if(src_data[i] != VALUE) return -1;           // my_memset is not working properly
  }
  // setting src_data to zero
  if (my_memzero(src_data, LENGTH) == NULL){
    return -1;                                    // my_memzero failed internally
  }
  // check if data setting is properly done.
  for(int i = 0; i<LENGTH; i++){
    if(src_data[i] != 0) return -1;           // my_memzero is not working properly
  }
  return 0 ;                                      // all is well
}

int8_t test_reverse(){
  uint8_t src_data[LENGTH] = {1, 2, 3, 4, 5};          // init with known values
  uint8_t rvrs_src_data[LENGTH] = {5, 4, 3, 2, 1};     // reversed
  // reversing src_data
  if (my_reverse(src_data, LENGTH) == NULL){
    return -1;                                        // my_reverse failed internally
  }
  // check if data reversing is properly done. compare src_data to rvrs_src_data
  for(int i = 0; i<LENGTH; i++){
    if(src_data[i] != rvrs_src_data[i]) return -1;     // my_memcopy is not working properly
  }
  return 0 ;                                      // all is well
}
