#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_RECTANGLE_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_RECTANGLE_H

#include "point.h"
#include "rectangle.h"
struct Rectangle{
    Rectangle(Point min, Point max):_min(min),_max(max){}
    Point _min;
    Point _max;

    bool contains(Point point) const{
        return _min.getLatitude() <= point.getLatitude() && _min.getLongitud() <= point.getLongitud() &&
                _max.getLatitude() >= point.getLatitude() && _max.getLongitud() >= point.getLongitud();
    }

    bool contains(Rectangle rectangle) const {
        return this->contains(rectangle._min) && this->contains(rectangle._max);
    }

    double getArea() {
        return (this->_max.getLatitude() - this->_min.getLatitude()) * (this->_max.getLongitud() - this->_min.getLongitud());
    }

};

#endif
