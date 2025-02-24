#pragma once

#include <cstddef>
#include <stdexcept>
template<typename type>
class Array {
public:
        Array() : _arr(NULL), _len(0) {}

        Array(unsigned int n) : _arr(new type[n]()), _len(n) {}

        Array(const Array &other) : _arr(NULL), _len(0) {
                *this = other;
        }

        ~Array() {
                delete[] _arr;
        }

        Array &operator=(const Array &other) {
                if(_arr) delete[] _arr;
                _arr = new type[other.size()];
                for(std::size_t i = 0; i < other.size(); i++) _arr[i] = other[i];
                _len = other.size();
                return *this;
        }

        type &operator[](std::size_t i) {
                if(i < 0 || i >= _len) throw std::out_of_range("array out of bounds");
                return _arr[i];
        }

        std::size_t size() {
                return _len;
        }
private:
        type *_arr;
        std::size_t _len;
};
