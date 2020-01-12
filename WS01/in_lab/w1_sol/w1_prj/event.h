// Name: Nathan Olah 
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/01/12
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_EVENT_H__ // Header file safeguard
#define SDDS_EVENT_H__
extern unsigned g_sysClock; // External linkage declaration 
namespace sdds {
   class Event {
      char m_desc[129]; // 128 characters plus and null terminator
      unsigned m_timeOfEvent;
      unsigned m_hours;
      unsigned m_minutes;
   public :
      Event();
      Event(const Event& RO);
      Event& operator=(const Event& RO);
      void display()const;
      void setDescription(const char* cString);
      void setTime();
      void setEmpty();
   };
}
#endif