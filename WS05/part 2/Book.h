// Workshop 5
// Book.h
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace seneca
{
  class Book
  {
    std::string bookAuthor      { "" };
    std::string bookTitle       { "" };
    std::string bookCountry     { "" };
    size_t bookYear             { 0 };
    double bookPrice            { 0.0 };
    std::string bookDescription { "" };

  public:
    Book() {}
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();
    Book(const std::string& strBook);
      
    template <typename T>
    void fixSpelling(T& spellChecker) {
      spellChecker(bookDescription);
    }
      
    /**overload the insertion operator to insert the content of a book object into an ostream object**/
    friend std::ostream& operator<<(std::ostream& os, const Book& src);
      
  private:
      void trim(std::string& src) const;
  };
}

#endif // !SDDS_BOOK_H


/**
 
 #ifndef SDDS_BOOK_H
 #define SDDS_BOOK_H

 #include <iostream>
 #include <string>

 namespace seneca
 {
   class Book
   {
     std::string b_author      { "" };
     std::string b_title       { "" };
     std::string b_country     { "" };
     size_t b_year             { 0 };
     double b_price            { 0.0 };
     std::string b_description { "" };

   public:
     Book() {}
     const std::string& title() const;
     const std::string& country() const;
     const size_t& year() const;
     double& price();
     Book(const std::string& strBook);

     template <typename T>
     void fixSpelling(T& spellChecker) {
       spellChecker(b_description);
     }

     friend std::ostream& operator<<(std::ostream& os, const Book& src);
   };
 }

 #endif // !SDDS_BOOK_H

 */
