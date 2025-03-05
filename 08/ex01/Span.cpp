#include "Span.hpp"
#include <algorithm>
#include <limits.h>

Span::Span(void): numbers(std::vector<int>()), size(0), filled(0) {}
Span::Span(unsigned int n): numbers(std::vector<int>(0)), size(n), filled(0) {}
Span::~Span(void) {}
Span::Span(Span &copy) { *this = copy; }

Span& Span::operator=(const Span& x) {
	if (this != &x) {
		numbers = x.numbers;
		size = x.size;
		filled = x.filled;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (filled == size)
		throw std::length_error("Span::addNumber: span is too small");
	numbers.push_back(n);
	filled++;
}

int Span::shortestSpan() {
	if (filled < 2)
		throw std::out_of_range("Span::shortestSpan: span is too small");
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	int shortest = INT_MAX;
	for (int i = 1; i < (int)sorted.size(); i++) {
		int span = sorted[i] - sorted[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

int Span::longestSpan(void) {
	if (filled < 2)
		throw std::out_of_range("Span::longestSpan: span is too small");
	std::vector<int>::const_iterator min = std::min_element(numbers.begin(), numbers.end());
	std::vector<int>::const_iterator max = std::max_element(numbers.begin(), numbers.end());
	return (*max - *min);
}

std::vector<int> const& Span::getNumbers(void) const {
	return numbers;
}

unsigned int Span::getFilled(void) const {
	return filled;
}

std::ostream& operator<<(std::ostream& os, const Span& x) {
	os << "Span(size=" << x.getFilled() << ", nums=[";
	std::vector<int> const& numbers = x.getNumbers();
	for (unsigned int i = 0; i < numbers.size(); i++) {
		os << numbers[i];
		if (i != numbers.size() - 1)
			os << ", ";
	}
	std::cout << "])" << std::endl;
	return os;
}
