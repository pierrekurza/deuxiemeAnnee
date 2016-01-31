#include <iostream>
#define NB_BITS 8
using namespace std;

void addition(int a1[NB_BITS], int a2[NB_BITS], int r[NB_BITS]);
void subs(int a1[NB_BITS], int a2[NB_BITS], int r[NB_BITS]);
void mult(int a1[NB_BITS], int a2[NB_BITS], int r[NB_BITS]);

void print(int tabBits[NB_BITS])
{
    for (int i =0; i < NB_BITS;i++)
    {
        cout << tabBits[i];
        if((i!=0) && ((i+1)%4 == 0))
            cout << " ";
    }
    cout << endl;
}

void complementA2(int tab[NB_BITS])
{
    int r, tmp;
    for(int i = 0; i < NB_BITS; i++)
        tab[i] = !tab[i];

    for(int j = NB_BITS - 1, r = 1; j >=0; j--)
    {
        tmp = tab[j] +r;
        tab[j] = tmp%2;
        r = tmp/2;
    }
}

void intToBin(int v, int tabBits[NB_BITS])
{
    bool negatif = v < 0;
    if(negatif)
        v = -v;
    for(int i = NB_BITS -1; i >= 0; i--)
    {
        tabBits[i] = v%2;
        v = v/2;
    }
    if(negatif)
        complementA2(tabBits);

}

int toInt(int tab[NB_BITS])
{
    int res, tmp = 1;
    if(tab[0] == 1)
    {
        complementA2(tab);
        for(int i = NB_BITS - 1; i > 0; i--)
        {
            res += (tab[i] * tmp);
            tmp *= 2;
        }
        res = -res;
        return res;
    }
    for(int j = NB_BITS -1; j > 0; j--)
    {
        res += (tab[j] * tmp);
        tmp *= 2;
    }
    return res;
}

void assign(int v[NB_BITS], int o[NB_BITS])
{
    for(int i = 0;i < NB_BITS; i++)
        o[i] = v[i];
}

void abs(int tab1[NB_BITS], int tab2[NB_BITS])
{
    assign(tab1, tab2);
    if(tab1[0] == 1)
        complementA2(tab2);
}

bool gt_abs(int tab1[NB_BITS], int tab2[NB_BITS])
{
    for(int i = 1; i < NB_BITS; i++)
    {
        if(tab1[i] != tab2[i])
            return (tab1[i] > tab2[i]);
    }
    return false;
}

bool lt_abs(int tab1[NB_BITS], int tab2[NB_BITS])
{
    return gt_abs(tab2, tab1);
}

bool eq_abs(int tab1[NB_BITS], int tab2[NB_BITS])
{
    return (!gt_abs(tab1, tab2) && (!lt_abs(tab1,tab2)) );
}

bool gt(int tab1[NB_BITS], int tab2[NB_BITS])
{
    if(tab1[0] != tab2[0])
        return !tab1[0];è-
    if(tab1[0])
    {
        abs(tab1, tab2);
        return lt_abs(tab1, tab2);
    }
    return gt_abs(tab1, tab2);
}

void lShift(int tab[NB_BITS])
{
    for(int i = 1; i < NB_BITS -1 ; i++)
        swap(tab[i],tab[i+1]);
    for (int p = 0; p < NB_BITS; p++)
    {
        cout << tab[p];
    }
    cout << endl;
}

void rShift(int tab[NB_BITS])
{
    for(int i = 0; i < NB_BITS -2 ; i++)
        swap(tab[i], tab[i-1]);
    for (int p = 0; p < NB_BITS; p++)
    {
        cout << tab[p];
    }
    cout << endl;
}

void addition(int a1[NB_BITS], int a2[NB_BITS], int r[NB_BITS])
{
    int abs_a1[NB_BITS], abs_a2[NB_BITS];
    if(a1[0] != a2[0])

}

int main()
{
   /* int nb;
    cout << "Entrez un nombre :";
    cin >> nb;*/
    int tabExo1[NB_BITS] = {0,1,0,1,1,0,1,0};
    int tabExo2[NB_BITS];
    int tabExo3[NB_BITS] = {1,0,1,1,0,1,0,0};
    int tabExo4[NB_BITS] = {0,1,0,1,1,0,1,0};

    //print(tabExo1);
    /*intToBin(nb,tabExo2);
    print(tabExo2);*/
    cout << "Le tableau vaut : " << toInt(tabExo3) << endl;
    cout << "On assign : " ;
    assign(tabExo4, tabExo2);
    print(tabExo4);
    cout << "Après assign :" << endl;
    print(tabExo2);

    lShift(tabExo1);
    rShift(tabExo3);
}
