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

int est_complet(automate a);
automate rendre_complet(automate a);

#endif

