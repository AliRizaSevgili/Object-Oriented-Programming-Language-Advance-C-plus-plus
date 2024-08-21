// Workshop 2
// StringSet.h
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <iostream>
#include <string>

namespace seneca
{
    class StringSet
    {
        size_t s_CurRecord{ 0u };
        std::string* s_str{ nullptr };

    public:
        StringSet() {}
        StringSet(const char* _filename);           
        ~StringSet();
        StringSet(const StringSet& src);            
        StringSet& operator=(const StringSet& src); 
        StringSet(StringSet&& src);                 
        StringSet& operator=(StringSet&& src);      

        size_t size() const;
        std::string operator[](size_t) const;
    };
}
#endif // SENECA_STRINGSET_H