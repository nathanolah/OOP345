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
   };
}
#endif // !SDDS_AUTOSHOP_H__
