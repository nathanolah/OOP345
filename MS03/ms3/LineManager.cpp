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
            station1_i = i;
         }

         if (station2_i == -1 && name == items[1].m_itemName) {
            station2_i = i; // save index 
         }

      }
      
      // Make station1 point to station2
      Workstation* station1 = theStations.at(station1_i);
      //AssemblyLine.push_back(theStations.at(station1_i));
      //Workstation* station2 = theStations.at(station2_i); //original code


      if (station2_i == -1) {
         Workstation* emptyStation = new Workstation();
         station1->setNextStation(*emptyStation);
         //AssemblyLine.push_back(&emptyStation);

      }
      else {
         Workstation* station2 = theStations.at(station2_i);
         station1->setNextStation(*station2);
         //AssemblyLine.push_back(theStations.at(station2_i));
      }


      // original code 
      //station1->setNextStation(*station2);


      //AssemblyLine.push_back(theStations.at(station1_i));
      /*if (station2_i != -1) {
         AssemblyLine.push_back(theStations.at(station2_i));

      }*/

      // Add stations to assembly line
      //AssemblyLine.push_back(theStations.at(station2_i));

      delete[] items;

   }
   file.close();

   for (auto i : theStations) {
      AssemblyLine.push_back(i);
   }

   // Move all the CustomerOrder objects onto the back of the ToBeFilled queue
   size_t i = 0;
   for (auto itr = theOrders.begin(); itr != theOrders.end(); itr++, i++) {
      ToBeFilled.push_back(std::move(theOrders.at(i)));
   }

}  

bool LineManager::run(std::ostream& os) {
   static size_t count = 0;
   bool ok = false;

  // count++;
   os << "Line Manager Iteration: " << ++count << endl;
   //If there are any CustomerOrder objects in the ToBeFilled queue, 
   //move the one at the front of the queue onto the starting point
   //of the AssemblyLine(you have to identify which station is the starting point of your assembly line).
   //Only one order can be moved on the assembly line on each call to this function.
   if (!ToBeFilled.empty()) {
      *AssemblyLine.front() += std::move(ToBeFilled.front());
   }

   //Loop through all stations on the assembly line and run one cycle of the station's process
  /* size_t i = 0;
   for (auto itr = AssemblyLine.begin(); itr != AssemblyLine.end(); itr++, i++) {
      AssemblyLine.at(i)->runProcess(os); 
   }*/
   for (auto& i : AssemblyLine) {
      i->runProcess(os);
   }

   // Loop through all stations on the assembly line and move the CustomerOrder objects down the line.
      //Hint: completed orders should be moved into the Completed queue.
   // return true if all customer orders have been filled, otherwise returns false.
   for (auto& i : AssemblyLine) {
      //Complete.push_back(std::move(m_orders));

      //if () { // fix this
      //   ok = true;
      //}
   }

   return ok; 
}


void LineManager::displayCompletedOrders(std::ostream& os)const {
   size_t i = 0;
   for (auto itr = Complete.begin(); itr != Complete.end(); itr++, i++) {
      Complete.at(i).display(os);
   }
}

void LineManager::displayStations()const {
   //size_t i = 0;
   //for (auto itr = AssemblyLine.begin(); itr != AssemblyLine.end(); itr++, i++) {
   //   cout << AssemblyLine.at(i)->getItemName() << " --> ";

   //   if (AssemblyLine.at(++i)->getNextStation()->getItemName() == "")
   //      cout << "END OF LINE" << endl;
   //   else
   //      cout << AssemblyLine.at(++i)->getNextStation()->getItemName() << endl; // check over 
   //}

   for (auto& i : AssemblyLine) {
      i->display(cout);
   }

}

void LineManager::displayStationsSorted()const {

   size_t i = 0;
   size_t j = 0;
   Workstation* current = nullptr;

   //for (auto itr1 = AssemblyLine.begin(); itr1 != AssemblyLine.end(); itr1++, i++) {
   for (i = 0; i < AssemblyLine.size(); i++) {
      current = AssemblyLine.at(i);
      bool is_next = false;

      //for (auto itr2 = AssemblyLine.begin(); itr2 != AssemblyLine.end(); itr2++, j++) {
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



