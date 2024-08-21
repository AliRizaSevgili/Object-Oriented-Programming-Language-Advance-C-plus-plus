// Name: Ali Riza Sevgili
// Seneca Student ID: 135200228
// Seneca email: arsevgili@myseneca.ca
// Date of completion: 03/20/2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Station.h"
#include "Utilities.h"
#include <iomanip>

namespace seneca {
    size_t Station::m_widthField = 0; 
    int Station::id_generator = 0;

    // Custom constructor 
    Station::Station(const std::string& record) {
        Utilities util;
        bool more = true; // to check if more tokens are available
        size_t next_pos = 0; // position for the next token to be parsed

        m_itemName = util.extractToken(record, next_pos, more); // extract item name from record
        if (more) {
            m_nextSerialNumber = std::stoi(util.extractToken(record, next_pos, more)); // extract next serial number
        }
        if (more) {
            m_quantity = std::stoul(util.extractToken(record, next_pos, more)); // extract quantity
        }
        if (more) {
            m_desc = util.extractToken(record, next_pos, more); // extract description
            m_desc.erase(0, m_desc.find_first_not_of(' ')); // trim leading whitespaces from the description
        }

        if (m_widthField < m_itemName.size()) { // update max width if current item name is longer
            m_widthField = m_itemName.size();
        }

        m_id = ++id_generator; // assign unique id to the station
    }

    // getter for item name
    const std::string& Station::getItemName() const {
        return m_itemName;
    }

    // retrieves and increments the next serial number
    size_t Station::getNextSerialNumber() {
        return m_nextSerialNumber++;
    }

    // getter for quantity
    size_t Station::getQuantity() const {
        return m_quantity;
    }

    // decreases the quantity of items
    void Station::updateQuantity() {
        if (m_quantity > 0) {
            --m_quantity;
        }
    }

    void Station::display(std::ostream& os, bool full) const {
        os << std::setw(3) << std::setfill('0') << m_id << " | ";
        os << std::left << std::setw(m_widthField) << std::setfill(' ') << m_itemName << "| ";
        os << std::right << std::setw(6) << std::setfill('0') << m_nextSerialNumber << " | ";
        if (full) { // if full then include the quantity and description
            os << std::setw(4) << std::setfill(' ') << m_quantity << " | " << m_desc;
        }
        os << std::endl;
    }

}
