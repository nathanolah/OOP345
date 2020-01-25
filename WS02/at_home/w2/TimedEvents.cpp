// Name: Nathan Olah 
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca 
// Date of completion: 2020-01-21
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <iomanip>
//#include <chrono>
#include "TimedEvents.h"
namespace sdds {

   // Definition of static class variable
   size_t TimedEvents::m_numOfRecords = 0u;

   // Default Constructor
   TimedEvents::TimedEvents() : m_startTime{}, m_endTime{} {}

   // Destructor
   TimedEvents::~TimedEvents() {}

   // Start clock 
   void TimedEvents::startClock() {
      m_startTime = std::chrono::steady_clock::now();
   }

   // Stop clock
   void TimedEvents::stopClock() {
      m_endTime = std::chrono::steady_clock::now();
   }

   // Updates next time record in the "m_records" array 
   void TimedEvents::recordEvent(const char* cString) {
      if (m_numOfRecords < MAXRECORDS) {
         this->m_records[m_numOfRecords].m_eventName = cString;
         this->m_records[m_numOfRecords].m_unitsOfTime = "nanoseconds";
         this->m_records[m_numOfRecords].m_duration =
            std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
         m_numOfRecords++;
      }
   }

   // Insertion operator overload
   std::ostream& operator<<(std::ostream& os, const TimedEvents& RO) {
      os << "--------------------------\n"
         << "Execution Times:\n"
         << "--------------------------\n";
      for (size_t i = 0; i < RO.m_numOfRecords; i++)
         os << std::setw(20) << std::left
         << RO.m_records[i].m_eventName << ' ' << std::setw(12) << std::right
         << RO.m_records[i].m_duration.count() << ' '
         << RO.m_records[i].m_unitsOfTime << '\n';
      os << "--------------------------\n";

      return os;
   }
}