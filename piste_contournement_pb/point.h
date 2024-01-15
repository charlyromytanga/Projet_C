#ifndef H_AUTOMATE_H
#define H_AUTOMATE_H

/* include other file.c*/
#include "point.c"
#include "test.c"

/* Structure*/
struct aef
{
    /* data */
    int nb_Etats;
    int nb_Symboles;
    int nb_Etat_finaux;

    int etat_init;
    
    int *Tab_etats_finaux;

    int ***Tab_transition;
    int ***matrice;
};
typedef struct aef aef;



/* List of fonctions*/

/* Miror of one afe*/
aef miror(aef a);
#endif