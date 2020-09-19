# Projet atelier C++

Mini-projet réalisé dans le cadre de l'atelier C++ de M2 IISC (réseaux et sécurité) durant la période du 07/09/2020 au 11/09/2020. Cet atelier a été proposé par M. Philippe LAROQUE, enseignant au département informatique à l'UFR des sciences et techniques de CY Cergy Paris Université (CYU) (lien du module : https://depinfo.u-cergy.fr/~pl/wiki/wakka.php?wiki=ModuleProgrammationCPP). Il a pour but de nous fournir les bases du language de programmation orienté objet C++ à travers un exercice mettant en oeuvre toutes les spécificités du language.

## Enoncé
Construire une simulation statistique mettant en scène l'arrivée et le service de clients au sein d'une banque.
https://depinfo.u-cergy.fr/~pl/docs/sujetBanque.pdf

## Scénario
### Arrivée d'un client :
* Un client arrive ;
* Si un caissier est disponible, il se dirige vers le caissier le plus proche ; sinon, il rejoins la file d'attente.

### Départ d'un client :
* Le client se fait servir par un caissier selon le temps de service du caissier ;
* Le client servi part de la banque ;
* Si la file d'attente n'est pas vide, le caissier prend en charge le premier de la file ; sinon, le caissier est disponible.

## Hypothèses
* Les arrivées client et services suivent une __loi de Poisson__ (fournie : https://depinfo.u-cergy.fr/~pl/docs/Poisson.h) ;
* Le client est : __honnête__ (il ne double pas), __patient__ (il ne quitte pas la queue (i.e. file d'attente jamais pleine)), __paresseux__ (il va à la caisse la plus proche de l'entrée (caissier[min])) ;
* Le caissier est : __parfait__ (il prend en charge un autre client dès qu'il a fini si la queue n'est pas vide) ;
* La simulation est par __évènements discrets__ (i.e. pas de notion de temps).
    
## Procédure -- Paramètres d'entrée et de sortie
### Paramètres d'entrée :
* Durée prévue : temps à partir duquel on accepte plus de client (/!\ ce n'est pas la fin de la simulation) ;
* Nombre de caissiers ;
* Temps moyen de service (par caissiers) : permet de simuler la différence de performance entre les caissiers (facteur humain) ;
* Temps moyen entre deux arrivées successives de clients.

### Paramètre de sortie :
* Durée réelle : temps auquel la simulation s'achève ;
* Longueur max. et moyenne de la file ;
* Nombre de clients servis (au total et par caissiers) ;
* Taux d'occupation par caissiers : temps de service total/durée réelle. 

## Rendu
### Date
* 20/09/2020
### Livrables
Archive contenant :
* Les sources du projet ;
* La documentation générée par Doxygen ;
* un Makefile permettant compiler/build le projet.

## Programme
### Makefile
Compilation/build :
```
make
```

Cleanup :
```
make clean
```

Lancement du programme :
```
bin/SimulationBanque -d <DUREE_PREVUE> -a <TEMPS_MOY_ARRIVEE> -s <TEMPS_MOY_SERVICE> -c <NB_CAISSIERS>
```
ou (`long` options) :
```
bin/SimulationBanque --duree-prevue <DUREE_PREVUE> --temps-moy-arrivee <TEMPS_MOY_ARRIVEE> -temps-moy-service <TEMPS_MOY_SERVICE> --caissiers <NB_CAISSIERS>
```

__Remarque :__ Il n'y pas de tests unitaires pour les classes implémentées.

### Doxygen
La documentation présente est normalement la dernière à jour. Vous pouvez néanmoins la regénérer (sous Linux) :
```
doxygen DoxyFile
```

Elle est accessible au format `html` au chemin `docs/index.html`.

__Remarque :__ Assurez-vous bien d'avoir les packages `doxygen` et `doxygen-doc` d'installés (ou équivalents selon la distribution).

### Output
Le programme affiche :
* Une journalisation du déroulé de la simulation recensant les actions du client (arrivée, départ, et positionnement dans la file d'attente) ;
* Les paramètres d'entrées de la simulation ;
* Les paramètres statisques de sortie de la simulation.

```
root@dlay-VirtualBox:/var/share/cpp/cpp-banque# bin/SimulationBanque -d 10 -a 0.5 -s 10 -c 5
################### DEBUT DE LA SIMULATION A 0 ###################
Event <ARRIVAL>: Client just arrived at 0 !
Event <DEPARTURE>: Client has been served and leave at 103.544 !
Event <ARRIVAL>: Client just arrived at 0.055666 !
Event <DEPARTURE>: Client has been served and leave at 3.63814 !
Event <ARRIVAL>: Client just arrived at 0.111332 !
Event <DEPARTURE>: Client has been served and leave at 51.2395 !
Event <ARRIVAL>: Client just arrived at 0.166998 !
Event <DEPARTURE>: Client has been served and leave at 5.01793 !
Event <ARRIVAL>: Client just arrived at 0.222664 !
Event <DEPARTURE>: Client has been served and leave at 64.165 !
Event <ARRIVAL>: Client just arrived at 0.27833 !
Aucun caissier disponible - le client rejoint la file à la 1e position ---
Event <ARRIVAL>: Client just arrived at 1.88724 !
Aucun caissier disponible - le client rejoint la file à la 2e position ---
Event <ARRIVAL>: Client just arrived at 3.49616 !
Aucun caissier disponible - le client rejoint la file à la 3e position ---
Event <ARRIVAL>: Client just arrived at 5.10507 !
Event <DEPARTURE>: Client has been served and leave at 7.22061 !
Event <DEPARTURE>: Client has been served and leave at 9.86886 !
Aucun caissier disponible - le client rejoint la file à la 2e position ---
Event <ARRIVAL>: Client just arrived at 6.71398 !
Aucun caissier disponible - le client rejoint la file à la 3e position ---
Event <ARRIVAL>: Client just arrived at 8.3229 !
Event <DEPARTURE>: Client has been served and leave at 10.8031 !
Aucun caissier disponible - le client rejoint la file à la 3e position ---
Event <ARRIVAL>: Client just arrived at 9.93181 !
Event <DEPARTURE>: Client has been served and leave at 14.7198 !
Aucun caissier disponible - le client rejoint la file à la 3e position ---
Event <DEPARTURE>: Client has been served and leave at 14.3856 !
Event <DEPARTURE>: Client has been served and leave at 17.968 !
Event <DEPARTURE>: Client has been served and leave at 19.5707 !
###################### FIN DE LA SIMULATION ######################
################## PARAMETRES DE LA SIMULATION ###################
Durée prévue:                        10             
Nombre de caissiers:                 5              
Temps moyen d'arrivée des clients    0.5            
Temps de service moyen               10             
##################### STATISTIQUES GLOBALES ######################
Durée réelle:                        103.544        
Nombre de clients servis au total:   12             
Longueur max. de la file:            3              
Longueur moyenne de la file:         0.288944       
##################### STATISTIQUES CAISSIERS #####################
Caissier #1 (tmpsServiceMoy 32.1783):
	- Taux d'occupation:                100 %          
	- Nombre de clients servis:         1              
Caissier #2 (tmpsServiceMoy 1.11332):
	- Taux d'occupation:                17.2993 %      
	- Nombre de clients servis:         5              
Caissier #3 (tmpsServiceMoy 15.889):
	- Taux d'occupation:                49.3781 %      
	- Nombre de clients servis:         1              
Caissier #4 (tmpsServiceMoy 1.50752):
	- Taux d'occupation:                18.7396 %      
	- Nombre de clients servis:         4              
Caissier #5 (tmpsServiceMoy 19.8713):
	- Taux d'occupation:                61.7537 %      
	- Nombre de clients servis:         1              
##################################################################
```

### Améliorations
* __Journalisation des événements (désordonnée)__ -- idée : re-empiler les évènements dans une seconde priority_queue et la parcourir à la fin de la simulation (sans traitement) et affichage de message selon le type d'événement (arrivée ou départ) ;
* __Makefile__ : j'ai un peu triché avec des règles génériques raccourcies/faciles (`mv <OBJECTS/EXECUTABLE> <DIR>`) ;
* __Convention de nommage__ : je me suis un peu embrouillé me montrant hésitant sur la convention de nommage à adopter notamment pour les méthodes (préfixée par un `m`) ;
* __Documentation__ : essentielle mais non-exhaustive contenant peut-être des fautes d'orthographe/de syntaxe (relecture verticale) + choix de la langue française pour le nommage des méthodes/variables et pour la documentation (certains passages en anglais) ;
* __Options__ : passage d'arguments au programme via `getopt` faite rapidement sans analyse des valeurs pouvant entraîner des bugs.
