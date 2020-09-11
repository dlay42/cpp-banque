#include "../include/Client.h"
#include "../include/Caissier.h"
#include "../include/Banque.h"
#include "../include/Simulation.h"
#include "../include/Arrivee.h"
#include "../include/Depart.h"

#include <iostream>
using namespace std;

int main() {

    Simulation *simulation = new Simulation(10, 20, 0.5, 5, 10);
    Banque *banque_simulation = simulation->mBanque();

    for (int i = 0; i < 5; i++) {
        cout << banque_simulation->mCaissiers()[i]->mTempsMoyenService() << endl;
    }

    // Temps *t = new Temps(duree,nbCaissiers,temps,tempsArrivees);
    // t->declencher();

    // Banque * b = t->banque();

    // // affichage des resultats
    // FileAttente * f = b->fileAttente();
    // cout << "duree Reelle : " << t->dureeReelle() << endl;
    // cout << "nb clients   : " << b->nbClients() << endl;
    // cout << "lg max file  : " << f->longueurMax() << endl;
    // cout << "lg moy file  : " << f->longueurMoyenne() << endl;
    // for (int i = 1; i <= nbCaissiers ; i++) {
    // cout << "caissier " << i << " : ";
    // Caissier * c = b->caissier(i);
    // cout << c->tauxOccupation() << "%, "
    //     << c->nbClients() << " clients\n";
    // }


    return 0;
}