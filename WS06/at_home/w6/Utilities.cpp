// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <sstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
using namespace std;
namespace sdds {

   // Removes whitespace around the string
   void trim(std::string& str) {
      size_t i = 0;
      // Remove leading whitespace
      for (i = 0; i < str.length() && str[i] == ' '; i++); // gets index of whitespace
      str = str.substr(i);

      // Remove trailing whitespace
      for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
      str = str.substr(0, i);
   }

   Vehicle* createInstance(std::istream& is) {
      std::string tag;

      getline(is, tag, ',');
      trim(tag);
      
      if (tag == "") {
         return nullptr;
      }

      if (tag == "c" || tag == "C") {
         return new Car(is); 
      }
      else if (tag == "r" || tag == "R") {
         return new Racecar(is);
      } 
      else if (tag != "r" || tag != "R" || tag != "c" || tag != "C") {
         // Clear remaining string
         string temp;
         getline(is, temp, '\n');
         temp.clear();
         throw "Unrecognized record type: [" + tag + "]";
      }
      else {
         return nullptr;
      }

   }

}