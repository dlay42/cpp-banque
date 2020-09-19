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