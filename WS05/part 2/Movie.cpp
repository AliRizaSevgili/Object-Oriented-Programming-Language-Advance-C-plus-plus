// Workshop 5
//  Movie.cpp
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Movie.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

namespace seneca
{
      const std::string& Movie::title() const {
        return movieTitle;
      }

    std::string Movie::trim(const std::string& str) {
        auto left = std::find_if_not(str.begin(), str.end(), [](unsigned char ch) { return std::isspace(ch); });
        auto right = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char ch) { return std::isspace(ch); }).base();

        if (left >= right)
            return "";

        return std::string(left, right);
    }

    Movie::Movie(const std::string& strMovie) {
        if (!strMovie.empty()) {
            std::istringstream iss(strMovie);
            std::getline(iss, movieTitle, ',');
            movieTitle = trim(movieTitle);

            std::string yearStr;
            std::getline(iss, yearStr, ',');
            movieYear = static_cast<size_t>(std::stoi(trim(yearStr)));

            std::getline(iss, movieDescription);
            movieDescription = trim(movieDescription);
        }
    }

     std::ostream &operator<<(std::ostream &os, const Movie &src) {
        os << setw(40) << std::right << src.movieTitle << " | ";
        os << std::left << setw(4) << src.movieYear << " | "
         << src.movieDescription << endl;
        return os;
      }

}
