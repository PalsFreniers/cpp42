#pragma once

template<typename type>
void swap(type &a, type &b) {
        type tmp = a;
        a = b;
        b = tmp;
}

template<typename type>
type min(type a, type b) {
        return a < b ? a : b;
}

template<typename type>
type max(type a, type b) {
        return a > b ? a : b;
}
