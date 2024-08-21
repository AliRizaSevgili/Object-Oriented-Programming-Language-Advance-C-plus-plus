// Workshop 5
// SpellChecker.cpp
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
using namespace std;

namespace seneca
{
    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream fileStream(filename);
        if (!fileStream) {
            throw "Bad file name!";
        }
        std::string line;
        size_t count = 0;
        while (count < STR_SIZE && std::getline(fileStream, line)) {
            std::istringstream lineStream(line);
            std::string badWord, goodWord;
            if (lineStream >> badWord >> goodWord) {
                m_badWords[count] = badWord;
                m_goodWords[count] = goodWord;
                ++count;
            }
        }
    }

    void SpellChecker::operator()(std::string& text) {
        for (size_t i = 0; i < STR_SIZE; ++i) {
            size_t pos = text.find(m_badWords[i]);
            while (pos != std::string::npos) {
                text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                ++m_replaceCount[i];
                pos = text.find(m_badWords[i], pos + m_goodWords[i].length());
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const {
        out << "Spellchecker Statistics\n";
        for (size_t i = 0; i < STR_SIZE; ++i) {
               out << std::setw(15) << std::right << m_badWords[i] << ": "
                   << std::left << m_replaceCount[i] << " replacements\n";
           }
    }
}
