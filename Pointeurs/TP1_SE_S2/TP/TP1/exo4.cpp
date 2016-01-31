#include <iostream>
using namespace std;


struct Point {
  int x;
  int y;
};

int main()
{
    int a = 3;
    double d;
    Point p;
    p.x = 4;
    p.y= 10;

    cout << "Pointer size :" << endl;
    cout << "size of a : " << sizeof(a) << " -- size of address of a " << sizeof(&a) << endl;
    cout << "size of p : " << sizeof(p) << " -- size of address of p " << sizeof(&p) << endl;

    int *px = &(p.x);
    cout << "address of p : " << &p << endl;
    cout << "address of p.x : " << &(p.x) << endl;
    cout << "value of px : " << px << endl;
    cout << "value of p.y : " << &(p.y) << endl;

    return 0;

    // a est un entier sur 4 octets, par contre l'adresse est sur 8 octets
    // b double sur 8 octets

    //sur une arch x64 , la taille d'une adresse quelque soit la taille de variable utilisé
    // l'adresse sere tjrs sur 8 octets
}
