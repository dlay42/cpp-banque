#include "../include/Caissier.h"

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

// TODO
void Caissier::servir(Client* client) {

}

void Caissier::liberer() {
    this->disponible = true;
}

double Caissier::mTempsMoyenService() {
    return temps_moyen_service;
}