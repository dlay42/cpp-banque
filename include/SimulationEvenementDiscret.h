/// @file SimulationEvenementDiscret.h
/// @author Donald LAY (nomail@private.com)
/// @brief Classe SimulationEvenementDiscret, Simulation base class et implémente la classe CompareEvenement
/// @see SimulationEvenementDiscret
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

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
        virtual double heureActuelle();
        priority_queue< Evenement*, vector< Evenement* >, CompareEvenement > mEvtQueue();

        /// @brief Ajoute un Evenement à la priority_queue 
        /// @param evt Evenement* : Evenement à ajouter à la priority_queue.
        void ajouter(Evenement* evt);

        /// @brief Liaison dynamique pour le lancement de la Simulation
        /// @see Simulation::lancer()
        virtual void lancer();
};

#endif