// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/03
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>   
#include <algorithm>
#include <iomanip>
#include "Reservation.h"
namespace sdds {
  
   // Default constructor
   Reservation::Reservation() 
      : m_reservationId{}, m_name{}, m_email{}, m_numberOfPeople(0u), m_day(0u), m_hour(0u) {}

   //
   Reservation::Reservation(const std::string& res) {
      //if (res) {}
      std::string str = res;
      std::string const delimiter{ ":," };
      size_t beg, pos = 0;
      size_t i = 0;
      std::string info{};

      // Remove all whitespace in the string
      str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());

      while ((beg = str.find_first_not_of(delimiter, pos)) != std::string::npos) {
         pos = str.find_first_of(delimiter, beg + 1);

         //std::cout << str.substr(beg, pos - beg) << std::endl;
         info = str.substr(beg, pos - beg);
         i++;

         if (i == 1) {
            m_reservationId = info;
         }
         else if (i == 2) {
            m_name = info;
         }
         else if (i == 3) {
            m_email = info;
         }
         else if (i == 4) {
            m_numberOfPeople = std::stoi(info); // Converts string into integer
         }
         else if (i == 5) {
            m_day = std::stoi(info);
         }
         else if (i == 6) {
            m_hour = std::stoi(info);
         }
      }
   }

   //
   void Reservation::display(const char* cString) {
      //std::string tempEmail = m_email;
      std::string right = "<", str;
      std::string left = ">";
      //std::string str;
      str.append(right); // Concatenate the email into a complete string
      str.append(m_email);
      str.append(left);
      
      std::cout << "Reservation " << m_reservationId << ":"
         << std::setw(11) << std::right
         << m_name
         << "  "
         << std::left 
         << std::setw(24) << std::left
         << str 
         << cString << m_day << " @ " << m_hour
         << ":00 for " << m_numberOfPeople << " people.";
   }

   //
   std::ostream& operator<<(std::ostream& os, Reservation& res) {
      if (res.m_hour >= 6 && res.m_hour <= 9) {
         res.display("Breakfast on day ");  
      }
      else if (res.m_hour >= 11 && res.m_hour <= 15) {
         res.display("Lunch on day ");
      }
      else if (res.m_hour >= 17 && res.m_hour <= 21) {
         res.display("Dinner on day ");
      }
      else {
         res.display("Drinks on day ");
      }
      os << std::endl;
      return os;
   }
}