// Name: Nathan Olah 
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020-01-21
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <string>
#include "RecordSet.h"
namespace sdds {

   // Definition of class static variable
   size_t RecordSet::m_numberOfStrings = 0u;

   // Default constructor 
   RecordSet::RecordSet() : m_pStrings(nullptr) {}

   // One argument constructor 
   RecordSet::RecordSet(const char* filename) {
      size_t index{ 0u };
      std::string line;

      // Opens file
      std::ifstream file(filename);
      // Check if file successfully opened
      if (file.is_open()) {
         // Checks if not end of file and state of stream is good
         while (!file.eof() && file.good()) {
            getline(file, line, ' ');
            m_numberOfStrings++; // Counts amount of strings
            //file.clear();
         }
         
         // Checks if the end of the file 
         if (file.eof()) {
            file.clear();
            // Sets the position of the next character to be extracted from the input stream
            file.seekg(0, file.beg); // beginning of the stream
         }

         // Allocate number of strings for string array
         m_pStrings = new std::string[m_numberOfStrings];

         //size_t index = 0;
         while (!file.eof() && file.good()) {
            // Get each line from file into each element of "m_pStrings"
            getline(file, m_pStrings[index], ' ');
            index++;
         }
      }
      file.close(); // Close file
   }

   // Copy constructor
   RecordSet::RecordSet(const RecordSet& ro) { 
      allocateAndCopy(ro);
   }

   // Copy assignment operator
   RecordSet& RecordSet::operator=(const RecordSet& ro) {
      if (this != &ro) {
         // Deallocate the current resource
         delete[] m_pStrings;
         m_pStrings = nullptr;
         // Allocate for the newest resource
         allocateAndCopy(ro);
      }
      return *this;
   }

   // Move constructor 
   RecordSet::RecordSet(RecordSet&& ro) { *this = std::move(ro); }

   // Move assignment operator
   RecordSet& RecordSet::operator=(RecordSet&& ro) {
      if (this != &ro) {
         m_pStrings = ro.m_pStrings;
         ro.m_pStrings = nullptr;
      }
      return *this;
   }

   // 
   void RecordSet::allocateAndCopy(const RecordSet& ro) {
      // Allocate string array based on number of strings
      m_pStrings = new std::string[m_numberOfStrings];
      // Copy into new resource
      for (size_t i = 0; i < m_numberOfStrings; i++) {
         m_pStrings[i] = ro.m_pStrings[i];
      }
   }

   // Destructor
   RecordSet::~RecordSet() {
      delete[] m_pStrings;
      --m_numberOfStrings;
   }

   // Return number of strings 
   size_t RecordSet::size()const {
      return m_numberOfStrings;
   }

   // Returns string from valid index
   std::string RecordSet::getRecord(size_t index)const {
      std::string line{};
      return line = (!m_pStrings) ? "" : m_pStrings[index];
   }
}
