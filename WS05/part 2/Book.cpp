// Workshop 5
// Book.cpp
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <algorithm>
#include <cctype>
#include <iomanip>
#include "Book.h"

using namespace std;

namespace seneca
{
  const std::string& Book::title() const {
    return bookTitle;
  }

  const std::string& Book::country() const {
    return bookCountry;
  }

  const size_t& Book::year() const {
    return bookYear;
  }

  double& Book::price() {
    return bookPrice;
  }

Book::Book(const std::string& strBook) {
        std::istringstream bookStream(strBook);
        std::getline(bookStream, bookAuthor, ',');
        std::getline(bookStream, bookTitle, ',');
        std::getline(bookStream, bookCountry, ',');
        std::string part;
        std::getline(bookStream, part, ',');
        bookPrice = std::stod(part);
        std::getline(bookStream, part, ',');
        bookYear = std::stod(part);
        std::getline(bookStream, bookDescription);

        trim(bookAuthor);
        trim(bookTitle);
        trim(bookCountry);
        trim(bookDescription);
    }

    void seneca::Book::trim(std::string& src) const {
        src.erase(src.begin(), std::find_if(src.begin(), src.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        src.erase(std::find_if(src.rbegin(), src.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), src.end());
    }

  std::ostream& operator<<(std::ostream& os, const Book& src) {
    os << setw(20) << std::right << src.bookAuthor << " | ";
    os << setw(22) << src.title() << " | ";
    os << setw(5) << src.country() << " | ";
    os << setw(4) << src.year() << " | ";
    os << setw(6) << fixed << setprecision(2) << src.bookPrice << " | ";
    os << std::left << src.bookDescription << endl;

    return os;
  }
}
