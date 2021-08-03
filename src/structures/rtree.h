
#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_RTREE_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_RTREE_H

#include <string>
#include <vector>
#include "trip.h"
#include "neighborhood.h"
#include "point.h"
#include "rtree_node.h"
#include <limits.h>
using namespace std;

class Rtree {
    string tripFileName;
    string neighborhoodFileName;
    vector<Neighborhood*> neighborhoods;
    vector<Trip> commonBeginAndEndTrips;
    int m_min;
    int m_max;

    void range_search_helper(Rectangle& window_query, RNode* node, vector<Neighborhood*>& result);

public:
    RNode* root;
    explicit Rtree(string tripFileName, string neighborhoodFileName, int m_min, int m_max);

    vector<Trip> sameNeighborhood();

    vector<Neighborhood> kNeighborhoodsMostTrips(int k);

    int beginInRegion(Point p1, Point p2);

    vector<Trip> maxDistance(Point point, double distance);

    void insert(Neighborhood& neighborhood, RNode* node);

    void static_insert(vector<Neighborhood*> neighborhoods);

    Neighborhood* search(Point point, RNode* node);

    vector<Neighborhood*> range_search(Rectangle& window_query);
};


#endif //SPATIAL_DATA_STRUCTURES_PROJECT_RTREE_H
