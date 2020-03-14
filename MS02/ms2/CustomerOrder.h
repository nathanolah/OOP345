// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/03/10
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTOMERORDER_H__
#define SDDS_CUSTOMERORDER_H__
#include <iostream>
#include "Station.h"
struct Item {
   std::string m_itemName;
   unsigned int m_serialNumber = 0;
   bool m_isFilled = false;

   Item(const std::string& src) : m_itemName(src) {};

   Item() {};
   Item(const Item& ro) {
      m_itemName = ro.m_itemName;
      m_serialNumber = ro.m_serialNumber;
      m_isFilled = ro.m_isFilled;
   }

};

class CustomerOrder {
   std::string m_name;
   std::string m_product;
   unsigned int m_cntItem;
   Item* m_lstItem; // or ** ???? try using a vector
   static size_t m_widthField;
public:
   CustomerOrder();
   ~CustomerOrder();
   CustomerOrder(std::string& str);

   CustomerOrder(const CustomerOrder& ro);
   CustomerOrder& operator=(const CustomerOrder& ro) = delete;

   CustomerOrder(CustomerOrder&& ro)noexcept;
   CustomerOrder& operator=(CustomerOrder&& ro)noexcept;

   bool isOrderFilled()const;
   bool isItemFilled(const std::string& itemName)const;
   void fillItem(Station& station, std::ostream& os);
   void display(std::ostream& os)const;

};


#endif // !SDDS_CUSTOMERORDER_H__
