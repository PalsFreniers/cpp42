#pragma once

#include "Fixed.hpp"

class Point {
public:
        Point();
        Point(Fixed x, Fixed y);
        Point(const Point &other);
        ~Point();
        Point &operator=(const Point &other);
        Fixed getX();
        Fixed getY();
private:
        Fixed _x;
        Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const pt);
