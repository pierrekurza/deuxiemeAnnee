#include <iostream>
using namespace std;

int main()
{
    int *p;
    int x = 17;
    p = &x;

    cout << x << " " << &x << " " << p << " " << &p << " " << *p << endl;
}
