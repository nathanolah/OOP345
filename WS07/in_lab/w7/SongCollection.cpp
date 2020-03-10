// Name: Nathan Olah 
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/03/07
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "SongCollection.h"
using namespace std;
namespace sdds {

   std::string getString(std::string& tempStr, bool extractFive) {
      std::size_t pos;
      std::string str;

      // Extract up to 5 characters
      if (extractFive) {
         pos = 4; 
         str = tempStr.substr(0, pos); // extract the string     
         tempStr.erase(0, pos + 1);
      }
      else {
         // Extract up to 25 characters
         pos = 24; 
         str = tempStr.substr(0, pos); // extract the string     
         tempStr.erase(0, pos + 1);
      }

      return str;
   }

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

   //
   Song::Song() : m_price(0.0) {}
   //
   SongCollection::SongCollection() {}
   SongCollection::~SongCollection() {
      while (!m_songs.empty()) {
        // delete m_songs.back();
         m_songs.pop_back();
      }
   }

   // 
   SongCollection::SongCollection(const char* filename) {
      std::ifstream file(filename);
      if (!file) {
         std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
         return;
      }
      while (file) {
         
         Song newSong;

         string tempStr;
         getline(file, tempStr, '\n'); 

         if (tempStr != "") {
            newSong.m_title = getString(tempStr, false);
            trim(newSong.m_title);
            newSong.m_artist = getString(tempStr, false);
            trim(newSong.m_artist);
            newSong.m_album = getString(tempStr, false);
            trim(newSong.m_album);

            newSong.m_yearOfRelease = getString(tempStr, true);
            trim(newSong.m_yearOfRelease);

            newSong.m_songLength = getString(tempStr, true);
            trim(newSong.m_songLength);
            newSong.m_songLength.insert(1, 1, ':');

            if (stod(tempStr))
               newSong.m_price = stod(getString(tempStr, true));

            // THIS WAS WHEN I WAS TRYING TO USE Song DYNAMICALLY
            /*
            newSong->m_title = getString(tempStr, false);
            trim(newSong->m_title);
            newSong->m_artist = getString(tempStr, false);
            trim(newSong->m_artist);
            newSong->m_album = getString(tempStr, false);
            trim(newSong->m_album);

            newSong->m_yearOfRelease = getString(tempStr, true);
            trim(newSong->m_yearOfRelease);

            newSong->m_songLength = getString(tempStr, true);
            trim(newSong->m_songLength);
            newSong->m_songLength.insert(1, 1, ':');

            if (stod(tempStr))
               newSong->m_price = stod(getString(tempStr, true));*/

            // Add song to m_songs
            m_songs.push_back(newSong);
         }
         
      }
      file.close();
   }

   // Iterate through the collection 
   void SongCollection::display(std::ostream& out)const {
      //std::for_each(m_songs.begin(), m_songs.end(), [&](const Song* song) { out << *song << endl; });
      std::for_each(m_songs.begin(), m_songs.end(), [&](const Song song) { out << song << endl; });

   }

   std::ostream& operator<<(std::ostream& out, const Song& theSong) {
      
      out << "| " << left << setw(20) << theSong.m_title
         << " | " << left << setw(15) << theSong.m_artist
         << " | " << left << setw(20) << theSong.m_album
         << " | " << right << setw(6) << theSong.m_yearOfRelease
         << " | " << theSong.m_songLength
         << " | " << theSong.m_price << " | ";
      return out;
   }
}