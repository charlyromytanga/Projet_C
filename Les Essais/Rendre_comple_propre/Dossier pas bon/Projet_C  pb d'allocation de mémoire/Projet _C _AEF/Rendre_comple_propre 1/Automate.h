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

/*La fonction qui génère une matrice 3D*/
automate  generate_3D();

/*La fonction qui affiche la matrice 3D*/
void  affichage_3D(automate a);


/*La fonction qui examine si l'automate est complet*/
int est_complet(automate a);

/*La fonction qui questionne l'utilisateur avant de rendre complet*/
automate question(automate a, int val);

/*La fonction qui permute deux valeurs*/
void echange(int *a, int *b);


/*La fonction qui remplis la matrice d'un automate par une valeur*/
automate remplissage(automate a, int val1);


/*La fonction qui copie l'automate dans le but d'en faire une copie*/
automate copie_automate (automate origine, automate copie, automate tmp);


/*Proposition de la fonction qui trouve les états cibles et cré les arcs vers le nouvel état final de l'automate complet*/
automate creation_arc(automate a);

/*La fonction qui rend complet un automate*/
automate rendre_complet(automate a);


#endif
