#include "../include/Arrivee.h"
#include "../include/Simulation.h"

#include <iostream>
using namespace std;

Arrivee::Arrivee(double heure_evenement, Simulation* simulation):Evenement(heure_evenement, simulation) {
    this->heure_evenement = heure_evenement;
    this->simulation = simulation;
}

void Arrivee::traiter() {
    Poisson* generateur_aleatoire = new Poisson();
    generateur_aleatoire->init();

    Client* nouveau_client = new Client(simulation->heureActuel());
    Caissier* caissier_disponible = simulation->mBanque()->unCaissierDisponible();
    if (caissier_disponible != NULL)
        caissier_disponible->servir(nouveau_client);
    else
        simulation->mBanque()->mFileAttente()->ajouter(nouveau_client);

    double prochaine_echeance = simulation->heureActuel() + generateur_aleatoire->next(simulation->tempsMoyenArrivee());
    if (prochaine_echeance <= simulation->dureePrevue())
        simulation->ajouter(new Arrivee(prochaine_echeance));
}