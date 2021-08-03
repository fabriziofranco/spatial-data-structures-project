#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_RTREE_NODE_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_RTREE_NODE_H

#include <vector>
#include "rectangle.h"

class RNode {
public:
    RNode(bool isLeaf):_isLeaf(isLeaf){}

    bool add(Point p, int &max_m){
        if(_points.size() < max_m) {
            _points.push_back(p);
            return true;
        }
        return false;
    }

    std::vector<RNode*> getChildren(){
        return _children;
    }

    std::vector<Point> getPoints(){
        return _points;
    }

private:
    std::vector<Point> _points;
    bool _isLeaf;

    std::vector<RNode*> _children;
    std::vector<Rectangle> _mbrs;
};

#endif
