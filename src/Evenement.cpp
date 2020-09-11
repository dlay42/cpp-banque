#include "../include/Evenement.h"

Evenement::Evenement(double heure_evenement) {
    this->heure_evenement = heure_evenement;
}

double Evenement::heureEvenement() {
    return heure_evenement;
}

void Evenement::traiter() {

}
