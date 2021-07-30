#include <string>
#include <utility>
#include "rtree.h"

Rtree::Rtree(string fileName) : fileName(std::move(fileName)) {}

vector<Trip> Rtree::sameNeighborhood() {
    return vector<Trip>();
}

vector<Neighborhood> Rtree::kNeighborhoodsMostTrips(int k) {
    return vector<Neighborhood>();
}

vector<Trip> Rtree::beginOrEndInRegion(Point p1, Point p2) {
    return vector<Trip>();
}

vector<Trip> Rtree::maxDistance(Point point, double distance) {
    return vector<Trip>();
}
