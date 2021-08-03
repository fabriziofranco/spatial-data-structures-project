#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_RTREE_NODE_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_RTREE_NODE_H

#include <vector>
#include "rectangle.h"
#include "neighborhood.h"

class RNode {
public:
    RNode(bool isLeaf):_isLeaf(isLeaf){}

    bool addNeighborhood(Neighborhood& neighborhood, int& max_m){
        if(_neighborhoods.size() < max_m) {
            _neighborhoods.push_back(neighborhood);
            return true;
        }
        return false;
    }

    bool addChild(RNode* child, int& max_m) {
        if(_children.size() < max_m) {
            _children.push_back(child);
            return true;
        }
        return false;
    }

    std::vector<RNode*> getChildren(){
        return _children;
    }

    std::vector<Neighborhood> getNeighborhoods(){
        return _neighborhoods;
    }

    bool isLeaf() {
        return this->_isLeaf;
    }

    Rectangle getMBR() {
        return this->_mbr;
    }

    void setMBR(Rectangle newMBR) {
        this->_mbr = newMBR;
    }

private:
    std::vector<Neighborhood> _neighborhoods;
    bool _isLeaf;

    std::vector<RNode*> _children;
    Rectangle _mbr;
};

#endif
