/*Name: Nathan Olah
Seneca Student ID: 124723198
Seneca email: nolah@myseneca.ca
Date of completion: 2020/03/28

I confirm that I am the only author of this file
  and the content was created entirely by me.*/
#ifndef SDDS_LINEMANAGER_H__
#define SDDS_LINEMANAGER_H__
#include <iostream>
#include <vector>
#include <deque>
#include <memory>
#include "Workstation.h"
#include "CustomerOrder.h"

class LineManager {
   std::vector<Workstation*> AssemblyLine;
   std::deque<CustomerOrder> ToBeFilled;
   std::deque<CustomerOrder> Complete;
   std::vector<Workstation*> orderedLine;
   unsigned int m_cntCustomerOrder;
   Workstation* emptyStation;
public:
   LineManager(const std::string& str, std::vector<Workstation*>& theStations,
      std::vector<CustomerOrder>& theOrders);
   ~LineManager();
   bool run(std::ostream& os);
   void displayCompletedOrders(std::ostream& os)const;
   void displayStations()const;
   void displayStationsSorted()const;
};
#endif // !SDDS_LINEMANAGER_H__
