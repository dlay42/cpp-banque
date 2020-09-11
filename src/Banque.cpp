#include "../include/Banque.h"

Banque::Banque(int nb_caissiers, double temps_moyen_service) {
    Poisson *generateur_aleatoire = new Poisson();
    generateur_aleatoire->init();
    
    this->nb_caissiers = nb_caissiers;
    this->temps_moyen_service = temps_moyen_service;
    this->nb_clients_servis = 0;
    this->caissiers = new Caissier*[nb_caissiers];
    this->file_attente = new FileAttente(this);

    for (int i = 0; i < nb_caissiers; i++) {
        this->caissiers[i] = new Caissier(generateur_aleatoire->next(temps_moyen_service), this);
    }
}

Caissier* Banque::unCaissierDisponible() {
    int i = 0;
    Caissier *caissier_courant;

    do {
        caissier_courant = caissiers[i];
        i++;
    } while (!caissier_courant->estDisponible() && i < nb_caissiers);
    
    if (i <= nb_caissiers)
        return caissier_courant;
    else
        return NULL;
}

Caissier** Banque::mCaissiers() {
    return caissiers;
}
