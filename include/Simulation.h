#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "../include/Client.h"
#include "../include/Banque.h"
#include "../include/SimulationEvenementDiscret.h"

class Simulation:public SimulationEvenementDiscret {
    protected:
        double duree_prevue;
        double duree_reelle;
        double temps_moyen_arrivee;
        Banque *banque;

    public:
        Simulation(double duree_prevue, double duree_reelle, double temps_moyen_arrivee, int nb_caissiers, double temps_moyen_service);

        // Getter
        double dureePrevue();
        double dureeReelle();
        double tempsMoyenArrivee();
        Banque* mBanque();

        // Setter
        void setHeureActuelle(double heure_actuelle);
};

#endif