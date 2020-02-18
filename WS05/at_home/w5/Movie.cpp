// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion:
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
      std::string copy = strMovie;
      trim(copy); 
      size_t position;

      position = copy.find(',');
      m_title = copy.substr(0, position);
      trim(m_title);
      copy.erase(0, position + 1);

      position = copy.find(',');
      m_yearOfRelease = std::stoi(copy.substr(0, position));
      copy.erase(0, position + 1);

      m_description = copy.substr(0);
      trim(m_description);

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