
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 5: Building a Database with BSTs
*/


/*
	This class constructs the Faculty. It holds all member variables and functions required to properly manage a BST of faculty.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Faculty.h"

#include "BST.cpp"



using namespace std;

/*
	Faculty constructor for testing
*/
	Faculty::Faculty()
	{
		set_name("DR. NULL");
		set_ID(5001 + (rand() % 5000));
		set_level("Professor");
		set_subject("Mathematics");
		add_advisee(1017);
		add_advisee(3609);
	}


/*
	Faculty constructor for testing. Also used in methods to find Faculty of a given ID #.
	Taken here as input 'new_ID'
*/
	Faculty::Faculty(int new_ID)
	{
		set_ID(new_ID);
	}

/*
	Faculty constructor for creating new Faculty in the database, given all basic inputs.
*/
	Faculty::Faculty(string new_name, int new_ID, string new_level, string new_department)
	{
		set_name(new_name);
		set_ID(new_ID);
		set_level(new_level);
		set_subject(new_department);
	}

/*
	Faculty constructor for creating new Faculty in the database, given all basic inputs, plus the addition of all advisees.
	This is accomplished using a vector of ints to store new_advisees any copy it to the Faculty member variable.
*/
	Faculty::Faculty(string new_name, int new_ID, string new_level, string new_department, vector<int> new_advisees)
	{
		set_name(new_name);
		set_ID(new_ID);
		set_level(new_level);
		set_subject(new_department);

		for (int i = 0; i < new_advisees.size(); ++i)
		{
			add_advisee(new_advisees[i]);
		}
	}

/*
	Faculty destructor. Shall you never fall Rene.
*/
	Faculty::~Faculty()
	{

	}

/*
	Used to add advisees to the advisee vector of ints holding Student ID #s.
	Takes the new advisee ID# as input.
*/
	void Faculty::add_advisee(int new_advisee)  
	{
		advisees.push_back(new_advisee);
	}

/*
	Used to remove advisees from the advisee vector class member variable.
	Takes the advisee ID# as input that we want to delete.
*/
	void Faculty::remove_advisee(int rm_advisee)
	{
		for (int i = 0; i < get_advisees().size(); ++i)
		{
			if (get_advisees()[i] == rm_advisee)
			{
				advisees.erase(advisees.begin() + i);
			}
		}
	}

/*
	Returns the private member variable containing all advisees.
*/
	vector<int> Faculty::get_advisees()  
	{
		return advisees;
	}





/*
	When streaming out a Faculty object, this is the correct way to print it, with all member variables labeled.
*/
	ostream& operator<<(ostream& os, Faculty& f)
	{

   		os << "Faculty Name: " << f.get_name() << endl
		<< "ID #: " << f.get_ID() << endl
		<< "Level: " << f.get_level() << endl
		<< "Department: " << f.get_subject() << endl
		<< "Advisees: ";

		for (int i = 0; i < f.get_advisees().size(); ++i)
		{
			os << f.get_advisees()[i] << " ";
		}

		os << endl;
		return os;
	}




