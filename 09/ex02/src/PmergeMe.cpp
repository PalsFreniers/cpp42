
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
        PRINT BOLD "Before: " BYLW AND sequence AND CLR ENDL;
        double elapsedV, elapsedD;

        {
                std::clock_t start = std::clock();
                _loadSequence(sequence, _vector);
                _mergeInsertSort(_vector, 0, _vector.size() - 1);
                std::clock_t end = std::clock();
                elapsedV = (double)(end - start) / CLOCKS_PER_SEC * 1e6;
                PRINT BOLD "After: " BBLK "std::vector<uint> " BGRN;
                for(std::vector<uint>::const_iterator it = _vector.begin(); it != _vector.end() ; ++it) {
                        PRINT *it;
                        if(it + 1 != _vector.end()) PRINT " ";
                }
                NEWL;
        }
        NEWL;
        NEWL;
        {
                std::clock_t start = std::clock();
                _loadSequence(sequence, _deque);
                _mergeInsertSort(_deque, 0, _deque.size() - 1);
                std::clock_t end = std::clock();
                elapsedD = (double)(end - start) / CLOCKS_PER_SEC * 1e6;
                PRINT BOLD "After: " BBLK "std::deque<uint> " BGRN;
                for(std::deque<uint>::const_iterator it = _deque.begin(); it != _deque.end() ; ++it) {
                        PRINT *it;
                        if(it + 1 != _deque.end()) PRINT " ";
                }
                NEWL;
        }

        NEWL;
        PRINT BCYN "Time to process " CLR BOLD AND _vector.size() AND BCYN " integers" ENDL;
        PRINT BCYN " elements with " BBLU "std::vector<uint>" BCYN ": " CLR;
        PRINT BPRP AND elapsedV AND "ns" CLR ENDL;
        NEWL;
        PRINT BCYN "Time to process " CLR BOLD AND _deque.size() AND BCYN " integers" ENDL;
        PRINT BCYN " elements with " BBLU "std::deque<uint>" BCYN ": " CLR;
        PRINT BPRP AND elapsedD AND "ns" CLR ENDL;
}

template<typename T>
void PmergeMe::_loadSequence(const std::string &sequence, T &data) {
        long tmp;
        char *end;

        errno = 0;
        for(std::string::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
                tmp = std::strtol(it.base(), &end, 10);
                if((errno == ERANGE && tmp == LONG_MAX) || tmp > UINT_MAX) throw std::overflow_error("Number is too big");
                if((errno == ERANGE && tmp == LONG_MIN) || tmp < 0) throw std::underflow_error("Number is too small");
                if(*end != ' ' && *end != '\0') throw std::logic_error("Invalid number");
                data.push_back(static_cast<uint>(tmp));
                while(*it != *end) ++it;
        }
}

template<typename T>
void PmergeMe::_mergeInsertSort(T &data, int start, int end) {
        int newEnd;

        if(start > end) return ;
        if(end - start < 10) _insertSort(data, start, end);
        else {
                newEnd = start + (end - start) / 2;
                _mergeInsertSort(data, start, newEnd);
                _mergeInsertSort(data, newEnd + 1, end);
                _mergeSort(data, start, newEnd, end);
        }
}

template<typename T>
void PmergeMe::_mergeSort(T &data, int start, int mid, int end) {
        int i, j, k;

        std::vector<uint> left(mid - start + 1);
        std::vector<uint> right(end - mid);
        for(i = 0; i < (mid - start + 1); ++i) left[i] = data[start + i];
        for(j = 0; j < (end - mid); ++j) right[j] = data[mid + 1 + j];
        i = 0;
        j = 0;
        k = start;
        while(i < (mid - start + 1) && j < (end - mid)) {
                if(left[i] <= right[j]) data[k] = left[i++];
                else data[k] = right[j++];
                k++;
        }

        while(i < (mid - start + 1)) data[k++] =  left[i++];

        while(j < (end - mid)) data[k++] = right[j++];
}

template<typename T>
void PmergeMe::_insertSort(T &data, int start, int end) {
        for(int i = start + 1; i <= end; ++i) {
                uint hold = data[i];
                int j = i - 1;
                for(; j >= start && data[j] > hold; --j) data[j + 1] = data[j];
                data[j + 1] = hold;
        }
}
