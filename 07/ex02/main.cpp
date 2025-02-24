#include <iostream>
#include "Array.hpp"

int main() {
        Array<int> arr(100);
        for(std::size_t i = 0; i < arr.size(); i++) if(arr[i] != 0)std::cout << arr[i] << std::endl;
        return 0;
}
