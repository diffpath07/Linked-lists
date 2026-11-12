#include <stdio.h>
#include <stdlib.h>        
#include "Liste_chainee.h"


Liste liste_vide() {
return NULL;
}

int longueur(Liste l) {
    int taille=0;
    while(l) {
        taille++;
        l=l->suivant;
    }
    return taille;
}

Liste inserer(Liste l, int i, Element e) {

    if (i<1 || i>longueur(l)+ 1) {
        printf("Erreur : rang non valide !\n");
        exit(-1);
    }
    Liste pc = (Liste)malloc(sizeof(Cellule));
    pc->valeur=e;
    pc->suivant=NULL;
    if (i==1){
        pc->suivant=l;
        return pc;
    }
    Liste p=l;
    for (int j=1; j<i-1; j++) {
        p=p->suivant;
    }
    pc->suivant=p->suivant;
    p->suivant=pc;
    return l;
}

Place acces(Liste l, int k) {
    int i;
    Place p;
    if (k<1 || k>longueur(l)) {
        printf("Erreur: rang invalide !\n");
        exit(-1);
    }
    if(k==1) {
        return l;
    }else {
        p=l;
        for(i=1; i<k; i++) {
            p=p->suivant;
        }
        return p;
    }
}



Element contenu(Liste l, Place p) {  
    if (longueur(l) == 0) {
        printf("Erreur: liste vide !\n");
        exit(-1);
    }
    return p->valeur;
}


Place succ(Liste l, Place p) {
    if (p->suivant == NULL) {
        printf("Erreur: suivant dernière place!\n");
        exit(-1);
    }
    return p->suivant;
}


