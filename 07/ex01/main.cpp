#include "iter.hpp"
#include <iostream>
#include <string>

void printToLower(std::string str)
{
	for (auto it = str.begin(); it != str.end(); it++)
		std::cout << (char)tolower(*it);
	std::cout << std::endl;
}

void printToUpper(std::string str)
{
	for (auto it = str.begin(); it != str.end(); it++)
		std::cout << (char)toupper(*it);
	std::cout << std::endl;
}

int main()
{
	std::string strings[] = {"One", "Two", "Three", "Four"};

	std::cout << "Normal: " << std::endl;
	::iter(strings, 4, print_normal<std::string>);
	std::cout << "To Upper: " << std::endl;
	::iter(strings, 4, printToUpper);
	std::cout << "To Lower: " << std::endl;
	::iter(strings, 4, printToLower);

	float floats[] = {1.23, 4.56, 7.89};

	std::cout << "Floats: " << std::endl;
	::iter(floats, 3, print_normal<float>);
}
