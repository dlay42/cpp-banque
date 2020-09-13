#include "../include/SimulationEvenementDiscret.h"

SimulationEvenementDiscret::SimulationEvenementDiscret(double heure_actuel) {
    this->heure_actuel = heure_actuel;
}

// TODO
double SimulationEvenementDiscret::heureActuel() {
    return heure_actuel;
}

priority_queue< Evenement*, vector< Evenement* >, CompareEvenement > SimulationEvenementDiscret::mEvtQueue() {
    return evt_queue;
}

void SimulationEvenementDiscret::ajouter(Evenement* evt) {
    evt_queue.push(evt);
}

void SimulationEvenementDiscret::lancer() {

}
