// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/02/17
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_COLLECTION_H__
#define SDDS_COLLECTION_H__
#include <iostream>
#include <string>
namespace sdds {
   template <typename T>
   class Collection {
      std::string m_nameOfCollection;
      T* m_items;
      size_t m_size;
      void (*newItem)(const Collection<T>&, const T&) = nullptr; // Default nullptr
   public:
      Collection(std::string name) : m_nameOfCollection(name), m_items(nullptr), m_size(0u) {}

      // Delete copy operations
      Collection(const Collection& ro) = delete;
      Collection& operator=(const Collection ro) = delete;

      // Destructor
      ~Collection() {
         delete[] m_items;
      }

      // Returns the name of the collection 
      const std::string& name()const {
         return m_nameOfCollection;
      }

      // Returns how many items are in the collection
      size_t size()const {
         return m_size;
      }

      //
      void setObserver(void (*observer)(const Collection<T>&, const T&)) {
         newItem = observer;
      }

      //
      Collection<T>& operator+=(const T& item) {
         size_t i = 0;
         T* tempItems;
          
         
         for (i = 0; i < m_size; i++) {
            if (m_items[i].title() == item.title()) {
               return *this;
            }
         }
          
         tempItems = new T[m_size + 1];

         for (i = 0; i < m_size; i++) {
            tempItems[i] = m_items[i];
         }

         tempItems[m_size] = item;
         delete[] m_items;
         m_items = tempItems;
         m_size++;
         
         if (newItem) {
            newItem(*this, m_items[m_size - 1]);
         }


         //// If item is already in the collection, return current object
         //for (i = 0; i < m_size; i++) {
         //   if (m_items[i].title() == item.title()) {
         //      return *this;
         //   }
         //}

         //

         ////adds a copy of item to the collection
         ////resize the array to accomodate the new item
         //T* temp = new T[m_size + 1];

         //for (i = 0; i < m_size; i++) {
         //   temp[i] = m_items[i];
         //}

         //temp[m_size] = item; // add copy of new item to 'temp'
         //delete[] m_items; // clear m_items before passing 'temp' over 
         //m_items = temp; // m_item is now new item
         //m_size++; // add item

         //////if there is an observer registered, call the observer function passing *this and the new item as parameters
         //if (itemAdded != nullptr) {
         //   itemAdded(*this, m_items[m_size - 1]);
         //}

         return *this;
      }

      // Returns item at index
      T& operator[](size_t idx) const {
         std::string errorMessage;
         if (idx >= size()) {
            // Concatenate strings into errorMessage
            errorMessage = "Bad index [";
            errorMessage += std::to_string(idx);
            errorMessage += "]. Collection has [";
            errorMessage += std::to_string(size());
            errorMessage += "] items.";

            throw std::out_of_range(errorMessage);
         }
         // Returns item at index idx
         return m_items[idx];

      }

      // Returns the address of "m_items" if it finds the title parameter
      T* operator[](std::string title) const {
         for (size_t i = 0; i < size(); i++) {
            if (m_items[i].title() == title) {
               return &m_items[i];
            }
         }
         return nullptr;
        
      }

      friend std::ostream& operator<<(std::ostream& os, const Collection& ro) {
         for (size_t i = 0; i < ro.size(); i++) {
            os << ro.m_items[i]; 
         }
         return os;
      }

   };

}
#endif // !SDDS_COLLECTION_H__
