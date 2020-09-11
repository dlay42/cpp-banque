#ifndef EVENEMENT_H_
#define EVENEMENT_H_

class Evenement {
    protected:
        double heure_evenement;

    public:
        Evenement(double heure_evenement);

        // Getter
        double heureEvenement();
        
        void traiter();
};

#endif