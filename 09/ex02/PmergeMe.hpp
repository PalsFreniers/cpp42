#include <iostream>
#include <string>

class PmergeMe {
private:
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);

public:
	template <typename T>
	static void sort(T &toSort);
};
