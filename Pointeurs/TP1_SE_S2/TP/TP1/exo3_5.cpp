#include <iostream>
using namespace std;

int main()
{
    char test[10];
    char c ='A';
    char *p = &c;
    test[0] = *p;
    cout << test[0] << endl;
    return 0;
}
