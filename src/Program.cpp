#include "../include/Client.h"
#include "../include/Caissier.h"
#include "../include/Banque.h"
#include "../include/Simulation.h"
#include "../include/Arrivee.h"
#include "../include/Depart.h"

#include <getopt.h>
#include <typeinfo>
#include <cmath>

#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char** argv) {

    double arg_duree_prevue = -1;
    double arg_temps_moyen_arrivee = -1;
    int arg_nb_caissiers = -1;
    double arg_temps_moyen_service = -1;

    // Command line arguments parser
    // (Inspiré de l'exemple provenant de https://www.gnu.org)
    int c;
    
    while (1) {
        static struct option long_options[] =
        {
            {"duree-prevue",       required_argument, 0, 'd'},
            {"temps-moy-arrivee",  required_argument, 0, 'a'},
            {"temps-moy-service",  required_argument, 0, 's'},
            {"caissiers",          required_argument, 0, 'c'}
        };

        int option_index = 0;
        c = getopt_long (argc, argv, "a:c:d:s:", long_options, &option_index);

        // Détection de la fin des options
        if (c == -1)
            break;

        double valeur_numerique = 0;
        switch (c) {
            // Durée prévue --duree-prevue
            case 'd':
                try {
                    valeur_numerique = stod(optarg);
                } catch (...) {
                    cerr << argv[0] << ": durée prévue (option --duree-prevue ou -d) invalide: valeur décimale attendue -- " << optarg << " reçu." << endl;
                    throw;
                }

                if (valeur_numerique > 0)
                    arg_duree_prevue = valeur_numerique;
                else {
                    cerr << argv[0] << ": durée prévue (option --duree-prevue ou -d) invalide: valeur décimale positive attendue -- " << optarg << " reçu." << endl;
                    return 2;
                }
                break;

            // Temps moyen d'arrivée des clients --temps-moy-arrivee
            case 'a':
                try {
                    valeur_numerique = stod(optarg);
                } catch (...) {
                    cerr << argv[0] << ": temps moyen d'arrivée des clients (option --temps-moy-arrivee ou -a) invalide: valeur décimale attendue -- " << optarg << " reçu." << endl;
                    throw;
                }

                if (valeur_numerique > 0)
                    arg_temps_moyen_arrivee = valeur_numerique;
                else {
                    cerr << argv[0] << ": temps moyen d'arrivée des clients (option --temps-moy-arrivee ou -a) invalide: valeur décimale positive attendue -- " << optarg << " reçu." << endl;
                    return 2;
                }
                break;

            // Temps de service moyen des caissiers --temps-moy-service
            case 's':
                try {
                    valeur_numerique = stod(optarg);
                } catch (...) {
                    cerr << argv[0] << ": temps de service moyen des caissiers (option --temps-moy-service ou -s) invalide: valeur décimale attendue -- " << optarg << " reçu." << endl;
                    throw;
                }

                if (valeur_numerique > 0)
                    arg_temps_moyen_service = valeur_numerique;
                else {
                    cerr << argv[0] << ": temps de service moyen des caissiers (option --temps-moy-service -s) invalide: valeur décimale positive attendue -- " << optarg << " reçu." << endl;
                    return 2;
                }
                break;

            // Nombre de caissiers --caissiers
            case 'c':
                try {
                    valeur_numerique = stod(optarg);
                } catch (...) {
                    cerr << argv[0] << ": nombre de caissiers (option --caissiers ou -c) invalide: valeur entière attendue -- " << optarg << " reçu." << endl;
                    throw;
                }

                if (valeur_numerique > 0 && fmod(valeur_numerique, 1) == 0)
                    arg_nb_caissiers = valeur_numerique;
                else {
                    cerr << argv[0] << ": nombre de caissiers (option --caissiers ou -c) invalide: valeur entière positive attendue -- " << optarg << " reçu." << endl;
                    return 2;
                }
                break;

            case '?':
                // Message d'erreur généré par getopt_long
                return 2;
                break;

            default:
                abort ();
        }
    }

    /* Vérification des valeurs des arguments passés
     * Cas possible : un argument n'a pas été renseigné
     * CHOIX DU DEVELOPPEUR :
     *   - arguments REQUIRED ;
     *   - pas de valeurs par défaut.
     */
    
    // Durée prévue --duree-prevue
    if (arg_duree_prevue == -1) {
        cerr << argv[0] << ": paramètre --duree-prevue (-d) de la simulation manquant." << endl;
        return 2;
    }

    // Temps moyen d'arrivée des clients --temps-moy-arrivee
    if (arg_temps_moyen_arrivee == -1) {
        cerr << argv[0] << ": paramètre --temps-moy-arrivee (-a) de la simulation manquant." << endl;
        return 2;
    }

    // Temps de service moyen des caissiers --temps-moy-service
    if (arg_temps_moyen_service == -1) {
        cerr << argv[0] << ": paramètre --temps-moy-service (-s) de la simulation manquant." << endl;
        return 2;
    }

    // Nombre de caissiers --caissiers
    if (arg_nb_caissiers == -1) {
        cerr << argv[0] << ": paramètre --caissiers (-c) de la simulation manquant." << endl;
        return 2;
    }


    cout << "################### DEBUT DE LA SIMULATION A " << "0" << " ###################" << endl;
    Simulation *simulation = new Simulation(arg_duree_prevue, arg_temps_moyen_arrivee, arg_nb_caissiers, arg_temps_moyen_service);
    simulation->lancer();
    cout << "###################### FIN DE LA SIMULATION ######################" << endl;

    cout << "################## PARAMETRES DE LA SIMULATION ###################" << endl;
    cout    << left << setw(39) << "Durée prévue:"
            << left << setw(15) << arg_duree_prevue << endl;
    cout    << left << setw(37) << "Nombre de caissiers:"
            << left << setw(15) << arg_nb_caissiers << endl;
    cout    << left << setw(38) << "Temps moyen d'arrivée des clients"
            << left << setw(15) << arg_temps_moyen_arrivee << endl;
    cout    << left << setw(37) << "Temps de service moyen"
            << left << setw(15) << arg_temps_moyen_service << endl;

    Banque *simulation_banque = simulation->mBanque();
    cout << "##################### STATISTIQUES GLOBALES ######################" << endl;
    cout    << left << setw(39) << "Durée réelle:"
            << left << setw(15) << simulation->heureActuelle() << endl;
    cout    << left << setw(37) << "Nombre de clients:"
            << left << setw(15) << simulation->mNbClients() << endl;
    cout    << left << setw(37) << "Longueur max. de la file:"
            << left << setw(15) << simulation_banque->mFileAttente()->mLongueurMax() << endl;
    cout    << left << setw(37) << "Longueur moyenne de la file:"
            << left << setw(15) << simulation_banque->mFileAttente()->mLongueurMoyenne() << endl;

    cout << "##################### STATISTIQUES CAISSIERS #####################" << endl;
    stringstream string_stream;
    for (int i = 0; i < arg_nb_caissiers; i++) {
        string_stream.str(""); string_stream.clear();
        string_stream << simulation_banque->mCaissiers()[i]->mTauxOccupation();
        cout    << "Caissier #" << i + 1 << " (tmpsServiceMoy " << simulation_banque->mCaissiers()[i]->mTempsMoyenService() << "):" << endl;
        cout    << left << setw(37) << "\t- Taux d'occupation:"
                << left << setw(15) << string_stream.str() + " %" << endl;
        cout    << left << setw(37) << "\t- Nombre de clients servis:"
                << left << setw(15) << simulation_banque->mCaissiers()[i]->mNbClientsServis() << endl;
    }

    cout << "##################################################################" << endl;

    return 0;
}