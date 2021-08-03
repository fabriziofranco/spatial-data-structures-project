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

    rtree.beginOrEndInRegion(Point(2.2, 3.2), Point(1.2, 2.2));
 
    return 0;
}