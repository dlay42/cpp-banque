/// @file FileAttente.cpp
/// @author Donald LAY (nomail@private.com)
/// @brief Implémente la classe FileAttente
/// @see FileAttente
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#include "../include/FileAttente.h"
#include "../include/Banque.h"
#include "../include/Simulation.h"

#include <iostream>
using namespace std;

FileAttente::FileAttente(Banque* banque) {
    this->longueur_max = 0;
    this->longueur_moyenne = 0;
    this->attente_moyenne = 0;
    this->banque = banque;
}

int FileAttente::mLongueurMax() {
    return longueur_max;
}

double FileAttente::mLongueurMoyenne() {
    if (banque->mSimulation()->dureeReelle() != 0)
        return longueur_moyenne / banque->mSimulation()->dureeReelle();
    else
        return 0;
}

int FileAttente::taille() {
    return this->file_clients.size();
}

void FileAttente::ajouter(Client* client) {
    cout << "Aucun caissier disponible - le client rejoint la file à la " << this->file_clients.size() + 1 << "e position ---" << endl;
    this->file_clients.push_back(client);
    if (file_clients.size() > longueur_max)
        this->longueur_max = file_clients.size();
}

void FileAttente::ajouterContributionLongueurMoyenne(double contribution) {
    this->longueur_moyenne += contribution;
}

bool FileAttente::estVide() {
    return file_clients.empty();
}

Client* FileAttente::retirer() {
    Client* premier_file = this->file_clients.front();
    this->file_clients.pop_front();
    return premier_file;
    
}
