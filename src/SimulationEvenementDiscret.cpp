#include "../include/SimulationEvenementDiscret.h"

#include <iostream>
using namespace std;

SimulationEvenementDiscret::SimulationEvenementDiscret(double heure_actuelle) {
    this->heure_actuelle = heure_actuelle;
}

double SimulationEvenementDiscret::heureActuelle() {
    return heure_actuelle;
}

priority_queue< Evenement*, vector< Evenement* >, CompareEvenement > SimulationEvenementDiscret::mEvtQueue() {
    return evt_queue;
}

void SimulationEvenementDiscret::ajouter(Evenement* evt) {
    this->evt_queue.push(evt);
}

void SimulationEvenementDiscret::lancer() {}
