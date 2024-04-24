#include "Point.hpp"

struct vec2 {
        Fixed x, y;
        vec2(Fixed X, Fixed Y) : x(X), y(Y) {}
};

static int Orientation(Point a, Point b, Point c) {
        vec2 AB(b.getX() - a.getX(), b.getY() - a.getY());
        vec2 AC(c.getX() - a.getX(), c.getY() - a.getY());
        Fixed crossProduct = AB.x * AC.y - AB.y * AC.x;
        return crossProduct > 0 ? 1 : -1;
}

static int _abs(int a) {
        return a < 0 ? -a : a;
}

bool bsp(Point const a, Point const b, Point const c, Point const pt) {
        int triA = Orientation(a, b, pt) + Orientation(b, c, pt) + Orientation(c, a, pt);
        return _abs(triA) == 3;
}
