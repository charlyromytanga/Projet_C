#ifndef H_GENERATE_3D_H
#define H_GENERATE_3D_H

#include<stdio.h>
#include<stdlib.h>
#include "string.h"

# include "Automate.h"

struct Noeud
{
    /* data */
    int val;
    struct Noeud *suivant;
    
};

typedef struct Noeud *Noeud;


automate  generate_3D();
int parcourir_val_matrice( automate a);

int *information_automate();

void affichage_3D(automate a);
void affichage_2D(int **m, int d1, int d2);
void affichage_1D(int *tab, int d1);


#endif

