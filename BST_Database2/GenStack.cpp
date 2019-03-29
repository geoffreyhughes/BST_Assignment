
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 5: Building a Database with BSTs
*/


/*
	A Generic Stack class. First object in, last object out.
	Uses template <class T> to handle any object type.
	Dynamically handles push(T d) such that a new array is created if the current one is full.
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "GenStack.h"

using namespace std;
/*
	Default Constructor
*/
template <class T>	
GenStack<T>::GenStack() 
{
	set_size(0);
	top = -1;
}

/*
	Overloaded Constructor
*/	
template <class T>	
GenStack<T>::GenStack(int max_size)
{

	my_array = new T[max_size];

	set_size(max_size);
	top = -1;
}
	
/*
	Class Destructor
*/	
template <class T>	
GenStack<T>::~GenStack() 
{

	delete[] my_array;
}


/*
	Using class T, pushes any data type onto the Stack.
	If the Stack if full, dynamically allocates newly needed space and
	points my_array to bigger_array.
*/
template <class T>	
void GenStack<T>::push(T d) 
{

	if (is_full()) 
	{

		T* bigger_array = new T[get_size() + 1];

		for (int i = 0; i < get_size(); ++i) 
		{
			bigger_array[i] = my_array[i];
		}

		size += 1;
		my_array = bigger_array;
		my_array[++top] = d;

	}
	else 
	{
		my_array[++top] = d;
	}
}

/*
	Returns the object of type T from the top of the Stack, and deletes it (moves top)
	Throws an error if the Stack is empty.
*/
template <class T>
T GenStack<T>::pop()
{
	try 
	{
		if (is_empty()) 
		{
			throw 1;
		}
	}
	catch (int x) 
	{
		cout << "Cannot call function pop() to empty stack. Error " << x << endl;
	}

	return my_array[top--];
}
	

/*
	Returns the object of type T from the top of the Stack.
	Throws an error if the Stack is empty.
*/
template <class T>	
T GenStack<T>::peek()
{
	try 
	{
		if (is_empty()) 
		{
			throw 2;
		}
	}
	catch (int x) 
	{
		cout << "Cannot call function peek() to empty stack. Error " << x << endl;
	}

	return my_array[top];
}


/*
	Returns a boolean value as to whether the Stack is full
*/
template <class T>		
bool GenStack<T>::is_full() 
{
	if (get_size() - 1 == top) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
		

/*
	Returns a boolean value as to whether the Stack is empty
*/
template <class T>	
bool GenStack<T>::is_empty()
{
	if (top == -1)
	{
		return true;
	}
	else 
	{
		return false;
	}
}


/*
	GETS the size of the Stack (array)
*/
template <class T>	
int GenStack<T>::get_size()
{
	return size;
}


/*
	SETS the size of the Stack
*/
template <class T>			
void GenStack<T>::set_size(int new_size)
{
	size = new_size;
}





