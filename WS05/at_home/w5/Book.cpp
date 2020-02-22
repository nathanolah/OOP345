// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/13
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <algorithm>
#include <string> // for stoi() and stod()
#include <iomanip>
#include "Book.h"
namespace sdds {

   //
   Book::Book(): m_yearOfPub(0u), m_price(0) {}

   //
   Book::Book(const std::string& strBook) {
      std::string tempStr = strBook;
      trim(tempStr);

      m_author = getString(tempStr);
      trim(m_author);

      m_title = getString(tempStr);
      trim(m_title);

      m_countryOfPub = getString(tempStr);
      trim(m_countryOfPub);

      m_price = std::stod(getString(tempStr));
      m_yearOfPub = std::stoi(getString(tempStr));

      m_description = tempStr.substr(0); // I want to keep the commas inside the description 
      trim(m_description);
     
      //
      //pos = tempStr.find(','); // Returns index up to comma position
      //m_author = tempStr.substr(0, pos); // Extract up to the position
      //trim(m_author); // Remove whitespace
      //tempStr.erase(0, pos + 1); // Erase up to comma 

      //pos = tempStr.find(',');
      //m_title = tempStr.substr(0, pos);
      //trim(m_title);
      //tempStr.erase(0, pos + 1);

      //pos = tempStr.find(',');
      //m_countryOfPub = tempStr.substr(0, pos);
      //trim(m_countryOfPub);
      //tempStr.erase(0, pos + 1);

      //pos = tempStr.find(',');
      //m_price = std::stod(tempStr.substr(0, pos)); // returns floating point value
      //tempStr.erase(0, pos + 1);

      //pos = tempStr.find(',');
      //m_yearOfPub = std::stoi(tempStr.substr(0, pos)); // returns integer value
      //tempStr.erase(0, pos + 1);

      //m_description = tempStr.substr(0);
      //trim(m_description);
   }

   //
   std::string Book::getString(std::string& tempStr) {
      std::size_t pos;
      std::string str;

      pos = tempStr.find(',');
      str = tempStr.substr(0, pos); // extract the string     
      tempStr.erase(0, pos + 1);

      return str;
   }

   // Removes whitespace around the string
   void Book::trim(std::string& str) {
      size_t i = 0;
      // Remove leading whitespace
      for (i = 0; i < str.length() && str[i] == ' '; i++); // gets index of whitespace
      str = str.substr(i);

      // Remove trailing whitespace
      for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
      str = str.substr(0, i);
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

   const std::string& Book::description()const {
      return m_description;
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