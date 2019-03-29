
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 5: Building a Database with BSTs
*/


/*
	This class manages makes use of the tree_node class to properly construct a Binary Search Tree of any type T.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>

#include "BST.h"

using namespace std;


/*
	BST Constructor
*/
template <class T>
BST<T>::BST()
{
	root = NULL;
}


/*
	BST Destructor
*/
template <class T>
BST<T>::~BST()
{
	root = NULL;
	// Iterate and deletes
	// Build character along the way
}


/*
	Getter for the BST root leaf node.
	Returns the root as a leaf node (pointer).
*/
template <class T>
tree_node<T>* BST<T>::get_root()
{
	return root;
}


/*
	Prints the entire BST, from leftmost (least) node to rightmost (greatest)
	Lesser and greater are defined by comarison operators, overloaded or not.
*/
template <class T>
void BST<T>::print_tree(tree_node<T> *node) // In-order traversal
{
	if (node == NULL)
	{
		return;
	}

	print_tree(node->left);
	cout << node->key << endl;
	print_tree(node->right);
}


/*
	Returns the leftmost tree_node. (Least)
*/
template <class T>
tree_node<T>* BST<T>::get_min()
{

	tree_node<T> *curr = root;

	if (root == NULL)
	{
		return NULL;
	}

	while (curr->left != NULL)
	{
		curr = curr->left;
	}

	return curr;
}


/*
	Returns the rightmost tree_node. (Greatest)
*/
template <class T>
tree_node<T>* BST<T>::get_max()
{

	tree_node<T> *curr = root;

	if (root == NULL)
	{
		return NULL;
	}

	while (curr->right != NULL)
	{
		curr = curr->right;
	}

	return curr;
}



/*
	Inserts data of type k into the BST. Finds the correct spot to insert following sorted BST guidelines.
	Uses (overloaded) comparison operators.
*/
template <class T>
void BST<T>::insert(T k)
{

	tree_node<T> *node = new tree_node<T>(k);


	// Empty tree; insert new tree_node as root
	if (root == NULL) 
	{
		root = node;
	}

	// Non-empty tree
	else
	{
		tree_node<T> *curr = root;
		tree_node<T> *parent = NULL;

		// Now traverse and compare
		while (true) 
		{
			parent = curr;

			if (k < curr->key) // Go left
			{
				curr = curr->left;

				if (curr == NULL) // Found the insertion point
				{
					parent->left = node;
					break;
				}
			}

			else // Go right
			{
				curr = curr->right;

				if (curr == NULL) // Found the insertion point
				{
					parent->right = node;
					break;
				}
			}
		}
	}
}


/*
	Finds tree_node that holds data which equals k, and returns that tree_node.
*/
template <class T>
tree_node<T>* BST<T>::find(T k)
{
	
	tree_node<T> *curr = root;

	if (root == NULL)
	{
		cout << "This tree is empty" << endl;
		return NULL;
	}

	else
	{
		while (curr->key != k)
		{
			if (k < curr->key) // Go left
			{
				curr = curr->left;
			}

			else // Go right
			{
				curr = curr->right;
			}

			if (curr == NULL) // Did not find it
			{
				cout << "Could not find tree node with ID = " << k.get_ID() << endl;

				tree_node<T>* doesnt_exist = new tree_node<T>(-1);
				return doesnt_exist;
			}
		}
	}

	return curr;
}


/*
	Returns true or false; whether the tree contains data k, or not.
*/
template <class T>
bool BST<T>::contains(T k)
{
	if (root == NULL)
	{
		return false;
	}

	else
	{
		tree_node<T> *curr = root;

		while (curr->key != k)
		{
			if (k < curr->key) // Go left
			{
				curr = curr->left;
			}

			else // Go right
			{
				curr = curr->right;
			}

			if (curr == NULL) // Did not find it
			{
				return false;
			}
		}
	}

	return true;
}


/*
	Returns true or false; whether the tree_node with data = k was found and deleted.
	Properly rearranges the BST tree_nodes after deletion.
*/
template <class T>
bool BST<T>::delete_node(T k)
{
	if (root == NULL)	// Empty tree
	{
		return false;
	}

	tree_node<T> *current = root;
	tree_node<T> *parent = root;

	bool is_left;

	// Look for node to be deleted
	while (current->key != k)
	{
		parent = current;

		if (k < current->key)
		{
			is_left = true;
			current = current->left; 
		}

		else
		{
			is_left = false;
			current = current->right;
		}

		if (current == NULL) // Node to be deleted does not exist
		{
			return false;
		}


	}

	// We have found what needs to be deleted!


	// 3 cases below: no children, one child, two children

	// No children; easiest case
	if (current->left == NULL && current->right == NULL)
	{
		if (current == root)
		{
			root = NULL;
		}

		else if (is_left)
		{
			parent->left = NULL;
		}

		else 
		{
			parent->right = NULL;
		}

	}


	// One child
		// No right child
	else if (current->right == NULL)
	{
		if (current == root)
		{
			root = current->left;
		}

		else if (is_left)
		{
			parent->left = current->left;
		}

		else 
		{
			parent->right = current->left;
		}
	}


		// No left child
	else if (current->left == NULL)
	{
		if (current == root)
		{
			root = current->right;
		}

		else if (is_left)
		{
			parent->left = current->right;
		}

		else
		{
			parent->right = current->right;
		}
	}


	// Two children
	else 
	{
		tree_node<T> *successor = get_successor(current);

		if (current == root)
		{
			root = successor;
		}

		else if (is_left)
		{
			parent->left = successor;
		}

		else 
		{
			parent->right = successor;
		}

		successor->left = current->left;
	}

	return true;
}


/*
	Used by delete_node to find an appropriate successor to the deleted node. Takes the deleted node as input.
	Also used to find an appropriate successor for a student's advisor in SimulateData.
*/
template <class T>
tree_node<T>* BST<T>::get_successor(tree_node<T> *d) // d represents the node that we are going to delete
{

	/* traverse right once from d, and then go all the way left to find the successor */

	tree_node<T> *sp = d; // sp = successor's parent
	tree_node<T> *successor = d; // successor should be one right, all the way left
	tree_node<T> *current = d->right;

	while (current != NULL)
	{
		sp = successor;
		successor = current;
		current = current->left;
	}

	if (successor != d->right) // Not the right child of d
	{
		sp->left = successor->right;
		successor->right = d->right;
	}


	return successor;
}



