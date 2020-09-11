#include "../include/Client.h"

Client::Client(double heure_arrivee) {
    this->heure_arrivee = heure_arrivee;
}

double Client::heureArrivee() {
    return heure_arrivee;
}