#include <iostream>
using namespace std;

int main()
{
    double *q;
    int x = 28;
    int *p = &x;
    *q = *p;

    return 0;

    /*
    Q ne peut recevoir p car q est un double et p est un int
    */

}
