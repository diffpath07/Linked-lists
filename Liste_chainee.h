#ifndef _LISTE_CHAINEE
#define _LISTE_CHAINEE


typedef int Element; 

typedef struct Cellule *Place; 

typedef struct Cellule {
    Element valeur; 
    struct Cellule *suivant; // adresse Cellule suivante 
} Cellule ;

typedef Cellule *Liste;

// Déclaration des fonctions gerant la liste

Liste liste_vide (void);

int longueur (Liste l);

Liste inserer (Liste l, int i, Element e);

Liste supprimer (Liste l, int i);

Element keme (Liste l, int k);

Place acces (Liste l, int i);

Element contenu (Liste l, Place i);

Place succ (Liste l, Place i);

//Fonction pour TD :

Liste ajouter (Liste l, Place p, Element e);

Liste enlever (Liste l, Place p);

void afficher (Liste l);

int appartient (Liste l, Element e);

Liste inverser (Liste l);

Liste copier (Liste l);

Liste concatener (Liste l1, Liste l2);

#endif
