// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/18
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h" // for trim()
#include "Movie.h"
namespace sdds {

   //
   Movie::Movie() : m_title{}, m_description{}, m_yearOfRelease(0u) {}

   //
   Movie::Movie(const std::string& strMovie) {
      std::string tempStr = strMovie;
      trim(tempStr); 
      
      m_title = getString(tempStr);
      trim(m_title);

      m_yearOfRelease = std::stoi(getString(tempStr));

      m_description = tempStr.substr(0);
      trim(m_description);


     /* pos = tempStr.find(',');
      m_title = tempStr.substr(0, pos);
      trim(m_title);
      tempStr.erase(0, pos + 1);

      pos = tempStr.find(',');
      m_yearOfRelease = std::stoi(tempStr.substr(0, pos));
      tempStr.erase(0, pos + 1);

      m_description = tempStr.substr(0);
      trim(m_description);*/

   }

   //
   std::string Movie::getString(std::string& tempStr) {
      std::size_t pos;
      std::string str;

      pos = tempStr.find(',');
      str = tempStr.substr(0, pos); // extract the string     
      tempStr.erase(0, pos + 1);

      return str;
   }


   // Removes whitespace around the string
   void Movie::trim(std::string& str) {
      size_t i = 0;
      // Remove leading whitespace
      for (i = 0; i < str.length() && str[i] == ' '; i++); // gets index of whitespace
      str = str.substr(i);

      // Remove trailing whitespace
      for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
      str = str.substr(0, i);
   }

   const std::string& Movie::title()const {
      return m_title;
   }

   //
   std::ostream& operator<<(std::ostream& os, const Movie& ro) {
      os << std::setw(40) << ro.m_title << " | " 
         << std::setw(4) << ro.m_yearOfRelease << " | "
         << ro.m_description << std::endl;

      return os;
   }
}