#ifndef SIMULATIONEVENEMENTDISCRET_H_
#define SIMULATIONEVENEMENTDISCRET_H_

#include "../include/Evenement.h"
#include <queue>
#include <vector>
using namespace std;

class CompareEvenement {
    public:
        int operator() ( Evenement* evt1, Evenement* evt2) {
            return evt1->heureEvenement() > evt2->heureEvenement();
        }
};

class SimulationEvenementDiscret {
    protected:
        double heure_actuelle;
        priority_queue< Evenement*, vector< Evenement* >, CompareEvenement > evt_queue;

    public:
        SimulationEvenementDiscret(double heure_actuelle);
        
        // Getter
        double heureActuelle();
        priority_queue< Evenement*, vector< Evenement* >, CompareEvenement > mEvtQueue();

        void ajouter(Evenement* evt);
        void lancer();
};

#endif