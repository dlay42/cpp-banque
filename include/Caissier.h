#ifndef CAISSIER_H_
#define CAISSIER_H_

#include "../include/Client.h"

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

        Caissier(double temps_moyen_service, Banque* banque);
        void servir(Client* client);
        void liberer();
};

#endif