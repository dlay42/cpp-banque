#include "../include/Simulation.h"
#include "../include/Arrivee.h"

#include <iostream>
using namespace std;

Simulation::Simulation(double duree_prevue, double temps_moyen_arrivee, int nb_caissiers, double temps_moyen_service):SimulationEvenementDiscret(heure_actuelle) {
    this->duree_prevue = duree_prevue;
    this->duree_reelle = 0;
    this->nb_clients = 1;
    this->temps_moyen_arrivee = temps_moyen_arrivee;
    this->banque = new Banque(nb_caissiers, temps_moyen_service, this);
    cout << "Event <ARRIVAL>: Client just arrived at " << "0" << " !" << endl;
    this->evt_queue.push(new Arrivee(0, this));
}

double Simulation::dureePrevue() {
    return duree_prevue;
}

double Simulation::dureeReelle() {
    return duree_reelle;
}

int Simulation::mNbClients() {
    return nb_clients;
}

double Simulation::tempsMoyenArrivee() {
    return temps_moyen_arrivee;
}

Banque* Simulation::mBanque() {
    return banque;
}

void Simulation::setHeureActuelle(double heure_actuelle) {
    this->heure_actuelle = heure_actuelle;
}

void Simulation::incrementNbClients() {
    this->nb_clients++;
}