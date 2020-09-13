#ifndef CLIENT_H_
#define CLIENT_H_

class Client {

    protected:
        double heure_arrivee;

    public:
        Client(double heure_arrivee);
        double heureArrivee();

        ~Client();
};

#endif