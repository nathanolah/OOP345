// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/01/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SET_H__
#define SDDS_SET_H__
namespace sdds {

   // Class template
   template <class T, size_t N>
   class Set {
      T m_array[N];
      size_t m_elements{ 0u };
   public:
      // Returns current number of elements in the array
      size_t size()const { return m_elements; };

      // Returns element at the specified index 
      const T& operator[](size_t idx)const { return m_array[idx]; }

      // Checks for the capacity of elements and copys new item into "m_elements"
      void operator+=(const T& item) {
         if (m_elements < N) {
            m_array[m_elements] = item;
            m_elements++;
         }
      }
   };
}
#endif // !SDDS_SET_H__
