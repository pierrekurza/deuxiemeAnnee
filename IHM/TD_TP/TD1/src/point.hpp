#ifndef POINT_HPP
#define POINT_HPP
#include <ostream>
#include <istream>
#include <iostream>

using namespace std;

class Point{
    float x;
    float y;

public:
    Point();
    Point(const float a, const float b);
    Point(const Point& p);
    void setCoordinates(const float a, const float b);
    float dist(const Point& q);
    ~Point() {}

    friend ostream &operator <<(ostream &output, const Point& p);
};
#endif
