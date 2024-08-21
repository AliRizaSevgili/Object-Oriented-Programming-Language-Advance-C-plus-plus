// Workshop 3 
// Set.h
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Collection.h"
#include <iostream>
#include <math.h>

#ifndef SENECA_SET_H
#define SENECA_SET_H


namespace seneca {
	template <typename T> class Set : public Collection<T, 100> {
		T* element;
		size_t counter;

	public:
		Set() : element(nullptr), counter(0) { element = new T[100]; }

		size_t size() const override {
			size_t count = 0;
			while (count < counter) {
				count++;
			}
			return count;
		}

		std::ostream& display(std::ostream& os = std::cout) const override {
			os << "----------------------" << std::endl;
			os << "| Collection Content |" << std::endl;
			os << "----------------------" << std::endl;

			for (int i = 0; (size_t)i < counter; i++) {
				os << element[i] << std::endl;
			}

			os << "----------------------" << std::endl;
			return os;
		}

		T operator[](size_t index) const override {
			if (index < 100 && index < counter) {
				return element[index];
			}
			return T();
		}

		virtual bool add(const T& item) override {

			if (counter == 0) {
				element[counter] = item;
				counter++;
				return true;
			}

			if (size() < 100) {

				bool is_repeated = false;

				for (int i = 0; static_cast<size_t>(i) < counter; i++) {
					if (item == element[i]) {
						is_repeated = true;
						break;
					}
				}

				if (!is_repeated) {
					element[counter] = item;
					counter++;
					return true;
				}
			}
			return false;
		}
		~Set() { delete[] element; }
	};

	template <> class Set<double> : public Collection<double, 100> {

		double* element;
		size_t counter;

	public:
		Set() : element(nullptr), counter(0) { element = new double[100]; }

		size_t size() const override {
			size_t count = 0;
			while (count < counter) {
				count++;
			}
			return count;
		}

		std::ostream& display(std::ostream& os = std::cout) const override {
			os << "----------------------" << std::endl;
			os << "| Collection Content |" << std::endl;
			os << "----------------------" << std::endl;

			for (int i = 0; (size_t)i < size(); i++) {
				os << element[i] << std::endl;
			}

			os << "----------------------" << std::endl;
			return os;
		}

		double operator[](size_t index) const override {
			if (index < 100 && index < counter) {
				return element[index];
			}
			return double();
		}
		virtual bool add(const double& item) override {

			if (counter == 0) {
				element[counter] = item;
				counter++;
				return true;
			}

			if (size() < 100) {

				bool is_repeated = false;

				for (int i = 0; static_cast<size_t>(i) < counter; i++) {
					if (std::fabs(item - element[i]) <= 0.01) {
						is_repeated = true;
						break;
					}
				}

				if (!is_repeated) {
					element[counter] = item;
					counter++;
					return true;
				}
			}
			return false;
		}

		~Set() { delete[] element; }
	};

	template <> class Set<Pair> : public Collection<Pair, 100> {

		Pair* element;
		size_t counter;

	public:
		Set() : element(nullptr), counter(0) {
			element = new Pair[100];
			for (int i = 0; i < 100; i++) {
				element[i] = Pair(std::string("No Key"), std::string("No Value"));
			}
		}

		size_t size() const override {
			size_t count = 0;
			while (count < counter) {
				count++;
			}
			return count;
		}

		std::ostream& display(std::ostream& os = std::cout) const override {
			os << "----------------------" << std::endl;
			os << "| Collection Content |" << std::endl;
			os << "----------------------" << std::endl;

			for (int i = 0; (size_t)i < size(); i++) {
				os << element[i] << std::endl;
			}

			os << "----------------------" << std::endl;
			return os;
		}

		Pair operator[](size_t index) const override {
			if (index < 100 && index < counter) {
				return element[index];
			}
			return Pair(std::string("No Key"), std::string("No Value"));
		}
		virtual bool add(const Pair& item) override {
			if (counter == 0) {
				element[counter] = item;
				counter++;
				return true;
			}

			if (size() < 100) {

				bool is_repeated = false;

				for (int i = 0; static_cast<size_t>(i) < counter; i++) {
					if (item == element[i]) {
						is_repeated = true;
						break;
					}
				}

				if (!is_repeated) {
					element[counter] = item;
					counter++;
					return true;
				}
			}
			return false;
		}

		~Set() { delete[] element; }
	};
}
#endif

