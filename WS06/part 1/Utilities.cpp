
// Workshop 6
// Utilities.cpp
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Employee.h"
#include "Utilities.h"
#include <string>
#include <sstream>
namespace seneca {
	Person* buildInstance(std::istream& in) {
		std::string line{};
		std::stringstream tempVar{};
		Person* personPtr{};
		getline(in, line, '\n');
		tempVar << line;
		if (line[0] == 'e' || line[0] == 'E')
		{
			personPtr = new Employee(tempVar);
		}
		/*
		else if (line[0] == 's' || line[0] == 'S') {
			personPtr = new Student(tempStream);
		}
		else if (line[0] == 'p' || line[0] == 'P') {
			personPtr = new Professor(tempStream);
		}
		 */
		else
		{
			personPtr = nullptr;
		}

		return personPtr;
	}
	bool isDigit(std::string& src) {
		auto begin = src.begin();
		while (begin != src.end() && std::isdigit(*begin)) {
			++begin;
		}
		return !src.empty() && begin == src.end();
	}
	std::string& trim(std::string& src) {
		bool valid = false;

		while (!valid)
		{
			if (src[0] == ' ')
			{
				src.erase(0, src.find_first_not_of(' '));
			}
			else if (src[src.length() - 1] == ' ')
			{
				src.erase(src.find_last_not_of(' ') + 1);
			}
			else
			{
				valid = true;
			}
		}
		return src;
	}
}
