
# Linked-lists

Singly linked list in C, with the exercises from TD2 (Structure de Données en C, Faculté des Sciences Rabat).

## Files

- `Liste_chainee.h`: types (`Element`, `Cellule`, `Place`, `Liste`) and function declarations
- `Liste_chainee.c`: basic functions (`liste_vide`, `longueur`, `inserer`, `acces`, `contenu`, `succ`)
- `TD_listeCH.c`: TD2 exercises (`ajouter`, `supprimer`, `enlever`, `keme`, `afficher`, `appartient`, `inverser`, `concatener`)

## Compile

There is no `main`, so this only checks for errors:

    gcc -c Liste_chainee.c TD_listeCH.c
