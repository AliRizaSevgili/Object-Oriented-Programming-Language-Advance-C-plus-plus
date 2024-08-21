// Workshop 9
// TreasureMap.h
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_TREASURE_MAP_H
#define SENECA_TREASURE_MAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <future>
#include <functional>

namespace seneca {

    class TreasureMap {
        size_t rows;
        size_t colSize;
        std::string* map;

    public:
        TreasureMap(const char* filename);
        ~TreasureMap();
        std::ostream& display(std::ostream& os) const;
        void enscribe(const char* filename);
        void recall(const char* filename);
        void clear();
        size_t findTreasure(char mark);
    };

}

#endif // TREASURE_MAP_H
