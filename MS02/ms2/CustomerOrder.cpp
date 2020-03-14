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
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"
using namespace std;

size_t CustomerOrder::m_widthField(0u);

CustomerOrder::CustomerOrder() : m_cntItem(0u) {}

CustomerOrder::~CustomerOrder() {
   delete[] m_lstItem; // check over
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


   m_cntItem = std::count(str.begin(), str.end(), newStr.getDelimiter()) - 1;
   // Allocate for number of items
   m_lstItem = new Item[m_cntItem]; 

   // Check for items
   if (m_cntItem >= 1) {
      // Copy tokens into m_lstItem
      for (size_t i = 0; i < m_cntItem; i++) {
         string tempStr = newStr.extractToken(str, next_pos, more); // gets stuck in the forloop
         Item newItem(tempStr);

         // m_lstItem needs to be intialized
         m_lstItem[i] = newItem; // TO DO : TRY USING A VECTOR


        // m_lstItem[i].m_itemName = newStr.extractToken(str, next_pos, more);
      }
   }
   else {
      throw "No items found";
   }
}

void CustomerOrder::display(std::ostream& os)const {
   os << std::setw(m_widthField) << m_name << " - " << m_product << endl;

   // FIX THIS
   for (size_t i = 0; i < m_cntItem; i++) {
      os << setw(6) << "[" << m_lstItem->m_serialNumber << "] " << m_lstItem->m_itemName << " - "
         << ((!isOrderFilled()) ? "MISSING" : "FILLED") << endl;
   }
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
   // TO DO : FINISH THIS FUNCTION
}


bool CustomerOrder::isItemFilled(const std::string& itemName)const {
   for (size_t i = 0; i < m_cntItem; i++) {
      if (m_lstItem[i].m_itemName == itemName) {
         if (!isOrderFilled())
            return false;
      }
   }
   return true;
}

bool CustomerOrder::isOrderFilled()const {
   bool filled = true;
   for (size_t i = 0; i < m_cntItem; i++) {
      if (!m_lstItem[i].m_isFilled) {
         filled = false;
      }
   }
   return filled;
   
}

CustomerOrder::CustomerOrder(const CustomerOrder& ro) {
   throw ""; // CHANGE THIS 
}


CustomerOrder::CustomerOrder(CustomerOrder&& ro)noexcept {
   *this = std::move(ro);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& ro)noexcept {
   if (this != &ro) {
      m_name = ro.m_name;
      m_product = ro.m_product;
      m_cntItem = ro.m_cntItem;
      m_lstItem = ro.m_lstItem;

      ro.m_lstItem = nullptr;
   }
   return *this;
}