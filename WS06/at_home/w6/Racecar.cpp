// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/03/03
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <sstream>
#include "Car.h"
#include "Racecar.h"
using namespace std;
namespace sdds {
   Racecar::Racecar(): m_booster(0) {}
   Racecar::~Racecar() {}

   Racecar::Racecar(std::istream& in) : Car(in) {
      string str;
      
      // If end of file clear failed state to rewind 
      if (in.eof()) {
         in.clear();
      }
      // Get current position
      streampos pos = in.tellg();
      pos -= 5;
      in.seekg(pos);

      getline(in, str, '\n');
      if (!str.empty())
         m_booster = std::stod(str);

   }

   void Racecar::display(std::ostream& os)const {
      this->Car::display(os);
      os << "*";
   }

   double Racecar::topSpeed()const {
      return (Car::topSpeed() * (m_booster + 1.0));
   }

}

