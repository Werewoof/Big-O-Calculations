#ifndef ___NODEHPP___
#define ___NODEHPP___

/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #2
 
 
    Description of the problem:
         This project implements the Node class. It contains private data to 
         hold a random int and a random string. It also contains two nodes, 
	 left and right, that point to other nodes, implemented via a binary 
	 tree. Accessor functions are available to retrieve the private data. 
	 Mutator functions are available to set private data.
         
 
Pseudo Code

Struct: data

   Data:
      randomInt - an integer to be randomized.
      randomString - a string to be randomized.
 
   Functions:
      None.

   

   
   
Class: Node

   Data: 
      data - an instance of the struct data.
      left - a pointer to the left subtree of the node.
      right - a pointer to the right subtree of the node.
   
   Mutator Functions:
      =>    setLeft - set the left subtree of a node to another node.
               Input Parms: pointer to a node
               Output Parms: None
               
      =>    setRight - set the right subtree of a node to another node.
               Input Parms: pointer to a node
               Output Parms: None
               
      =>    setNumber - set randomInt.
               Input Parms: number
               Output Parms: None
               
      
   Accessor Functions:
      =>    getLeft - return node's left subtree.
               Input Parms: None
               Output Parms: left subtree
                        
      =>    getRight - return node's right subtree.
               Input Parms: None
               Output Parms: right subtree
               
      =>    getNumber - gets randomInt.
                  Input Parms: None
                  Output Parms: randomInt
                  
      =>    getName - gets randomString.
                  Input Parms: None
                  Output Parms: randomString
                  
   Functions:
      None.
*/  


#include <iostream>
#include <string>

#include "structData.hpp"

using namespace std;


struct info
{
	string name;
	int number;
};

class Node
{
	structData d;
	Node *left, *right;
public:
	Node();
	Node(int num, string str);
	Node *getLeft();
	Node *getRight();
	int getNumber();
	string getName();
	void setLeft(Node* n);
	void setRight(Node* n);
	void setNumber(int n);
};

#endif 