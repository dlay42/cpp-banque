#ifndef FILEATTENTE_H_
#define FILEATTENTE_H_

#include "../include/Client.h"
#include <deque>
using namespace std;

class Banque;
class FileAttente {
    protected:
        int longueur_max;
        int longueur_moyenne;
        double attente_moyenne;
        Banque* banque;
        deque< Client* > file_clients;

    public:
        FileAttente(Banque* banque);
        void ajouter(Client* client);
        bool estVide();
        Client* retirer();
};

#endif