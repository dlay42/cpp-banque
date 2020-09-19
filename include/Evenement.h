/// @file Evenement.h
/// @author Donald LAY (nomail@private.com)
/// @brief Classe Evenement, Arrivee & Depart base class
/// @see Evenement
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#ifndef EVENEMENT_H_
#define EVENEMENT_H_

class Simulation;
class Evenement {
    protected:
        double heure_evenement;
        Simulation* simulation;

    public:
        Evenement(double heure_evenement, Simulation* simulation);
        Evenement();

        /// @brief Liaison dynamique pour l'accesseur de heure_evenement
        /// des événements de type 'Arrivee' et 'Depart'.
        virtual double heureEvenement();

        /// @brief Liaison dynamique pour le traitement
        /// des événements de type 'Arrivee' et 'Depart'.
        /// @see Arrivee::traiter()
        /// @see Depart::traiter()
        virtual void traiter();
};

#endif