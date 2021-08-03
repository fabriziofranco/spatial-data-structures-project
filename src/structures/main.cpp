#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "rtree.h"
#include "rtree_node.h"
#include "rectangle.h"
#include "point.h"

using namespace std;

int main() {
    Rtree rtree("../data/green_tripdata_2015-01.csv", "../data/neighborhood.json", 1, 4);

    // rtree.beginInRegion(Point(2.2, 3.2), Point(1.2, 2.2));
    // Neighborhood* n1 = rtree.search(Point(40.7759399414063, -73.9108276367188), rtree.root);
    // Neighborhood* n2 = rtree.search(Point(40.6909942626953, -73.9548187255859), rtree.root);
    // Neighborhood* n3 = rtree.search(Point(40.6973114013672, -73.9355697631836), rtree.root);
    // cout << "name 1: " << n1->getName() << "\n";
    // cout << "name 2: " << n2->getName() << "\n";
    // cout << "name 3: " << n3->getName() << "\n";
    
    cout << "consulta 1"
    rtree.sameNeighborhood();
    rtree.kNeighborhoodsMostTrips(5);
    rtree.beginInRegion(Point(40.773754119873047, -73.907257080078125), Point(40.691108703613281, -73.991691589355469));
    return 0;
}