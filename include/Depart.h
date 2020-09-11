#ifndef DEPART_H_
#define DEPART_H_

#include "../include/Caissier.h"
#include "../include/Client.h"
#include "../include/Evenement.h"

class Depart:public Evenement {
    protected:
        Caissier* caissier;
        Client* client;

    public:
        Depart(double heure_evenement, Caissier* caissier, Client* client);
        void traiter();
};

#endif