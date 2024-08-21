// Workshop 5
// Collection.h
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

namespace seneca {
    template <typename T>
    class Collection {
        T* itemCollection { nullptr };
        std::string collectionName { "" };
        size_t noOfCollection { 0 };
        void (*c_observer)(const Collection<T>&, const T&) { nullptr };

    public:
        Collection(const std::string& name) : collectionName(name) {}
        Collection(const Collection&) = delete;
        Collection& operator=(const Collection&) = delete;

        ~Collection() {
            delete[] itemCollection;
        }

        const std::string& name() const {
            return collectionName;
        }

        size_t size() const {
            return noOfCollection;
        }

        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            c_observer = observer;
        }

        Collection<T>& operator+=(const T& item) {
            for (size_t i = 0; i < noOfCollection; ++i) {
                if (itemCollection[i].title() == item.title()) {
                    return *this;
                }
            }

            T* temp = nullptr;
            try {
                temp = new T[noOfCollection + 1];
            } catch (const std::bad_alloc&) {
                std::cerr << "Failed to allocate memory for new item in collection." << std::endl;
                return *this;
            }

            for (size_t i = 0; i < noOfCollection; ++i) {
                temp[i] = itemCollection[i];
            }
            
            temp[noOfCollection] = item;
            delete[] itemCollection;
            itemCollection = temp;
            ++noOfCollection;

            if (c_observer) {
                c_observer(*this, item);
            }
            return *this;
        }

        T& operator[](size_t idx) const {
            if (idx >= noOfCollection) {
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(noOfCollection) + "] items.");
            }
            return itemCollection[idx];
        }
        
        T* operator[](const std::string& title) const {
            auto it = std::find_if(itemCollection, itemCollection + noOfCollection, [&title](const T& item) {
                return item.title() == title;
            });

            if (it != itemCollection + noOfCollection) {
                return &*it;
            }
            return nullptr;
        }
        
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& src) {
        for (size_t i = 0; i < src.size(); ++i) {
            os << src[i];
        }
        return os;
    }
}

#endif


/**
 #ifndef SDDS_COLLECTION_H
 #define SDDS_COLLECTION_H

 #include <iostream>
 #include <string>
 #include <stdexcept> // For std::out_of_range

 namespace seneca {
     template <typename T>
     class Collection {
         T* c_item { nullptr };
         std::string c_name { "" };
         size_t c_numOfCol { 0 };
         void (*c_observer)(const Collection<T>&, const T&) { nullptr };

     public:
         Collection(const std::string& name) : c_name(name) {}
         Collection(const Collection&) = delete;
         Collection& operator=(const Collection&) = delete;

         ~Collection() {
             delete[] c_item;
         }

         const std::string& name() const {
             return c_name;
         }

         size_t size() const {
             return c_numOfCol;
         }

         void setObserver(void (*observer)(const Collection<T>&, const T&)) {
             c_observer = observer;
         }

         Collection<T>& operator+=(const T& item) {
             // Check for existing item
             for (size_t i = 0; i < c_numOfCol; ++i) {
                 if (c_item[i].title() == item.title()) {
                     return *this; // Item already exists, do not add
                 }
             }

             // Add new item
             T* temp = new T[c_numOfCol + 1];
             for (size_t i = 0; i < c_numOfCol; ++i) {
                 temp[i] = c_item[i];
             }
             temp[c_numOfCol] = item;
             delete[] c_item;
             c_item = temp;
             ++c_numOfCol;

             // Notify observer if set
             if (c_observer) {
                 c_observer(*this, item);
             }

             return *this;
         }
         
         T& operator[](size_t idx) const {
             if (idx >= c_numOfCol) {
                 throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_numOfCol) + "] items.");
             }
             return c_item[idx];
         }
         
         T* operator[](const std::string& title) const {
             for (size_t i = 0; i < c_numOfCol; ++i) {
                 if (c_item[i].title() == title) {
                     return &c_item[i];
                 }
             }
             return nullptr; // No item found
         }
     };

     template<typename T>
     std::ostream& operator<<(std::ostream& os, const Collection<T>& src) {
         for (size_t i = 0; i < src.size(); ++i) {
             os << src[i];
         }
         return os;
     }
 }

 #endif // SDDS_COLLECTION_H


 */

