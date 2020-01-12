// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/01/12
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>             
#include <iomanip>
#include <cstring>
#include "event.h"

unsigned g_sysClock = 0u; // Definition of external variable 
namespace sdds {

   // Default constructor
   Event::Event() : m_timeOfEvent{ 0u }, m_hours{ 0u }, m_minutes{ 0u } { 
      *m_desc = 0;
   }

   // Copy constructor
   Event::Event(const Event& RO) {
      strcpy(m_desc, RO.m_desc);
      m_timeOfEvent = RO.m_timeOfEvent;
      m_minutes = RO.m_minutes;
      m_hours = RO.m_hours;
   }

   // Copy assignment operator
   Event& Event::operator=(const Event& RO) {
      if (this != &RO) {
         strcpy(m_desc, RO.m_desc);
         m_timeOfEvent = RO.m_timeOfEvent;
         m_minutes = RO.m_minutes;
         m_hours = RO.m_hours;            
      }
      return *this;
   }

   // Displays the current event's time and description
   void Event::display()const {
      static unsigned counter{ 0u }; // Static counter to keep track of iterations 

      counter++;
      if (!m_desc || strcmp(m_desc, "") == 0) {
         // Displays counter with no description available
         std::cout 
            << std::setw(3) << std::setfill(' ')
            << counter << ". " << "[ No Event ]" << std::endl;
      }
      else {
         // Displays counter
         std::cout << std::setw(3) << std::setfill(' ') << counter << ". ";
         // Displays time and description 
         std::cout 
            << std::setw(2) << std::setfill('0') << m_hours << ":" 
            << std::setw(2) << std::setfill('0') << (m_minutes % 60u) << ":"
            << std::setw(2) << std::setfill('0') << (m_timeOfEvent % 60u) 
            << " -> " << m_desc << std::endl;
      }
   }

   // Set description if parameter "cString" is available
   void Event::setDescription(const char* cString) {
      if (cString) {
         strcpy(m_desc, cString);
         setTime(); // Sets time of the description 
      }
      else {
         setEmpty();
      }
   }

   // Sets time for seconds, minutes, and hours
   void Event::setTime() {
      m_timeOfEvent = g_sysClock;
      m_minutes = m_timeOfEvent / 60u;
      m_hours = m_minutes / 60u;
   }

   // Set attributes to an empty state
   void Event::setEmpty() {
      *m_desc = 0;
      m_timeOfEvent = 0u;
      m_hours = 0u;
      m_minutes = 0u;
   }
}