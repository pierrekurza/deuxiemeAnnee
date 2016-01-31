#include "point.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Point::Point()
{
}

Point::Point(const float a, const float b):
x(a),
y(b)
{
}

Point::Point(const Point& p)
{
}

void Point::setCoordinates(const float a, const float b)
{
    x = a;
    y = b;
}

float Point::dist(const Point& q)
{
    float dist = sqrt((x-q.x)*(x-q.x) + (y-q.y)*(y-q.y));
    return dist;
}

ostream &operator <<(ostream &output, const Point& p)
{
    output << "(" << p.x << ":" << p.y << ")" << endl;
    return output;
}
