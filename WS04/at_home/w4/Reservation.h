// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca  
// Date of completion: 2020/02/10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__
#include <iostream>
namespace sdds {

   class Reservation {
      std::string m_reservationId;
      std::string m_name;
      std::string m_email;
      size_t m_numberOfPeople;
      size_t m_day;
      size_t m_hour;
   public:
      Reservation();
      Reservation(const std::string& res);
      void display(std::ostream& os)const;
      void display(const char* cString)const;
      friend std::ostream& operator<<(std::ostream& os,const Reservation& res);
      size_t hour()const;
      bool isEmpty()const;
   };
}
#endif // !SDDS_RESERVATION_H__