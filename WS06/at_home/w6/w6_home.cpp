// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "Autoshop.h"
#include "Autoshop.h"
#include "Utilities.h"
#include "Utilities.h"


void loadData(const char* filename, sdds::Autoshop& as)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	while (file)
	{
		// TODO: This code can throw errors to signal that something went wrong while
		//         extracting data. Write code to catch and handle the following errors:
		//       - the type of vehicle is not recognized: the first non-empty character
		//           on the line is not 'c', 'C', 'r', or 'R'. In this case print
		//           "Unrecognized record type: [TAG]<endl>"
		//       - one of the fields in the record contains invalid data. In this case print
		//           "Invalid record!<endl>"
		try {
			// createInstance
			sdds::Vehicle* aVehicle = sdds::createInstance(file);
			if (aVehicle)
				as += aVehicle;
		}
		catch (std::string errorMessage) {
			std::cout << errorMessage << std::endl;
		}
		catch (const char* errorMessage) {
			std::cout << errorMessage << std::endl;
		}

		/*sdds::Vehicle* aVehicle = sdds::createInstance(file);
		if (aVehicle)
			as += aVehicle;*/
	}
	file.close();
}

// ws dataClean.txt dataMessy.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Autoshop as;
	loadData(argv[1], as);
	as.display(std::cout);
	std::cout << "\n";
	loadData(argv[2], as);
	as.display(std::cout);

	std::cout << std::endl;
	std::list<const sdds::Vehicle*> vehicles;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
		//         and returns true if the vehicle has a top speed >300km/h
		
		auto fastVehicles = [] (const sdds::Vehicle* vehicle) { 
			if (vehicle->topSpeed() > 300) {
				return true;
			}
			else {
				return false;
			}
		};

			as.select(fastVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "|       Fast Vehicles          |\n";
		std::cout << "--------------------------------\n";
		for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
		{
			(*it)->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	vehicles.clear();
	std::cout << std::endl;
	{
		// todo: create a lambda expression that receives as parameter `const sdds::vehicle*`
		//         and returns true if the vehicle is broken and needs repairs.

		auto brokenvehicles = [] (const sdds::Vehicle* vehicle) {
			if (vehicle->condition() == "broken") {
				return true;
			}
			else {
				return false;
			}
		};

			as.select(brokenvehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "| Vehicles in need of repair   |\n";
		std::cout << "--------------------------------\n";
		for (const auto vehicle : vehicles)
		{
			vehicle->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	return 0;
}
