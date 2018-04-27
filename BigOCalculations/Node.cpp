#ifndef ___NODECPP___
#define ___NODECPP___

/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #2
*/ 

#include <iostream>
#include <string>
#include <fstream>
#include "Node.hpp"
using namespace std;

//Default constructor. Sets randomInt to 0, randomString to blank, and
//both subtrees to NULL.
Node::Node()
{
	d.randomInt = 0;
	d.randomString = "";
	left = right = NULL;
}

//Overloaded constructor. Sets both subtrees to NULL, but allows both 
//randomInt and randomString number to be initialized.
Node::Node(int num, string str)
{
	d.randomInt = num;
	d.randomString = str;
	left = right = NULL;
}

//Returns left subtree.
Node* Node::getLeft()
{
	return left;
}

//Returns right subtree.
Node* Node::getRight()
{
	return right;
}

//Returns randomInt.
int Node::getNumber()
{
	return d.randomInt;
}

//Returns randomString.
string Node::getName()
{
	return d.randomString;
}


//Sets node's left subtree to whatever node gets passed in.
void Node::setLeft(Node* n)
{
	left = n; 
}

//Sets node's right subtree to whatever node gets passed in.
void Node::setRight(Node* n)
{
	right = n;
}

//Sets randomInt to whatever gets passed in.
void Node::setNumber(int n)
{
	d.randomInt = n;
}

#endif 