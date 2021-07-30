
#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_RTREE_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_RTREE_H

#include <string>
#include <vector>
#include "trip.h"
#include "neighborhood.h"
#include "point.h"
using namespace std;

class Rtree {
    string tripFileName;
    string neighborhoodFileName;
public:
    explicit Rtree(string tripFileName, string neighborhoodFileName);

    vector<Trip> sameNeighborhood();

    vector<Neighborhood> kNeighborhoodsMostTrips(int k);

    vector<Trip> beginOrEndInRegion(Point p1, Point p2);

    vector<Trip> maxDistance(Point point, double distance);
};


#endif //SPATIAL_DATA_STRUCTURES_PROJECT_RTREE_H
