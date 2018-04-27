#ifndef ___BSTHPP___
#define ___BSTHPP___

/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #2

 
    Description of the problem:
         This project implements the BST class. It contains a private node 
         called root. Concerning nodes, it has functions to insert, delete,
         search for, and traverse them in-order. Lastly, it includes a 
	 function to print the binary search tree to a file in-order.
         
 
Pseudo Code


Class: BST

   Data: 
      root - pointer to the first node--the root--of a binary search tree.
   
   Mutator Functions:
      None.
      
   Accessor Functions:
      None.
   Functions:
      =>   insert - adds a node to the BST.
               Input Parms: name, number
               Output Parms: Node
              
               create new node, initialize with passed in data
               
               if (node is the only one in tree)
                  make it the root by default
               
               if (search key is = to passed node's key)
                  reject it, no duplicates!
               else if (search key is < than passed node's key)
                  return insert, pass left subtree and search key
               else if (search key is > than root)
                  return insert, pass right subtree and search key
               end if
               
      =>    delete - deletes a node from the BST.
               Input Parms: number
               Output Parms: Node
              
               if (tree is empty)
                  can't delete anything!

               if (search key is < than passed node's key)
                  return delete, pass left subtree and search key
               else if (search key is > passed node's key)
                  return delete, pass right subtree and search key
               else if (search key = passed node's key)
                  do the appropriate operations based on whether or not the 
                  passed node's left and/or right subtrees are null
               else if (search key != any passed node's key)
                  node to be deleted isn't in tree  
               end if

      =>    inOrder - prints the BST IN order.
               Input Parms: None
               Output Parms: None
              
               Print left subtree, then root, then right subtree
               
               
      =>    writeToFile - writes the BST in-order to the file.
               Input Parms: None
               Output Parms: None
              
               Write BST out to file in-order.         
*/  

#include <iostream>
#include <string>
#include <fstream>
#include "Node.hpp"

using namespace std;

class BST
{
	Node *root;
   
	Node *insert(Node *newRoot, Node *addNode, unsigned long &n);
	Node *remove(Node *newRoot, int delKey);
   
public:
	BST();
	void insert(int num, string str, unsigned long &n);
	void remove(int num);
	void inOrder(void);
	void inOrder(Node *);
	Node *getSmallest(Node* root);
	void writeToFiles(ofstream &oF, ofstream &sI, int size, unsigned long &n);
	void inOrderWrite(Node *newRoot, ofstream &oF);
};

#endif