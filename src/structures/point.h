
#ifndef SPATIAL_DATA_STRUCTURES_PROJECT_POINT_H
#define SPATIAL_DATA_STRUCTURES_PROJECT_POINT_H


class Point{

    double latitude, longitud;

public:
    Point(double latitude, double longitud);

    double getLatitude() const;

    double getLongitud() const;
};



#endif //SPATIAL_DATA_STRUCTURES_PROJECT_POINT_H
