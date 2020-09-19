/// @file Depart.h
/// @author Donald LAY (nomail@private.com)
/// @brief Classe Depart, Evenement derived class
/// @see Depart
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

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
        
        /// @brief Implémente le traitement
        /// pour un événement de type 'Depart'.
        /// @see Caissier::servir(Client* client)
        void traiter();
};

#endif