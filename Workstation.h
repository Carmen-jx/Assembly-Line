// Name: Carmen Lam
// Seneca Student ID: 129950226
// Seneca email: clam98@myseneca.ca
// Date of completion: August 1, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef M1_WORKSTATION_H
#define M1_WORKSTATION_H

#include <iostream>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {
    //global variables:
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station{
        std::deque<CustomerOrder> m_orders {};
        Workstation* m_pNextStation {nullptr};

    public:
        Workstation(const std::string& str);
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station= nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);



    };

}

#endif //M1_WORKSTATION_H
