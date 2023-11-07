
#ifndef M1_CUSTOMERORDER_H
#define M1_CUSTOMERORDER_H
#include <iostream>
#include "Station.h"

namespace sdds{

    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder {

        std::string m_name {};
        std::string m_product {};
        size_t m_cntItem {0u};
        Item** m_lstItem {};
        static size_t m_widthField;

    public:
        //rule of 5 operators
        CustomerOrder()=default;
        CustomerOrder(const std::string& str);
        ~CustomerOrder();
        //copy operators
        CustomerOrder(const CustomerOrder& order);
        CustomerOrder& operator=(const CustomerOrder&)=delete;
        //move operators
        CustomerOrder(CustomerOrder&& order) noexcept;
        CustomerOrder& operator=(CustomerOrder&& order) noexcept;

        bool isOrderFilled() const;

        bool isItemFilled(const std::string& itemName) const;

        void fillItem(Station& station, std::ostream& os);

        void display(std::ostream& os) const;




    };

}


#endif //M1_CUSTOMERORDER_H
