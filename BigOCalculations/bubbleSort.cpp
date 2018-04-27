#ifndef ___BUBBLESORT___
#define ___BUBBLESORT___

/*****************************************************************************
   Author: Timothy Rollings
   Student ID: F638V635                                                                                                                                          
   Project: #2
*/ 


#include <iostream>
#include "bubbleSort.hpp"

using namespace std;


void bubbleSort(struct structData list[], int last, unsigned long &n)
{
	int hold, curr, walker;

	for (curr = 0; curr < last - 1; curr++) 
	{
		for (walker = 0; walker<last - curr - 1; walker++)
			if (list[walker].randomInt > list[walker + 1].randomInt)
			{
				hold = list[walker].randomInt;
				list[walker].randomInt = list[walker + 1].randomInt;
				list[walker + 1].randomInt = hold;
				n++;
			}
	}
}

#endif