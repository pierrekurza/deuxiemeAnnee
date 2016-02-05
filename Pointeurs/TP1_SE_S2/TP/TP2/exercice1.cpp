#include <iostream>
using namespace std;

struct Etudiant {
    int numEtudiant;
    int ageEt;
    float moyenne;
};

void afficherEtudiantStatique(Etudiant etu)
{
    cout << "De Manière Statique : " << endl;
    cout << "                     Numéro Étudiant : " << etu.numEtudiant << endl;
    cout << "                     Age Étudiant : " << etu.ageEt << endl;
    cout << "                     Moyenne Étudiant : " << etu.moyenne << endl;
}

void afficherEtudiantDynamique(Etudiant *etu)
{
    cout << "De Manière Dynamique : " << endl;
    cout << "                      Numéro Étudiant : " << etu->numEtudiant << endl;
    cout << "                      Age Étudiant : " << etu->ageEt << endl;
    cout << "                      Moyenne Étudiant : " << etu->moyenne << endl;
}

void swapEtudiants(Etudiant *un, Etudiant *deux)
{
    Etudiant *tmp = new Etudiant;
    *tmp = *un;
    *un = *deux;
    *deux = *tmp;
    delete tmp;
}

int main()
{
    //Manière statique
    Etudiant seb;
    seb.numEtudiant = 125872;
    seb.ageEt = 18;
    seb.moyenne = 10.25;

    //Manière Dynamique
    Etudiant *pauline = new Etudiant;
    Etudiant *laure = new Etudiant;
    Etudiant *valentin = new Etudiant;

    pauline->numEtudiant = 4875564;
    laure->numEtudiant = 4148784;
    valentin->numEtudiant = 4785129;

    pauline->ageEt = 20;
    laure->ageEt = 19;
    valentin->ageEt = 20;

    pauline->moyenne = 12.36;
    laure->moyenne = 8.41;
    valentin->moyenne = 15.47;

    //Affichage étudiants
    afficherEtudiantStatique(seb);
    afficherEtudiantDynamique(valentin);

    //Swap etudiants
    cout << "Après le swap -> " << endl;
    swapEtudiants(laure, valentin);
    afficherEtudiantDynamique(laure);
    afficherEtudiantDynamique(valentin);
    delete pauline;
    delete laure;
    delete valentin;

}
