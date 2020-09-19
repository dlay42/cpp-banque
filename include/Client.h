/// @file Client.h
/// @author Donald LAY (nomail@private.com)
/// @brief Classe Client
/// @see Client
/// @version 0.1
/// @date 2020-09-19
/// @copyright Copyright (c) 2020

#ifndef CLIENT_H_
#define CLIENT_H_

class Client {

    protected:
        double heure_arrivee;

    public:
        Client(double heure_arrivee);

        // Getter
        double heureArrivee();
};

#endif