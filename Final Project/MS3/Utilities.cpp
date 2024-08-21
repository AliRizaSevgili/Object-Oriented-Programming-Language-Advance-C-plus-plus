// Name: Ali Riza Sevgili
// Seneca Student ID: 135200228
// Seneca email: arsevgili@myseneca.ca
// Date of completion: 04/05/2024
// I confirm that I am the only author of this file and the content was created entirely by me.

#include <string>
#include "Utilities.h"

using namespace std;

namespace seneca {

    char Utilities::m_delimiter{};

    void Utilities::setFieldWidth(size_t newWidth) {
        m_fieldWidth = newWidth;
    }
    size_t Utilities::getFieldWidth() const {
        return m_fieldWidth;
    }
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        std::string ret{};
        char ch = str[next_pos];
        if (ch == m_delimiter) {
            more = false;
            throw "Error";
        }
        while (ch != m_delimiter && ch != '\0') {
            ret += ch;
            ch = str[++next_pos];
        }
        if (m_fieldWidth < ret.length())
            m_fieldWidth = ret.length();
        if (ch == '\0')
            more = false;
        else
            ++next_pos; 

        return trim(ret, " ");
    }
    void Utilities::setDelimiter(char newDelim) {
        m_delimiter = newDelim;
    }
    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}