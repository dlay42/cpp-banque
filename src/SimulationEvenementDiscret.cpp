#include "../include/SimulationEvenementDiscret.h"

#include <iostream>
using namespace std;

SimulationEvenementDiscret::SimulationEvenementDiscret(double heure_actuelle) {
    this->heure_actuelle = heure_actuelle;
}

// TODO
double SimulationEvenementDiscret::heureActuelle() {
    return heure_actuelle;
}

priority_queue< Evenement*, vector< Evenement* >, CompareEvenement > SimulationEvenementDiscret::mEvtQueue() {
    return evt_queue;
}

void SimulationEvenementDiscret::ajouter(Evenement* evt) {
    this->evt_queue.push(evt);
}

void SimulationEvenementDiscret::lancer() {
    Evenement *evt_courant;
    while (!evt_queue.empty()) {
        evt_courant = this->evt_queue.top();
        this->evt_queue.pop();
        this->heure_actuelle = evt_courant->heureEvenement();
        evt_courant->traiter();
    }
}
