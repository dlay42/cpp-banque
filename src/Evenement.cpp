/// @file Evenement.cpp
/// @author Donald LAY (nomail@private.com)
/// @brief Implémente la classe Evenement, Arrivee & Depart base class
/// @see Evenement
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#include "../include/Evenement.h"
#include "../include/Simulation.h"

Evenement::Evenement(double heure_evenement, Simulation* simulation) {
    this->heure_evenement = heure_evenement;
    this->simulation = simulation;
}

Evenement::Evenement() {}

double Evenement::heureEvenement() {
    return heure_evenement;
}

/// Méthode vide.
void Evenement::traiter() {}
