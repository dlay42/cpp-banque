#ifndef SIMULATIONEVENEMENTDISCRET_H_
#define SIMULATIONEVENEMENTDISCRET_H_

#include "../include/Evenement.h"

class SimulationEvenementDiscret {
    protected:
        double heure_actuel;

    public:
        SimulationEvenementDiscret(double heure_actuel);
        double heureActuel();
        void ajouter(Evenement* evt);
        void lancer();
};

#endif