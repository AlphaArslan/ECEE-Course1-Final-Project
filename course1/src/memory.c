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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  // creating a temporary place to hold data
  uint8_t * p_temp = (uint8_t*) malloc(length*sizeof(uint8_t));
  // check if we successfully allocated memory
  if(p_temp == NULL) return NULL;               // indicating failure
  // copy data from src to temp
  my_memcopy(src, p_temp, length);
  // copy data from temp to dst
  my_memcopy(p_temp, dst, length);
  // free the allocated temp memory
  free(p_temp);
  return dst;

}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  for(int i = 0; i < length; i++){
    *(dst + i) = *(src + i);
  }
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  for(int i = 0; i < length; i++){
    *(src + i) = value;
  }
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  return my_memset(src, length, 0);
}
