// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/01/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__
#include <iostream>
namespace sdds {
   template <typename K, typename V >
   class Pair {
      K m_key;
      V m_value;
   public:
      // Default constructor
      Pair() : m_key{}, m_value{} {}

      // 2 Argument constructor
      Pair(const K& key, const V& value) : m_key{ key }, m_value{ value } {} 

      const K& key()const { return m_key; }
      const V& value()const { return m_value; }

      void display(std::ostream& os)const {
         os << m_key << " : " << m_value << std::endl;
      }
   };

   // Helper function 
   template <typename K, typename V>
   std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
      pair.display(os);
      return os;
   }
}
#endif // !SDDS_PAIR_H__
