
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 5: Building a Database with BSTs
*/


/*
	This class is what makes the Binary Search Tree possible. It essentially makes a 'leaf' of the tree, which is connected to other leaves through pointers.
	All information in the database is held within one of these tree nodes.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "tree_node.h"

using namespace std;


template <class T>
tree_node<T>::tree_node()
{

	left = NULL;
	right = NULL;
}

template <class T>
tree_node<T>::tree_node(T k)
{
	key = k;
	left = NULL;
	right = NULL;
}

template <class T>
tree_node<T>::~tree_node()
{
	// build some character - may or may not be in the book!
}
