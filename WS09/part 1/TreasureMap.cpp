// Workshop 9
// TreasureMap.cpp
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <future>
#include <functional>
#include "TreasureMap.h"

namespace seneca {

    size_t digForTreasure(const std::string& str, char mark) {
        size_t cnt = 0;
        for (auto& x : str) {
            if (x == mark) {
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename) {
        std::fstream fin(filename);
        if (fin) {
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while (fin) {
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap() {
        delete[] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const {
        if (map) {
            for (size_t i = 0; i < rows; ++i) {
                os << map[i] << std::endl;
            }
        }
        else
            os << "The map is empty!" << std::endl;
        return os;
    }



    void TreasureMap::enscribe(const char* filename) {
        // Binary write
        if (map) {
            std::ofstream fout(filename, std::ios::binary);
            if (!fout)
                throw std::string("Failed to open file for writing: ") + filename;

            fout.write(reinterpret_cast<char*>(&rows), sizeof(rows));
            fout.write(reinterpret_cast<char*>(&colSize), sizeof(colSize));

            for (size_t i = 0; i < rows; ++i) {
                size_t length = map[i].length();
                fout.write(map[i].c_str(), length);
            }
            fout.close();
        }
        else {
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename) {
        // Binary read
        std::ifstream fin(filename, std::ios::binary);
        if (!fin)
            throw std::string("Failed to open file for reading: ") + filename;

        fin.read(reinterpret_cast<char*>(&rows), sizeof(rows));
        fin.read(reinterpret_cast<char*>(&colSize), sizeof(colSize));

        map = new std::string[rows];
        for (size_t i = 0; i < rows; ++i) {
            char* buffer = new char[colSize + 1];
            fin.read(buffer, colSize);
            buffer[colSize] = '\0';
            map[i] = buffer;
            delete[] buffer;
        }
        fin.close();
    }




    void TreasureMap::clear() {
        delete[] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }




    size_t TreasureMap::findTreasure(char mark) {
        size_t count = 0;

        // Multithreaded version
        const int numThreads = 4;
        std::thread threads[numThreads];
        std::packaged_task<size_t(const std::string&, char)> tasks[numThreads];
        std::future<size_t> futures[numThreads];

        // Partitioning the data and creating threads
        size_t partitionSize = rows / numThreads;
        for (int i = 0; i < numThreads; ++i) {
            size_t start = i * partitionSize;
            size_t end = (i == numThreads - 1) ? rows : start + partitionSize;
            std::string concatenatedData;
            for (size_t j = start; j < end; ++j)
                concatenatedData += map[j];
            tasks[i] = std::packaged_task<size_t(const std::string&, char)>
                (std::bind(digForTreasure, std::placeholders::_1, mark));
            futures[i] = tasks[i].get_future();
            threads[i] = std::thread(std::move(tasks[i]), concatenatedData, mark);
        }

        // Wait for threads to finish
        for (int i = 0; i < numThreads; ++i) {
            threads[i].join();
            count += futures[i].get();
        }

        return count;
    }
}
