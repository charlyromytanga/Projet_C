#ifndef H_AUTOMATE_H
#define H_AUTOMATE_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"


struct automate{
    int nb_Etats;
    int nb_Symboles;
    int * Etats_finaux;
    int etat_initial;
    int *** matrice;

};


/***************************************DEBUT AUTOMATE**********************************************/

/*************************PARTIE : maîtrise de la structure  AUTOMATE******************************/
typedef struct automate automate;

/*Allocation des états finaux*/
int *allocation_tab_1D(int t1);

/* Allocation nombre d'arcs par état*/
int **allocation_tab_2D(int t2, int t3);

/*La fonction qui alloue de la mémoire*/
int *** allocation_mat_vide(int d1, int d2);


/* La fonction qui génère la matrice nulle d'un automate dit nul*/
automate generate_automate_null(int d1, int d2, int d3);


/* La fonction qui récupère le nombre d'états et le nombres de symboles et génère un automate*/
automate generate_automate();


/* La fonction qui remplis une matrice avec les réponses fournies par un utilisateur*/
automate remplir_automate(automate m, int val);


/*La fonction qui affiche la matrice 3D*/
void  affichage_automate(automate a);

/* La fonction qui les états finaux*/
void lecture_etats_finaux(automate a);

/*La fonction qui examine si l'automate est complet*/
int est_complet(automate a);

/*La fonction qui questionne l'utilisateur avant de rendre complet*/
automate question(automate a, int val);

/*La fonction qui permute deux valeurs*/
void echange(int *a, int *b);

/*La fonction qui copie l'automate dans le but d'en faire une copie*/
automate copie_automate(automate a);

/* La fonction qui lie un automate à ne pas trop utiliser car il va lister tous les chemins possibles*/
int ***lecture_automate(automate a);

/* La fonction teste si un état est un final*/
int est_un_etat_final(automate a, int etat);

/*La fonction qui rend complet un automate*/
automate rendre_complet(automate a);


/*La concaténatiion */
automate concat(automate a, automate b);


/* La fonction qui génère le complément d'un automate*/
automate complement_automate(automate a);

/*************************FIN : maîtrise de la structure  AUTOMATE******************************/

/*************************PARTIE : Déterministe - Non déterministe******************************/

/* La fonction qui contruit la table des transitions de l'autome*/
int ***Tab_transition_automate(automate a);

/* La fonction qui contrtui la table des états obtenus à partir de l' état initial*/
int **Tab_etat_issu_q0(automate a);

/*************************FIN POUR L'AUTOMATE******************************/


/*************************DEBUT MOT***************************************/

struct mot{
    int size_mot;
    int *Tab_caract;
};

typedef struct mot mot;

/*Saisir le mot*/

mot *mot_saisi_avant(automate a);

mot  *mot_saisi(automate a);

/* La fonciton qui affiche le mot*/
void affichage_mot(mot *mot);

/* La fonction qui lie un mot et remmplie une matrice D*/
void  lecture_mot(mot m);

/* La fonction qui retourne l'état courant dans la lecture d'un automate*/
int retourne_etat_couant(automate a, int curent_state, int curent_symbol);

/* La fonction qui dit si un mot est reconnu ou pas par un automate*/
int est_reconnu(mot m, automate a);

/* La fonction qui réalise un certains nombres de test de la reconnaissance de mots*/
int test_reconnaissance(automate a, int n_fois);


/* La fonction qui teste si un mot est reconnu Version 2*/
int reconnu_v2(mot m, automate a);

/* La fonction qui retrouve un état par application d'un symbole du mot*/
int find_next_state(automate a, mot m);

/*
    Étape reconnaître un mot :

La fonction est reconnue :

En fonction de la taille du mot, une boucle est effectuée
Boucle faite sur la taille du mot.
Trois paramètres sont pris en compte
Etat courant mis a q0 au départ
Symbole mis aTab_mot[i=0]
Etat suivant mis a :
Automa.matrice[q0][symbole]

Dans cette boucle deux conditions sont établies :

Avant toute chose : on test si le dernier symbole du mot correspond 
à une transition qui conduit a un état final.
Si tel est le cas alors il y a des chances que ce mot soit reconnu.

Si la valeur retournée par Etat suivant vaut 1
Alors on avance et on met à jour :
Etat courant, il prend la valeur de était suivant 
Symbole, elle prend la valeur de Tab_mot[i+1]
*/



#endif
