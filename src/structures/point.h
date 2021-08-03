
#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_POINT_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_POINT_H


class Point{

    double latitude, longitud;

public:
    Point(double latitude, double longitud);
    
    Point()= default;

    double getLatitude() const;

    double getLongitud() const;

    // Point minBetweenPoints(Point& p1, Point& p2);

    // Point maxBetweenPoints(Point& p1, Point& p2);
};



#endif //SPATIAL_DATA_STRUCTURES_PROJECT_POINT_H
