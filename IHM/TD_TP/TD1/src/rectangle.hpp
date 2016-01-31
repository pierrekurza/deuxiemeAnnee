#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <iostream>
using namespace std;

class Rectangle {
    float xl, xr, yb, yt;

public:
    Rectangle();
    Rectangle(const float x_left, const float y_bot, const float x_right, const float y_top);
    Rectangle(const Rectangle& r);
    bool estInclus(const Rectangle& r);
    ~Rectangle() {};

    friend ostream &operator <<(ostream &output, const Rectangle& r);
};
#endif
