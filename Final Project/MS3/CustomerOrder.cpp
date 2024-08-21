// Name: Ali Riza Sevgili
// Seneca Student ID: 135200228
// Seneca email: arsevgili@myseneca.ca
// Date of completion: 04/05/2024
// I confirm that I am the only author of this file and the content was created entirely by me.


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;


namespace seneca {
    size_t CustomerOrder::m_fieldWidth{};

    CustomerOrder::CustomerOrder(const std::string& str) {
        Utilities ut;
        size_t pos{ 0 };
        bool more{ true };
        vector<string> items{};
        m_name = ut.extractToken(str, pos, more);
        m_orderTitle = ut.extractToken(str, pos, more);
        while (more) {
            ++m_itemCnt;
            string item = ut.extractToken(str, pos, more);
            items.push_back(item);
        }
        m_itemList = new Item * [m_itemCnt];
        for (auto i = 0u; i < m_itemCnt; ++i)
            m_itemList[i] = new Item(items[i]);
        if (ut.getFieldWidth() > m_fieldWidth)
            m_fieldWidth = ut.getFieldWidth();

    }
    CustomerOrder::CustomerOrder(const CustomerOrder& CO) {
        throw ("Customer order copies are not allowed!");
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& CO) noexcept {
        *this = move(CO);
    }
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& CO) noexcept {
        if (this != &CO) {
            for (auto i = 0u; i < m_itemCnt; ++i)
                delete m_itemList[i];
            delete[] m_itemList;
            m_name = CO.m_name; 
            m_orderTitle = CO.m_orderTitle;
            m_itemCnt = CO.m_itemCnt;
            m_itemList = CO.m_itemList; 
            CO.m_itemList = nullptr;
            CO.m_name.clear();
            CO.m_orderTitle.clear();
            CO.m_itemCnt = 0;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder() {
        for (auto i = 0u; i < m_itemCnt; ++i)
            delete m_itemList[i];
        delete[] m_itemList;
    }
    bool CustomerOrder::isOrderFilled() const {
        bool ret{};
        size_t cnt{};
        for (auto i = 0u; i < m_itemCnt; ++i)
            if (m_itemList[i]->m_isFilled) 
                ++cnt;

        if (cnt == m_itemCnt) ret = true;

        return ret;
    }
    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        bool ret{};
        int cntItems{}, cntFilled{};

        for (auto i = 0u; i < m_itemCnt; ++i) {
            if (m_itemList[i]->m_itemName == itemName) {
                ++cntItems; 
                if (m_itemList[i]->m_isFilled)
                    ++cntFilled;
            }
        }

        if (cntItems == 0 || cntFilled == cntItems) ret = true;
        
        return ret;
    }
    void CustomerOrder::fillItem(Station& S, std::ostream& os) {
        bool filled{};
        for (auto i = 0u; i < m_itemCnt && !filled; ++i) {
            if (m_itemList[i]->m_itemName == S.getItemName() && m_itemList[i]->m_isFilled == false) {
                if (S.getQuantity() > 0) {
                    S.updateQuantity();
                    m_itemList[i]->m_isFilled = true;
                    m_itemList[i]->m_serialNumber = S.getNextSerialNumber();
                    os << "    Filled " << m_name << ", " << m_orderTitle << " ["
                        << m_itemList[i]->m_itemName << "]\n";
                    filled = true;
                } else {
                    os << "    Unable to fill " << m_name << ", " << m_orderTitle << " ["
                        << m_itemList[i]->m_itemName << "]\n";
                }
            }
        }
    }
    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_orderTitle << endl;
        for (auto i = 0u; i < m_itemCnt; ++i) {
            os << "[" << setfill('0') << setw(6) << m_itemList[i]->m_serialNumber << "] "
                << setfill(' ') << left << setw(m_fieldWidth-1) << m_itemList[i]->m_itemName << "- ";
            if (m_itemList[i]->m_isFilled) os << "FILLED" << endl;
            else os << "TO BE FILLED" << endl;
            os << right;
        }
    }
}