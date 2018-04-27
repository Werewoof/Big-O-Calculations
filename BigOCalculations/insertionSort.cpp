#ifndef ___INSERTIONSORT___
#define ___INSERTIONSORT___

/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #2
*/ 


#include <iostream>
#include "insertionSort.hpp"

using namespace std;

void insertionSort(struct structData list[], int last, unsigned long &n)
{

	//Hold is equal to the VALUE, not index, of the array at curr.
	int hold;


	//Walker is always behind curr by 1 index (left to right).
	int walker, curr;

	//Used to calculate efficiency.

	//Go through entire array from beggining to end.
	for (curr = 1; curr < last; curr++)
	{
		walker = curr - 1;
		hold = list[curr].randomInt;


		//This checks to see if the value before curr (aka walker) is greater
		//than curr.
		while ((walker >= 0) && (hold < list[walker].randomInt))
		{


			//cout << list[walker].randomInt << " ";
			//If it is, curr (aka walker + 1) gets the greater value from 
			//walker.
			list[walker + 1].randomInt = list[walker].randomInt;

			//Walker gets decremented by 1 index.
			walker--;
			n++;
		}


		/*
		Even if the value before curr (aka walker) wasn't greater than curr,
		this next thing still happens.

		Remember: hold = list[curr].

		If walker wasn't greater than curr, then hold just stays what it was:
		the greater value, which was already at curr.

		However, if walker was greater, then the place where walker WAS
		(before it got decremented) is assigned the value of hold.

		Again, hold = list[curr]: this performs a swap!
		*/

		list[walker + 1].randomInt = hold;
	}
}

#endif