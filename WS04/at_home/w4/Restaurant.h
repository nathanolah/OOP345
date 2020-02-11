// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca  
// Date of completion: 2020/02/10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__
#include "Reservation.h"
namespace sdds {

   class Restaurant {
      Reservation* m_reservations;
      size_t m_numOfReservations;
   public:
      Restaurant();
      Restaurant(Reservation* reservation[], size_t cnt);
      Restaurant(const Restaurant& ro);
      Restaurant& operator=(const Restaurant& ro);
      Restaurant(Restaurant&& ro); // Move constructor
      Restaurant& operator=(Restaurant&& ro); // Move assignment operator
      ~Restaurant();
      size_t size()const;
      friend std::ostream& operator<<(std::ostream& os, const Restaurant ro);
      void display(std::ostream& os)const;
   };

}
#endif // !SDDS_RESTAURANT_H__
