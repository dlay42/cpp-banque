#include "../include/FileAttente.h"

FileAttente::FileAttente(Banque* banque) {
    this->longueur_max = 0;
    this->longueur_moyenne = 0;
    this->attente_moyenne = 0;
    this->banque = banque;
}

void FileAttente::ajouter(Client client) {
    this->file_clients.push_back(client);
}

bool FileAttente::estVide() {
    return file_clients.empty();
}

Client FileAttente::retirer() {
    Client premier_file = this->file_clients.front();
    this->file_clients.pop_front();
    return premier_file;
    
}
