
#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_TRIP_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_TRIP_H

#include "point.h"

class Trip {
    Point Pickup;
    Point Dropoff;
    double distance;

public:
    Trip(Point p1, Point p2, double distancia) : Pickup(p1), Dropoff(p2), distance(distancia){}
    Point getPickup() { return Pickup; }
    Point getDropoff() { return Dropoff; }
};


#endif //SPATIAL_DATA_STRUCTURES_PROJECT_TRIP_H
