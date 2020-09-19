/// @file Simulation.cpp
/// @author Donald LAY (nomail@private.com)
/// @brief Implémente la classe Simulation, SimulationEvenementDiscret derived class
/// @see Simulation
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#include "../include/Simulation.h"
#include "../include/Arrivee.h"

#include <iostream>
using namespace std;

/// Initialise / créer la première Arrivee de Client.
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
    this->duree_reelle = heure_actuelle;
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

/// Cette méthode réalise les actions suivantes :\n
/// * parcours de la file des Evenement (priority_queue) :\n
///     - retire l'Evenement de la priority_queue et la traite selon son type (Arrivee ou Depart) ;\n
///     - ajoute la contribution en temps pour le calcul de longueur moyenne de la FileAttente.
void Simulation::lancer() {
    Evenement *evt_courant = new Evenement();
    double heure_dernier_evt = 0;
    while (!evt_queue.empty()) {
        heure_dernier_evt = evt_courant->heureEvenement();
        evt_courant = this->evt_queue.top();
        this->evt_queue.pop();
        this->heure_actuelle = evt_courant->heureEvenement();

        // Add time contribution for file avg. time computation
        banque->mFileAttente()->ajouterContributionLongueurMoyenne((heure_actuelle - heure_dernier_evt) * banque->mFileAttente()->taille());

        evt_courant->traiter();
    }
}