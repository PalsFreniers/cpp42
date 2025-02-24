#pragma once

#include <cstddef>
#include <iostream>

#define auto __auto_type

template<typename type>
void iter(type *arr, std::size_t arrLen, void(*fn)(type)) {
       for(std::size_t i = 0; i < arrLen; i++) fn(arr[i]); 
}

template <typename T>
void print_normal(T a)
{
	std::cout << a << std::endl;
}
