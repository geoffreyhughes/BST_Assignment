
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "BST.h"
#include "GenStack.h"

#include "Person.h"
#include "Student.h"
#include "Faculty.h"



class SimulateDatabase
{

public:

	SimulateDatabase();
	~SimulateDatabase();

	void Run();

	bool does_file_exist(string file_name);
	void read_files();
	void write_files();

	void case_1();
	void case_2();
	void case_3();
	void case_3_with_student_ID(int student_ID);
	void case_4();
	void case_4_with_faculty_ID(int faculty_ID);
	void case_5();
	int case_5_with_student_ID(int student_ID);
	void case_6();
	void case_7();
	void case_8();
	void case_9();
	void case_10();
	void case_11();
	void case_12();
	void case_13();
	void case_14();



	//GenStack<BST<Student> > student_stack;
	//GenStack<BST<Faculty> > faculty_stack;


	BST<Student> masterStudent;
	BST<Faculty> masterFaculty;

	BST<Person> masterDuo [2];



	bool exit_now;
	int user_input_int;
	string user_input_string;

};


