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

}

void Caissier::liberer() {
    this->disponible = true;
}

double Caissier::mTempsMoyenService() {
    return temps_moyen_service;
}