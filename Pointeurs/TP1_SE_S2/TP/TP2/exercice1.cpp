#include <iostream>
using namespace std;

struct Etudiant {
    int numEtudiant;
    int ageEt;
    float moyenne;
    Etudiant *suivant;

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

void ajouterEtudiant(Etudiant **listeEtu, int numEtud, int age, float moy)
{
    Etudiant *nouvelEtu = new Etudiant;
    nouvelEtu->numEtudiant = numEtud;
    nouvelEtu->ageEt =age;
    nouvelEtu->moyenne = moy;
    nouvelEtu->suivant = *listeEtu;
    *listeEtu = nouvelEtu;
}

void afficherEtudiant(Etudiant *listeEtu)
{
    while(listeEtu != nullptr)
    {
        cout << "Numéro étudiant : " << listeEtu -> numEtudiant << endl;
        cout << "Age : " << listeEtu->ageEt << endl;
        cout << "Moyenne : " << listeEtu->moyenne << endl;
        listeEtu = listeEtu->suivant;
    }
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

    Etudiant *pointTete = nullptr;
    ajouterEtudiant(&pointTete,125455,27,13.54);
    ajouterEtudiant(&pointTete,132155,44,12.99);
    ajouterEtudiant(&pointTete, 4464646, 22, 17.01);
    afficherEtudiant(pointTete);

}
