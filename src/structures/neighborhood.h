
#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_NEIGHBORHOOD_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_NEIGHBORHOOD_H

///longitud , latitud en el json

#include "trip.h"
#include <set>
#include "point.h"
#include <vector>

using namespace std;

class Neighborhood {
    //MBR
    multiset<Trip> begin_here;
    multiset<Trip> end_here;



    Neighborhood(vector<Trip> trips, vector<Point> points);
};


#endif //SPATIAL_DATA_STRUCTURES_PROJECT_NEIGHBORHOOD_H
