#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <bitset>
#include <string>
using namespace std;

/*
Il faut compiler ce programme avec C++ 11
Auteur : Pierre KURZAWSKI
Date Début de projet : 7 Nov. 2015
OS : Arch Linux x64
G++ : 5.2.0
*/

int MenuChoix() //Demande quelle transformation l'user va choisir, elle retourne un entier
{
    int choixTransformation;
    cout << "Utilitaire de conversion IEEE 754" << endl;
    cout << endl;
    cout << "Choisissez votre transformation : " << endl;
    cout << "1- Décimal -> Simple Précision" << endl;
    cout << "2- Décimal -> Double Précision" << endl;
    cout << "3- Simple Précision -> Décimal" << endl;
    cout << "4- Double Précision -> Décimal" << endl;
    cout << "> ";
    cin >> choixTransformation;
    return choixTransformation;
}

float stringToFloat(string& motBinaireEnString)
{
	float resultatEnEntier = stof(motBinaireEnString);
	return resultatEnEntier;
}

float saisieConvertDecimalToString() //L'user saisie un string qui sera converti en float pour une meilleure manipulation :)
{
    string saisie;
    cout << "Veuillez saisir une valeur : ";
    cin >> saisie;
    return stringToFloat(saisie);
}

string saisieIEEE_32bitsToString()
{
    string saisie;
    cout << "Veuillez saisir un mot binaire de 32 Bits (Simple Précision) : ";
    cout << endl;
    cin >> saisie;
        if(saisie.length() < 31 || saisie.length() > 31)
        {
            cout << "Ceci n'est pas un mot binaire sur 32 Bits !" << endl;
            cout << "Veuillez recommencer !" << endl;
            cout << '\n';
            saisieIEEE_32bitsToString();
        }

        else (saisie.length() == 31);
            return saisie;

}

string saisieIEEE_64bitsToString()
{
    string saisie;
    cout << "Veuillez saisir un mot binaire de 64 Bits (Double Précision) : ";
    cout << endl;
    cin >> saisie;
        if(saisie.length() < 63 || saisie.length() > 63)
        {
            cout << "Ceci n'est pas un mot binaire sur 64 Bits !" << endl;
            cout << "Veuillez recommencer !" << endl;
            cout << '\n';
            saisieIEEE_64bitsToString();
        }

        else (saisie.length() == 63);
            return saisie;
}

/*string reverseString(string s)
{
    string tmp ="";
    for (int i = s.size() - 1 ; i >= 0; i--)
    {
        tmp += s[i];
    }
    return tmp;
}*/

void separePartieEntiereEtPartieDecimale(float valeur)
{
    int partieEntiere = floor(valeur);
    int partieDecimale = valeur - partieEntiere;
    cout << "Partie entiere :" << partieEntiere << "-> Partie déc :" << partieDecimale << endl;
}

void floatToSimpleIEEE()
{

}

void floatToDoubleIEEE()
{

}

void simpleIEEEtoFloat()
{

}

void doubleIEEEtoFloat()
{

}

void switchConversion(int c)
{
    switch(c)
    {
        case 1:
        {
        separePartieEntiereEtPartieDecimale(saisieConvertDecimalToString());
        floatToSimpleIEEE();
        }
        break;

        case 2:
        {
        separePartieEntiereEtPartieDecimale(saisieConvertDecimalToString());
        floatToDoubleIEEE();
        }
        break;

        case 3:
        saisieIEEE_32bitsToString();
        simpleIEEEtoFloat();
        break;

        case 4:
        saisieIEEE_64bitsToString();
        doubleIEEEtoFloat();
        break;

        default:
        cerr << "Erreur ! Faites un choix valide compris entre 1 et 4 ! " << endl;
        exit(1);
        break;
    }
}


int main()
{
    switchConversion(MenuChoix());
    return 0;
}
