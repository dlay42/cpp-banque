#include "../include/Evenement.h"
#include "../include/Simulation.h"

Evenement::Evenement(double heure_evenement, Simulation* simulation) {
    this->heure_evenement = heure_evenement;
    this->simulation = simulation;
}

double Evenement::heureEvenement() {
    return heure_evenement;
}

void Evenement::traiter() {
    
}
