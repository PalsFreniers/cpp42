#include "PmergeMe.hpp"
#include <algorithm>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

PmergeMe::PmergeMe(void) {}
PmergeMe::~PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe &) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &) { return *this; }

static const unsigned long long jacobsthal[] = {
	3, 5, 15, 17, 51, 85, 263, 433, 739, 1103, 1753, 2579, 7681, 12321,
	19683, 31429, 51429, 83209, 134639, 217819, 352459, 570287, 922743, 1493031,
	2415787, 3908817, 6324593, 10233415, 16558014, 26791429, 43349443, 70140873,
	113490317, 183631191, 297121507, 480752693, 777874203, 1258626987, 2036501171,
	3295128059, 5331629117, 8626757127, 13958386247, 22585143371, 36543529615,
	59128672987, 95672202607, 154800875543, 250473078171, 405273953753, 655747031987,
	1061020985777, 1716768017757, 2777789003527, 4494557021287, 7272346024817,
	11766903046099, 19039249070927, 30806152117027, 49845401187943, 80651553304961,
	130496954492867, 211148507797807, 341645462290673, 552793970088479, 905558983171739,
	1411110671110443, 2322114855302521, 3744219512585317, 6089431616787513,
	10368130883075873, 16776177573072787, 28037546506230353, 42016644271527021,
	67989163763861033, 110008777836610191, 177997941600471491, 281594801638193567,
	457789699540639137, 735446673280834633, 1149859888336757231,
};

/**  Pairs  **/

static void sortPairs(std::vector<std::pair<int, int> > &pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first > pairs[i].second) {
            int temp = pairs[i].first;
            pairs[i].first = pairs[i].second;
            pairs[i].second = temp;
        }
    }
}

static std::vector<std::pair<int, int> > mergePairs(std::vector<std::pair<int, int> > &a, std::vector<std::pair<int, int> > &b) {
    std::vector<std::pair<int, int> > result;
    while (a.size() && b.size()) {
        if (a[0].second < b[0].second) {
            result.push_back(a[0]);
            a.erase(a.begin());
        } else {
            result.push_back(b[0]);
            b.erase(b.begin());
        }
    }
    while (a.size()) {
        result.push_back(a[0]);
        a.erase(a.begin());
    }
    while (b.size()) {
        result.push_back(b[0]);
        b.erase(b.begin());
    }
    return result;
}

static std::vector<std::pair<int, int> > mergeSort(std::vector<std::pair<int, int> > &pairs) {
    if (pairs.size() == 1) {
        return pairs;
    }
    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + (pairs.size() / 2));
    std::vector<std::pair<int, int> > right(pairs.begin() + (pairs.size() / 2), pairs.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return mergePairs(left, right);
}

template <typename T>
static int catchExtra(T &toSort) {
	int extra = -1;
	if (toSort.size() % 2 != 0) {
		extra = toSort.back();
		toSort.pop_back();
	}
	return extra;
}

template <typename T>
static void insert(T &toSort, int n) {
    toSort.insert(std::upper_bound(toSort.begin(), toSort.end(), n), n);
}

template <typename T>
static std::vector<std::pair<int, int> > buildPairs(T &toSort) {
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < toSort.size() - 1; i += 2) {
		pairs.push_back(std::make_pair(toSort[i], toSort[i + 1]));
	}
	return pairs;
}

template <typename T>
static void insertPairs(T &toSort, std::vector<std::pair<int, int> > &pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        toSort.push_back(pairs[i].second);
    }
    toSort.insert(toSort.begin(), pairs.front().first);

    int i = 0;
    unsigned long long tmp = 0;
    unsigned long long value = jacobsthal[i];
    while (value < pairs.size()) {
        while (true) {
            insert(toSort, pairs[value].first);
			value--;
			if (value <= tmp) {
                break;
            }
        }
        tmp = jacobsthal[i];
        value = jacobsthal[++i];
    }
    while (++tmp < pairs.size()) {
        insert(toSort, (pairs.begin() + tmp)->first);
    }
}

template <typename T>
void PmergeMe::sort(T &toSort) {
	if (toSort.size() <= 1) {
		return;
	}

	int extra = catchExtra(toSort);
	// Create pairs
	std::vector<std::pair<int, int> > pairs = buildPairs(toSort);
	toSort.clear();
	// sort pairs
	sortPairs(pairs);
	// merge pairs
	pairs = mergeSort(pairs);
	// insertion sort
	insertPairs(toSort, pairs);
	// add extra
	if (extra != -1) {
		insert(toSort, extra);
	}
}

// vim: set ft=cpp:
