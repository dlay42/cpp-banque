#include "../include/FileAttente.h"
#include "../include/Banque.h"

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
    return longueur_moyenne;
}

void FileAttente::ajouter(Client* client) {
    cout << "Aucun caissier disponible - le client rejoint la file à la " << this->file_clients.size() << "eme position ---" << endl;
    this->file_clients.push_back(client);
}

bool FileAttente::estVide() {
    return file_clients.empty();
}

Client* FileAttente::retirer() {
    Client* premier_file = this->file_clients.front();
    this->file_clients.pop_front();
    return premier_file;
    
}
