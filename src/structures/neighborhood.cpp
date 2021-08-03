
#include "neighborhood.h"

Neighborhood::Neighborhood(vector<Point> points){
    this->edges= points;
}

Rectangle Neighborhood::getMBR() {
    return this->_mbr;
}
