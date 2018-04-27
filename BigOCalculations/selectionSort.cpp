#ifndef ___SELECTIONSORT___
#define ___SELECTIONSORT___

/*****************************************************************************
   Author: Timothy Rollings
   Student ID: F638V635                                                                                                                                          
   Project: #2
*/ 

#include <iostream>
#include "selectionSort.hpp"

using namespace std;


void selectionSort(struct structData list[], int size, unsigned long &n)
{
   int minValue,temp;

   for (int walker = 0; walker < size - 1; walker++)
   {
       minValue = walker;
      
      for (int curr = walker + 1; curr < size; curr++)
      {
         if (list[curr].randomInt < list[minValue].randomInt)
         {
            minValue = curr;
            n++;
         }
      }
      
      if (minValue != walker)
      {
           temp = list[walker].randomInt;
           list[walker].randomInt = list[minValue].randomInt;
           list[minValue].randomInt = temp;
      }
   }
}



#endif