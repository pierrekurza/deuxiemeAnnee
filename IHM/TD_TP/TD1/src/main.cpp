#include "point.hpp"
#include "rectangle.hpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "Les Points" << endl;
    Point p(1,0);
    Point q(4,5);
    cout << "Coordonnées de départ -> " << endl;
    cout << p ;
    cout << q ;
    p.setCoordinates(12,8);
    cout << "Après avoir modifié les coordonnées -> " << p << endl;
    cout << "Distance entre les points : " << endl;
    cout << p.dist(q) << endl;

    cout << endl;
    cout << "Les rectangles" << endl;
    Rectangle R1(1,1,2,2);
    Rectangle R2(0,0,3,3);
    cout << "Rectangle R1 : " << R1 << endl;
    cout << "Rectangle R2 : " << R2 << endl;
    cout << "Test si rect inclus !"<< endl;

    if(R1.estInclus(R2) == 1)
        cout << "R1 est inclus dans R2" << endl;
    else
        cout << "R2 est inclus dans R1" << endl;

}
