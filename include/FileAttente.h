#ifndef FILEATTENTE_H_
#define FILEATTENTE_H_

#include "../include/Client.h"
#include <deque>
using namespace std;

class Banque;
class FileAttente {
    protected:
        int longueur_max;
        double longueur_moyenne;
        double attente_moyenne;
        Banque* banque;
        deque< Client* > file_clients;

    public:
        FileAttente(Banque* banque);

        // Getter
        int mLongueurMax();
        double mLongueurMoyenne();
        int taille();

        void ajouter(Client* client);
        void ajouterContributionLongueurMoyenne(double contribution);
        bool estVide();
        Client* retirer();
};

#endif