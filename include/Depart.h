#ifndef DEPART_H_
#define DEPART_H_

#include "../include/Client.h"
#include "../include/Evenement.h"

class Caissier;
class Depart:public Evenement {
    protected:
        Caissier* caissier;
        Client* client;

    public:
        Depart(double heure_evenement, Caissier* caissier, Simulation* simulation);
        void traiter();
};

#endif