#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + 5);
    int arr2[] = {10, 20, 30, 40};
    std::list<int> lst(arr2, arr2 + 4);
    int arr3[] = {100, 200, 300};
    std::deque<int> deq(arr3, arr3 + 3);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        if (it != vec.end()) {
            std::cout << "Found: " << *it << " in vector" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 25);
        if (it != lst.end()) {
            std::cout << "Found: " << *it << " in list" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::deque<int>::iterator it = easyfind(deq, 200);
        if (it != deq.end()) {
            std::cout << "Found: " << *it << " in deque" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
