#ifndef Person_H
#define Person_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;



class Person
{

public:

	Person();
	~Person();


	int get_ID() const;
	void set_ID(int new_ID);

	string get_name();
	void set_name(string new_name);

	string get_level();
	void set_level(string new_level);

	string get_subject();
	void set_subject(string new_subject);

	friend bool operator<(const Person& p1, const Person& p2);
	friend ostream& operator<<(ostream& os, const Person& p);  
	friend bool operator==(const Person& p1, const Person& p2);
	friend bool operator!=(const Person& p1, const Person& p2);



private:

	int ID;
	string name;
	string level;
	string subject; // Major for student; department for faculty



};


#endif //Person_H