// Workshop 3 
// Pair.h
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <cstdlib>
#include <string>



namespace seneca {
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() const;
		const std::string& getValue() const;

		Pair(const std::string& key, const std::string& value);
		Pair();

		bool operator==(const Pair&)const;
		friend std::ostream& operator<<(std::ostream&, const Pair&);
	};

}

#endif // PAIR_H

