
#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_NEIGHBORHOOD_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_NEIGHBORHOOD_H

///longitud , latitud en el json

#include "trip.h"
#include <set>
#include "point.h"
#include <vector>
#include "rectangle.h"
#include <limits.h>
#include <string>

using namespace std;

class Neighborhood {
    string name;
    Rectangle _mbr;
    multiset<Trip> begin_here;
    multiset<Trip> end_here;
    vector<Point> edges;
    long total_trips=0;
public:
    Rectangle getMBR();
    Neighborhood(vector<Point> points,string nombre);
    Neighborhood();
    string getName(){ return this->name; }
    void addBeginHere(Trip trip){
        begin_here.insert(trip);
    }

    void addEndHere(Trip trip){
        end_here.insert(trip);
    }

    void addTotalTrip(){total_trips++;}

};


#endif //SPATIAL_DATA_STRUCTURES_PROJECT_NEIGHBORHOOD_H
