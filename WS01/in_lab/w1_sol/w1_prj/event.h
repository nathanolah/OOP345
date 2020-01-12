// Name:
// Seneca Student ID:
// Seneca email:
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__
extern unsigned g_sysClock;
namespace sdds {
   class Event {
      char m_desc[129]; // 128 characters plus and null terminator
      unsigned long m_timeOfEvent;
   public :
      Event() : m_desc(""), m_timeOfEvent{0} {}
      void display();
      void setDescription(const char* cString);
      void setEmpty();
   };
}
#endif 
