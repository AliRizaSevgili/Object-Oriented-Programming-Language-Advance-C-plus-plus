// Workshop 5
// Movie.h
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>

namespace seneca
{
  class Movie
  {
    std::string movieTitle       { "" };
    size_t movieYear             { 0u };
    std::string movieDescription { "" };

  public:
    Movie(){}
    const std::string &title() const;
    Movie(const std::string& strMovie);

    template <typename T>
    void fixSpelling(T& spellChecker) {
      spellChecker(movieTitle);
      spellChecker(movieDescription);
    }

    friend std::ostream& operator<<(std::ostream& os, const Movie& src);
      
  private:
      static std::string trim(const std::string& str);
  };
}
#endif // !SDDS_MOVIE_H
