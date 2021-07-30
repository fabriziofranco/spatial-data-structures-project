#include "rtree.h"
using namespace std;
int main(){
    Rtree rtree("data/green_tripdata_2015-01.csv");


    rtree.beginOrEndInRegion(Point(2.2, 3.2), Point(1.2, 2.2));
    return 0;
}