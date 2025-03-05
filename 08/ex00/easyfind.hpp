#pragma once

#include <stdexcept>
#include <algorithm>
template<typename T>
typename T::iterator easyfind(T &arr, int val) {
        typename T::iterator it = std::find(arr.begin(), arr.end(), val);
        if(it == arr.end()) throw std::runtime_error("unable to find value");
        return it;
}
