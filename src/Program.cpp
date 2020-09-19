#include "../include/Client.h"
#include "../include/Caissier.h"
#include "../include/Banque.h"
#include "../include/Simulation.h"
#include "../include/Arrivee.h"
#include "../include/Depart.h"

#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main(int argc, char ** argv) {

    stringstream string_stream;

    double arg_duree_prevue = 10;
    double arg_duree_reelle = 20;
    double arg_temps_moyen_arrivee = 0.5;
    int arg_nb_caissiers = 5;
    double arg_temps_moyen_service = 10;

    cout << "###################### Début de la simulation à " << "0" << " ######################" << endl;
    Simulation *simulation = new Simulation(arg_duree_prevue, arg_duree_reelle, arg_temps_moyen_arrivee, arg_nb_caissiers, arg_temps_moyen_service);
    simulation->lancer();
    cout << "###################### Fin de la simulation ######################" << endl;

    Banque *simulation_banque = simulation->mBanque();
    cout << "##################### STATISTIQUES GLOBALES ######################" << endl;
    cout    << left << setw(35) << "Durée réelle:"
            << left << setw(10) << simulation->dureeReelle() << endl;
    cout    << left << setw(33) << "Nombre de clients:"
            << left << setw(10) << simulation->dureePrevue() << endl;
    cout    << left << setw(33) << "Longueur max. de la file:"
            << left << setw(10) << simulation_banque->mFileAttente()->mLongueurMax() << endl;
    cout    << left << setw(33) << "Longueur moyenne de la file:"
            << left << setw(10) << simulation_banque->mFileAttente()->mLongueurMoyenne() << endl;

    cout << "##################### STATISTIQUES CAISSIERS #####################" << endl;
    for (int i = 0; i < arg_nb_caissiers; i++) {

        string_stream.str(""); string_stream.clear();
        string_stream << i + 1;
        cout    << "Caissier #" + string_stream.str() + " (tmpsServiceMoy " << simulation_banque->mCaissiers()[i]->mTempsMoyenService() << "):" << endl;
        cout    << left << setw(33) << "\t- Taux d'occupation:"
                << left << setw(10) << simulation_banque->mCaissiers()[i]->mTauxOccupation() << endl;
        cout    << left << setw(33) << "\t- Nombre de clients servis:"
                << left << setw(10) << simulation_banque->mCaissiers()[i]->mNbClientsServis() << endl;

    }
    
    
    

    cout << "##################################################################" << endl;
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