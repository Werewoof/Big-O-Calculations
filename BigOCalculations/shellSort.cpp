#ifndef ___SHELLSORT___
#define ___SHELLSORT___

/*****************************************************************************
   Author: Timothy Rollings
   Student ID: F638V635                                                                                                                                          
   Project: #2
*/ 


#include <iostream>
#include "shellSort.hpp"

using namespace std;


void shellSort(struct structData list[], int size, unsigned long &n)
{
	int walker, curr, increment, temp;

   increment = 3;
   while (increment > 0)
   {
      for (walker = 0; walker < size; walker++)
       {
         curr = walker;
         temp = list[walker].randomInt;
         while ((curr >= increment) && (list[curr-increment].randomInt > temp))
         {
           list[curr].randomInt = list[curr - increment].randomInt;
           curr = curr - increment;
            n++;
         }
         list[curr].randomInt = temp;
      }
      if (increment/2 != 0)
      {
         increment = increment/2;
      }
      else if (increment == 1)
      {
         increment = 0;
      }
      else
      {
         increment = 1;
      }
   }
}

#endif