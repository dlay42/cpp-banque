/// @file Arrivee.h
/// @author Donald LAY (nomail@private.com)
/// @brief Classe Arrivee, Evenement derived class
/// @see Arrivee
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#ifndef ARRIVEE_H_
#define ARRIVEE_H_

#include "../include/Evenement.h"
#include "../include/Poisson.h"

class Arrivee:public Evenement {
    public:
        Arrivee(double heure_evenement, Simulation* simulation);

        /// @brief Implémente le traitement 
        /// pour un événement de type 'Arrivee'.
        /// @see Caissier::servir(Client* client)
        void traiter();
};

#endif