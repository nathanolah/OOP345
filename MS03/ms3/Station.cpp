// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/03/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"
using namespace std;

size_t Station::m_widthField = 0u;
size_t Station::m_idGenerator = 0u;

Station::Station() : m_id(0u), m_serialNumber(0u), m_numberOfItems(0u) {
   m_nameOfItem.clear();
   m_description.clear();
}

Station::Station(const std::string& str) {
   m_nameOfItem.clear();
   m_description.clear();
   Utilities newStr;
   size_t next_pos = 0;
   bool more = false;

   if (!str.empty())
      more = true;

      m_nameOfItem = newStr.extractToken(str, next_pos, more);
      m_serialNumber = std::stoi(newStr.extractToken(str, next_pos, more));
      m_numberOfItems = std::stoi(newStr.extractToken(str, next_pos, more));
      m_description = str.substr(next_pos + 1);
      m_id = ++m_idGenerator;


   if (m_widthField < newStr.getFieldWidth())
      m_widthField = newStr.getFieldWidth();
}

const std::string& Station::getItemName()const {
   return m_nameOfItem;
}

unsigned int Station::getNextSerialNumber() {
   unsigned serialNumber = m_serialNumber;
   m_serialNumber++;
   return serialNumber;
}

unsigned int Station::getQuantity()const {
   return m_numberOfItems;
}

void Station::updateQuantity() {
   m_numberOfItems--;
   if (m_numberOfItems < 0) {
      m_numberOfItems = 0;
   }
}

void Station::display(std::ostream& os, bool full)const {
   if (!full) {
      os << "[" << right << setfill('0') << setw(3) << m_id << "] " << setfill(' ')
         << "Item: " << left << setw(m_widthField) << m_nameOfItem
         << " [" << right << setw(6) << setfill('0') << m_serialNumber << "]";
   }
   else if (full) {
      os << "[" << right << setfill('0') << setw(3) << m_id << "] " << setfill(' ')
         << "Item: " << left << setw(m_widthField) << m_nameOfItem
         << " [" << right << setw(6) << setfill('0') << m_serialNumber << "] " << setfill(' ')
         << "Quantity: " << left << setw(m_widthField) << m_numberOfItems
         << " Description: " << m_description;
   }
   os << endl;
}

