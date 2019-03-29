
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 5: Building a Database with BSTs
*/


/*
	This class acts as a parent class for both Student and Faculty. Comparison operators are overloaded for both classes here to compare ID #s.
	Shared member variables are also here for Student / Faculty.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Person.h"


using namespace std;

/*
	Person constructor for testing
*/
Person::Person()
{
	int x = rand();

	ID = rand();
}

/*
	Person destructor. We all shall fall.
*/
Person::~Person()
{


}


/*
	Getter for ID
*/
int Person::get_ID() const
{
	return (this->ID);
}

/*
	Setter for ID
*/
void Person::set_ID(int new_ID)
{
	this->ID = new_ID;
}

/*
	Getter for name
*/
string Person::get_name()
{
	return name;
}

/*
	Setter for name
*/
void Person::set_name(string new_name)
{
	name = new_name;
}

/*
	Getter for level (Student = year | Faculty = profession)
*/
string Person::get_level()
{
	return this->level;
}

/*
	Setter for level (Student = year | Faculty = profession)
*/
void Person::set_level(string new_level)
{
	this->level = new_level;
}

/*
	Getter for subject
*/
string Person::get_subject()
{
	return subject;
}

/*
	Setter for subject
*/
void Person::set_subject(string new_subject)
{
	subject = new_subject;
}


/*
	Overloads the < operator to compare Persons, (ie. Student to Student, and Faculty to Faculty)
*/
bool operator<(const Person& p1, const Person& p2)
{
	return (p1.get_ID() < p2.get_ID());
}

/*
	You should not be streaming out this base class (Person)
*/
ostream& operator<<(ostream& os, const Person& p) 
{  
    os << p.get_ID() << " ... printing a person class (base class)" << endl;
    return os;  
}  

/*
	Overloads the == operator to compare Persons, (ie. Student to Student, and Faculty to Faculty)
*/
bool operator==(const Person& p1, const Person& p2)
{
	return (p1.get_ID() == p2.get_ID());
}

/*
	Overloads the != operator to compare Persons, (ie. Student to Student, and Faculty to Faculty)
*/
bool operator!=(const Person& p1, const Person& p2)
{
	return (p1.get_ID() != p2.get_ID());
}





