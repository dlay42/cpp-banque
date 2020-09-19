/// @file Banque.cpp
/// @author Donald LAY (nomail@private.com)
/// @brief Implémente la classe Banque
/// @see Banque
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#include "../include/Banque.h"
#include "../include/Simulation.h"
#include "../include/FileAttente.h"

#include <iostream>
using namespace std;

Banque::Banque(int nb_caissiers, double temps_moyen_service, Simulation* simulation) {
    Poisson *generateur_aleatoire = new Poisson();
    generateur_aleatoire->init();
    
    this->nb_caissiers = nb_caissiers;
    this->temps_moyen_service = temps_moyen_service;
    this->nb_clients_servis = 0;
    this->caissiers = new Caissier*[nb_caissiers];
    this->file_attente = new FileAttente(this);
    this->simulation = simulation;

    for (int i = 0; i < nb_caissiers; i++) {
        this->caissiers[i] = new Caissier(generateur_aleatoire->next(temps_moyen_service), this);
    }
}

Caissier** Banque::mCaissiers() {
    return caissiers;
}

FileAttente* Banque::mFileAttente() {
    return file_attente;
}

Simulation* Banque::mSimulation() {
    return simulation;
}

/// Parcours de la liste des Caissier de la banque (caissiers) :\n
/// * tant qu'un Caissier n'est pas disponible, continuer le parcours ;\n
/// * retourner le premier Caissier disponible (lazy cashier behaviour) -- sinon, NULL.
Caissier* Banque::unCaissierDisponible() {
    int i = 0;
    Caissier *caissier_courant;

    do {
        caissier_courant = caissiers[i];
        i++;
    } while (!caissier_courant->estDisponible() && i < nb_caissiers);

    if (i <= nb_caissiers && caissier_courant->estDisponible())
        return caissier_courant;
    else
        return NULL;
}
