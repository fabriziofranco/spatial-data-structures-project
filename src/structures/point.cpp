
#include "point.h"

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

Point::Point(double x, double y) : x(x), y(y) {}
