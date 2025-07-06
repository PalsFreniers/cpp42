#include "PmergeMe.hpp"
#include <algorithm>
#include <pair>
#include <vector>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

PmergeMe::PmergeMe(void) {}
PmergeMe::~PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe &) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &) { return *this; }

const unsigned long long jacobsthal[] = {3, 5, 15, 17, 51, 85, 263, 433, 739, 1103, 1753, 2579, 7681, 12321};

void sortPairs(std::vector<std::pair<int, int>> &pairs) {
        for(size_t i = 0; i < pairs.size(); ++i) {
                if(pairs[i].first > pairs[i].second) {
                        int temp = pairs[i].first;
                        pairs[i].first = pairs[i].second;
                        pairs[i].second = temp;
                }
        }
}

std::vector<std::pair<int, int>> mergePairs(std::vector<std::pair<int, int>> &a, std::vector<std::pair<int, int>> &b) {
        std::vector<std::pair<int, int>> result;
        while(a.size() && b.size()) {
                if(a[0].second < b[0].second) {
                        result.push_back(a[0]);
                        a.erase(a.begin());
                } else {
                        result.push_back(b[0]);
                        b.erase(b.begin());
                }
        }
        while(a.size()) {
                result.push_back(a[0]);
                a.erase(a.begin());
        }
        while(b.size()) {
                result.push_back(b[0]);
                b.erase(b.begin());
        }
        return result;
}

std::vector<std::pair<int, int>> mergeSort(std::vector<std::pair<int, int>> &pairs) {
        if(pairs.size() == 1) {
                return pairs;
        }
        std::vector<std::pair<int, int>> left(pairs.begin(), pairs.begin() + (pairs.size() / 2));
        std::vector<std::pair<int, int>> right(pairs.begin() + (pairs.size() / 2), pairs.end());
        left = mergeSort(left);
        right = mergeSort(right);
        return mergePairs(left, right);
}

template <typename T>
int cacheExtra(T &arr) {
        int extra = -1;
        if(arr.size() % 2 != 0) {
                extra = arr.back();
                arr.pop_back();
        }
        return extra;
}

template <typename T>
void insert(T &arr, int n) {
        arr.insert(std::upper_bound(arr.begin(), arr.end(), n), n);
}

template <typename T>
std::vector<std::pair<int, int>> makePairs(T &arr) {
        std::vector<std::pair<int, int>> pairs;
        for(size_t i = 0; i < arr.size() - 1; i += 2) {
                pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
        return pairs;
}

template <typename T>
void insertPairs(T &arr, std::vector<std::pair<int, int>> &pairs) {
        for(size_t i = 0; i < pairs.size(); ++i) {
                arr.push_back(pairs[i].second);
        }
        arr.insert(arr.begin(), pairs.front().first);

        int i = 0;
        unsigned long long tmp = 0;
        unsigned long long value = jacobsthal[i];
        while(value < pairs.size()) {
                while(true) {
                        insert(arr, pairs[value].first);
                        value--;
                        if(value <= tmp) {
                                break;
                        }
                }
                tmp = jacobsthal[i];
                value = jacobsthal[++i];
        }
        while(++tmp < pairs.size()) {
                insert(arr, (pairs.begin() + tmp)->first);
        }
}

template <typename T>
void PmergeMe::sort(T &arr) {
        if(arr.size() <= 1) {
                return;
        }

        int extra = cacheExtra(arr);
        std::vector<std::pair<int, int>> pairs = makePairs(arr);
        arr.clear();
        sortPairs(pairs);
        pairs = mergeSort(pairs);
        insertPairs(arr, pairs);
        if(extra != -1) {
                insert(arr, extra);
        }
}
