/// @file Simulation.h
/// @author Donald LAY (nomail@private.com)
/// @brief Classe Simulation, SimulationEvenementDiscret derived class
/// @see Simulation
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "../include/Client.h"
#include "../include/Banque.h"
#include "../include/SimulationEvenementDiscret.h"

class Simulation:public SimulationEvenementDiscret {
    protected:
        double duree_prevue;
        double duree_reelle;
        int nb_clients;
        double temps_moyen_arrivee;
        Banque *banque;

    public:

        /// @brief Constructeur de la classe Simulation
        Simulation(double duree_prevue, double temps_moyen_arrivee, int nb_caissiers, double temps_moyen_service);

        // Getter
        double dureePrevue();

        /// @brief Paramètre statistique de sortie du programme.
        /// @return double : durée réelle de la Simulation (dernier Client servi).
        double dureeReelle();

        /// @brief Paramètre statistique de sortie du programme.
        /// @return int : nombre total de Client servi durant la Simulation.
        int mNbClients();
        double tempsMoyenArrivee();
        Banque* mBanque();

        // Setter
        void setHeureActuelle(double heure_actuelle);
        void incrementNbClients();

        /// @brief Algorithme implémentant la Simulation.
        /// @see Arrivee::traiter()
        /// @see Depart::traiter()
        /// @see FileAttente:ajouterContributionLongueurMoyenne(double contribution)
        void lancer();
};

#endif