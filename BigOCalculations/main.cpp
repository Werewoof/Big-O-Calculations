/*****************************************************************************
   Authors: Timothy Rollings and Jon Korte
   Student ID: Tim: F638V635 | Jon: B993A295
   Project: #2
   
   FINAL PSEUDOCODE


   int main()

      ========================STEP ONE========================
                        Setting up the arrays
      ========================================================
      First, declare 3 arrays of structs:

         arrayA[50]
         arrayB[5000]
         arrayC[100000]
         
      Send each array through a randomizer function. The randomizer could use a 
      for loop, but then it would need to know where to stop. This could 
      be passed as an argument into this function as the size of the arrays. 
         
         For example,
            
            //function prototype
            randomize(data arr[], int size)
            
            //function call
            randomize(arrayA, 50); 
            
            //function definition
            randomize(data arr[], int size)
            {
               for (i = 0; i < size ; i++)
               {
                  randomize arr[i]'s int value
                  randomize arr[i]'s string value
               }
            }
            
         Then randomize arrays B and C in the same manner.
            
      These 3 arrays will be constant blueprints.
            
            
            
            
            
            
            
            
      ========================STEP TWO========================
                     Going through all the sorts
      ========================================================
      
      Before each sort function, print out 
         1.) Which sort function is getting called
         2.) What the array size will be 
         3.) What the Big-O Notation for the sort is 
         4.) What the expected calculation after plugging in size for n will be

            For example,
          
                  OUTPUT:
                  1     **Calling selectionSort (array size = 50)**
                  2
                  3     * Big-O Notation: O(n^2)
                  4     * Expected value: O((50)^2) = 2500
                  5
                  ...
      
      
      
      From here, we can copy the contents of our permanent array 
      (or something like that) of 50 to a new array, then pass that new array 
      into the sort functions, as well as the size of the array.
      
               
               //function call
               selectionSort(arrayA, 50); 
              
      
            
      During each sort function, we should count the number of iterations
      by some variable 'n' just to match up with the notation. I think we could 
      probably just print out what n is from each function after all the sorting 
      and iterating is done. But for a recursive algorithm like quickSort, we'll
      probably have to pass in n by reference just so that each calling of 
      quickSort within itself doesn't reset n to 0 each time.
      
      After any sorting routine is complete, we write it out its results to a 
      file, where the contents contain the sorted array data, probably output via 
      a for loop.

         For example,
         
            (An array is passed into a function)
               (It gets sorted in the function, results get returned to main)
            (After the array is sorted, iterate through it from the beginning,
            printing out to an appropriate file)
            
            This happens 5 times for each array size:
            
            SEL50.txt
            QCK50.txt
            INS50.txt
            BUB50.txt
            SHL50.txt        
      
            SEL5000.txt
            QCK500.txt
            INS500.txt
            BUB500.txt
            SHL500.txt
            
            SEL100K.txt
            QCK100K.txt
            INS100K.txt
            BUB100K.txt
            SHL100K.txt
            
            
            
            
            
            
      ========================STEP THREE========================
                        Using the binary tree
      ==========================================================     
      
      Once again with our permanent arrays, we will iterate through them and pass
      their unsorted contents into a function that will insert them into 3 separate 
      binary trees. 
      
       Declare:
         
         bstA 
         bstB 
         bstC
         
      
      
      We will need to modify the binary trees to count the number of operations 
      like the sort functions, so we'll just use 'n' again and keep counting it. 
      Also, the Big-O Notation for binary trees is O(n).
      
      I am actually not sure how to correctly implement the big-O calculations
      here, so I will email the teacher just to be sure. I attempted something 
      but after reviewing it, it doesn't make sense to me.

         
      Anyway, here's what I'm thinking:
      
         //function prototype
         btSort(binaryTree, array, size);
         
         //function call
         btSort(bstA, arrayA, 50);

         //function definition
         btSort(binaryTree, array, size)
         {
            (Print out the info, like in the sort functions: see line #83)
    
            for (int i = 0; i < size; i++)
            {
               //binaryTree needs to be modified to insert nodes with structs.
               //(If it isn't already equipped to do that)
               
               //function call
               binaryTree.insert(array[i]);
            }
            
            (Correctly print out big-O calculation somehow)
         }
    
    
      Then, once a binaryTree is sorted, we can call its print function to print
      out its contents in-order to an appropriate file,
      
         bst50.txt
         bst5000.txt
         bst100K.txt
    
    
    
    
    
    
      ========================STEP FOUR=========================
                        Something about sortinfo.txt
      ==========================================================   
      
      I don't quite understand this fully, if this part has no correlation to 
      the step below. So I'm going to ask the teacher. :r
      
      
      
      
      
      
      ========================STEP FIVE=========================
             Send a sorted array of 5000 through all sorts
      ==========================================================   
      
      For all 5 sorts, we need to run this sorted array through them, calculate 
      the number of operations each one takes, and print them out to
      sortinfo.text
      
      
      
      
      ========================STEP SIX=========================
                  Not in main, but write a paragraph
      ==========================================================   
      
      I guess, just analyse what we get back in a paragraph. Compare what get
      with what we expected, say which sort is fastest, and if data size makes 
      a difference.
   
*/ 


#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>

#include "insertionSort.hpp"
#include "quickSort.hpp"
#include "bubbleSort.hpp"
#include "selectionSort.hpp"
#include "shellSort.hpp"
#include "BST.hpp"
#include "Node.hpp"
#include "structData.hpp"

using namespace std;


class MasterArray
{
	int sizeOf;
	structData *arr;

	void randomizeInt();
	void randomizeString();

public:
	MasterArray(int size);
	structData* copyArray();
	void randomize();
	void printArray(char choice);
	int getSize();

};


MasterArray::MasterArray(int size)
{
	arr = new structData[size];
	sizeOf = size;
}

structData *MasterArray::copyArray()
{
	structData *arrCopy = new structData[sizeOf];

	for (int i = 0; i < sizeOf; i++)
	{
		arrCopy[i].randomInt = arr[i].randomInt;
		arrCopy[i].randomString = arr[i].randomString;
	}
	return arrCopy;
}

void MasterArray::randomize()
{
	randomizeInt();
	randomizeString();
}

void MasterArray::randomizeInt()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < sizeOf; ++i)
	{
		arr[i].randomInt = rand() % 1000;
	}
}

void MasterArray::randomizeString()
{
	 char characterSet[] =
		"abcdefghijklmnopqrstuvwxyz";

	 int stringLength = sizeof(characterSet) - 1;

	srand((unsigned)time(NULL));
	for (int i = 0; i < sizeOf; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			arr[i].randomString += characterSet[rand() % stringLength];
		}
	}
}

void MasterArray::printArray(char choice)
{
	int nextLine = 0;
	for (int i = 0; i < sizeOf; ++i)
	{
		cout << arr[i].randomInt;

		if (choice == 'y')
		{
			cout << arr[i].randomString << ", ";
		}
		else
		{
			cout << ", ";
		}
		nextLine++;

		//Only allows 7 structs per line
		if (nextLine > 7)
		{
			cout << endl;
			nextLine = 0;
		}
	}
	cout << endl << endl;
}

int MasterArray::getSize()
{
	return sizeOf;
}





void printArray(struct structData *printThis, int size, char choice)
{
	int nextLine = 0;
	for (int i = 0; i < size; i++)
	{
		cout << printThis[i].randomInt;

		if (choice == 'y')
		{
			cout << printThis[i].randomString << ", ";
		}
		else
		{
			cout <<", ";
		}

		nextLine++;

		//Only allows 7 structs per line
		if (nextLine > 7)
		{
			cout << endl;
			nextLine = 0;
		}
	}
}

//Just press enter here. :)
void justHitEnter()
{
	cin.get();
}









void callInsertSort(struct structData list[], unsigned long size, 
					unsigned long &n)
{
	cout << "\n\n\n======================================================\n";
	cout << "\n** CALLING INSERTION SORT ON COPY (ARRAY SIZE = " << size 
		<< ") ** \n\n"
		<< "Big - O Notation : O(n ^ 2)\n"
		<< "Expected value for n: O((" << size << ")^2) = " << pow(size, 2)
		<< "\n\n\n ---RESULTS---";
	
	//Reset n.
	n = 0;
	insertionSort(list, size, n);



	cout << "\n\nCalculated value for n: " << n << "\n\n";
	/*cout << "\n\nSorted array:\n\n";


	printArray(list, size, d);
	*/
	cout << "\n======================================================\n";
	cout << "** INSERTION SORT FINISHED **\n\n\n\n";
}




void callQuickSort(struct structData *arr, int left, int right, 
					unsigned long &n)
{
	cout << "\n\n\n======================================================\n";
	cout << "\n** CALLING QUICK SORT ON COPY (ARRAY SIZE = " << right
		<< ") ** \n\n"
		<< "Big - O Notation : O(n)\n"
		<< "Expected value for n: O(("<< right << ")) = " << right
		<<"\n\n\n ---RESULTS---";


	//Reset n.
	n = 0;
	quickSort(arr, 0, right, n);


	cout << "\n\nCalculated value for n: " << n << "\n\n";
	/*cout << "\n\nSorted array:\n\n";


	printArray(list, size, d);
	*/

	cout << "\n======================================================\n";
	cout <<	"** QUICK SORT FINISHED **\n\n\n\n";
}


void callBubbleSort(struct structData list[], unsigned long size,
	unsigned long &n)
{
	cout << "\n\n\n======================================================\n";
	cout << "\n** CALLING BUBBLE SORT ON COPY (ARRAY SIZE = " << size
		<< ") ** \n\n"
		<< "Big - O Notation : O(n ^ 2)\n"
		<< "Expected value for n: O((" << size << ")^2) = " << pow(size, 2)
		<< "\n\n\n ---RESULTS---";

	//Reset n.
	n = 0;
	bubbleSort(list, size, n);



	cout << "\n\nCalculated value for n: " << n << "\n\n";
	/*cout << "\n\nSorted array:\n\n";


	printArray(list, size, d);
	*/
	cout << "\n======================================================\n";
	cout << "** BUBBLE SORT FINISHED **\n\n\n\n";
}



void callSelectionSort(struct structData list[], unsigned long size,
	unsigned long &n)
{
	cout << "\n\n\n======================================================\n";
	cout << "\n** CALLING SELECTION SORT ON COPY (ARRAY SIZE = " << size
		<< ") ** \n\n"
		<< "Big - O Notation : O(n ^ 2)\n"
		<< "Expected value for n: O((" << size << ")^2) = " << pow(size, 2)
		<< "\n\n\n ---RESULTS---";

	//Reset n.
	n = 0;
	selectionSort(list, size, n);



	cout << "\n\nCalculated value for n: " << n << "\n\n";
	/*cout << "\n\nSorted array:\n\n";


	printArray(list, size, d);
	*/
	cout << "\n======================================================\n";
	cout << "** SELECTION SORT FINISHED **\n\n\n\n";
}



void callShellSort(struct structData list[], unsigned long size,
	unsigned long &n)
{
	cout << "\n\n\n======================================================\n";
	cout << "\n** CALLING SHELL SORT ON COPY (ARRAY SIZE = " << size
		<< ") ** \n\n"
		<< "Big - O Notation : O(n(log(n))^2)\n"
		<< "Expected value for n: O((" << size << ")^2) = " << size*(pow(log(size),2))
		<< "\n\n\n ---RESULTS---";

	//Reset n.
	n = 0;
	shellSort(list, size, n);



	cout << "\n\nCalculated value for n: " << n << "\n\n";
	/*cout << "\n\nSorted array:\n\n";


	printArray(list, size, d);
	*/
	cout << "\n======================================================\n";
	cout << "** SHELL SORT FINISHED **\n\n\n\n";
}



void useBinaryTree(struct structData list[], int size,
	unsigned long &n, ofstream &oF, ofstream &sI, BST &bst)
{
   n = 0;
	for (int i = 0; i < size; i++)
	{
		bst.insert(list[i].randomInt, list[i].randomString, n);
	}

	bst.inOrder();
	bst.writeToFiles(oF, sI, size, n);
   
   

	for (int i = 0; i < size; i++)
	{
		bst.remove(list[i].randomInt);
	}

}





void writeToFiles(struct structData list[], int size, unsigned long &n, 
				ofstream &oF, ofstream &sI, string sortName, 
				string calc, string result)
{
	sI << "Big-O for " << sortName << ": " << calc
		<< "\nExpected value for n (" << sortName << ") (size = "
		<< size << "): " << result
		<< "\nCalculated value for n (" << sortName <<") (size = " 
		<< size << "): " << n << "\n\n";

	oF << "\nSorted array without random strings:\n\n";

	int nextLine = 0;
	for (int i = 0; i < size; i++)
	{
		oF << list[i].randomInt << ", ";

		nextLine++;

		//Only allows 7 structs per line
		if (nextLine > 9)
		{
			oF << endl;
			nextLine = 0;
		}
	}



	oF << "\n\n\n\n\n\n\n\n\n\n\n\nSorted array with random strings:\n\n";

	nextLine = 0;
	for (int i = 0; i < size; i++)
	{
		oF << list[i].randomInt
			<< list[i].randomString << ", ";

		nextLine++;

		//Only allows 7 structs per line
		if (nextLine > 9)
		{
			oF << endl;
			nextLine = 0;
		}
	}
}























































int main()
{
	//This variable will be used again and again for Big-O calculations.
	unsigned long n = 0;


	//Short for "outFile".
	ofstream oF;
	
	//Short for "sortInfo".
	ofstream sI;

	sI.open("sortinfo.txt");
	//=================================================================
	//======================== STEP ONE ===============================
	//=================================================================
	//				Create and Randomize the Arrays


	//Create 3 master arrays that never get changed.
	MasterArray arrayA(50);
	MasterArray arrayB(5000);
	MasterArray arrayC(100000);

	cout << "\n      WELCOME TO THE PROGRAM\n\n"
		<< "This program randomizes arrays of structs.\n"
		<< "Each struct contains a random integer and a random string.\n"
		<< "The arrays are sorted by their integer in ascending order.\n\n";

	/*
	do
	{
		cout << "When the arrays are printed, do you want to see the random "
			<< "strings? y/n: ";

		cin >> displayString;

	} while ((displayString != 'y') && (displayString != 'n'));
	*/

	cout << "\n\n--------------------- BEGIN PROGRAM ---------------------\n";


	
	cout << "\nRandomizing arrayA (50):\n"
		<< "\nRandomizing arrayB (5000):\n"
		<< "\nRandomizing arrayC (100000):\n\n\n";


	//Randomize the first master array AND print it.
	arrayA.randomize();
	arrayB.randomize();
	arrayC.randomize();
	

	cout << "\n      ** ARRAYS RANDOMIZED **\n"
		<< "\n     Copies of these arrays will\n"
		<< "   be passed into the sort routines.\n";
	
	/*
	char choice = ' ';

	do
	{
		cout << "\n\n\nWould you like to see the first array?\n"
			<< "(the others take a long time.) y/n: ";

		cin >> choice;

		if (choice == 'y')
		{
			cout << "\n\n\nRandomized arrayA:\n\n";
			arrayA.printArray(displayString);
		}
		else if (choice == 'n')
		{

		}
		else
		{
			cout << "\n\nI didn't understand that.\n";
		}
	} while ((choice != 'y') && (choice != 'n'));
	*/
	
	
	cout << "\n\nLet's begin sorting.\n\n";



	
	

	//-------------------- SORTS : ARRAY A --------------------

	cout << "\n\n-------------------- SORTS : ARRAY A --------------------\n";

	cout << "\nArray size = (50), we will sort by: \n\n"

		<< "  * Insertion sort\n"
		<< "  * Quick sort\n"
		<< "  * Bubble sort\n"
		<< "  * Selection sort\n"
		<< "  * Shell sort";


	cout << "\n\n\nPress ENTER to begin sorting process. ";

	justHitEnter();






	//Making a copy of the first randomized array.
	//This copy will be used for ALL arrays! Saves memory. :)
	structData *copy = arrayA.copyArray();




	//..............................................................
	//Let's call Insertion sort and pass in that copy.

	callInsertSort(copy, arrayA.getSize(), n);

	
	oF.open("INS50.txt");
	writeToFiles(copy, arrayA.getSize(), n, oF, sI, 
				"Insertion sort", "O(n)^2", "2500");
	
	oF.close();


	//Using the same modifiable array, reset it to the master array.
	copy = arrayA.copyArray();

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();


   



	//..............................................................
	//Let's call Quicksort!

	callQuickSort(copy, 0, arrayA.getSize() , n);

	
	oF.open("QCK50.txt");
	writeToFiles(copy, arrayA.getSize(), n, oF, sI, 
		"Quick sort", "O(n)^2", "2500");
	
	oF.close();

  
   copy = arrayA.copyArray();

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();





	//..............................................................
		//Let's call Bubble sort now.

	callBubbleSort(copy, arrayA.getSize(), n);


	
	oF.open("BUB50.txt");
	writeToFiles(copy, arrayA.getSize(), n, oF, sI, 
		"Bubble sort", "O(n)^2", "2500");
	
	oF.close();


	copy = arrayA.copyArray();

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();






	//..............................................................
	//Let's call Selection sort now.

	callSelectionSort(copy, arrayA.getSize(), n);


	oF.open("SEL50.txt");
	writeToFiles(copy, arrayA.getSize(), n, oF, sI,
		"Selection sort", "O(n)^2", "2500");
	
	oF.close();


	copy = arrayA.copyArray();

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();






	//..............................................................
	//Finally, let's call Shell sort.

	callShellSort(copy, arrayA.getSize(), n);

	oF.open("SHL50.txt");
	writeToFiles(copy, arrayA.getSize(), n, oF, sI, 
		"Shell sort", "O(n(log(n))^2)", "765.196");
	
	oF.close();

	copy = arrayA.copyArray();


	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();

	



	sI << "\n\n\n\n\n";


	//-------------------- SORTS : ARRAY B --------------------

	cout << "\n\n-------------------- SORTS : ARRAY B --------------------\n";

	cout << "\nArray size = (5000), we will sort by: \n\n"

		<< "  * Insertion sort\n"
		<< "  * Quick sort\n"
		<< "  * Bubble sort\n"
		<< "  * Selection sort\n"
		<< "  * Shell sort";


	cout << "\n\n\nPress ENTER to begin sorting process. ";

	justHitEnter();






	//Making a copy of the first randomized array.
	//This copy will be used for ALL arrays! Saves memory. :)
	copy = arrayB.copyArray();



	//..............................................................
	//Let's call insertionSort and pass in that copy.

	callInsertSort(copy, arrayB.getSize(), n);

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();


	
	oF.open("INS5000.txt");
	writeToFiles(copy, arrayB.getSize(), n, oF, sI, 
		"Insertion sort", "O(n)^2", "25000000");
	
	oF.close();


	//Using the same modifiable array, reset it to the master array.
	copy = arrayB.copyArray();




	//..............................................................
	//Let's call quicksort!

	callQuickSort(copy, 0, arrayB.getSize() , n);

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();


	
	oF.open("QCK5000.txt");
	writeToFiles(copy, arrayB.getSize(), n, oF, sI, 
		"Quick sort", "O(n)^2", "25000000");
	
	oF.close();

	structData *sorted5K = copy;
	//structData *copy = arrayA.copyArray();
	//Using the same modifiable array, reset it to the master array.
	
	copy = arrayB.copyArray();





	//..............................................................
	//Let's call Bubble sort now.

	callBubbleSort(copy, arrayB.getSize(), n);


	
	oF.open("BUB5000.txt");
	writeToFiles(copy, arrayB.getSize(), n, oF, sI, 
		"Bubble sort", "O(n)^2", "25000000");
	
	oF.close();


	copy = arrayB.copyArray();

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();






	//..............................................................
	//Let's call Selection sort now.

	callSelectionSort(copy, arrayB.getSize(), n);


	
	oF.open("SEL5000.txt");
	writeToFiles(copy, arrayB.getSize(), n, oF, sI, 
		"Selection sort", "O(n)^2", "25000000");
	
	oF.close();


	copy = arrayB.copyArray();

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();






	//..............................................................
	//Finally, let's call Shell sort.

	callShellSort(copy, arrayB.getSize(), n);

	
	oF.open("SHL5000.txt");
	writeToFiles(copy, arrayB.getSize(), n, oF, sI, 
		"Shell sort", "O(n(log(n))^2)", "362712.899");
	
	oF.close();

	copy = arrayB.copyArray();


	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();






	sI << "\n\n\n\n\n";




	//-------------------- SORTS : ARRAY C --------------------

	cout << "\n\n-------------------- SORTS : ARRAY C --------------------\n";

	cout << "\nArray size = (100000), we will sort by: \n\n"

		<< "  * Insertion sort\n"
		<< "  * Quick sort\n"
		<< "  * Bubble sort\n"
		<< "  * Selection sort\n"
		<< "  * Shell sort";


	cout << "\n\n\nPress ENTER to begin sorting process. ";

	justHitEnter();






	//Making a copy of the first randomized array.
	//This copy will be used for ALL arrays! Saves memory. :)
	copy = arrayC.copyArray();



	//..............................................................
	//Let's call insertionSort and pass in that copy.

	callInsertSort(copy, arrayC.getSize(), n);

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();


	
	oF.open("INS100K.txt");
	writeToFiles(copy, arrayC.getSize(), n, oF, sI, 
		"Insertion sort", "O(n)^2", "10000000000");
	
	oF.close();


	//Using the same modifiable array, reset it to the master array.
	copy = arrayC.copyArray();




	//..............................................................
	//Let's call quicksort!

	callQuickSort(copy, 0, arrayC.getSize() , n);

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();


	
	oF.open("QCK100K.txt");
	writeToFiles(copy, arrayC.getSize(), n, oF, sI, 
		"Quick sort", "O(n)^2", "10000000000");
	
	oF.close();


	//Using the same modifiable array, reset it to the master array.
	copy = arrayC.copyArray();



	//..............................................................
	//Let's call Bubble sort now.

	callBubbleSort(copy, arrayC.getSize(), n);


	
	oF.open("BUB100K.txt");
	writeToFiles(copy, arrayC.getSize(), n, oF, sI, 
		"Bubble sort", "O(n)^2", "10000000000");
	
	oF.close();


	copy = arrayC.copyArray();

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();






	//..............................................................
	//Let's call Selection sort now.

	callSelectionSort(copy, arrayC.getSize(), n);


	
	oF.open("SEL100K.txt");
	writeToFiles(copy, arrayC.getSize(), n, oF, sI, 
		"Selection sort", "O(n)^2", "10000000000");
	
	oF.close();


	copy = arrayC.copyArray();

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();






	//..............................................................
	//Finally, let's call Shell sort.

	callShellSort(copy, arrayC.getSize(), n);

	
	oF.open("SHL100K.txt");
	writeToFiles(copy, arrayC.getSize(), n, oF, sI, 
		"Shell sort", "O(n(log(n))^2)", "13254745.276");
	
	oF.close();

	copy = arrayC.copyArray();


	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();


   
   
	sI << "\n\n\n\n\n";


   
   
   
   
   
	//-------------------- BINARY TREES --------------------

	BST bst;

   
   
	copy = arrayA.copyArray();
	
	oF.open("BST50.dat");
	useBinaryTree(copy, arrayA.getSize(), n, oF, sI, bst);
	oF.close();



	copy = arrayB.copyArray();

	oF.open("BST5000.dat");
	useBinaryTree(copy, arrayB.getSize(), n, oF, sI, bst);
	oF.close();



	copy = arrayC.copyArray();

	oF.open("BST100K.dat");
	useBinaryTree(copy, arrayC.getSize(), n, oF, sI, bst);
	oF.close();



	

	sI << "\n\n\n\n\n";

   
   
	//------------------ SHOVING SORTED ARRAY INTO ROUTINES ------------------
	
	copy = sorted5K;


	cout << "\n\n------------------ RE-SORTS : ARRAY B -------------------\n";

	cout << "\nSorted array size = (5000), we will resort by: \n\n"

		<< "  * Insertion sort\n"
		<< "  * Quick sort\n"
		<< "  * Bubble sort\n"
		<< "  * Selection sort\n"
		<< "  * Shell sort";


	cout << "\n\n\nPress ENTER to begin sorting process. ";

	justHitEnter();

	//..............................................................
	//Let's call insertionSort and pass in that copy.

	callInsertSort(copy, arrayB.getSize(), n);

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();


	sI << "\nValue of n after resorting Insertion sort (size = 5000): " << n;

	//Using the same modifiable array, reset it to the master array.
	copy = sorted5K;




	//..............................................................
	//Let's call quicksort!

	callQuickSort(copy, 0, arrayB.getSize(), n);

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();


	sI << "\nValue of n after resorting Quick sort (size = 5000): " << n;

	//structData *copy = arrayA.copyArray();
	//Using the same modifiable array, reset it to the master array.
	copy = sorted5K;

	



	//..............................................................
	//Let's call Bubble sort now.

	callBubbleSort(copy, arrayB.getSize(), n);



	sI << "\nValue of n after resorting Bubble sort (size = 5000): " << n;


	copy = sorted5K;

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();






	//..............................................................
	//Let's call Selection sort now.

	callSelectionSort(copy, arrayB.getSize(), n);




	sI << "\nValue of n after resorting Selection sort (size = 5000): " << n;

	copy = sorted5K;

	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();






	//..............................................................
	//Finally, let's call Shell sort.

	callShellSort(copy, arrayB.getSize(), n);



	sI << "\nValue of n after resorting Shell sort (size = 5000): " << n;

	copy = sorted5K;


	cout << "\n\n\nSee above for results.";
	cout << "\nPress ENTER to continue. ";
	justHitEnter();

	sI.close();
}



