#include "../include/Simulation.h"

Simulation::Simulation(double duree_prevue, double duree_reelle, double temps_moyen_arrivee, int nb_caissiers, double temps_moyen_service):SimulationEvenementDiscret(heure_actuel) {
    this->duree_prevue = duree_prevue;
    this->duree_reelle = duree_reelle;
    this->temps_moyen_arrivee = temps_moyen_arrivee;
    this->banque = new Banque(nb_caissiers, temps_moyen_service, this);
}

double Simulation::dureePrevue() {
    return duree_prevue;
}

double Simulation::dureeReelle() {
    return duree_reelle;
}

double Simulation::tempsMoyenArrivee() {
    return temps_moyen_arrivee;
}

Banque* Simulation::mBanque() {
    return banque;
}