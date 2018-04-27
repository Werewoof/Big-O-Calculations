#ifndef ___QUICKSORTHPP___
#define ___QUICKSORTHPP___

/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #2
*/ 

#include <iostream>
#include "structData.hpp"
#include "insertionSort.hpp"

using namespace std;

// This function creates the left and right partitions for Quicksort.
int partition(struct structData *arr, int left, int right, unsigned long &n);

void quickSort(struct structData *arr, int left, int right, unsigned long &n);
#endif