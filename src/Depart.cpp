/// @file Depart.cpp
/// @author Donald LAY (nomail@private.com)
/// @brief Implémente la classe Depart, Evenement derived class
/// @see Depart
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020


#include "../include/Depart.h"
#include "../include/Simulation.h"
#include "../include/Caissier.h"

#include <iostream>
using namespace std;

Depart::Depart(double heure_evenement, Caissier* caissier, Simulation* simulation):Evenement(heure_evenement, simulation) {
    this->heure_evenement = heure_evenement;
    this->caissier = caissier;
    this->simulation = simulation;
}

/// Cette méthode réalise les actions suivantes :\n
/// * récupère la file d'attente (clients) via Simulation -> Banque 
///     - SI : la file n'est pas vide :\n
///         - sers le premier client dans la file d'attente :\n
///             - ...(omitted for brievety -- cf. class Caissier) ;\n
///             - création d'un nouveau Depart ;\n
///     - SINON : rend le caissier disponible.
void Depart::traiter() {
    FileAttente *file_clients = simulation->mBanque()->mFileAttente();
    if (!file_clients->estVide()) {
        Client *premier_client = file_clients->retirer();
        caissier->servir(premier_client);
    } else {
        caissier->liberer();
    }
}