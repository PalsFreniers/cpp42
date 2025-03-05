#include "Span.hpp"

template <typename T>
void Span::addNumbers(const typename T::const_iterator begin, const typename T::const_iterator end) {
	unsigned int csize = filled;
	csize += std::distance(begin, end);
	if (csize > size)
		throw std::length_error("Span::addNumbers: numbers vector is too small");
	numbers.insert(numbers.end(), begin, end);
	filled = csize;
}

// vim: set ft=cpp:
