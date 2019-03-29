

#ifndef Faculty_H
#define Faculty_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include <vector>

#include "Person.h"

#include "BST.h"




using namespace std;

class Faculty : public Person
{

public:


	Faculty();
	Faculty(int new_ID);
	Faculty(string new_name, int new_ID, string new_level, string new_department);
	Faculty(string new_name, int new_ID, string new_level, string new_department, vector<int> new_advisees);
	~Faculty();

	void add_advisee(int new_advisee);
	void remove_advisee(int rm_advisee);
	vector<int> get_advisees();




	friend ostream& operator<<(ostream& os, Faculty& f);


private:

	vector<int> advisees;

};






#endif //Faculty_H