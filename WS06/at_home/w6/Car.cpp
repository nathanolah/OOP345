// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include "Car.h"
using namespace std;
namespace sdds {
   Car::Car() : m_topSpeed(0u) {}

   Car::~Car() {}

   //
   Car::Car(std::istream& is) {
      std::string tempStr;
      bool error = true;

      // Get record
      getline(is, tempStr, '\n');

      m_maker = getString(tempStr);
      trim(m_maker);
      m_condition = getString(tempStr);
      trim(m_condition);
      // Check for empty string set to "new"
      if (m_condition.empty()) {
         m_condition = "n";
      }

      if (m_condition == "n" || m_condition == "u" || m_condition == "b") {
         error = false;
      }
      if (error) {
         throw "Invalid record!";
      }

      if (isUnsigned(tempStr)) {
         m_topSpeed = std::stoi(getString(tempStr));
      }
      else {
         throw "Invalid record!";
      }
      

   }

   // Checks if string matches a unsigned type
   bool Car::isUnsigned(const std::string s) {
      bool ok = true;
      try {
         std::stoi(s);
      }
      catch (...) {
         ok = false;
      }
      return ok;
   }

   //
   std::string Car::getString(std::string& tempStr) {
      std::size_t pos;
      std::string str;

      pos = tempStr.find(',');
      str = tempStr.substr(0, pos); // extract the string     
      tempStr.erase(0, pos + 1);

      return str;
   }

   // Removes whitespace around the string
   void Car::trim(std::string& str) {
      size_t i = 0;
      // Remove leading whitespace
      for (i = 0; i < str.length() && str[i] == ' '; i++); // gets index of whitespace
      str = str.substr(i);

      // Remove trailing whitespace
      for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
      str = str.substr(0, i);
   }

   //
   void Car::display(std::ostream& os)const {
      os << "| " << std::setw(10) << right << m_maker
         << " | " << std::setw(6) << left << condition()
         << " | " << std::setw(6) << fixed << setprecision(2) << topSpeed()
         << " |";
   }

   //
   double Car::topSpeed()const {
      return m_topSpeed;
   }

   //
   std::string Car::condition()const {
      std::string str;
      if (m_condition == "n") {
         str = "new";
      }
      else if (m_condition == "u") {
         str = "used";
      }
      else if (m_condition == "b") {
         str = "broken";
      }
      return str;
   }
}
