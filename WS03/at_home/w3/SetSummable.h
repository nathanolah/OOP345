// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/01/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__
#include "Set.h"
namespace sdds {

   // Class template
   template <typename T, size_t N, typename K, typename V>
   class SetSummable : public Set<T, N> {
   public:

      // Accumulate all elements that have a key, and returns sum of the elements
      V accumulate(const K& key)const {
         T currentT;
         V sumOfElements;

         sumOfElements = currentT.getInitialValue();
         //((Set<T, N>&)* this) refers to the current object from 

         for (size_t i = 0; i < ((Set<T, N>&)* this).size(); i++) {
            if (key == ((Set<T, N>&)*this)[i].key()) 
               sumOfElements = ((Set<T, N>&) * this)[i].sum(key, sumOfElements);
         }

         return sumOfElements;
      }
   };
}
#endif // !SDDS_SETSUMMABLE_H__