#include <iostream>
using namespace std;


struct Produit{
    string nom;
    float prix;
    float poids;
    Produit *suivant;
};

/*
struct Caddie{
    Produit *
};
*/


Produit creerProduit(string nomP, float prixP, float poidsP)
{
    Produit *newPro = new Produit;
    newPro->nom = nomP;
    newPro->prix = prixP;
    newPro->poids = poidsP;
    return *newPro;
}

/*void ajouterProduit(Produit *p, Caddie *c)
{

}
*/

void afficherProduit(Produit *pro)
{
    cout << "Nom Produit : " << pro->nom << endl;
    cout << "Prix : " << pro->prix << endl;
    cout << "Poids : " << pro->poids << endl;
}

int main()
{

    Produit *patate = new Produit;
    *patate = {"Patate", 0.87, 2.04};
    afficherProduit(patate);
    return 0;
}
