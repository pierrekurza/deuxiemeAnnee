/* Ecrire programme qui demande à l'utilisateur le nom d'un fichier dans lequel est ecrit des nombres réels et affiche la moyenne de cet ensemble de nbre*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream monFichierAvecChiffres;
    float moyenne = 0.0, tmp, somme = 0.0;
    float nbValeur = 0.0;
    char nomDuFichier[256];
    cout << "EntrAIENT le nom du fichier : " ;
    cin >> nomDuFichier;
    monFichierAvecChiffres.open(nomDuFichier, ios::in);

    for (int i = 0;!monFichierAvecChiffres.eof(); i++)
    {
        monFichierAvecChiffres >> tmp;
        somme += tmp;
        nbValeur += 1;
    }
    moyenne  = somme / nbValeur;
    cout << "La moyenne de cet ensemble est de : " << moyenne << endl;
	return 0;
}
