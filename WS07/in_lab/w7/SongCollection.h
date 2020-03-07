// Name:
// Seneca Student ID:
// Seneca email:
// Date of completion:
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
      std::string m_yearOfRelease;
      size_t m_songLength = 0; // or double ? find and replace '.' with ':'
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

