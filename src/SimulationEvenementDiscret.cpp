/// @file SimulationEvenementDiscret.cpp
/// @author Donald LAY (nomail@private.com)
/// @brief Implémente la classe SimulationEvenementDiscret, Simulation base class
/// @see SimulationEvenementDiscret
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

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

/// Méthode vide.
void SimulationEvenementDiscret::lancer() {}
