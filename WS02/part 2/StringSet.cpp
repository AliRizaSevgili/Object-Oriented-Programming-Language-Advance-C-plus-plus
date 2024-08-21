// Workshop 2 
// StringSet.cpp
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "StringSet.h"
#include <fstream>

using namespace std;

namespace seneca
{
    
    StringSet::StringSet(const char* _filename) {
        if (_filename) {
            ifstream readFile(_filename);
            string _temp;

            if (readFile) {
              
                while (getline(readFile, _temp, ' '))
                    ++s_CurRecord;

                
                s_str = new string[s_CurRecord];

                
                readFile.clear();
                readFile.seekg(0, std::ios::beg);

                int i = 0;
                while (getline(readFile, s_str[i], ' '))
                    ++i;
            }
        }
    }

    StringSet::~StringSet() {
        if (s_str)
            delete[] s_str;
    }

    // copy constructor
    StringSet::StringSet(const StringSet& src) {
        *this = src;
    }

    // copy assignment
    StringSet& StringSet::operator=(const StringSet& src) {
        if (this != &src) {
            if (this->s_str) {
                delete[] s_str;
                s_str = nullptr;
            }

            this->s_CurRecord = src.s_CurRecord;

            this->s_str = new string[s_CurRecord];
            for (auto i = 0u; i < s_CurRecord; ++i)
                this->s_str[i] = src.s_str[i];
        }

        return *this;
    }

    // move constructor
    StringSet::StringSet(StringSet&& src) {
        *this = std::move(src);
    }

    // move assignment
    StringSet& StringSet::operator=(StringSet&& src) {
        if (this != &src) {

            if (this->s_str) {
                delete[] s_str;
                s_str = nullptr;
            }

            this->s_CurRecord = src.s_CurRecord;
            src.s_CurRecord = 0u;

            this->s_str = src.s_str;
            src.s_str = nullptr;
        }

        return *this;
    }

    size_t StringSet::size() const {
        return s_CurRecord;
    }

    std::string StringSet::operator[](size_t src) const {
        string _copy = "";

        if (src < s_CurRecord)
            _copy = s_str[src];

        return _copy;
    }
}