// Comment?
#include <iostream>
#include "StatsCanParser.hpp"

using namespace std;

// Comment?
#define ARG_COUNT 2
#define FILE_ARG 1

// Comment?
int main(int argc, char** argv)
{
	if (argc != ARG_COUNT)
	{
		cerr << "Supply a data file as an argument." << endl;
	}
	else
	{
		StatsCanGroceryDataReader* groceries = new StatsCanGroceryDataReader();
		cout << "Reading " << argv[FILE_ARG] << " ..." << endl;

		if (!groceries->read_file(argv[FILE_ARG]))
		{
			StatsCanGroceryData dt = groceries->parse();
			UserInputHandler* handler = new UserInputHandler(dt);
			handler->clear();
			handler->interact();
			delete handler;
		}
		else
		{
			cerr << "Error." << endl;
		}
	}
}

