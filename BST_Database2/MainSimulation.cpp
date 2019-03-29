
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 5: Building a Database with BSTs
*/


/*
	This class is the home to the main function. It constructs the SimulateDatabase class, where most everything is done.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "SimulateDatabase.h"

int main(int argc, char** argv)
{

	// read in facultyTable and studentTable if they exist into their respective trees,
	// if they do not exist, create new empty trees

	SimulateDatabase theSimulation = SimulateDatabase();
	theSimulation.Run();

}