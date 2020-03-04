// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_UTILITIES_H__
#define SDDS_UTILITIES_H__
#include "Vehicle.h"
namespace sdds {

   Vehicle* createInstance(std::istream& is);
   void trim(std::string& str);
}
#endif // !SDDS_UTILITIES_H__




