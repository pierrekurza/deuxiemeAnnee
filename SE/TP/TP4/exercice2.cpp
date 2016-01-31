/*concaténer deux fichier dans un troisieme*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream fichier1, fichier2;
    ofstream fichierDestination;
    char nomDuFichier1[128], nomDuFichier2[128], nomFichierDestination[128];
    string s;

    cout << "EntrAIENT le nom du 1er fichier : ";
    cin >> nomDuFichier1;
    cout << "EntrAIENT le nom du 2nd fichier : ";
    cin >> nomDuFichier2;
    cout << "EntrAIENT le nom du fichier de destination: ";
    cin >> nomFichierDestination;

    fichier1.open(nomDuFichier1, ios::in);
    fichier2.open(nomDuFichier2, ios::in);
    fichierDestination.open(nomFichierDestination, ios::app);

    for(int i=0; !fichier1.eof(); i++)
    {
        fichier1 >> s;
        for (int j=0; !fichier2.eof(); i++)
        {
            fichier2 >> s;
        }
        fichierDestination << s;
    }

    return 0;
}
