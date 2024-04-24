#include "Point.hpp"
#include <iostream>

int main() {
        {
                Point a = Point(1, 1);
                Point b = Point(4, 1);
                Point c = Point(3, 4);

                Point pt = Point(2, 2);
                std::cout << "the point {2; 2} is in triangle :[{1, 1}, {4, 1}, {3, 4}] : " << std::boolalpha << bsp(a, b, c, pt) << std::noboolalpha << std::endl;
        }
        {
                Point a = Point(1, 1);
                Point b = Point(4, 1);
                Point c = Point(3, 4);

                Point pt = Point(2, 2.6f);
                std::cout << "the point {2; 2.6} is in triangle :[{1, 1}, {4, 1}, {3, 4}] : " << std::boolalpha << bsp(a, b, c, pt) << std::noboolalpha << std::endl;
        }
        {
                Point a = Point(1, 1);
                Point b = Point(4, 1);
                Point c = Point(3, 4);

                Point pt = Point(-2, 2);
                std::cout << "the point {-2; 2} is in triangle :[{1, 1}, {4, 1}, {3, 4}] : " << std::boolalpha << bsp(a, b, c, pt) << std::noboolalpha << std::endl;
        }
        {
                Point a = Point(1, 1);
                Point b = Point(4, 1);
                Point c = Point(3, 4);

                Point pt = Point(3.5f, 1.5f);
                std::cout << "the point {3.5; 1.5} is in triangle :[{1, 1}, {4, 1}, {3, 4}] : " << std::boolalpha << bsp(a, b, c, pt) << std::noboolalpha << std::endl;
        }
}
