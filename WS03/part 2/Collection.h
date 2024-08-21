// Workshop 3
// Collection.h
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include "Pair.h"
#include <cstddef>
#include <iostream>
#include <string>



namespace seneca {
	template <typename T, int CAPACITY>

	class Collection {
		T* obj;
		size_t next = 0;

	public:
		Collection() : obj(new T[CAPACITY]) {}


		virtual std::ostream& display(std::ostream& os = std::cout) const {
			os << "----------------------" << std::endl;
			os << "| Collection Content |" << std::endl;
			os << "----------------------" << std::endl;

			for (int i = 0; i < static_cast<int>(size()); i++) {
				os << obj[i] << std::endl;
			}

			os << "----------------------" << std::endl;
			return os;
		}

		virtual bool add(const T& item) {

			if (size() < CAPACITY) {
				obj[size()] = item;
				next++;
				return true;
			}
			return false;
		}

		virtual T operator[](size_t index) const {
			if (index < next) {
				return obj[index];
			}
			return T();
		}

		virtual size_t size() const {
			size_t count = 0;
			while (count < next) {
				count++;
			}
			return count;
		}

		virtual ~Collection() { delete[] obj; }
	};

	template <> class Collection<Pair, 100> {
		Pair* obj;

	public:
		Collection() : obj(new Pair[100]) {
		}

		virtual std::ostream& display(std::ostream& os = std::cout) const {
			os << "----------------------" << std::endl;
			os << "| Collection Content |" << std::endl;
			os << "----------------------" << std::endl;

			for (size_t i = 0; i < size(); i++) {
				os << obj[i];
			}

			os << "----------------------" << std::endl;
			return os;
		}

		virtual bool add(const Pair& item) {
			if (size() < 50) {
				obj[size()] = item;
				return true;
			}
			return false;
		}

		virtual Pair operator[](size_t index) const {
			if (index < 50) {
				return Pair(obj[index].getKey(), obj[index].getValue());
			}
			return Pair();
		}

		virtual size_t size() const {
			size_t count = 0;
			while (count < 50 && obj[count].getKey() != "") {
				count++;
			}
			return count;
		}

		virtual ~Collection() { delete[] obj; }
	};

}

#endif // COLLECTION_H
