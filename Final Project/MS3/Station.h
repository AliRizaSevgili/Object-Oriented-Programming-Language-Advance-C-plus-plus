// Name: Ali Riza Sevgili
// Seneca Student ID: 135200228
// Seneca email: arsevgili@myseneca.ca
// Date of completion: 04/05/2024
// I confirm that I am the only author of this file and the content was created entirely by me.


#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iostream>
#include <sstream>
#include <string>

namespace seneca {
    class Station {
        size_t m_stationId{};
        std::string m_itemName{};
        std::string m_description{};
        size_t m_nextSerial{};
        size_t m_stockCount{};
        static size_t m_fieldWidth;
        static size_t m_idGenerator;
        static std::size_t stringToSize_t(std::string str) {
            std::stringstream sstream(str);
            size_t result;
            sstream >> result;
            return result;
        }
    public:
        Station(const std::string& str);
        const std::string& getItemName() const;
        size_t getQuantity() const;
        size_t getNextSerialNumber();
        void updateQuantity();
        void display(std::ostream& os, bool full) const;  
    };
}

#endif // !SENECA_STATION_H_