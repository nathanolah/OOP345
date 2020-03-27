// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/03/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H__
#define SDDS_WORKSTATION_H__
#include <iostream>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"
class Workstation : public Station {
   std::deque<CustomerOrder> m_orders; // ORDERS THAT HAVENT BEEN FILLED
   //Station* m_pNextStation;
   Workstation* m_pNextStation;
public:
   Workstation();
   Workstation(const std::string& str);
   ~Workstation();
   void runProcess(std::ostream& os);
   bool moveOrder();
   void setNextStation(Station& station);
   const Workstation* getNextStation()const;
   bool getIfCompleted(CustomerOrder& order);
   void display(std::ostream& os);
   Workstation& operator+=(CustomerOrder&& ro);

   // Deleted move and copy functions
   Workstation(const Workstation&) = delete;
   Workstation& operator=(const Workstation&) = delete;
   Workstation(Workstation&&) = delete;
   Workstation& operator=(Workstation&&) = delete;
};

#endif // !SDDS_WORKSTATION_H__
