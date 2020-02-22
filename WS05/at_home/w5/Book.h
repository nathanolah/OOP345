// Name: Nathan Olah    
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca 
// Date of completion: 2020/02/13
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
namespace sdds {
   class Book {
      std::string m_author;
      std::string m_title;
      std::string m_countryOfPub;
      size_t m_yearOfPub;
      double m_price;
      std::string m_description;
   public:
      Book();
      Book(const std::string& strBook);
      const std::string& title()const;
      const std::string& country()const;
      const size_t& year()const;
      const std::string& description()const;
      double& price();
      void display(std::ostream& os)const;
      std::string getString(std::string& str);
      friend std::ostream& operator<<(std::ostream& os, const Book& ro);
      void trim(std::string& str);
      template <typename T>
      void fixSpelling(T spellChecker) {
         spellChecker(m_description); // functor
      }

   };
}
#endif // !SDDS_BOOK_H__