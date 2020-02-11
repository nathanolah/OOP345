// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca  
// Date of completion: 2020/02/10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <utility>
#include "Restaurant.h"
namespace sdds {

   // 
   Restaurant::Restaurant() : m_reservations(nullptr), m_numOfReservations(0u) {}

   //
   Restaurant::Restaurant(Reservation* reservation[], size_t cnt) {
      m_numOfReservations = cnt;
      m_reservations = new Reservation[m_numOfReservations];
      
      for (size_t i = 0; i < m_numOfReservations; i++) {
         this->m_reservations[i] = *reservation[i];
      }
   }

   // Copy Constructor
   Restaurant::Restaurant(const Restaurant& ro) {
      *this = ro;
   }

   //
   Restaurant& Restaurant::operator=(const Restaurant& ro) {
      if (this != &ro) {
         m_numOfReservations = ro.m_numOfReservations;
         m_reservations = new Reservation[m_numOfReservations];

         for (size_t i = 0; i < m_numOfReservations; i++) {
            this->m_reservations[i] = ro.m_reservations[i];
         }
      }
      return *this;
   }

   // Move Constructor
   Restaurant::Restaurant(Restaurant&& ro) {
      *this = std::move(ro);
   }

   // Move assignment operator
   Restaurant& Restaurant::operator=(Restaurant&& ro) {
      if (this != &ro) {
         m_numOfReservations = ro.m_numOfReservations;
         m_reservations = ro.m_reservations;
         ro.m_numOfReservations = 0u;
         ro.m_reservations = nullptr;
      }
      return *this;
   }

   //
   Restaurant::~Restaurant() {
      delete[] m_reservations;
   }

   //
   size_t Restaurant::size()const {
      return m_numOfReservations;
   }

   //
   void Restaurant::display(std::ostream& os)const {
      for (size_t i = 0; i < this->size(); i++)
         os << this->m_reservations[i];
   }

   // 
   std::ostream& operator<<(std::ostream& os, const Restaurant ro) {
      if (!ro.m_reservations || ro.size() == 0) {
         os
            << "--------------------------\n"
            << "Fancy Restaurant\n"
            << "--------------------------\n"
            << "The object is empty!\n"
            << "--------------------------\n";
      }
      else {

         os << "--------------------------\n"
            << "Fancy Restaurant\n"
            << "--------------------------\n";

         ro.display(os);
   
         os << "--------------------------\n";
      }

      return os;
   }

}