// Name: Nathan Olah 
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020-01-21
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RECORDSET_H__
#define SDDS_RECORDSET_H__
#include <iostream>
#include <string>
namespace sdds {
   class RecordSet {
      static size_t m_numberOfStrings; // Class variable
      std::string* m_pStrings;
   public:
      RecordSet();
      RecordSet(const char* filename);
      RecordSet(const RecordSet& ro);
      ~RecordSet();
      RecordSet& operator=(const RecordSet& ro);
      size_t size()const;
      std::string getRecord(size_t index)const;
      void allocateAndCopy(const RecordSet& ro);
   };
}
#endif // !SDDS_RECORDSET_H__
