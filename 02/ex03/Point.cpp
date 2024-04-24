#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {}

Point::Point(const Point &other) {
        *this = other;
}

Point::~Point() {}

Point &Point::operator=(const Point &other) {
        _x = other._x;
        _y = other._y;
        return *this;
}

Fixed Point::getX() {
        return _x;
}

Fixed Point::getY() {
        return _y;
}
