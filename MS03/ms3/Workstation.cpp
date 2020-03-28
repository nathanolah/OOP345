 /*Name: Nathan Olah
 Seneca Student ID: 124723198
 Seneca email: nolah@myseneca.ca
 Date of completion: 2020/03/09

 I confirm that I am the only author of this file
   and the content was created entirely by me.*/

#include <iostream>
#include <memory>
#include <deque>
#include "Workstation.h"
#include "Station.h"
#include "CustomerOrder.h" 
#include "Utilities.h"
using namespace std;

Workstation::~Workstation() {}

Workstation::Workstation() : Station() {
   m_pNextStation = nullptr;
}

Workstation::Workstation(const std::string& str) : Station(str) {
   m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os) {
   // runs a single cycle of the assembly line for the current station.

   // IF THERE ARE CUSTOMERORDERS IN QUEUE 
   // FILL THE ORDER IN THE FRONT AT CURRENT WORKSTATION


   if (!m_orders.empty()) {
      if (!m_orders.front().isItemFilled(this->getItemName()))
         m_orders.front().fillItem(*this, os);
   }
   
}

bool Workstation::moveOrder() {
   bool ok = false;
   if (m_orders.size() == 0)
      ok = false;
   else {
      if (m_orders.front().isItemFilled(getItemName()))
         if (m_pNextStation) {
            *m_pNextStation += move(m_orders.front());
            m_orders.pop_front();
            ok = true;
         }
   }
   return ok;

}

void Workstation::setNextStation(Station& station) {
   m_pNextStation = (Workstation*)&station; 
}

const Workstation* Workstation::getNextStation()const {
   return m_pNextStation;
} 

bool Workstation::getIfCompleted(CustomerOrder& order) {
   bool ok = false;


   if (m_orders.size() == 0) {
      ok = false;
   }
   else {
      if (m_orders.front().isOrderFilled()) {
         order = std::move(m_orders.front());
         m_orders.pop_front();
         ok = true;
      }
   }

   return ok;
}

void Workstation::display(std::ostream& os) {
   if (m_pNextStation->getItemName().empty())
      os << getItemName() << " --> END OF LINE" << endl;
   else {
      os << getItemName()
         << " --> "
         << m_pNextStation->getItemName() << endl;
      //os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;
   }
}

Workstation& Workstation::operator+=(CustomerOrder&& ro) {
   //  moves the parameter onto the back of the CustomerOrder queue.
   m_orders.push_back(std::move(ro));
   return *this;
}



