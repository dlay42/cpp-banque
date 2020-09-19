/// @file Arrivee.cpp
/// @author Donald LAY (nomail@private.com)
/// @brief Implémente la classe Arrivee, Evenement derived class
/// @see Arrivee
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#include "../include/Arrivee.h"
#include "../include/Simulation.h"

#include <iostream>
using namespace std;

Arrivee::Arrivee(double heure_evenement, Simulation* simulation):Evenement(heure_evenement, simulation) {
    this->heure_evenement = heure_evenement;
    this->simulation = simulation;
}

/// Cette méthode réalise les actions suivantes :\n
/// * calcul de la prochaine échéance (aléatoire en fonction du temps d'arrivée moyen des clients) et si la prochaine échéance ne dépasse pas la durée prévue :\n
///     - création d'un nouveau client (= arrivée d'un client) ;\n
///     - ajout du client dans la file d'attente selon la disponibilité des caissiers ;\n
///     - création de l'événement et ajout dans la file des événements.
void Arrivee::traiter() {
    Poisson* generateur_aleatoire = new Poisson();
    generateur_aleatoire->init();

    Client* nouveau_client = new Client(simulation->heureActuelle());
    Caissier* caissier_disponible = simulation->mBanque()->unCaissierDisponible();
    if (caissier_disponible != NULL)
        caissier_disponible->servir(nouveau_client);
    else
        simulation->mBanque()->mFileAttente()->ajouter(nouveau_client);

    double prochaine_echeance = simulation->heureActuelle() + generateur_aleatoire->next(simulation->tempsMoyenArrivee());
    if (prochaine_echeance <= simulation->dureePrevue()) {
        cout << "Event <ARRIVAL>: Client just arrived at " << prochaine_echeance << " !" << endl;
        simulation->incrementNbClients();
        simulation->ajouter(new Arrivee(prochaine_echeance, this->simulation));
    }
}