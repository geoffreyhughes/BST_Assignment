
#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "tree_node.h"
#include "tree_node.cpp"



using namespace std;




template <class T>
class BST
{

public:

	BST();
	~BST();


	void insert(T k);
	tree_node<T>* find(T k);
	bool contains(T k);
	bool delete_node(T k);

	tree_node<T> *get_min();
	tree_node<T> *get_max();

	tree_node<T> *get_root();

	bool is_empty();
	int get_size();
	void print_tree(tree_node<T> *node);

	tree_node<T>* get_successor(tree_node<T> *d);



private:

	tree_node<T> *root;
	unsigned int size;
};



#endif //BST_H
