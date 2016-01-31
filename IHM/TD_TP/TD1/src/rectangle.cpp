#include "rectangle.hpp"
#include "point.hpp"
#include <iostream>
#include <cmath>
using namespace std;

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(const float x_left, const float y_bot, const float x_right, const float y_top):
xl(x_left),
yb(y_bot),
xr(x_right),
yt(y_top)
{
}

Rectangle::Rectangle(const Rectangle& r)
{
}


bool Rectangle::estInclus(const Rectangle& r)
{
    return (xl < r.xl && yb < r.yb && xr < r.xr && yt < r.yt);
}

Rectangle::Rectangle(const Point& bas_gauche, const Point& haut_droite)
{

}

ostream &operator <<(ostream &output, const Rectangle& r)
{
    output << "(" << r.xl << ":" << r.yb << ":" << r.xr << ":" << r.yt << ")" << endl;
    return output;
}
