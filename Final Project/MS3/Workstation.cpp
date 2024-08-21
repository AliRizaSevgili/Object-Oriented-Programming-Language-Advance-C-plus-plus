// Name: Ali Riza Sevgili
// Seneca Student ID: 135200228
// Seneca email: arsevgili@myseneca.ca
// Date of completion: 04/05/2024
// I confirm that I am the only author of this file and the content was created entirely by me.



#include <iostream>
#include <deque>
#include "Workstation.h"

using namespace std;

namespace seneca {

    deque<CustomerOrder> g_pending{};
    deque<CustomerOrder> g_completed{};
    deque<CustomerOrder> g_incomplete{};

    Workstation::Workstation(const std::string& str) : Station(str) {}

    void Workstation::fill(std::ostream& os) {
        if (!m_orders.empty())
            m_orders.front().fillItem(*this, os);
    }

    bool Workstation::attemptToMoveOrder() {
        bool ret{};
        if (!m_orders.empty()) {
            if (m_orders.front().isItemFilled(this->getItemName()) || this->getQuantity() <= 0) {
                if (m_pNextStation) {
                    *m_pNextStation += std::move(m_orders.front());
                    m_orders.pop_front();
                } else {
                    m_orders.front().isOrderFilled() ?
                        g_completed.push_back(std::move(m_orders.front())) :
                        g_incomplete.push_back(std::move(m_orders.front()));
                    m_orders.pop_front();
                }
                ret = true;
            }
        }
        return ret;
    }

    void Workstation::setNextStation(Workstation* station) {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const {
        if (m_pNextStation)
            os << getItemName() << " --> " << getNextStation()->getItemName() << endl;
        else
            os << getItemName() << " --> End of Line" << endl;
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}