// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/01/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__
#include <iostream>
#include "Pair.h"
namespace sdds {
   
   // Class template 
   template <class K, class V>
   class PairSummable : public Pair<K, V> {
      static V m_initialValue;
      static size_t m_minFieldWidth;
   public:

      // Default constuctor 
      PairSummable() {}

      // 2 Argument constructor
      PairSummable(const K& key, const V& val) : Pair<K, V>(key, val) {
         if (m_minFieldWidth < key.size()) {  
            m_minFieldWidth = key.size() + 1;
         }
      }

      // Class function 
      static const V& getInitialValue() {
         return m_initialValue;
      }

      V sum(const K& key, const V& val)const {
         V result;

         // If the key of pair is stored in the current instance 
         if (Pair<K, V>::key() == key) {
            result = Pair<K, V>::value() + val;
         }
         else {
            result = val;
         }
         return result;
      }

      void display(std::ostream& os)const {
         os.setf(std::ios::left); 
         os.width(m_minFieldWidth);
         os << Pair<K, V>::key() << ": " << Pair<K, V>::value() << std::endl;
         os.unsetf(std::ios::left);
      }
   };

   // Template class variable definition 
   template <class K, class V>
   size_t PairSummable<K, V>::m_minFieldWidth(0u);

   // Template specialization 
   template<> // Denotes specialization
   int PairSummable<std::string, int>::m_initialValue(0u);

   template<>
   std::string PairSummable<std::string, std::string>::m_initialValue("");

   template<> 
   std::string PairSummable<std::string, std::string>
      ::sum(const std::string& key, const std::string& val)const {
      std::string line{};

      if (val == "") {
         line = val + "" + Pair<std::string, std::string>::value();
      }
      else {
         line = val + ", " + Pair<std::string, std::string>::value();
      }

      return line;
   }

}
#endif // !SDDS_PAIRSUMMABLE_H__
