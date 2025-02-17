// Name: Nathan Olah
// Seneca Student ID: 124723198
// Seneca email: nolah@myseneca.ca
// Date of completion: 2020/03/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_UTILITIES_H__
#define SDDS_UTILITIES_H__

class Utilities {
   size_t m_widthField;
   static char m_delimiter;
public:
   Utilities();
   void setFieldWidth(size_t newWidth);
   size_t getFieldWidth()const;
   std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
   static void setDelimiter(char newDelimiter);
   static char getDelimiter();
};

#endif // !SDDS_UTILITIES_H__
