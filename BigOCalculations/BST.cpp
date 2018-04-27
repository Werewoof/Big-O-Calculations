#ifndef ___BSTCPP___
#define ___BSTCPP___

/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #2
*/ 


#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "BST.hpp"


using namespace std;

//Default constructor. Sets root to NULL.
BST::BST()
{
	root = NULL; 
}

//Insert (STEP ONE)
void BST::insert(int num, string str, unsigned long &n)
{
   
   //If there are no nodes in the tree, just let it go in.
	if (root == NULL)
	{
		Node *ptr = new Node(num, str);
		root = insert(root, ptr, n);
	}
   
   //Otherwise, we first need to check for duplicates before creating a node.
	else
	{
		
			Node *ptr = new Node(num, str);
			root = insert(root, ptr, n);
	}
}

/*Insert (STEP TWO)

Recursively decides where a node should go by repeatedly returning nodes.
Here, newRoot will change frequently, being that it's whatever node we
compare against in the recursion process. On the other hand, ptr is the 
unchanging node we're trying to insert.
*/

Node *BST::insert(Node *newRoot, Node *ptr, unsigned long &n)
{
   //If the passed node is NULL, then this is where our new one goes into 
   //the tree.
	if (newRoot == NULL)
   {
		newRoot = ptr;
	}
   
   //Otherwise, do the expected operations.
   else if (ptr->getNumber() < newRoot->getNumber())
   {
      /*What happens here:
      The ever-changing node that we pass in is going to have its left subtree
      changed, because a value will be returned to it, by, you guessed it,
      calling insert again. And again and again, if necessary.
      
      We pass in the CURRENTLY passed in node's left subtree... which, in the 
      next calling of insert, TAKES THE PLACE of our currently passed node. 
      So, it then BECOMES that ever-changing, currently passed in node! 
      
      ptr, which we're trying to figure out the place for, gets re-passed 
      in each time.
      */
      
      newRoot->setLeft(insert(newRoot->getLeft(), ptr, n));
   }
   else
   {
      //Read above comments about passing in the left subtree.
      //Just adjust for the right subtree.
      newRoot->setRight(insert(newRoot->getRight(), ptr, n));
   }
   	  n++;
	return newRoot;
}




//Remove (STEP ONE)
void BST::remove(int num)
{
	root = remove(root, num);
}

/*Remove (STEP TWO)

Recursively decides which node gets deleted by repeatedly returning nodes.
Here, newRoot will change frequently, being that it's whatever node we
compare against the deletion key in the recursion process.
*/
Node *BST::remove(Node *newRoot, int delKey)
{
   //If the tree is empty, then...
	if (root == NULL)
	{
		cout << "\n\n!!You have no contacts!!\n\n";
		return newRoot;
	}

   //Whereas in the insert function we used NULL to know where to put the new 
   //node, we instead use NULL to indicate that the node wasn't in the tree. 
	if (newRoot == NULL)
	{
		cout << "\n\n!!Number not found!!\n\n";
	}
   
   //Much like insert, we're gonna return a bunch of nodes via comparisons.
	else if (delKey < newRoot->getNumber())
	{
      
      //Read comments about passing in the left subtree for the insert 
      //function. The only differences are 1.) we're passing in a fixed key,
      //not "ptr", and 2.) we're deleting nodes.
      
		newRoot->setLeft(remove(newRoot->getLeft(), delKey));
	}
	else if (delKey > newRoot->getNumber())
	{
      //Basically the same as the above, except with right subtree.
		newRoot->setRight(remove(newRoot->getRight(), delKey));
	}
   
   
   
   
   //If the node to delete WAS found, then we need figure out what's attached
   //(if anything).
	else if (delKey == newRoot->getNumber())
	{
      //If it has no children, delete it.
		if ((newRoot->getLeft() == NULL) && (newRoot->getRight() == NULL)) 
		{
			newRoot = NULL;
			delete newRoot;
		}
      
      //If node only has a right subtree child, then the PARENT of the node to 
      //delete will adopt the node to delete's right subtree child.
		else if (newRoot->getLeft() == NULL) 
		{
			Node *temp = newRoot;
			newRoot = newRoot->getRight();
			delete temp;
		}
      
      //Like the above, but for the case where the node has a left subtree 
      //child instead.
		else if (newRoot->getRight() == NULL)
		{
			Node *temp = newRoot;
			newRoot = newRoot->getLeft();
			delete temp;
		}
      
      
      
      //Well, if it has two children, it gets complicated.
		else 
		{
         //The node temp will equal whichever Node is the smallest, passing in
         //the right subtree. It follows that subtree down, all the way left,
         //and returns that node.
			Node *temp = getSmallest(newRoot->getRight());
			
         //It then replaces the matching node's number to temp's number.
         newRoot->setNumber(temp->getNumber());
         
         //Finally, it ends up deleting the smallest node. 
			newRoot->setRight(remove(newRoot->getRight(), temp->getNumber()));
		}
	}
	return newRoot;

}

//inOrder (STEP ONE)
void BST::inOrder()
{
	inOrder(root);
}

//inOrder (STEP TWO)
void BST::inOrder(Node *newRoot)
{
   //Emptiness causes chaos. Don't have chaos.
	if (newRoot != NULL)
	{
		inOrder(newRoot->getLeft());
		cout << newRoot->getNumber()
			<< newRoot->getName() << endl;
		inOrder(newRoot->getRight());

	}
}


//Gets the smallest node by constantly passing in the left subtree, starting
//from whatever node was initially passed in.
Node* BST::getSmallest(Node* root)
{
	while (root->getLeft() != NULL)
	{
		root = root->getLeft();
	}
	return root;
}

//Calls the big function to print stuff out.
void BST::writeToFiles(ofstream &oF, ofstream &sI, int size, unsigned long &n)
{
	sI << "Big-O for Binary Tree: O(log(n))"
		<< "\nExpected value for n (Binary Tree) (size = "
		<< size << "): " << log(size)
		<< "\nCalculated value for n (Binary Tree) (size = " 
		<< size << "): " << n << "\n\n";

	inOrderWrite(root, oF);

}

//I mean, this is basically just using the method for printing in pre order.
//Except, you print stuff out.
void BST::inOrderWrite(Node *newRoot, ofstream &oF)
{

   //If a tree exists, print it to file.
	if (newRoot != NULL)
	{
		inOrderWrite(newRoot->getLeft(), oF);
		oF << newRoot->getNumber()
			<< newRoot->getName() << endl;
		inOrderWrite(newRoot->getRight(), oF);
	}
}

#endif