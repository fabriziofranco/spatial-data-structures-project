
#include "point.h"

Point::Point(double latitude, double longitud) : latitude(latitude), longitud(longitud) {}

double Point::getLatitude() const {
    return latitude;
}

double Point::getLongitud() const {
    return longitud;
}

// Point Point::minBetweenPoints(Point& p1, Point& p2) {
//     if (p1.getLatitude() < p2.getLatitude() && p1.getLongitud() < p2.getLongitud()) {
//         return p1;
//     } else if (p1.getLatitude() > p2.getLatitude() && p1.getLongitud() > p2.getLongitud()) {
//         return p2;
//     } else if (p1.getLatitude() == p2.getLatitude()) {
//         if (p1.getLongitud() < p2.getLongitud()) {
//             return p1;
//         } else {
//             return p2;
//         }
//     } else
// }

// Point Point::maxBetweenPoints(Point& p1, Point& p2) {

// }
