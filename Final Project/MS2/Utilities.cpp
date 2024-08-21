// Name: Ali Riza Sevgili
// Seneca Student ID: 135200228
// Seneca email: arsevgili@myseneca.ca
// Date of completion: 03/20/2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace seneca {
    char Utilities::m_delimiter = ',';

    // sets the field width of the current object
    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }

    // returns the field width of the current object
    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

    // extracts a token from string str
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        size_t end_pos = str.find(m_delimiter, next_pos); // find the position of the next delimiter

        // check if there are no more tokens
        if (end_pos == std::string::npos) {
            more = false;
        }

        // check if this is the last token
        if (next_pos == end_pos) {
            more = false;
            throw std::string("No token between delimiters."); // throw exception for missing token
        }

        std::string token = str.substr(next_pos, end_pos - next_pos); // extract the token
        next_pos = end_pos + 1; // update the starting position for the next token

        if (m_widthField < token.length()) { // adjust the field width if necessary
            m_widthField = token.length();
        }

        return token; // return the extracted token
    }

    // sets the delimiter for this class
    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    // returns the delimiter for this class
    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}
