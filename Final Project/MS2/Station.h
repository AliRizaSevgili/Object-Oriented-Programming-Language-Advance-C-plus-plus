// Name: Ali Riza Sevgili
// Seneca Student ID: 135200228
// Seneca email: arsevgili@myseneca.ca
// Date of completion: 03/20/2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <string>
#include <iostream>

namespace seneca {
    class Station {
        int m_id{};
        std::string m_itemName{};
        std::string m_desc{};
        size_t m_nextSerialNumber{ 0 };
        size_t m_quantity{ 0 };
        static size_t m_widthField;
        static int id_generator;
    public:
        Station(const std::string& record);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}

#endif 
