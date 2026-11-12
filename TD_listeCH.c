#include <stdio.h>
#include <stdlib.h>        
#include "Liste_chainee.h"


/*Exercice 1*/

Liste ajouter(Liste l, Place p, Element e) {
    Liste pc = (Liste)malloc(sizeof(Cellule));
    if (pc == NULL) {
        printf("Problème d'allocation mémoire \n");
        exit(-1);
    }
    pc->valeur = e;
    pc->suivant = p->suivant;
    p->suivant = pc;
    return l;
}


Liste supprimer(Liste l, int i) {
    Place p, q;
    if (i < 1 || i > longueur(l)) {
        printf("Rang invalide \n");
        exit(-1);
    } else {
        if (i == 1) {
            p = l;
            l = l->suivant;
        } else {
            q = acces(l, i-1);
            p = succ(l, q);
            q->suivant = p->suivant;
        }
        free(p);
        return l;
    }
}


Liste enlever(Liste l, Place p) {
    Place pred;
    if (p == l)
        l = l->suivant;
    else {
        pred = l;
        while (succ(l, pred) != p)
            pred = pred->suivant;
        pred->suivant = p->suivant;
    }
    free(p);
    return l;
}



Element keme(Liste l, int k) {
    if (k < 1 || k > longueur(l)) {
        printf("Rang invalide \n");
        exit(-1);
    }
    return contenu(l, acces(l, k));
}


/*Exercice 2*/

void afficher(Liste l) {
    for (int i = 1; i <= longueur(l); i++)
        printf("%d -> ", keme(l, i));
    printf("NULL \n");
}
//version 2 :
void afficher2(Liste l) {
    Liste p = l;
    while (p != NULL) {
        printf("%d -> ", p->valeur);
        p = p->suivant;
    }
    printf("NULL \n");
}


int appartient(Liste l, Element e) {
    int i;
    for (i = 1; i <= longueur(l); i++) {
        if (keme(l, i) == e)
            return 1;
    }
    return 0;
}

//version 2 :
int appartient2(Liste l, Element e) {
    Liste p = l;
    while (p != NULL) {
        if (p->valeur == e)
            return 1;
        p = p->suivant;
    }
    return 0;
}


Liste inverser(Liste l) {
    Liste p = l;
    Liste q = liste_vide();
    while (l != NULL) {
        l = l->suivant;
        p->suivant = q;
        q = p;
        p = l;
    }
    return q;
}


Liste concatener(Liste l1, Liste l2) {
    Liste lc = liste_vide();
    int i, j, n1 = longueur(l1), n2 = longueur(l2);
    for (i = 1; i <= n1; i++)
        lc = inserer(lc, i, keme(l1, i));
    for (i = n1+1, j = 1; j <= n2; i++, j++)
        lc = inserer(lc, i, keme(l2, j));
    return lc;
}