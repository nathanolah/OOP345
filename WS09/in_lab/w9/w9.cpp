// Workshop 9 - Multi-Threading
// w9.cpp

#include <iostream>
#include <fstream>
#include <string>
// Name: Nathan Olah	
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/31
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.9
#include "SecureData.h"
#include "SecureData.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	if (argc != 4)
	{
		cerr << endl << "***Incorrect number of arguments***" << endl;
		return 1;
	}

	char key = argv[3][0];

	try {
		w9::SecureData sd(argv[1], key, &cout);
		sd.backup(argv[2]);

		sd.restore(argv[2], key);
		cout << sd << std::endl;

	}
	catch (const std::string & msg) {
		cout << msg << std::endl;
	}

	return 0;
}
