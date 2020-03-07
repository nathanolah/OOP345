// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/03/07
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SONGCOLLECTION_H__
#define SDDS_SONGCOLLECTION_H__
#include <iostream>
#include <vector>
namespace sdds {

   struct Song {
      std::string m_artist;
      std::string m_title;
      std::string m_album;
      double m_price = 0;
      std::string m_yearOfRelease; // If no year provided must be empty string
      std::string m_songLength; // string so that colon can be inserted
      Song();
   };

   class SongCollection {
      std::vector<Song*> m_songs;
   public:
      SongCollection();
      ~SongCollection();
      SongCollection(const char* filename);
      void display(std::ostream& out)const;
   };
   std::ostream& operator<<(std::ostream& out, const Song& theSong);


}
#endif // !SDDS_SONGCOLLECTION_H__

