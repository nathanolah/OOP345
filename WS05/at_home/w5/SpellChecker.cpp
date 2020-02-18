// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
//#include <algorithm>
#include "SpellChecker.h"
namespace sdds {


   //
   SpellChecker::SpellChecker(const char* filename) {
      
      
      std::ifstream file(filename); 
      if (!file.is_open()) {
         throw "Bad file name!";
      }

      // Looking for a size of an array in a for loop
      // NOTE: sizeof( myArray ) will get the total number of bytes allocated for that array.
      // Find the number of elements in the array by dividing by the size of one element in the array: sizeof( myArray[0] )
      // for i less than mumber of element in m_badWords
      for (size_t i = 0; i < sizeof m_badWord / sizeof(m_badWord[0]); i++) {
         //Each line from the file is in the format BAD_WROD GOOD_WORD so load both
         //the two fields can be separated by any number of spaces.
         file >> m_badWord[i]; // load content of file
         file >> m_goodWord[i]; // load content of file
      } 
   }

   // Functor
   // Checks for the misspelled words and replaces with the correct words
   void SpellChecker::operator()(std::string& text)const {
      size_t word = 0;

      //if size of array is less than i = 0, i++
      for (size_t i = 0; i < sizeof(m_badWord) / sizeof(m_badWord[0]); i++) {

         word = text.find(m_badWord[i]); // word = any bad word

         if (word != std::string::npos) { // if parameter 'text' contains m_badWords at least once in the whole 
            do {
               text.replace(word, m_badWord[i].size(), m_goodWord[i]); //replace it
               word = text.find(m_badWord[i]); //then keep looking


            } while (word != std::string::npos);
         }
      }

   }
}