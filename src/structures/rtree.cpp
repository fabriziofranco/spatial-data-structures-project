#include <string>
#include <utility>
#include "rtree.h"
#include <fstream>
#include <utility>
#include <vector>
#include <iostream>

#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>


Rtree::Rtree(string tripFileName, string neighborhoodFileName, int m_min, int m_max):
tripFileName(tripFileName),neighborhoodFileName(neighborhoodFileName), m_min(m_min), m_max(m_max) {

    // inicializar árbol
    this->root = new RNode(true);
    // end inicializar árbol
    vector<Neighborhood> neighborhoods;
    ifstream ifs(neighborhoodFileName);
    Json::Reader reader;
    Json::Value val;

    if (!reader.parse(ifs, val)) {
        cout<<"Error reading the document";
    }

    int sz = val.size();
    // cout<<sz<<endl;
    for (int i = 0; i < sz; ++i) {
        vector<Point> points;
        Json::Value puntos= val[i]["geometry"]["coordinates"];
        string nombre = val[i]["properties"]["neighborhood"].asString();
        for(int j=0; j < puntos[0].size(); ++j) {
            points.push_back(Point(puntos[0][j][1].asDouble(),puntos[0][j][0].asDouble()));
        }

        Neighborhood barrio(points, nombre);
        neighborhoods.push_back(barrio);
    }

    this->static_insert(neighborhoods);
}

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

void Rtree::static_insert(vector<Neighborhood> neighborhoods) {
    // generar nodos hoja
    RNode* temp = new RNode(true);
    vector<RNode*> nodes;
    temp->addNeighborhood(neighborhoods.front(), m_max);
    temp->setMBR(neighborhoods.front().getMBR());
    neighborhoods.erase(neighborhoods.begin());
    while (neighborhoods.size() > 0) {
        // find best neighborhood to merge with
        Neighborhood best_nh;
        int best_area = INT_MAX;
        Rectangle best_new_mbr;
        int best_nh_pos = 0;
        for (int i = 0; i < neighborhoods.size(); ++i) {
            Neighborhood current_nh = neighborhoods[i];
            Rectangle new_mbr(
                Point(
                    min(temp->getMBR()._min.getLatitude(), current_nh.getMBR()._min.getLatitude()),
                    min(temp->getMBR()._min.getLongitud(), current_nh.getMBR()._min.getLongitud())
                ),
                Point(
                    max(temp->getMBR()._max.getLatitude(), current_nh.getMBR()._max.getLatitude()),
                    max(temp->getMBR()._max.getLatitude(), current_nh.getMBR()._max.getLatitude())
                )
            );
            if (new_mbr.getArea() < best_area) {
                best_nh = current_nh;
                best_new_mbr = new_mbr;
                best_nh_pos = i;
                best_area = new_mbr.getArea();
            }
        }
        // update mbr and addNeighborhood sibling
        if (!temp->addNeighborhood(best_nh, m_max)) {
            RNode* new_leaf = new RNode(true);
            *new_leaf = *temp;
            nodes.push_back(new_leaf);
            temp = new RNode(true);
            temp->addNeighborhood(best_nh, m_max);
            temp->setMBR(best_nh.getMBR());
        } else {
            temp->setMBR(best_new_mbr);
        }
        neighborhoods.erase(neighborhoods.begin() + best_nh_pos);
    }
    // creación de hojas terminada

    // inicio de creación de nodos internos
    vector<RNode*> next_level;
    while (nodes.size() != 1) {
        temp = new RNode(false);
        temp->addChild(nodes.front(), m_max);
        temp->setMBR(nodes.front()->getMBR());
        nodes.erase(nodes.begin());
        while (nodes.size() > 0) {
            // cout << "nodes size " << nodes.size() << "\n";
            RNode* best_child;
            int best_area = INT_MAX;
            Rectangle best_new_mbr;
            int best_child_pos = 0;
            for (int i = 0; i < nodes.size(); ++i) {
                RNode* current_node = nodes[i];
                Rectangle new_mbr(
                    Point(
                        min(temp->getMBR()._min.getLatitude(), current_node->getMBR()._min.getLatitude()),
                        min(temp->getMBR()._min.getLongitud(), current_node->getMBR()._min.getLongitud())
                    ),
                    Point(
                        max(temp->getMBR()._max.getLatitude(), current_node->getMBR()._max.getLatitude()),
                        max(temp->getMBR()._max.getLatitude(), current_node->getMBR()._max.getLatitude())
                    )
                );
                if (new_mbr.getArea() < best_area) {
                    best_child = current_node;
                    best_new_mbr = new_mbr;
                    best_child_pos = i;
                    best_area = new_mbr.getArea();
                }
            }
            // cout << "terminé de encontrar al mejor hijo\n";
            // update mbr and addNeighborhood sibling
            // cout << "nuevo mbr seteado\n";
            if (!temp->addChild(best_child, m_max)) {
                RNode* new_node = new RNode(false);
                *new_node = *temp;
                next_level.push_back(new_node);
                temp = new RNode(false);
                temp->addChild(best_child, m_max);
                temp->setMBR(best_child->getMBR());
            } else {
                temp->setMBR(best_new_mbr);
            }
            nodes.erase(nodes.begin() + best_child_pos);
            // cout << "borré al mejor hijo de la lista de nodos\n";
        }
        next_level.push_back(temp);
        nodes = next_level;
        // cout << "nodes size 2.1: " << nodes.size() << "\n";
        // cout << "next level size: " << next_level.size() << "\n";
        next_level.clear();
        // cout << "nodes cleared\n";
        // cout << "nodes size 2.2: " << nodes.size() << "\n";
    }
    this->root = nodes.front();
}

Neighborhood Rtree::search(Point point, RNode* node) {
    if (node->isLeaf()) {
        for (Neighborhood neighborhood : node->getNeighborhoods())
            if (neighborhood.getMBR().contains(point))
                return neighborhood;
    } else {
        for (RNode* child : node->getChildren())
            if (child->getMBR().contains(point)) {
                Neighborhood n = this->search(point, child);
                if (n.getName() != "not found") {
                    return n;
                }
                // return this->search(point, child);
            }
    }
    // si no se encontró el punto
    Neighborhood n(vector<Point>(), "not found");
    return n;
}

// F
void Rtree::insert(Neighborhood& neighborhood, RNode* node) {
    if (!node->isLeaf()) {
        for (RNode* child : node->getChildren()) {
            if (child->getMBR().contains(neighborhood.getMBR())) {
                insert(neighborhood, child);
                return;
            }
        }
        // extender hijo
        // encontrar el mejor hijo a extender
        RNode* best_child;
        int best_area = INT_MAX;
        Rectangle best_child_new_mbr;
        for (RNode* child : node->getChildren()) {
            Rectangle new_mbr(
                Point(
                    min(child->getMBR()._min.getLatitude(), neighborhood.getMBR()._min.getLatitude()),
                    min(child->getMBR()._min.getLongitud(), neighborhood.getMBR()._min.getLongitud())
                ),
                Point(
                    max(child->getMBR()._max.getLatitude(), neighborhood.getMBR()._max.getLatitude()),
                    max(child->getMBR()._max.getLatitude(), neighborhood.getMBR()._max.getLatitude())
                )
            );
            if (new_mbr.getArea() < best_area) {
                best_child = child;
                best_child_new_mbr = new_mbr;
            }
        }
        best_child->setMBR(best_child_new_mbr);
        insert(neighborhood, best_child);
        return;
    } else {
        if (!node->addNeighborhood(neighborhood, this->m_max)) {
            // split node
            // while (node->parent != null) para simular la llamada recursiva
            // separar en dos nuevos nodos al nodo
            // 
        }
    }
}

