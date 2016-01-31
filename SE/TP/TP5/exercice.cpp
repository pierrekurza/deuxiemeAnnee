#include <iostream>
#include <cmath>
#include <stdio.h>
#define NB_BITS 8
using namespace std;

void print(int tabBits[NB_BITS])
{
    for (int i =0; i < NB_BITS;i++)
    {
        cout << tabBits[i];
        if((i!=0) && ((i+1)%4 ==0))
            cout << " ";
    }
    cout << endl;
}

void intToBin(int v, int tabBits[NB_BITS])
{
    if (v < 0)
    {
        tabBits[0] = 1;
        v = -v;
    }

    else
        tabBits[0] = 0;
    for (int i = NB_BITS -1 ; i > 0 ; i--)
    {
        tabBits[i] = v%2;
        v = v/2;
    }
    if (v > 0)
        cerr  << "Out Of Capacity" << endl;
}

int binToInt(int tabBits[NB_BITS])
{
    int res;
    int currentPow = 1;
    for(int i = NB_BITS -1; i > 0; i--)
        {
            res += tabBits[i] * currentPow;
            currentPow * 2;
        }
    return (tabBits[0] ? -res : res);
}

void assign(int v[NB_BITS], int o[NB_BITS])
{
    for(int i = 0;i < NB_BITS; i++)
        o[i] = v[i];
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
        return (!tab1[0]);
    if(!tab1[0])
        return gt_abs(tab1, tab2);
    return gt_abs(tab2, tab1);
}

bool lt(int tab1[NB_BITS], int tab2[NB_BITS])
{
    return gt(tab2, tab1);
}

bool eq(int tab1[NB_BITS], int tab2[NB_BITS])
{
    return (!gt(tab1, tab2) && (!lt(tab1,tab2)) );
}


void lShift(int tab[NB_BITS])
{
    for(int i = 1; i < NB_BITS -1 ; i++)
        tab[i] = tab[i-1];
    tab[0] = 0;
    for (int p = 0; p < NB_BITS; p++)
    {
        cout << tab[p];
    }
    cout << endl;
}

void rShift(int tab[NB_BITS])
{
    for(int i = 0; i < NB_BITS -2 ; i++)
        tab[i] = tab[i+1];
    tab[NB_BITS-1] = 0;
    for (int p = 0; p < NB_BITS; p++)
    {
        cout << tab[p];
    }
        cout << endl;
}

void additionBinaire(int a1[NB_BITS], int a2[NB_BITS], int res[NB_BITS])
{
    int tmp;
    int retenue = 0;
    if(a1[0] == a2[0])
    {
        for(int i = NB_BITS - 1; i > 0; i--)
        {
            tmp = a1[i] + a2[i] + retenue;
            if(tmp == 2)
            {
                res[i] = 0;
                retenue = 1;
            }

            else if(tmp == 1)
            {
                res[i] = 1;
                retenue = 1;
            }

            else if(tmp == 3)
            {
                res[i] = 1;
                retenue = 1;
            }

            else
            {
                res[i] = 0;
                retenue = 0;
            }
        }
        res[0] = a1[0];
        if(retenue == 1)
            cerr << "Overflow" << endl;
        print(res);
    }
}

void soustractionBinaire(int a1[NB_BITS], int a2[NB_BITS], int res[NB_BITS])
{

}

int main()
{
    int v;
    int tabExo1[NB_BITS] = {0,1,0,1,1,0,1,0};
    int tabExo2[NB_BITS];
    int tabExo3[NB_BITS] = {1,0,1,1,0,1,0,0};
    int tabExo4[NB_BITS] = {0,1,0,1,1,0,1,0};
    /*cout << "Affiche le tableau :" << endl;
    print(tabExo1);
    cout << endl;
    cout << "Conversion entier to Binaire " << endl;
    cout << "Entrer un entier : ";
    cin >> v;
    intToBin(v, tabExo2);
    print(tabExo2);
    cout << endl;
    cout << binToInt(tabExo1) << endl;
    cout << endl;
    cout << "Fonction assign :" << endl;
    assign(tabExo1, tabExo2);
    for(int i = 0; i < NB_BITS; i++)
        cout << tabExo2[i];
    cout << endl;*/
    cout << "Comparaisons \"Valeurs absolues\" " << endl;
    cout << gt_abs(tabExo3,tabExo1) << endl;
    cout << lt_abs(tabExo1,tabExo3) << endl;
    cout << eq_abs(tabExo1, tabExo4) << endl;

    cout << "Comparaisons \"Deux valeurs binaires\" " << endl;
    cout << gt(tabExo1,tabExo3) << endl;
    cout << lt(tabExo3,tabExo1) << endl;
    cout << eq(tabExo1, tabExo4) << endl;

    /*lShift(tabExo3);
    rShift(tabExo1);*/

    additionBinaire(tabExo1,tabExo3,tabExo2);
    return 0;
}
