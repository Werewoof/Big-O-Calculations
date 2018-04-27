#ifndef ___QUICKSORT___
#define ___QUICKSORT___

/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #2
*/ 


#include <iostream>
#include "quickSort.hpp"

using namespace std;

// This function creates the left and right partitions for Quicksort.
int partition(struct structData *arr, int left, int right, unsigned long &n)
{
   //Start the pivot at the end (right) of the array.
	int pivot = arr[right].randomInt;


	//We'll find out where the pivot goes: for now, start at the beginning 
	//(left) of the array.
	int pivotIndex = left;

	//Go from beginning to end of array.
	for (int i = left; i < right; i++)
	{

		//If value in the array at i is <= to value of the pivot, then...
		if (arr[i].randomInt <= pivot)
		{

			//...swap the two values.
			int tmp = arr[i].randomInt;
			arr[i].randomInt = arr[pivotIndex].randomInt;
			arr[pivotIndex].randomInt = tmp;

			//AND increase pivotIndex!
			pivotIndex++;
		}
	}

	//At this point, all values <= than the pivot have been moved to the left 
	//of pivotIndex, and everything larger has stayed to the right of 
	//pivotIndex. This explains why pivotIndex was increased every time a 
	//value lower than the value of the pivot was found!    


	//Finally, swap the value of the pivot (which is still at the end of the 
	//array) with the value at the pivotIndex.

	int tmp = arr[pivotIndex].randomInt;
	arr[pivotIndex].randomInt = arr[right].randomInt;
	arr[right].randomInt = tmp;

	//Now we know where the pivotIndex is, we can return it to quickSort.
	return pivotIndex;
}


void quickSort(struct structData *arr, int left, int right, unsigned long &n)
{
	if (left < right)
	{
		if (right < 16)
		{
			insertionSort(arr, right, n);
		}
		else
		{
			//See partition function for documentation.
			int pivotIndex = partition(arr, left, right, n);


			//This partitions the left side of the pivotIndex.
			quickSort(arr, left, pivotIndex - 1, n);

			//This partitions the right side of the pivotIndex.
			quickSort(arr, pivotIndex + 1, right, n);


			n++;
		}
	}
}

#endif