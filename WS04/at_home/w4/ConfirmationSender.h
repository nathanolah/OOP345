// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca  
// Date of completion: 2020/02/10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CONFIRMATIONSENDER_H__
#define SDDS_CONFIRMATIONSENDER_H__
#include "Reservation.h"

namespace sdds {
   class ConfirmationSender {
      Reservation** m_reservationsObj;
      size_t m_numOfaddresses;
      size_t m_maxNumOfAddresses;
   public:
      ConfirmationSender();
      ~ConfirmationSender();
      ConfirmationSender(const ConfirmationSender& ro);
      ConfirmationSender(ConfirmationSender&& ro);
      ConfirmationSender& operator=(const ConfirmationSender& ro);
      ConfirmationSender& operator=(ConfirmationSender&& ro);
      ConfirmationSender& operator+=(Reservation& res);
      ConfirmationSender& operator-=(Reservation& res);
      friend std::ostream& operator<<(std::ostream& os,const ConfirmationSender ro);
   };
}
#endif // !SDDS_CONFIRMATIONSENDER_H__
