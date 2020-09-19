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

        // Getter
        virtual double heureEvenement();
        
        virtual void traiter();
};

#endif