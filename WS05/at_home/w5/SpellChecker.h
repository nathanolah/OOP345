// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SPELLCHECKER_H__
#define SDDS_SPELLCHECKER_H__
#include <iostream>
namespace sdds {
   class SpellChecker {
      std::string m_badWord[5];
      std::string m_goodWord[5];
   public:
      SpellChecker(const char* filename);
      void operator()(std::string& text)const;

   };
} 
#endif // !SDDS_SPELLCHECKER_H__
