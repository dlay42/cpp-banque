/// @file Banque.h
/// @author Donald LAY (nomail@private.com)
/// @brief Classe Banque
/// @see Banque
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#ifndef BANQUE_H_
#define BANQUE_H_

#include "../include/Caissier.h"
#include "../include/FileAttente.h"
#include "../include/Poisson.h"

class Simulation;
class Banque {
    protected:
        int nb_caissiers;
        int nb_clients_servis;
        double temps_moyen_service;
        Caissier** caissiers;
        FileAttente* file_attente;
        Simulation* simulation;

    public:
        Banque(int nb_caissiers, double temps_moyen_service, Simulation* simulation);
        
        // Getter
        Caissier** mCaissiers();
        FileAttente* mFileAttente();
        Simulation* mSimulation();

        /// @brief Vérifie si un Caissier de la banque est disponible
        /// @return Caissier disponible, NULL sinon.
        Caissier* unCaissierDisponible();
};

#endif