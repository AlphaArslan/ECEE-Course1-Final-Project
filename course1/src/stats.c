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
 * @file <Add File Name>
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  //sorting test array from largest to smallest
  sort_array(test, SIZE);

  /* Statistics and Printing Functions Go Here */
  // printing sorted array
  print_array(test, SIZE);
  // printing statistical statistical values
  print_statistics(test, SIZE);

}

void sort_array( unsigned char * pArray, char arraySize){
  unsigned char temp;
  char finished = 0;                                  //1 when we are done sorting
  while(finished == 0){
    finished = 1 ;
    for(int i = 0; i < arraySize-1; i++){
      if(pArray[i+1] > pArray[i]){
        temp = pArray[i+1];
        pArray[i+1] = pArray[i];
        pArray[i] = temp;
        finished = 0 ;
      }
    }
  }
}

void print_array(unsigned char * pArray, char arraySize){
  #ifdef VERBOSE
  PRINTF("Sorted data:\n");
  for(int i = 0; i < arraySize;){
    for (int j = 0; j < 5; j++, i++) {
      PRINTF("\t%u\t", pArray[i]);
    }
    PRINTF("\n");
  }
  #endif
}

void print_statistics( unsigned char * pArray, char arraySize){
  printf("\n");
  printf("Mean  :\t%d\n", find_mean(pArray, arraySize));
  printf("Median:\t%d\n", find_median(pArray, arraySize));
  printf("Max   :\t%d\n", find_max(pArray, arraySize));
  printf("Min   :\t%d\n", find_min(pArray, arraySize));
}

unsigned char find_mean( unsigned char * pArray, char arraySize){
  int sum = 0;
  for(int i = 0; i < arraySize; i++){
    sum += pArray[i];
  }
  return sum/arraySize;
}

unsigned char find_median( unsigned char * pArray, char arraySize){
  return pArray[arraySize/2];
}

unsigned char find_max( unsigned char * pArray, char arraySize){
  return pArray[0];
}

unsigned char find_min( unsigned char * pArray, char arraySize){
  return pArray[arraySize-1];
}
