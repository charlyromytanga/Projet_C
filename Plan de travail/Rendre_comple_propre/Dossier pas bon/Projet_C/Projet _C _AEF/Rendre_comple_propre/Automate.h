#ifndef H_AUTOMATE_H
#define H_AUTOMATE_H

#include<stdio.h>
#include<stdlib.h>
#include "string.h"


struct automate{
    int nb_Etats;
    int nb_Symboles;
    int * finaux;
    int initial;
    int *** matrice;

};

typedef struct automate automate;
/*La fonction qui récupère le nombre d'états et le nombres de symboles*/
int *information_automate();

/* La fonction qui génère la matrice nulle d'un automate dit nul*/
automate generate_automate_null(int d1, int d2, int d3);


/* La fonction qui remplis une matrice avec les réponses fournies par un utilisateur*/
automate remplir_automate(automate m, int val);


/*La fonction qui génère une matrice 3D*/
automate  saisir_automate();

/*La fonction qui affiche la matrice 3D*/
void  affichage_3D(automate a);


/*La fonction qui examine si l'automate est complet*/
int est_complet(automate a);

/*La fonction qui questionne l'utilisateur avant de rendre complet*/
automate question(automate a, int val);

/*La fonction qui permute deux valeurs*/
void echange(int *a, int *b);

/*La fonction qui copie l'automate dans le but d'en faire une copie*/
automate copie_automate(automate a, automate b);


/*La fonction qui rend complet un automate*/
automate rendre_complet(automate a);


#endif
