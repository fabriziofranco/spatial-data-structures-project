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
#include "../utils/csv.h"

Rtree::Rtree(string tripFileName, string neighborhoodFileName, int m_min, int m_max):
tripFileName(tripFileName),neighborhoodFileName(neighborhoodFileName), m_min(m_min), m_max(m_max) {

    // inicializar árbol
    this->root = new RNode(true);
    // end inicializar árbol
    vector<Neighborhood*> neighborhoods;
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

        Neighborhood* barrio = new Neighborhood(points, nombre);
        neighborhoods.push_back(barrio);
    }

    this->neighborhoods=neighborhoods;
    this->static_insert(neighborhoods);

    //Parser aquí https://github.com/ben-strasser/fast-cpp-csv-parser
    io::CSVReader<5> in(tripFileName);
    in.read_header( io::ignore_extra_column,
                    "Pickup_longitude",
                    "Pickup_latitude",
                    "Dropoff_longitude",
                    "Dropoff_latitude",
                    "Trip_distance"
                    );
    double pickup_longitude, pickup_latitude, dropoff_longitude, dropoff_latitude, trip_distance;
    while(in.read_row(pickup_longitude, pickup_latitude, dropoff_longitude, dropoff_latitude, trip_distance)){
        Trip trip(Point(pickup_latitude,pickup_longitude),Point(dropoff_latitude, dropoff_longitude),trip_distance);
        
        Neighborhood * NeighborhoodPickUp = this->search(trip.getPickup(),this->root); 
        Neighborhood * NeighborhoodDropOff = this->search(trip.getDropoff(),this->root); 

        if(NeighborhoodPickUp){
            NeighborhoodPickUp->addBeginHere(trip);
            NeighborhoodPickUp->addTotalTrip();
        }

        if(NeighborhoodDropOff)
            NeighborhoodDropOff->addEndHere(trip);



        if(NeighborhoodPickUp != NeighborhoodDropOff){
            if(NeighborhoodDropOff)
                NeighborhoodDropOff->addTotalTrip();
        }
        else{
            if(NeighborhoodDropOff and NeighborhoodPickUp)
                this->commonBeginAndEndTrips.push_back(trip);
        }
    }
    
   //generar el conjunto de 

}

vector<Trip> Rtree::sameNeighborhood() {
    cout<<this->commonBeginAndEndTrips.size()<<"\n";
    return this->commonBeginAndEndTrips;
}

vector<Neighborhood> Rtree::kNeighborhoodsMostTrips(int k) {
    vector<Neighborhood> copy;
    for (Neighborhood* n : this->neighborhoods) {
        copy.push_back(*n);
    }
    sort(copy.begin(), copy.end(), greater<Neighborhood>());
    for (int i = 0; i < k && i < copy.size(); ++i) {
        cout << copy[i].getName() << "\n";
    }
    return vector<Neighborhood>(copy.begin(), copy.begin() + k);
}

int Rtree::beginInRegion(Point p1, Point p2) {
    Rectangle window_query(p1, p2);
    vector<Neighborhood*> neighborhoods = this->range_search(window_query);
    int total_trips = 0;
    for (Neighborhood* n : neighborhoods) {
        for (Trip &p : n->getBeginHere()) {
            if (window_query.contains(p.getPickup()))
                total_trips += 1;
        }
    }
    cout << total_trips << "\n";
    return total_trips;
}

vector<Trip> Rtree::maxDistance(Point point, double distance) {
    return vector<Trip>();
}

void Rtree::static_insert(vector<Neighborhood*> neighborhoods) {
    // generar nodos hoja
    RNode* temp = new RNode(true);
    vector<RNode*> nodes;
    temp->addNeighborhood(neighborhoods.front(), m_max);
    temp->setMBR(neighborhoods.front()->getMBR());
    neighborhoods.erase(neighborhoods.begin());
    while (neighborhoods.size() > 0) {
        // find best neighborhood to merge with
        Neighborhood* best_nh;
        int best_area = INT_MAX;
        Rectangle best_new_mbr;
        int best_nh_pos = 0;
        for (int i = 0; i < neighborhoods.size(); ++i) {
            Neighborhood* current_nh = neighborhoods[i];
            Rectangle new_mbr(
                Point(
                    min(temp->getMBR()._min.getLatitude(), current_nh->getMBR()._min.getLatitude()),
                    min(temp->getMBR()._min.getLongitud(), current_nh->getMBR()._min.getLongitud())
                ),
                Point(
                    max(temp->getMBR()._max.getLatitude(), current_nh->getMBR()._max.getLatitude()),
                    max(temp->getMBR()._max.getLatitude(), current_nh->getMBR()._max.getLatitude())
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
            temp->setMBR(best_nh->getMBR());
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
        }
        next_level.push_back(temp);
        nodes = next_level;
        next_level.clear();
    }
    this->root = nodes.front();
}

Neighborhood* Rtree::search(Point point, RNode* node) {
    if (node->isLeaf()) {
        for (Neighborhood* neighborhood : node->getNeighborhoods())
            if (neighborhood->getMBR().contains(point))
                return neighborhood;
    } else {
        for (RNode* child : node->getChildren())
            if (child->getMBR().contains(point)) {
                Neighborhood* n = this->search(point, child);
                if (n != nullptr)
                    return n;
            }
    }
    // si no se encontró el punto
    return nullptr;
}

vector<Neighborhood*> Rtree::range_search(Rectangle& window_query) {
    vector<Neighborhood*> result;
    this->range_search_helper(window_query, this->root, result);
    return result;
}

void Rtree::range_search_helper(Rectangle& window_query, RNode* node, vector<Neighborhood*>& result) {
    if (node->isLeaf()) {
        for (Neighborhood* neighborhood : node->getNeighborhoods()) {
            if (window_query.intersects(neighborhood->getMBR())) {
                result.push_back(neighborhood);
            }
        }
    } else {
        for (RNode* child : node->getChildren()) {
            if (window_query.intersects(child->getMBR())) {
                return range_search_helper(window_query, child, result);
            }
        }
    }
}
