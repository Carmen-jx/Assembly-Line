// Name: Carmen Lam
// Seneca Student ID: 129950226
// Seneca email: clam98@myseneca.ca
// Date of completion: August 3, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef M1_STATION_H
#define M1_STATION_H
#include <iostream>
#include "Utilities.h"

namespace sdds{
    class Station {
        size_t m_id{};
        std::string m_name{};
        std::string m_description{};
        size_t m_serialNumber{};
        size_t m_qty{};
        inline static size_t m_widthField{0};
        inline static size_t id_generator{0};
    public:
        Station()=default;
        Station(const std::string& str);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;




    };
}



#endif //M1_STATION_H
