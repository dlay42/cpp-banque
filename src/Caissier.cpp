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

Banque* Caissier::mBanque() {
    return banque;
}

// TODO
void Caissier::servir(Client* client) {
    Poisson* generateur_aleatoire = new Poisson();
    generateur_aleatoire->init();

    this->nb_clients_servis++;
    this->disponible = false;

    double heure_depart = banque->mSimulation()->heureActuelle() + generateur_aleatoire->next(temps_moyen_service);    
    cout << "Event <DEPARTURE>: Client has been served and leave at " << heure_depart << " !" << endl;
    banque->mSimulation()->ajouter(new Depart(heure_depart, this, this->mBanque()->mSimulation()));
}

void Caissier::liberer() {
    this->disponible = true;
}

double Caissier::mTempsMoyenService() {
    return temps_moyen_service;
}