/*Name: Nathan Olah
Seneca Student ID: 124723198
Seneca email: nolah@myseneca.ca
Date of completion: 2020/03/09

I confirm that I am the only author of this file
  and the content was created entirely by me.*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "LineManager.h"
#include "Workstation.h"
#include "CustomerOrder.h"
#include "Utilities.h"
using namespace std;

LineManager::LineManager(const std::string& str, std::vector<Workstation*>& theStations,
   std::vector<CustomerOrder>& theOrders) {
   static bool firstIdx = false;
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

      size_t theStationIdx = 0; // use to save last index

      if (!str.empty())
         more = true;

      // Count the amount of items 
      size_t itemCount = std::count(str.begin(), str.end(), newStr.getDelimiter()) + 1;
      Item* items = new Item[itemCount];

      for (i = 0; i < itemCount; i++)
         items[i].m_itemName = newStr.extractToken(str, next_pos, more);

      auto station1_i = -1;              
      auto station2_i = -1;

      i = 0;
      for (auto itr = theStations.begin(); itr != theStations.end(); itr++, i++) {
         string name = theStations.at(i)->getItemName();

        
         if (station1_i == -1 && name == items[0].m_itemName) {
            if (!firstIdx) {
               firstIndex = i;
               firstIdx = true;
            }
            station1_i = i;
         }

         if (station2_i == -1 && name == items[1].m_itemName) {
            station2_i = i; // save index 

         }
         
         theStationIdx = i; // save index in order to save the last index
      }
      
      // Make station1 point to station2
      Workstation* station1 = theStations.at(station1_i);


      if (station2_i == -1) {
         Workstation* emptyStation = new Workstation();
         station1->setNextStation(*emptyStation);
         lastIndex = theStationIdx - 1;
      }
      else {
         Workstation* station2 = theStations.at(station2_i);
         station1->setNextStation(*station2);
      }

      delete[] items;

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

   for (i = 0; i < AssemblyLine.size(); i++) {
      current = AssemblyLine.at(i);
      bool is_next = false;

      for (j = 0; j < AssemblyLine.size(); j++) {
         Workstation* temp = AssemblyLine.at(j);
         if (i != j && temp->getNextStation() && current->getItemName() == temp->getNextStation()->getItemName()) {
            is_next = true;
            break;
         }
      }

      if (!is_next) {
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
      bool is_next = false;

      for (j = 0; j < AssemblyLine.size(); j++) {
         Workstation* temp = AssemblyLine.at(j);
         if (i != j && temp->getNextStation() && current->getItemName() == temp->getNextStation()->getItemName()) {
            is_next = true;
            break;
         }
      }
      
      if (!is_next) {
         break;
      }
   }

   do {
      current->display(cout);
      current = (Workstation*)current->getNextStation();
   } while (!current->getItemName().empty());


}



