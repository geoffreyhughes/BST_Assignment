
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 5: Building a Database with BSTs
*/


/*
	This class is where all file reading / writing is done; all user input; and all modifications to the database.
	It also holds the main while loop that makes changes to the two Binary Search Trees.
	This class makes use of all other classes.
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <sstream>

#include "GenStack.cpp"

#include "BST.h"
#include "BST.cpp"

#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "SimulateDatabase.h"


using namespace std;

/*
	Constructs an instance of SimulateDatabase
*/
SimulateDatabase::SimulateDatabase()
{
}

/*
	Destructs an instance of SimulateDatabase. We all shall fall.
*/
SimulateDatabase::~SimulateDatabase()
{
}


/*
	This handles the entire database. 
	All file reading / writing is done within this method; all user input handled; and all modifications to the BSTs.
*/
void SimulateDatabase::Run()
{

	read_files();



	exit_now = false;
	user_input_int = -1;
	user_input_string = "";



	while (!exit_now)
	{

		cout << endl << 
				"What would you like to do?" << endl <<
				"[1] Print all students and their information" << endl <<
				"[2] Print all faculty and their information" << endl <<
				"[3] Find and display student information given the students id" << endl <<
				"[4] Find and display faculty information given the faculty id" << endl <<
				"[5] Given a student’s id, print the name and info of their faculty advisor" << endl <<
				"[6] Given a faculty id, print ALL the names and info of his/her advisees" << endl <<
				"[7] Add a new student" << endl <<
				"[8] Delete a student given the id" << endl <<
				"[9] Add a new faculty member" << endl <<
				"[10] Delete a faculty member given the id" << endl <<
				"[11] Change a student’s advisor given the student id and the new faculty id" << endl <<
				"[12] Remove an advisee from a faculty member given the ids" << endl <<
				"[13] Rollback" << endl <<
				"[14] Exit" << endl <<
				">";



		cin >> user_input_int;


		if (user_input_int == 1)
		{
			case_1();
		}
		else if (user_input_int == 2)
		{
			case_2();
		}
		else if (user_input_int == 3)
		{
			case_3();
		}
		else if (user_input_int == 4)
		{
			case_4();
		}
		else if (user_input_int == 5)
		{
			case_5();
		}
		else if (user_input_int == 6)
		{
			case_6();
		}
		else if (user_input_int == 7)
		{
			case_7();

		}
		else if (user_input_int == 8)
		{
			case_8();

		}
		else if (user_input_int == 9)
		{
			case_9();

		}
		else if (user_input_int == 10)
		{
			case_10();

		}
		else if (user_input_int == 11)
		{
			case_11();

		}
		else if (user_input_int == 12)
		{
			case_12();

		}
		else if (user_input_int == 13)
		{
			case_13();
		}



		else if (user_input_int == 14)
		{
			exit_now = true;
		}

		

	} // END OF while loop. Database modification complete. Exit called.

	write_files();
}




/*
	Handles case 1
*/
void SimulateDatabase::case_1()
{
	masterStudent.print_tree(masterStudent.get_root());
}

/*
	Handles case 2
*/
void SimulateDatabase::case_2()
{
	masterFaculty.print_tree(masterFaculty.get_root());
}

/*
	Handles case 3
*/
void SimulateDatabase::case_3()
{
	cout << "Please enter the student's ID #: ";
	cin >> user_input_int;

	Student temp = Student(user_input_int);

	if (masterStudent.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else
	{
		cout << endl << masterStudent.find(temp)->key << endl;
	}
}

/*
	Does the same operation as case 3; used in other cases
*/
void SimulateDatabase::case_3_with_student_ID(int student_ID)
{
	Student temp = Student(student_ID);

	if (masterStudent.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else
	{
		cout << endl << masterStudent.find(temp)->key << endl;
	}
}

/*
	Handles case 4
*/
void SimulateDatabase::case_4()
{
	cout << "Please enter the faculty's ID #: ";
	cin >> user_input_int;

	Faculty temp = Faculty(user_input_int);

	if (masterFaculty.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else
	{
		cout << endl << masterFaculty.find(temp)->key << endl;
	}
}


/*
	Does the same operation as case 4; used in other cases
*/
void SimulateDatabase::case_4_with_faculty_ID(int faculty_ID)
{
	Faculty temp = Faculty(faculty_ID);

	if (masterFaculty.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else
	{
		cout << endl << masterFaculty.find(temp)->key << endl;
	}
}

/*
	Handles case 5
*/
void SimulateDatabase::case_5()
{
	cout << "Please enter the student's ID # to display their advisor's information: ";
	cin >> user_input_int;

	Student temp = Student(user_input_int);

	if (masterStudent.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else		
	{
		case_4_with_faculty_ID(masterStudent.find(temp)->key.get_advisor());
	}
}

/*
	Does the same operation as case 5; used in other cases. 
	Returns an int of student's advisor ID#, after taking the student's ID#.
*/
int SimulateDatabase::case_5_with_student_ID(int student_ID)
{
	Student temp = Student(student_ID);

	if (masterStudent.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	
	return masterStudent.find(temp)->key.get_advisor();
}

/*
	Handles case 6
*/
void SimulateDatabase::case_6()
{
	cout << "Please enter the faculty's ID # to display ALL their advisees' information: ";
	cin >> user_input_int;

	Faculty temp = Faculty(user_input_int);

	if (masterFaculty.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else		
	{
		for (int i = 0; i < masterFaculty.find(temp)->key.get_advisees().size(); ++i)
		{
			case_3_with_student_ID(masterFaculty.find(temp)->key.get_advisees()[i]);
		}
	}


}

/*
	Handles case 7
*/
void SimulateDatabase::case_7()
{
	string new_name = "";
	int new_ID = -1;
	string new_level = "";
	string new_major = "";
	double new_GPA = 0.0;
	int new_advisor = -1;

	bool duplicates = true;

	cout << "Please enter the following info to add a new student..." << endl;
	cout << "Student Name: ";
	cin >> ws;
	getline(cin, new_name);

	while (duplicates)
	{
		cout << "Student ID # [1 - 5000]: ";
		cin >> new_ID;

		Student temp = Student(new_ID);

		if (masterStudent.contains(temp))
		{
			cout << "That student ID # is already in use." << endl;
		}

		if (!masterStudent.contains(temp))
		{
			duplicates = false;
		}
	}

	cout << "Student level [Freshman, Sophomore, Junior, Senior]: ";
	cin >> new_level;

	cout << "Student Major: ";
	cin >> ws;
	getline(cin, new_major);

	cout << "Student GPA: ";
	cin >> new_GPA;

	cout << "Advisor ID #: ";
	cin >> new_advisor;

	masterFaculty.find(new_advisor)->key.add_advisee(new_ID);

	masterStudent.insert(Student(new_name, new_ID, new_level, new_major, new_GPA, new_advisor));
}

/*
	Handles case 8
*/
void SimulateDatabase::case_8()
{
	int student_ID;
	int faculty_ID;

	cout << "Please enter the student's ID # to delete them from the database: ";
	cin >> student_ID;

	while (!masterStudent.contains(masterStudent.find(student_ID)->key))
	{
		cout << "The database does not contain a student under that ID #. Please try again:";
		cin >> ws;
		cin >> student_ID;
	}

	faculty_ID = case_5_with_student_ID(student_ID);
	Faculty temp_f = Faculty(faculty_ID);

	masterFaculty.find(temp_f)->key.remove_advisee(student_ID);



	Student temp_s = Student(student_ID);
	masterStudent.delete_node(temp_s);
}

/*
	Handles case 9
*/
void SimulateDatabase::case_9()
{

	string new_name = "";
	int new_ID = -1;
	string new_level = "";
	string new_department = "";
	int new_advisee = -1;

	bool duplicates = true;

	cout << "Please enter the following info to add a new faculty..." << endl;
	cout << "Faculty Name: ";
	cin >> ws;
	getline(cin, new_name);

	while (duplicates)
	{
		cout << "Faculty ID # [5001 - 10000]: ";
		cin >> new_ID;

		Faculty temp = Faculty(new_ID);

		if (masterFaculty.contains(temp))
		{
			cout << "That faculty ID # is already in use." << endl;
		}

		if (!masterFaculty.contains(temp))
		{
			duplicates = false;
		}
	}

	cout << "Faculty level [Professor, Assistant Professor, TA, etc...]: ";
	cin >> ws;
	getline(cin, new_level);

	cout << "Faculty Department: ";
	cin >> ws;
	getline(cin, new_department);

	bool not_finished = true;
	vector<int> new_advisees;

	while (not_finished)
	{
		cout << "Faculty advisee(s) [Enter existing Student of ID # 1 - 5000]" << endl;
		cout << "[enter 0 to finish]: ";
		cin >> new_advisee;

		if (new_advisee == 0)
		{
			not_finished = false;
		}

		else
		{
			new_advisees.push_back(new_advisee);
		}
	}

	Faculty new_faculty = Faculty(new_name, new_ID, new_level, new_department);
	masterFaculty.insert(new_faculty);

	for (int i = 0; i < new_advisees.size(); ++i)
	{
		masterFaculty.find(new_ID)->key.add_advisee(new_advisees[i]);
	}
}

/*
	Handles case 10
*/
void SimulateDatabase::case_10()
{


	int faculty_ID;

	vector<int> students_to_reassign;


	cout << "Please enter the faculty's ID # to delete them from the database: ";
	cin >> faculty_ID;

	while (!masterFaculty.contains(masterFaculty.find(faculty_ID)->key))
	{
		cout << "The database does not contain a faculty member under that ID #. Please try again:";
		cin >> ws;
		cin >> faculty_ID;
	}

	students_to_reassign = masterFaculty.find(faculty_ID)->key.get_advisees();
	masterFaculty.delete_node(masterFaculty.find(faculty_ID)->key);

	if (students_to_reassign.size() != 0)
	{
		cout << "With faculty member deleted, you must reassign " << students_to_reassign.size() << " students" << endl;
	}

	for (int i = 0; i < students_to_reassign.size(); ++i)
	{
		cout << "Enter existing Faculty ID # for student ID #" << students_to_reassign[i] << ": ";
		cin >> faculty_ID;
		masterStudent.find(students_to_reassign[i])->key.set_advisor(faculty_ID);
		masterFaculty.find(faculty_ID)->key.add_advisee(students_to_reassign[i]);
	}
}

/*
	Handles case 11
*/
void SimulateDatabase::case_11()
{
	int student_ID;
	int new_advisor_ID;

	cout << "Please enter the student's ID #: ";
	cin >> student_ID;

	cout << "Now enter the new advisor ID # you wish to change to: ";
	cin >> new_advisor_ID;

	if (masterFaculty.contains(masterStudent.find(student_ID)->key.get_advisor()))
	{
		masterFaculty.find(masterStudent.find(student_ID)->key.get_advisor())->key.remove_advisee(student_ID);
	}

	masterFaculty.find(new_advisor_ID)->key.add_advisee(student_ID);
	masterStudent.find(student_ID)->key.set_advisor(new_advisor_ID);

}

/*
	Handles case 12
*/
void SimulateDatabase::case_12()
{
	int faculty_ID;
	int advisee_ID;

	int faculty_successor;

	cout << "Please enter the faculty ID # from which you would like to remove an advisee: ";
	cin >> faculty_ID;

	cout << "Now choose which advisee to remove: ";
	for (int i = 0; i < masterFaculty.find(faculty_ID)->key.get_advisees().size(); ++i)
	{
		cout << masterFaculty.find(faculty_ID)->key.get_advisees()[i] << " "; 
	}

	cin >> advisee_ID;

	masterFaculty.find(faculty_ID)->key.remove_advisee(advisee_ID);
	faculty_successor = masterFaculty.get_successor(masterFaculty.find(faculty_ID))->key.get_ID();

	if (faculty_successor != faculty_ID)
	{
		masterStudent.find(advisee_ID)->key.set_advisor(faculty_successor);
		masterFaculty.find(faculty_successor)->key.add_advisee(advisee_ID);
	}
	
	else
	{
		masterStudent.find(advisee_ID)->key.set_advisor(0);
		cout << "No successor found to advise student. Advisor set to 0. Please call 11 to reassign." << endl;
	}

}

/*
	Handles case 13
*/
void SimulateDatabase::case_13()
{

	cout << "Don't make mistakes!" << endl << "See comments of case_13() :(" << endl;
/*

	Sadly I was only able to make the Stack method of savestates work with 1 iteration. Then it caused errors.
	I am very sad about conceding this

	masterStudent = student_stack.pop();
	masterFaculty = faculty_stack.pop();
*/

}

// comments, READ_ME, Makefile, *polish*


/*
	Reads files at startup if they are there. "studentTable" and "facultyTable"
	Reads them into the two Binary Search Trees, respectively.
	If no file(s) exist, it creates them.
*/
void SimulateDatabase::read_files()
{
	string file_line = "";

	// Create or Read studentTable
	if (!does_file_exist("studentTable"))
	{
		ofstream new_studentTable;
		new_studentTable.open("studentTable");
		new_studentTable.close();
	}

	else
	{
		ifstream read_studentTable("studentTable");

		if (read_studentTable.is_open())
		{
			bool keep_reading = true;

			string new_name;
			int new_ID;
			string new_level;
			string new_major;
			double new_GPA;
			int new_advisor;

			while (keep_reading) // = name, id, level, major, gpa, advisor
			{


				getline(read_studentTable, file_line);
				file_line.erase(0, 14);
				new_name = file_line;

				if (new_name == "")
				{
					break;
				}

				getline(read_studentTable, file_line);
				file_line.erase(0, 6);
				new_ID = stoi(file_line);

				getline(read_studentTable, file_line);
				file_line.erase(0, 7);
				new_level = file_line;

				getline(read_studentTable, file_line);
				file_line.erase(0, 7);
				new_major = file_line;

				getline(read_studentTable, file_line);
				file_line.erase(0, 5);
				new_GPA = stod(file_line);

				getline(read_studentTable, file_line);
				file_line.erase(0, 14);
				new_advisor = stoi(file_line);


				masterStudent.insert(Student(new_name, new_ID, new_level, new_major, new_GPA, new_advisor));


				if (!getline(read_studentTable, file_line))
				{
					keep_reading = false;
				}
			}

			read_studentTable.close();
		}
	}

	// Create or Read facultyTable
	if (!does_file_exist("facultyTable"))
	{
		ofstream new_facultyTable;
		new_facultyTable.open("facultyTable");
		new_facultyTable.close();
	}

	else
	{
		ifstream read_facultyTable("facultyTable");

		if (read_facultyTable.is_open())
		{
			bool keep_reading = true;

			string new_name;
			int new_ID;
			string new_level;
			string new_department;

			vector<int> new_advisees_int;

			while (keep_reading) // = name, ID, level, department, advisees [...]
			{

				getline(read_facultyTable, file_line);
				file_line.erase(0, 14);
				new_name = file_line;

				if (new_name == "")
				{
					break;
				}

				getline(read_facultyTable, file_line);
				file_line.erase(0, 6);
				new_ID = stoi(file_line);

				getline(read_facultyTable, file_line);
				file_line.erase(0, 7);
				new_level = file_line;

				getline(read_facultyTable, file_line);
				file_line.erase(0, 12);
				new_department = file_line;

				getline(read_facultyTable, file_line);
				file_line.erase(0, 10);


				new_advisees_int.clear();


				stringstream ss(file_line);
				istream_iterator<string> begin(ss);
				istream_iterator<string> end;
				vector<string> new_advisees_string(begin, end);

				for (int i = 0; i < new_advisees_string.size(); ++i)
				{
					new_advisees_int.push_back(stoi(new_advisees_string[i]));
				}


				masterFaculty.insert(Faculty(new_name, new_ID, new_level, new_department, new_advisees_int));

				if (!getline(read_facultyTable, file_line))
				{
					keep_reading = false;
				}
			}

			read_facultyTable.close();
		}
	}
}

/*
	Checks to see if input string "file_name" exists within the current directory
*/
bool SimulateDatabase::does_file_exist(string file_name)
{
	ifstream infile(file_name);
	return infile.good();
}

/*
	Writes all of the BSTs 'masterStudent' and 'masterFaculty' to their respective text files.
	Saves them for future use / modification.
*/
void SimulateDatabase::write_files()
{

    freopen("studentTable", "w", stdout);
    masterStudent.print_tree(masterStudent.get_root());


    freopen("facultyTable", "w", stdout);
    masterFaculty.print_tree(masterFaculty.get_root());
}




