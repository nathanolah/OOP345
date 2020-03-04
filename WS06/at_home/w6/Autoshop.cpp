// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include "Autoshop.h"
#include "Car.h"
namespace sdds {

   Autoshop::Autoshop() {}

   Autoshop::~Autoshop() {
      // Deallocate 
      while (!m_vehicles.empty()) {
         delete m_vehicles.back();
         m_vehicles.pop_back();
      }

   }

   Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
      m_vehicles.push_back(theVehicle);
      return *this;
   }

   void Autoshop::display(std::ostream& os)const {
      std::vector<Vehicle*>::iterator itr;
      size_t i = 0;

      os << "--------------------------------\n"
         << "| Cars in the autoshop!        |\n"
         << "--------------------------------\n";
      for (auto itr = m_vehicles.begin(); itr != m_vehicles.end(); itr++, i++) {
         m_vehicles.at(i)->display(os);
         os << std::endl;
      }
      os << "--------------------------------" << std::endl;
   }

}