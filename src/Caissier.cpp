/// @file Caissier.cpp
/// @author Donald LAY (nomail@private.com)
/// @brief Implémente la classe Caissier
/// @see Caissier
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#include "../include/Caissier.h"
#include "../include/Banque.h"
#include "../include/Simulation.h"
#include "../include/SimulationEvenementDiscret.h"
#include "../include/Poisson.h"

#include <iostream>
using namespace std;

Caissier::Caissier(double temps_moyen_service, Banque* banque) {
    this->temps_moyen_service = temps_moyen_service;
    this->nb_clients_servis = 0;
    this->taux_occupation = 0;
    this->disponible = true;
    this->banque = banque;
}

bool Caissier::estDisponible() {
    return disponible;
}

double Caissier::mTempsMoyenService() {
    return temps_moyen_service;
}

double Caissier::mTauxOccupation() {
    if (banque->mSimulation()->dureeReelle() != 0)
        return (taux_occupation / banque->mSimulation()->dureeReelle()) * 100;
    else
        return 0;
}

int Caissier::mNbClientsServis() {
    return nb_clients_servis;
}

Banque* Caissier::mBanque() {
    return banque;
}

/// Cette méthode est utilisée par les événement Arrivee et Depart et réalise les actions suivantes :\n
/// * calcul de la date de départ du Client (aléatoire en fonction du temps de service du Caissier) ;\n
/// * mise à jour du taux d'occupation du Caissier ;\n
/// * création et ajout d'un Depart de Client dans la file d'événement.
void Caissier::servir(Client* client) {
    Poisson* generateur_aleatoire = new Poisson();
    generateur_aleatoire->init();

    this->nb_clients_servis++;
    this->disponible = false;

    double heure_depart = banque->mSimulation()->heureActuelle() + generateur_aleatoire->next(temps_moyen_service);    
    
    // Add time contribution for busy stats. computation
    this->taux_occupation += heure_depart - banque->mSimulation()->heureActuelle();

    cout << "Event <DEPARTURE>: Client has been served and leave at " << heure_depart << " !" << endl;
    banque->mSimulation()->ajouter(new Depart(heure_depart, this, this->mBanque()->mSimulation()));
}

void Caissier::liberer() {
    this->disponible = true;
}