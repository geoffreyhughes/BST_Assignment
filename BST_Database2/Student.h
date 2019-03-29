#ifndef Student_H
#define Student_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Person.h"

using namespace std;

class Student : public Person
{

public:

	Student();
	Student(int new_ID);
	Student(string new_name, int new_ID, string new_level, string new_major, double new_GPA, int new_advisor);

	~Student();

	void print_info();


	double get_GPA();
	void set_GPA(double new_GPA);

	int get_advisor();
	void set_advisor(int new_advisor);


	friend ostream& operator<<(ostream& os, Student& s);


private:

	double GPA;
	int advisor;
};






#endif //Student_H