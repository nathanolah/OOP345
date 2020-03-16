// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/03/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include "Utilities.h"
using namespace std;

char Utilities::m_delimiter = ' ';
Utilities::Utilities() : m_widthField(1u) {}

void Utilities::setFieldWidth(size_t newWidth) {
   m_widthField = newWidth;
}

size_t Utilities::getFieldWidth()const {
   return m_widthField;
}

void Utilities::setDelimiter(char newDelimiter) {
   m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
   return m_delimiter;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
   //size_t pos;
   string token;
   
  
   if (next_pos == 0) {
      next_pos = str.find(getDelimiter());
      token = str.substr(0, next_pos);
   }
   else {

      size_t next_delimiter_pos = str.find(m_delimiter, next_pos + 1);	// find the next delimiter from 1 character after the previous one

      size_t word_length = (next_delimiter_pos - next_pos) - 1;

      token = str.substr(next_pos + 1, word_length);			// extract the string that starts from next_pos with the length of the next word
      next_pos = next_delimiter_pos;

   }

   //pos = str.find(getDelimiter(), next_pos);
   //for (size_t i = next_pos; i < pos; i++) { count++; }

   //token = str.substr(next_pos, count);
   //next_pos = pos + 1; // Set the next position

   try {

      if (token.empty()) {
         more = false;
         throw "Error: No token found";
      }
      else {
         more = true;
         if (token.size() > getFieldWidth()) {
            setFieldWidth(token.size());
         }
      }
   }
   catch (const char* ErrorMessage) {
      cout << ErrorMessage << endl;
   }

   return token;
}
