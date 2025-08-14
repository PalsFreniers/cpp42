#include "../inc/PmergeMe.h"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
        *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
        _vector = rhs._vector;
        _deque = rhs._deque;
        return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::run(const std::string &sequence) {
        auto vecElapsed = _showSortTimed("vector", _vector, sequence);
        NEWL ENDL ENDL;
        auto decElapsed = _showSortTimed("deque", _deque, sequence);
        NEWL ENDL;
        PRINT BCYN "Time to process " CLR BOLD AND _vector.size() AND BCYN " integers" ENDL;
        PRINT BCYN "elements with " BBLU "std::vector<uint>" BCYN ": " CLR;
        PRINT BPRP AND vecElapsed AND "ns" CLR ENDL ENDL;
        PRINT BCYN "Time to process " CLR BOLD AND _deque.size() AND BCYN " integers" ENDL;
        PRINT BCYN "elements with " BBLU "std::deque<uint>" BCYN ": " CLR;
        PRINT BPRP AND decElapsed AND "ns" CLR ENDL;
}

template<typename T>
void PmergeMe::_loadSequence(const std::string &sequence, T &data) {
        errno = 0;
        for(auto it = sequence.begin(); it != sequence.end(); ++it) {
                char *end;
                auto tmp = std::strtol(it.base(), &end, 10);
                if((errno == ERANGE && tmp == LONG_MAX) || tmp > UINT_MAX) throw std::overflow_error("Number is too big");
                if((errno == ERANGE && tmp == LONG_MIN) || tmp < 0) throw std::underflow_error("Number is too small");
                if(*end != ' ' && *end != '\0') throw std::logic_error("Invalid number");
                data.push_back(static_cast<uint>(tmp));
                auto len = end - it.base();
                it += len;
        }
}

template<typename T>
void PmergeMe::_mergeInsertSort(T &data, int start, int end) {
        if(start > end) return;
        if(end - start < 10) _insertSort(data, start, end);
        else {
                auto newEnd = start + (end - start) / 2;
                _mergeInsertSort(data, start, newEnd);
                _mergeInsertSort(data, newEnd + 1, end);
                _mergeSort(data, start, newEnd, end);
        }
}

template<typename T>
void PmergeMe::_mergeSort(T &data, int start, int mid, int end) {
        auto i = 0, j = 0, k = 0;
        auto left = std::vector<uint>(mid - start + 1);
        auto right = std::vector<uint>(end - mid);
        for(; i < (mid - start + 1); ++i) left[i] = data[start + i];
        for(; j < (end - mid); ++j) right[j] = data[mid + 1 + j];
        i = 0;
        j = 0;
        k = start;
        while(i < (mid - start + 1) && j < (end - mid)) {
                if(left[i] <= right[j]) data[k] = left[i++];
                else data[k] = right[j++];
                k++;
        }
        while(i < (mid - start + 1)) data[k++] = left[i++];
        while(j < (end - mid)) data[k++] = right[j++];
}

template<typename T>
void PmergeMe::_insertSort(T &data, int start, int end) {
        for(auto i = start + 1; i <= end; ++i) {
                uint hold = data[i];
                auto j = i - 1;
                for(; j >= start && data[j] > hold; --j) data[j + 1] = data[j];
                data[j + 1] = hold;
        }
}

template<typename T>
double PmergeMe::_doSortTimed(T &container, const std::string sequence) {
        auto start = std::clock();
        _loadSequence(sequence, container);
        _mergeInsertSort(_vector, 0, container.size() - 1);
        auto end = std::clock();
        return double (end - start) / CLOCKS_PER_SEC * 1e6;
}

template<typename T>
double PmergeMe::_showSortTimed(const std::string name, T &container, const std::string sequence) {
        PRINT BOLD "Before: " BYLW AND sequence AND CLR ENDL;
        auto elapsed = _doSortTimed(container, sequence);
        PRINT BOLD "After: " BBLK "std::" AND name AND "<uint> " BGRN;
        auto it = container.begin();
        while(it != container.end()) {
                PRINT *it;
                if(++it != container.end()) PRINT " ";
        }
        return elapsed;
}
