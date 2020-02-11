// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca  
// Date of completion: 2020/02/10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "ConfirmationSender.h"
namespace sdds {
   
   //
   ConfirmationSender::ConfirmationSender() 
      : m_reservationsObj{ nullptr }, m_numOfaddresses{ 0u }, m_maxNumOfAddresses{0u} {
   }

   //
   ConfirmationSender::~ConfirmationSender() {
     delete[] m_reservationsObj;
      
   }

   // Copy constructor 
   ConfirmationSender::ConfirmationSender(const ConfirmationSender& ro) {
      *this = ro;
   }

   //
   ConfirmationSender::ConfirmationSender(ConfirmationSender&& ro) {
      *this = std::move(ro);
   }

   //
   ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& ro) {
      if (this != &ro) {
         m_maxNumOfAddresses = ro.m_maxNumOfAddresses;
         m_numOfaddresses = ro.m_numOfaddresses;
         ro.m_maxNumOfAddresses = 0;
         ro.m_numOfaddresses = 0;

         if (ro.m_reservationsObj) { 
            m_reservationsObj = ro.m_reservationsObj;
            ro.m_reservationsObj = nullptr;
         }
      }
      return *this;
   }

   // Copy assignment operator 
   ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& ro) {
      if (this != &ro) {
         m_numOfaddresses = ro.m_numOfaddresses;
         m_reservationsObj = new Reservation*[m_numOfaddresses];

         for (size_t i = 0; i < m_numOfaddresses; i++) {
            if (ro.m_reservationsObj)
               this->m_reservationsObj[i] = ro.m_reservationsObj[i];
         }
      }
      return *this;
   }

   //
   ConfirmationSender& ConfirmationSender::operator+=(Reservation& res) {
      Reservation** temp_reservationsObj;
      bool skip = false;

      if (!res.isEmpty()) {
         temp_reservationsObj = new Reservation * [m_numOfaddresses + 1];

         for (size_t i = 0; i < m_numOfaddresses; i++) {
            if (m_reservationsObj[i] == &res) {
               skip = true;
            }
            temp_reservationsObj[i] = m_reservationsObj[i];
         }

         if (!skip) {
            temp_reservationsObj[m_numOfaddresses++] = &res;
         }

         delete[] m_reservationsObj;
         m_reservationsObj = temp_reservationsObj;
      }

      return *this;
   }

   //
   ConfirmationSender& ConfirmationSender::operator-=(Reservation& res) {
      for (size_t i = 0; i < m_numOfaddresses; i++) {
         if (m_reservationsObj[i] == &res) {
            m_reservationsObj[i] = nullptr;
         }
      }
      return *this;
   }

   //
   std::ostream& operator<<(std::ostream & os, const ConfirmationSender ro) {
      if (!ro.m_reservationsObj || ro.m_numOfaddresses == 0) {
         os
            << "--------------------------\n"
            << "Confirmations to Send\n"
            << "--------------------------\n"
            << "The object is empty!\n"
            << "--------------------------\n";
      }
      else {

         os << "--------------------------\n"
            << "Confirmations to Send\n"
            << "--------------------------\n";

         for (size_t i = 0; i < ro.m_numOfaddresses; i++) {
            if (ro.m_reservationsObj[i]) {
               os << *ro.m_reservationsObj[i];
            }
         }   
         os << "--------------------------\n";
      }

      return os;
   }

}