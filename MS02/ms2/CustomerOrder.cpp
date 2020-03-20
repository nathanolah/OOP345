// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/03/10
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <memory>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"
using namespace std;

size_t CustomerOrder::m_widthField(0u);
CustomerOrder::CustomerOrder() : m_cntItem(0u), m_lstItem(nullptr) {}

CustomerOrder::~CustomerOrder() {
   delete[] m_lstItem;
}

CustomerOrder::CustomerOrder(std::string& str) {
   Utilities newStr;
   size_t next_pos = 0;
   bool more = false;

   if (!str.empty())
      more = true;

   // extract the tokens and populate the current instance
   m_name = newStr.extractToken(str, next_pos, more);
   m_product = newStr.extractToken(str, next_pos, more);

   if (m_widthField < newStr.getFieldWidth())
      m_widthField = newStr.getFieldWidth();

   // Count the amount of items
   m_cntItem = std::count(str.begin(), str.end(), newStr.getDelimiter()) - 1;
  
   // Check for items
   if (m_cntItem >= 1) {

      // Allocate a for number of items using a unique_ptr
      m_lstItem = new std::unique_ptr<Item>[m_cntItem];
  
      // Copy tokens into m_lstItem
      for (size_t i = 0; i < m_cntItem; i++) {
         string tempStr = newStr.extractToken(str, next_pos, more);
         //Item newItem(tempStr);

         m_lstItem[i] = std::unique_ptr<Item>(new Item(tempStr));
      }
   }
   else {
      delete[] m_lstItem;
      m_lstItem = nullptr;
      throw "No items found";
   }
}

void CustomerOrder::display(std::ostream& os)const {
   os << m_name << " - " << m_product << endl;

   for (size_t i = 0; i < m_cntItem; i++) {
      os << "[" << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] "
         << setw(m_widthField) << left << setfill(' ') << m_lstItem[i]->m_itemName 
         << right << " - "  << ((!isOrderFilled()) ? "MISSING" : "FILLED") << endl;
   }
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
   
   for (size_t i = 0; i < m_cntItem; i++) {
      if (m_lstItem[i]->m_itemName == station.getItemName()) {
         if (station.getQuantity() == 0) {
            os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]"  << " is empty " << endl;
         }
         else {
               station.updateQuantity();
               m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
               m_lstItem[i]->m_isFilled = true;
               os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
         }
      }
   }

}

bool CustomerOrder::isItemFilled(const std::string& itemName)const {
   for (size_t i = 0; i < m_cntItem; i++) {
      if (m_lstItem[i]->m_itemName == itemName) {
         if (!m_lstItem[i]->m_isFilled)
            return false;
      }
   }
   return true;
}

bool CustomerOrder::isOrderFilled()const {
   bool filled = true;
   for (size_t i = 0; i < m_cntItem; i++) {
      if (!m_lstItem[i]->m_isFilled) {
        filled = false;
      }
   }
   return filled;
}

CustomerOrder::CustomerOrder(const CustomerOrder& ro) {
   throw "";
}

CustomerOrder::CustomerOrder(CustomerOrder&& ro)noexcept { 
   m_name = "";
   m_product = "";
   m_cntItem = 0;
   m_lstItem = new std::unique_ptr<Item>[m_cntItem];
   *this = std::move(ro);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& ro)noexcept {
   if (this != &ro) {
      delete[] m_lstItem;
      m_lstItem = nullptr;
      m_name = ro.m_name;
      m_product = ro.m_product;
      m_cntItem = ro.m_cntItem;
      m_lstItem = ro.m_lstItem;
      ro.m_lstItem = nullptr;
   }
   return *this;
}