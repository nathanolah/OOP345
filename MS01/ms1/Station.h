// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/03/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H__
#define SDDS_STATION_H__
#include <iostream>
class Station {
   size_t m_id;
   std::string m_nameOfItem;
   std::string m_description;
   size_t m_serialNumber;
   size_t m_numberOfItems;
   static size_t m_widthField; 
   static size_t m_idGenerator; 
public:
   Station();
   Station(const std::string& str);
   const std::string& getItemName()const;
   unsigned int getNextSerialNumber();
   unsigned int getQuantity()const;
   void updateQuantity();
   void display(std::ostream& os, bool full)const;
};

#endif // !SDDS_STATION_H__
