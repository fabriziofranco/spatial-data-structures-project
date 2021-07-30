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


Rtree::Rtree(string tripFileName, string neighborhoodFileName):
tripFileName(tripFileName),neighborhoodFileName(neighborhoodFileName){

    ifstream ifs(neighborhoodFileName);
    Json::Reader reader;
    Json::Value val;

    if (!reader.parse(ifs, val)) {
        cout<<"Error reading the document";
    }

    int sz = val.size();
    cout<<sz<<endl;
    for (int i = 0; i < sz; ++i) {
        std::cout << val[i]["properties"]["neighborhood"].asString();
        std::cout << std::endl;

    // cout << "Book: " << obj["book"].asString() << endl;
    // cout << "Year: " << obj["year"].asUInt() << endl;
    // const Json::Value& characters = obj["characters"]; // array of characters
    // for (int i = 0; i < characters.size(); i++){
    //     cout << "    name: " << characters[i]["name"].asString();
    //     cout << " chapter: " << characters[i]["chapter"].asUInt();
    //     cout << endl;
    // }
    }
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
