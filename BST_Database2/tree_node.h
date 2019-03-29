
#ifndef tree_node_H
#define tree_node_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;


template <class T>
class tree_node 
{

public:

	tree_node();
	tree_node(T k);
	~tree_node();

	T key;
	tree_node *left;
	tree_node *right;

};

#endif //tree_node_H
