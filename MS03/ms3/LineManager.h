#ifndef SDDS_LINEMANAGER_H__
#define SDDS_LINEMANAGER_H__
#include <iostream>
#include <vector>
#include <deque>
#include "Workstation.h"
#include "CustomerOrder.h"
class LineManager {
   // A container containing all the references of the Workstation objects on the assembly line
   std::vector<Workstation*> AssemblyLine;
   std::deque<CustomerOrder> ToBeFilled;
   std::deque<CustomerOrder> Complete;
   unsigned int m_cntCustomerOrder;
public:
   LineManager(const std::string& str, std::vector<Workstation*>& theStations,
      std::vector<CustomerOrder>& theOrders);
   bool run(std::ostream& os);
   void displayCompletedOrders(std::ostream& os)const;
   void displayStations()const;
   void displayStationsSorted()const;
};
#endif // !SDDS_LINEMANAGER_H__
