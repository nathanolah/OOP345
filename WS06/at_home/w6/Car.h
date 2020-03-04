// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include <iostream>
#include "Vehicle.h"
namespace sdds {
   class Car : public Vehicle {
      std::string m_maker;
      std::string m_condition;
      unsigned m_topSpeed;
   public:
      Car();
      Car(std::istream& is);
      virtual ~Car();
      std::string condition()const;
      double topSpeed()const;
      void display(std::ostream& os)const;
      void trim(std::string& str);
      std::string getString(std::string& tempStr);
      bool isUnsigned(const std::string str);

   };
}
#endif // !SDDS_CAR_H__
