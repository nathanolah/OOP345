// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/18
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_MOVIE_H__
#define SDDS_MOVIE_H__
#include <iostream>
namespace sdds {
   class Movie {
      std::string m_title;
      std::string m_description;
      size_t m_yearOfRelease;
   public: 
      Movie();
      Movie(const std::string& strMovie);
      const std::string& title()const;
      friend std::ostream& operator<<(std::ostream& os, const Movie& ro);
      void trim(std::string& str);
      std::string getString(std::string& str);
      template <typename T>
      void fixSpelling(T spellChecker) {
         spellChecker(m_title);
         spellChecker(m_description); 
      }

   };
}
#endif // !SDDS_MOVIE_H__
