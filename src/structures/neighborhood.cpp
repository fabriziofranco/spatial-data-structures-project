
#include "neighborhood.h"

Neighborhood::Neighborhood(vector<Point> points){
    this->edges= points;

    double min_x, min_y, max_x, max_y;
    min_x = min_y = INT_MAX;
    max_x = max_y = INT_MIN;

    for (Point &point: points) {
        if (point.getLatitude() < min_x) min_x = point.getLatitude();
        if (point.getLongitud() < min_y) min_y = point.getLongitud();
        if (point.getLatitude() > max_x) max_x = point.getLatitude();
        if (point.getLongitud() > max_y) max_y = point.getLongitud();
    }

    this->_mbr = Rectangle(Point(min_x, min_y), Point(max_x, max_y));
}

Rectangle Neighborhood::getMBR() {
    return this->_mbr;
}

Neighborhood::Neighborhood() {}
