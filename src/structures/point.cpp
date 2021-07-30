
#include "point.h"

Point::Point(double latitude, double longitud) : latitude(latitude), longitud(longitud) {}

double Point::getLatitude() const {
    return latitude;
}

double Point::getLongitud() const {
    return longitud;
}
