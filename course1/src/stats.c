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



#include "platform.h"
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


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
  PRINTF("data:\n");
  for(int i = 0; i < arraySize;){
    for (int j = 0; j < 5; j++, i++) {
      PRINTF("\t%u\t", pArray[i]);
    }
    PRINTF("\n");
  }
  #endif /* VERBOSE */
}

void print_statistics( unsigned char * pArray, char arraySize){
  #ifdef VERBOSE
  PRINTF("\n");
  PRINTF("Mean  :\t%d\n", find_mean(pArray, arraySize));
  PRINTF("Median:\t%d\n", find_median(pArray, arraySize));
  PRINTF("Max   :\t%d\n", find_max(pArray, arraySize));
  PRINTF("Min   :\t%d\n", find_min(pArray, arraySize));
  #endif /* VERBOSE */
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
