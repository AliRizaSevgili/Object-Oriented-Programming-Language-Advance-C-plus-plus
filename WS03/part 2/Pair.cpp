// Workshop 3
// Pair.cpp
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_PAIR_CPP
#define SENECA_PAIR_CPP

#include "Pair.h"
#include <iomanip>
#include <iterator>
#include <ostream>



namespace seneca {
	Pair::Pair() : m_key(std::string()), m_value(std::string()) {}
	Pair::Pair(const std::string& key, const std::string& value)
		: m_key(key), m_value(value) {}

	std::ostream& operator<<(std::ostream& os, const Pair& p) {
		os << std::setw(20) << p.getKey() << ": " << p.getValue();
		return os;
	}

	bool Pair::operator==(const Pair& rhs) const {
		return getKey() == rhs.getKey();
	}

	const std::string& Pair::getKey() const {
		return m_key;
	};

	const std::string& Pair::getValue() const {

		return m_value;
	};
}

#endif