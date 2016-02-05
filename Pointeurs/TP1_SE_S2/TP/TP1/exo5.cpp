#include <iostream>
#define MAX_ENFANTS 20
using namespace std;

struct Personne {
    string nomPers;
    Personne *conjoint;
    Personne *enf[MAX_ENFANTS];
    int nbEnfants;
};

void initPersonne(Personne *p, string name, Personne *c, Personne *e[], int nbE)
{
    p->nomPers = name;
    p->conjoint = c;
    for(int i = 0; i < nbE; i++)
        p->enf[i] = e[i];
        p->nbEnfants = nbE;
}

void affichePers(Personne p)
{
    cout << p.nomPers << endl;
    if(p.conjoint)
        cout << "Conjoint " << (p.conjoint)-> nomPers << endl;
    for(int i = 0; i < p.nbEnfants;i++)
        cout << "Enfants : " << i << " " << (p.enf)[i]->nomPers << endl;
}

int main()
{
    Personne *tmpE[MAX_ENFANTS];
    Personne world[5];
    tmpE[0] = &world[4];
    initPersonne(&world[0], "Jean", NULL, tmpE, 1);
    initPersonne(&world[1], "Maxime", NULL, tmpE, 1);
    initPersonne(&world[2], "Pierre", NULL, tmpE, 1);
    tmpE[0] = &world[1];
    tmpE[1] = &world[2];
    initPersonne(&world[3], "Martine", & world[4], tmpE, 2);
    initPersonne(&world[4], "Paul", & world[3], tmpE, 2);
    affichePers(world[0]);
    affichePers(world[1]);
    affichePers(world[2]);
    affichePers(world[3]);
}
