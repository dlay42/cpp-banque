#ifndef BANQUE_H_
#define BANQUE_H_

#include "../include/Caissier.h"
#include "../include/FileAttente.h"
#include "../include/Poisson.h"

class Banque {
    protected:
        int nb_caissiers;
        int nb_clients_servis;
        double temps_moyen_service;
        Caissier** caissiers;
        FileAttente* file_attente;

    public:
        Banque(int nb_caissiers, double temps_moyen_service);
        Caissier** mCaissiers();
        Caissier* unCaissierDisponible();
};

#endif