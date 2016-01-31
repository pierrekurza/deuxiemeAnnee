#include <iostream>
using namespace std;

void echanger(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a,b;
    cout << "Valeur A : ";
    cin >> a;
    cout << "Valeur B : ";
    cin >> b;
    cout << "                 " << a << " " << b << endl;
    echanger(&a,&b);
    cout << "Après echange -> ";
    cout << a << " " << b << endl;
}
