// Name: Nathan Olah 
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020-01-21
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TIMEDEVENTS_H__
#define SDDS_TIMEDEVENTS_H__
#include <iostream>
#include <chrono>
namespace sdds {

   const size_t MAXRECORDS = 7u;

   class TimedEvents {
      static size_t m_numOfRecords; // Class variable
      std::chrono::steady_clock::time_point m_startTime;
      std::chrono::steady_clock::time_point m_endTime;
      struct {
         const char* m_eventName;
         const char* m_unitsOfTime;
         std::chrono::steady_clock::duration m_duration;
         
      } m_records[MAXRECORDS];
   public:
      TimedEvents();
      ~TimedEvents();
      void startClock();
      void stopClock();
      void recordEvent(const char* cString);
      friend std::ostream& operator<<(std::ostream& os, const TimedEvents& RO);
   };
}
#endif // !SDDS_TIMEDEVENTS_H__
