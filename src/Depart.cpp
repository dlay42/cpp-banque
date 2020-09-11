#include "../include/Depart.h"

Depart::Depart(double heure_evenement, Caissier* caissier, Client* client):Evenement(heure_evenement, simulation) {
    this->heure_evenement = heure_evenement;
    this->caissier = caissier;
    this->client = client;
}

// TODO
void Depart::traiter() {

}