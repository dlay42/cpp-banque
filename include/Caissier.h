/// @file Caissier.h
/// @author Donald LAY (nomail@private.com)
/// @brief Classe Caissier
/// @see Caissier
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#ifndef CAISSIER_H_
#define CAISSIER_H_

#include "../include/Client.h"
#include "../include/Depart.h"

class Banque;
class Caissier {
    protected:
        bool disponible;
        double temps_moyen_service;
        int nb_clients_servis;
        double taux_occupation;
        Banque* banque;

    public:
        Caissier(double temps_moyen_service, Banque* banque);

        // Getters
        bool estDisponible();

        double mTempsMoyenService();

        /// @brief Paramètre statistique de sortie du programme.
        /// @return double : taux d'occupation du Caissier par rapport à la durée réelle de la simulation (pourcentage).
        double mTauxOccupation();

        /// @brief Paramètre statistique de sortie du programme.
        /// @return int : nombre de clients servis par le Caissier durant la Simulation.
        int mNbClientsServis();
        Banque* mBanque();

        /// @brief Implémente pour un Caissier l'action de servir un Client
        /// @param client Client* : client à servir
        /// @see Arrivee::traiter()
        /// @see Depart::traiter()
        void servir(Client* client);

        /// @brief Rend le Caissier disponible
        void liberer();
};

#endif