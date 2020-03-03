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
using namespace std;
namespace sdds {

   Vehicle* createInstance(std::istream& is) {
      //Car* tempCar;
      size_t pos;
      std::string tag;

      /*if (tempCar != 0) {
         delete tempCar;
         tempCar = nullptr;
      }*/

      is >> tag;
      pos = tag.find(',');
      tag = tag.substr(0, pos); // extract the string     
      
      if (tag == "c" || tag == "C") {
         return new Car(is); // Create new instance of car
         //tempCar = new Car(is); // Create new instance of car
      }
      else {
         return nullptr;
         //tempCar = nullptr;
      }

      //return tempCar;
   }
}