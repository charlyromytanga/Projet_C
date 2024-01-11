/**
 * @file Automate.h
 * @author charly romy TANGA  (charlyromytanga.cytech@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef H_AUTOMATE_H
#define H_AUTOMATE_H

/*Include other file*/
#include "automate.c"
#include "main.c"


/* All structure define */

struct automate{

    int nb_Etats;
    int nb_Symboles;

    int etat_initial;
    int *Etats_finaux;
    int nb_Etats_finaux;
    int *** matrice;

    int *** Table_transition;

};
typedef struct automate automate;
/*--------------------------------*/
/***********************************/

int *alloc_tab_1D(int t1);
int *** alloc_mat_vide(int d1, int d2);
automate generator_automate();


#endif