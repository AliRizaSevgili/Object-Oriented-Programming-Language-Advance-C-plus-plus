// Name: Ali Riza Sevgili
// Seneca Student ID: 135200228
// Seneca email: arsevgili@myseneca.ca
// Date of completion: 04/05/2024
// I confirm that I am the only author of this file and the content was created entirely by me.


#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <iostream>
#include <string>
#include <sstream>
#include "Station.h"

namespace seneca {
    class CustomerOrder {
        struct Item {
            std::string m_itemName;
            size_t m_serialNumber{ 0 };
            bool m_isFilled{ false };

            Item(const std::string& src) : m_itemName(src) {};
        };
        std::string m_name{};
        std::string m_orderTitle{};
        size_t m_itemCnt{};
        Item** m_itemList{};
        static size_t m_fieldWidth;
        static std::size_t stringToSize_t(std::string str) {
            std::stringstream sstream(str);
            size_t result;
            sstream >> result;
            return result;
        }
    public:
        
        CustomerOrder() = default;
        CustomerOrder(const std::string&);
        CustomerOrder(const CustomerOrder& CO);
        CustomerOrder& operator=(const CustomerOrder&) = delete;
        CustomerOrder(CustomerOrder&& CO) noexcept;
        CustomerOrder& operator=(CustomerOrder&& CO) noexcept;
        ~CustomerOrder();
        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& S, std::ostream& os);
        void display(std::ostream& os) const;
    };
}
#endif // !SENECA_CUSTOMERORDER_H_



