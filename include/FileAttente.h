/// @file FileAttente.h
/// @author Donald LAY (nomail@private.com)
/// @brief Classe FileAttente
/// @see FileAttente
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#ifndef FILEATTENTE_H_
#define FILEATTENTE_H_

#include "../include/Client.h"
#include <deque>
using namespace std;

class Banque;
class FileAttente {
    protected:
        int longueur_max;
        double longueur_moyenne;
        double attente_moyenne;
        Banque* banque;
        deque< Client* > file_clients;

    public:
        FileAttente(Banque* banque);

        // Getter
        /// @brief Paramètre statistique de sortie du programme.
        /// @return int : longueur maximale de la FileAttente durant la Simulation.
        int mLongueurMax();

        /// @brief Paramètre statistique de sortie du programme.
        /// @return double : longueur moyenne de la FileAttente durant la Simulation.
        double mLongueurMoyenne();
        int taille();

        /// @brief Ajoute un Client dans la FileAttente (deque file_clients).
        /// @param client Client* : Client à ajouter dans la FileAttente (deque file_clients).
        void ajouter(Client* client);

        /// @brief Ajout d'une contribution de temps pour le calcul de la longueur moyenne de la FileAttente.
        /// @param contribution double : contribution de temps entre deux arrivées de Clients dans la FileAttente (fenêtre de temps * longueur de la file).
        /// @see FileAttente::mLongueurMoyenne()
        void ajouterContributionLongueurMoyenne(double contribution);

        /// @brief Vérifie si la FileAttente (deque file_clients) est vide.
        /// @return bool : true si la FileAttente (deque file_clients) est vide false sinon.
        bool estVide();

        /// @brief Retire le premier Client de la FileAttente (deque file_clients).
        /// @return Client* : Client retiré de la FileAttente (deque file_clients).
        Client* retirer();
};

#endif