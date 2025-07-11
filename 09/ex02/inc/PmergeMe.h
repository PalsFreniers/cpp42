#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cerrno>
#include "colors.h"
#include "printUtils.h"

#define VECTOR 0
#define DEQUE 1

typedef unsigned int uint;

class PmergeMe {
        public:
                PmergeMe();
                PmergeMe(const PmergeMe &src);
                PmergeMe &operator=(const PmergeMe &rhs);
                ~PmergeMe();

                void run(const std::string &sequence);

        private:
                template <typename T>
                void _loadSequence(const std::string &sequence, T &container);

                template <typename T>
                void _mergeInsertSort(T &container, int start, int end);

                template <typename T>
                void _mergeSort(T &container, int start, int mid, int end);

                template <typename T>
                void _insertSort(T &container, int start, int end);

                std::vector<uint> _vector;
                std::deque<uint> _deque;
};
