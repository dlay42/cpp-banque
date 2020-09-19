#ifndef CAISSIER_H_
#define CAISSIER_H_

#include "../include/Client.h"
#include "../include/Depart.h"

class Banque;
class Caissier {
    protected:
        bool disponible;
        double temps_moyen_service;
        int nb_clients_servis;
        double taux_occupation;
        Banque* banque;

    public:
        // Getters
        bool estDisponible();
        double mTempsMoyenService();
        double mTauxOccupation();
        int mNbClientsServis();
        Banque* mBanque();

        Caissier(double temps_moyen_service, Banque* banque);
        void servir(Client* client);
        void liberer();
};

#endif