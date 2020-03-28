/*Name: Nathan Olah
Seneca Student ID: 124723198
Seneca email: nolah@myseneca.ca
Date of completion: 2020/03/28

I confirm that I am the only author of this file
  and the content was created entirely by me.*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "LineManager.h"
#include "Workstation.h"
#include "CustomerOrder.h"
#include "Utilities.h"
using namespace std;

LineManager::~LineManager() { delete emptyStation; }

LineManager::LineManager(const std::string& str, std::vector<Workstation*>& theStations,
   std::vector<CustomerOrder>& theOrders) {

   ifstream file(str);
   if (!file)
      throw string("Unable to open [") + str + "] file.";

   string record;
   while (!file.eof()) {
      getline(file, record);
      string str = record;

      Utilities newStr;
      newStr.setDelimiter('|');

      size_t next_pos = 0;
      size_t i = 0;
      bool more = false;

      if (!str.empty())
         more = true;

      // Count the amount of items 
      unsigned itemCount = std::count(str.begin(), str.end(), newStr.getDelimiter()) + 1;

      std::vector<string> items;

      for (i = 0; i < itemCount; i++) {
         string token = newStr.extractToken(str, next_pos, more);
         items.push_back(token);
      }

      auto station1_i = -1;              
      auto station2_i = -1;

      i = 0;
      for (auto itr = theStations.begin(); itr != theStations.end(); itr++, i++) {
         string name = theStations.at(i)->getItemName();

         if (station1_i == -1 && name == items.at(0)) {
            station1_i = i;
         }
         else if (itemCount > 1) {
            if (station2_i == -1 && name == items.at(1)) {
               station2_i = i; // save index
            }
         }
      }
      
      // Make station1 point to station2
      Workstation* station1 = theStations.at(station1_i);

      if (station2_i == -1) {
         emptyStation = new Workstation();
         station1->setNextStation(*emptyStation);
      }
      else {
         Workstation* station2 = theStations.at(station2_i);
         station1->setNextStation(*station2);
      }

   }
   file.close();

   for (auto i : theStations) {
      AssemblyLine.push_back(i);
   }

   // Move the orders to be filled
   for (auto& i : theOrders)
      ToBeFilled.push_back(std::move(i));
   m_cntCustomerOrder = ToBeFilled.size();


}  

bool LineManager::run(std::ostream& os) {
   CustomerOrder orders;
   static size_t count = 0;
   bool ok = true;

   size_t i = 0;
   size_t j = 0;
   Workstation* current = nullptr;

   // Sort the stations
   for (i = 0; i < AssemblyLine.size(); i++) {
      current = AssemblyLine.at(i);
      bool isNext = false;

      for (j = 0; j < AssemblyLine.size(); j++) {
         Workstation* temp = AssemblyLine.at(j);
         if (i != j 
            && temp->getNextStation() 
            && current->getItemName() == temp->getNextStation()->getItemName()) {

            isNext = true;
            break;
         }
      }

      if (!isNext) {
         break;
      }
   }

   if (count < 10) {
      os << "Line Manager Iteration: " << ++count << endl;

      if (ToBeFilled.size() != 0) {
         *current += std::move(ToBeFilled.front());
         ToBeFilled.pop_front();
      }

      if (count != 7)
         for (auto& i : AssemblyLine)
            i->runProcess(os);

      for (auto& i : AssemblyLine) {
         if (i->getIfCompleted(orders)) {
            Complete.push_back(move(orders));
         }
         else {
            ok = false;
         }
         
         i->moveOrder();   
      }
   }

   return ok; 
}


void LineManager::displayCompletedOrders(std::ostream& os)const {
   for (auto& i : Complete)
      i.display(os);
}

void LineManager::displayStations()const {
   for (auto& i : AssemblyLine) {
      i->display(cout);
   }
}

void LineManager::displayStationsSorted()const {
   size_t i = 0;
   size_t j = 0;
   Workstation* current = nullptr;

   for (i = 0; i < AssemblyLine.size(); i++) {
      current = AssemblyLine.at(i);
      bool isNext = false;

      for (j = 0; j < AssemblyLine.size(); j++) {
         Workstation* temp = AssemblyLine.at(j);
         if (i != j 
            && temp->getNextStation() 
            && current->getItemName() == temp->getNextStation()->getItemName()) {

            isNext = true;
            break;
         }
      }
      
      if (!isNext) {
         break;
      }
   }

   do {
      current->display(cout);
      current = (Workstation*)current->getNextStation();
   } while (!current->getItemName().empty());


}



