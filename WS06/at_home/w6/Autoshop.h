// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_AUTOSHOP_H__
#define SDDS_AUTOSHOP_H__
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"
#include "Car.h"
namespace sdds {
   class Autoshop {
      std::vector<Vehicle*> m_vehicles;
   public:
      Autoshop();
      ~Autoshop();
      Autoshop& operator+=(Vehicle* theVehicle);
      void display(std::ostream& os)const;

      template <typename T>
      void select(T test, std::list<const Vehicle*>& vehicles) {
         std::vector<Vehicle*>::iterator itr;
         size_t i = 0;

         for (auto itr = m_vehicles.begin(); itr != m_vehicles.end(); itr++, i++) {
            if (test(m_vehicles.at(i))) {
               vehicles.push_back(m_vehicles.at(i));
            }
         }
      }  
   };
}
#endif // !SDDS_AUTOSHOP_H__
