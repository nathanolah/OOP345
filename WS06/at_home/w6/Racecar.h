// Name: Nathan Olah
// Seneca Student ID: 124723198  
// Seneca email: nolah@myseneca.ca 
// Date of completion: 2020/03/03
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_RACECAR_H__
#define SDDS_RACECAR_H__
#include <iostream>
#include "Car.h"
namespace sdds {
   class Racecar : public Car {
      double m_booster;
   public:
      Racecar();
      ~Racecar();
      Racecar(std::istream& in);
      void display(std::ostream& os)const;
      double topSpeed()const;
   };
}
#endif // !SDDS_RACECAR_H__
