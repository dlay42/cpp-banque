#include "../include/Arrivee.h"

Arrivee::Arrivee(double heure_evenement):Evenement(heure_evenement, simulation) {
    this->heure_evenement = heure_evenement;
    this->simulation = simulation;
}

// TODO
void Arrivee::traiter() {
    
}