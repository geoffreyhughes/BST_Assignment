
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 5: Building a Database with BSTs
*/


/*
	This class constructs the Student. It holds all member variables and functions required to properly manage a BST of students.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Student.h"

using namespace std;


/*
	Student constructor for testing
*/
Student::Student()
{
	set_name("Jr. Null");
	set_ID(rand() % 5001);
	set_level("Freshman");
	set_subject("Math");
	set_GPA(3.42);
	set_advisor(9304);

}

/*
	Student constructor testing, and used in methods to find Students of a certain ID within masterStudent BST.
*/
Student::Student(int new_ID)
{
	set_name("Dr. Null");
	set_ID(new_ID);
}

/*
	Student constructor for creating new Students in the database
*/
Student::Student(string new_name, int new_ID, string new_level, string new_major, double new_GPA, int new_advisor)
{
	set_name(new_name);
	set_ID(new_ID);
	set_level(new_level);
	set_subject(new_major);
	set_GPA(new_GPA);
	set_advisor(new_advisor);
}


/*
	Student Destructor. We all shall fall.
*/
Student::~Student() 
{


}

/*
	Prints a student's basic info
*/
void Student::print_info()
{
	cout << "Student Name: " << get_name();
	cout << "ID #: " << get_ID();
	cout << "Level: " << get_level();
	cout << "Major: " << get_subject();
	cout << "GPA: " << get_GPA();
	cout << "Advisor ID #: " << get_advisor();

}

/*
	Getter for GPA
*/
double Student::get_GPA()
{
	return GPA;
}

/*
	Setter for GPA
*/
void Student::set_GPA(double new_GPA)
{
	GPA = new_GPA;
}

/*
	Getter for student's advisor
*/
int Student::get_advisor()
{
	return advisor;
}

/*
	Setter for student's advisor
*/
void Student::set_advisor(int new_advisor)
{
	advisor = new_advisor;
}

/*
	When streaming out a student object, this is the correct way to print it, with all member variables labeled.
*/
ostream& operator<<(ostream& os, Student& s) 
{  
    os << "Student Name: " << s.get_name() << endl
	<< "ID #: " << s.get_ID() << endl
	<< "Level: " << s.get_level() << endl
	<< "Major: " << s.get_subject() << endl
	<< "GPA: " << s.get_GPA() << endl
	<< "Advisor ID #: " << s.get_advisor() << endl;
    return os;  
}  


