#include "../include/Depart.h"
#include "../include/Simulation.h"

Depart::Depart(double heure_evenement, Caissier* caissier, Client* client):Evenement(heure_evenement, simulation) {
    this->heure_evenement = heure_evenement;
    this->caissier = caissier;
    this->client = client;
}

void Depart::traiter() {
    FileAttente *file_clients = simulation->mBanque()->mFileAttente();
    if (!file_clients->estVide()) {
        Client *premier_client = file_clients->retirer();
        caissier->servir(premier_client);
    } else {
        caissier->liberer();
    }
}