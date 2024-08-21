// Name: Ali Riza Sevgili
// Seneca Student ID: 135200228
// Seneca email: arsevgili@myseneca.ca
// Date of completion: 03/20/2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
#include "Utilities.h"
#include <iomanip>
#include <algorithm>

namespace seneca {
	// static member
	size_t CustomerOrder::m_widthField = 0;

    // Helper function to trim whitespace from the beginning and end of a string
    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        if (first == std::string::npos || last == std::string::npos)
            return str;
        return str.substr(first, (last - first + 1));
    }

    // Helper function to compare strings case-insensitively
    bool iequals(const std::string& a, const std::string& b) {
        return std::equal(a.begin(), a.end(), b.begin(), b.end(),
            [](char a, char b) {
                return tolower(a) == tolower(b);
            });
    }

	// default constructor
	CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {}
    
    // custom 1-argument constructor
    CustomerOrder::CustomerOrder(const std::string& record) {
        Utilities util;
        size_t next_pos = 0;
        bool more = true;

        try {
            m_name = util.extractToken(record, next_pos, more); // Extract customer name
            if (more) m_product = util.extractToken(record, next_pos, more); // Extract product name

            // Count the number of items in the order
            m_cntItem = std::count(record.begin() + next_pos, record.end(), util.getDelimiter()) + 1;

            // Allocate memory for items
            m_lstItem = new Item * [m_cntItem];

            // Initialize m_widthField to zero before determining the max length
            m_widthField = 0;

            for (size_t i = 0; i < m_cntItem && more; ++i) {
                // Extract item name and create a new Item object
                std::string item = trim(util.extractToken(record, next_pos, more));
                m_lstItem[i] = new Item(item);

                // Update m_widthField to the maximum item name length
                m_widthField = std::max(m_widthField, item.size());
            }
        }
        catch (const std::string& err) {
            std::cerr << err << std::endl;
        }
    }

    // Copy Constructor
    CustomerOrder::CustomerOrder(const CustomerOrder& other) {
        throw std::runtime_error("Copying not allowed"); 
    }

    // move constructor
    CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {
        *this = std::move(other);
    }

    // move assignment operator
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept {
        if (this != &other) { 
            // Free existing resources
            for (size_t i = 0; i < m_cntItem; ++i) {
                delete m_lstItem[i];
            }
            delete[] m_lstItem;

            // Transfer resources from other to this
            m_name = std::move(other.m_name);
            m_product = std::move(other.m_product);
            m_cntItem = other.m_cntItem;
            m_lstItem = other.m_lstItem;

            // Reset other to a safe state
            other.m_cntItem = 0;
            other.m_lstItem = nullptr;
        }
        return *this;
    }

    // Destructor
    CustomerOrder::~CustomerOrder() {
        for (size_t i = 0; i < m_cntItem; ++i) {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const {
        for (size_t i = 0; i < m_cntItem; ++i) {
            if (!m_lstItem[i]->m_isFilled) {
                return false; // If any item is not filled, return false immediately
            }
        }
        return true; // All items are filled
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        for (size_t i = 0; i < m_cntItem; ++i) {
            if (m_lstItem[i]->m_itemName == itemName) {
                return m_lstItem[i]->m_isFilled; // Return the filled status of the item
            }
        }
        return true; // Item not found, consider it filled
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        for (size_t i = 0; i < m_cntItem; i++) {
            // trim spaces from item name in the order and station for comparison
            std::string itemName = trim(m_lstItem[i]->m_itemName);
            std::string stationName = trim(station.getItemName());

            // check if the item matches the station item and it had not been filled yet
            if (iequals(itemName, stationName) && !m_lstItem[i]->m_isFilled) {
                // check if the station has enough inventory to fill the item
                if (station.getQuantity() > 0) {
                    // assign the next serial number and mark the item as filled
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    // decrease the station inventory count by one
                    station.updateQuantity();
                    m_name = trim(m_name);  
                    m_product = trim(m_product); 
                    os << std::right << std::setw(11) << "Filled " << m_name << ", " << m_product << " ["
                        << m_lstItem[i]->m_itemName << "]" << std::endl;
                    // stop processing as the item was found and filled
                    break;
                }
                else {
                    os << "Unable to fill " << m_name << "," << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
            }
        }
    }   

    void CustomerOrder::display(std::ostream& os) const {
        os << trim(m_name) << " - " << trim(m_product) << std::endl;
        for (size_t i = 0; i < m_cntItem; i++) {
            // trim spaces from the item name for display
            std::string trimmedItemName = trim(m_lstItem[i]->m_itemName);
            os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] "
                << std::setw(m_widthField + 18) // extra padding to account for the fixed text
                << std::setfill(' ') << std::left << trimmedItemName << " - "
                << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
        }
    }

}