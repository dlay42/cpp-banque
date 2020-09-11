# Projet atelier C++

## Cahier des charges

### Enoncé
https://depinfo.u-cergy.fr/~pl/docs/sujetBanque.pdf

### Préambule

Simulation d'une agence bancaire :
* N caissiers
* Clients qui arrivent de façon pseudo-aléatoire

=> Quand un client arrive, 
Si un ou des caissiers se libère il se dirige vers un caissier
Sinon il se place dans une queue :
    * Quand c'est son tour, il se dirige vers un caissier.

### Algorithme
Paramètres d'entrée :
    * Durée prévue : temps à partir duquel on accepte plus de client (:warning: ce n'est pas la fin de la simulation) ;
    * Nombre de caissiers ;
    * Temps moyen de service (/caissiers) : permet de simuler la différence de performance entre les caissiers (facteur humain) ;
    * Temps moyen entre deux arrivées successives de clients.

Paramètre de sortie :
    * Durée réelle : temps de fin de la simulation ;
    * Longueur max. et moyenne de la file ;
    * Nombre de clients servis (au total et par caissiers) ;
    * Temps moyen d'attente dans la file ;
    * Taux d'occupation par caissiers : temps de service total/durée total simulation. 

Hypothèse :
    * Arrivées et services poissonniens
    * Le client est :
        * Honnête : il ne double pas ;
        * Patient : il ne quitte pas la queue (i.e. file d'attente jamais pleine) ;
        * Paresseux : il va à la caisse la plus proche de l'entrée (caissier[min]). 
    * Le caissier est :
        * Parfait : il prend un autre client dès qu'il a fini si la queue n'est pas vide.
    * Simulation par évènement discrets (pas par pas d'horloge).

### Rendu

Doxygen