// Name: Carmen Lam
// Seneca Student ID: 129950226
// Seneca email: clam98@myseneca.ca
// Date of completion: August 3, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef M1_UTILITIES_H
#define M1_UTILITIES_H
#include <iostream>
namespace sdds{
    class Utilities {
        size_t m_widthField {1};
        inline static char m_delimiter {};
    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
        std::string eraseWhiteSpace(const std::string& str);

    };

}


#endif //M1_UTILITIES_H
