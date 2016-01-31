#include <iostream>
using namespace std;

int main()
{
    int x = 28;
    int *p = NULL;
    p = &x;

    return 0;
    /*
    int x est un entier classique tandis que int *p est un pointeur sur un entier, et donc ne peut recevoir
    un entier
    */
}
