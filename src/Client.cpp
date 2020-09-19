/// @file Client.cpp
/// @author Donald LAY (nomail@private.com)
/// @brief Implémente la classe Client
/// @see Client
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#include "../include/Client.h"

Client::Client(double heure_arrivee) {
    this->heure_arrivee = heure_arrivee;
}

double Client::heureArrivee() {
    return heure_arrivee;
}