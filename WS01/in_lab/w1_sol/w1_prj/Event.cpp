// Name:
// Seneca Student ID:
// Seneca email:
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"
namespace sdds {

   //
   void Event::display() {
      static unsigned counter{ 0 };
      unsigned hours{ 0 };
      unsigned minutes{ 0 };
      unsigned seconds{ 0 };

      counter++;

      // Obtain hours, minutes, and seconds 
      minutes = m_timeOfEvent / 60; // TO DO : need to obtain time from txt file 
      hours = minutes / 60;

      if (m_desc) {
         std::setw(3);
         std::cout << counter << ". ";
         std::setw(2); 
         std::setfill('0');
         std::cout << hours << ":" << minutes << ":" << seconds
            << " -> " << m_desc << std::endl;
      }
      else {
         std::cout << counter << ". " << "[ No Event ]" << std::endl;
      }
   }

   //
   void Event::setDescription(const char* cString) {
      if (cString) {
         strcpy(m_desc, cString);
      }
      else {
         setEmpty();
      }
   }

   //
   void Event::setEmpty() {
      *m_desc = 0; // check over
      m_timeOfEvent = 0;
   }
}