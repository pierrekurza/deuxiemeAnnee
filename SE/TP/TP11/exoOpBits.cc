#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


void init(unsigned long int &x)
{
    x &= 0;
    cout << "Init -> " << x << endl;
}

void setTrue(unsigned long int &x, int pos)
{
    x |= (1<<pos);
    cout << "Set True -> " << x << endl;
}

void setFalse(unsigned long int &x, int pos)
{
    x &= ~(1<<pos);
    cout << "Set False -> " << x << endl;
}


bool get(unsigned long int x, int pos)
{
    return x&=(1<<pos);
}

int main()
{
    unsigned long int nb = 69;
    init(nb);
    setTrue(nb, 6);
    setFalse(nb, 6);
    cout << get(nb, 6) << endl;
}
