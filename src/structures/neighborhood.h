
#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_NEIGHBORHOOD_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_NEIGHBORHOOD_H

///longitud , latitud en el json

#include "trip.h"
#include <set>
#include "point.h"
#include <vector>
#include "rectangle.h"
#include <limits.h>

using namespace std;

class Neighborhood {
    Rectangle _mbr;
    multiset<Trip> begin_here;
    multiset<Trip> end_here;
    vector<Point> edges;

public:
    Rectangle getMBR();
    Neighborhood(vector<Point> points);
    Neighborhood();
};


#endif //SPATIAL_DATA_STRUCTURES_PROJECT_NEIGHBORHOOD_H
