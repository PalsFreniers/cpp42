#include "PmergeMe.tpp"
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <sys/time.h>

static bool parseArgs(int argc, char **argv, std::vector<int> &vecToSort, std::deque<int> &dqToSort) {
	for (int i = 1; i < argc; i++) {
		char *end;
		int nb = std::strtol(argv[i], &end, 10);
		if (*end != '\0' || errno == ERANGE || i > INT_MAX || i < 0) {
			std::cerr << "Error: invalid number: " << argv[i] << std::endl;
			return false;
		}

		vecToSort.push_back(nb);
		dqToSort.push_back(nb);
	}
	return true;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <numbers>..." << std::endl;
		return 1;
	}

	std::vector<int> vecToSort;
	std::deque<int> dqToSort;

	if (!parseArgs(argc, argv, vecToSort, dqToSort)) {
		return 1;
	}

	std::cout << "Before:  ";
	for (int i = 1; i < argc; i++) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	timeval start, end;
	long nsvec, nsDq;

	gettimeofday(&start, NULL);
	PmergeMe::sort(vecToSort);
	gettimeofday(&end, NULL);
	nsvec = 1000000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	PmergeMe::sort(dqToSort);
	gettimeofday(&end, NULL);
	nsDq = 1000000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

	std::cout << "After:   ";
	int last = -1;
	int i = 0;
	while (!vecToSort.empty()) {
		int vecTop = vecToSort.front();
		vecToSort.erase(vecToSort.begin());
		int dqTop = dqToSort.front();
		dqToSort.pop_front();
		if (vecTop != dqTop) {
			std::cerr << "Error: vecToSort[" << i << "] = " << vecTop << ", dqToSort[" << i << "] = " << dqTop << std::endl;
			return 1;
		}
		if (vecTop < last) {
			std::cerr << "Error: vecToSort[" << i << "] = " << vecTop << ", last = " << last << std::endl;
			return 1;
		}
		last = vecTop;
		i++;
		std::cout << vecTop << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process " << argc - 1 << " elements (std::vector<int>): " << nsvec << " ns" << std::endl;
	std::cout << "Time to process " << argc - 1 << " elements (std::deque<int>): " << nsDq << " ns" << std::endl;
	return 0;
}
