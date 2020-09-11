#ifndef ARRIVEE_H_
#define ARRIVEE_H_

#include "../include/Evenement.h"

class Arrivee:public Evenement {
    public:
        Arrivee(double heure_evenement);
        void traiter();
};

#endif