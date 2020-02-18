// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/13
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Book.h"
#include <iostream>
#include <string> // for stoi() and stod()
#include <iomanip>
namespace sdds {

   //
   Book::Book(){}

   //
   Book::Book(const std::string& strBook) {
      std::string::size_type sz(0u);
      std::string str = strBook;
      const std::string delimiter{ "," };
      size_t beg = 0;
      size_t pos = 0;
      size_t i = 0;
      std::string info{};

      while ((beg = str.find_first_not_of(delimiter, pos)) != std::string::npos) {
         pos = str.find_first_of(delimiter, beg + 1);
         info = str.substr(beg, pos - beg);
         i++;
       
         if (i == 1) {
            info = trim(info);
            m_author = info;
         }
         else if (i == 2) {
            info = trim(info);
            m_title = info;
         }
         else if (i == 3) {
            info = trim(info);
            m_countryOfPub = info; 
         }
         else if (i == 4) {
            if (isDouble(info))
               m_price = std::stod(info, &sz); // Converts string into double
         }
         else if (i == 5) {
            if (isUnsigned(info))
               m_yearOfPub = std::stoi(info); // Converts string into integer
         }
         else if (i >= 6) {
            std::string temp{};
            std::string lastChar{};
            info = trim(info);
            temp = info.back(); // Get the last character in the string
            lastChar = (temp != ".") ? ", " : "";
            m_description += info + lastChar;
         }
      }
   }

   std::string Book::trim(std::string str) { 
      std::size_t pos = 0;
      // Remove trailing white space
      while (!str.empty() && std::isspace(str.back())) str.pop_back();

      // Return after leading white space  
      while (pos < str.size() && std::isspace(str[pos])) ++pos;

      return str.substr(pos);
     
   }

   // Checks if string matches a unsigned type
   bool Book::isUnsigned(const std::string s) {
      bool ok = true;
      try {
         std::stoi(s);
      }
      catch (...) {
         ok = false;
      }
      return ok;
   }

   // Checks if string matches a double type
   bool Book::isDouble(const std::string s) {
      bool ok = true;
      try {
         std::stod(s);
      }
      catch (...) {
         ok = false;
      }
      return ok;
   }

   const std::string& Book::title()const {
      return m_title;
   }

   const std::string& Book::country()const {
      return m_countryOfPub;
   }

   const size_t& Book::year()const {
      return m_yearOfPub;
   }

   double& Book::price() {
      return m_price;
   }

   void Book::display(std::ostream& os)const {
      os << std::setw(20) << m_author << " | "
         << std::setw(22) << m_title << " | "
         << std::setw(5) << m_countryOfPub << " | "
         << std::setw(4) << m_yearOfPub << " | "
         << std::setw(6) << std::fixed << std::setprecision(2) << m_price << " | "
         << m_description << std::endl;
   }

   //
   std::ostream& operator<<(std::ostream& os, const Book& ro) {
      ro.display(os);
      return os;
   }

}