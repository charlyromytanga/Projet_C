/**
 * @file Automate.h
 * @author Charly romy TANGA - Abdoulaye MBAYE - Berkehan USLU (you@domain.com)
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


/*Une structure intermédiaire : util pour la lecture d'automate long*/
/*Ajout d'une structute lecture automate avec trois attributs*/

/*-----------------------------------*/
struct table_de_lecture_automate{
    /* data */
    int ***etat_lu_depart;
    int ***etats_lus_intermediaires;
    int ***etats_lus_finaux;
};

typedef struct table_de_lecture_automate etats_lus;
/*-----------------------------------*/
/*************************************/


struct mot{
    int size_mot;
    int *Tab_caract;
};

typedef struct mot mot;
/*--------------------------------*/
/***********************************/


/*############################################################################################################*/
/*************************DEBUT AUTOMATE**********************************************/


/*************************PARTIE I: Objectif maîtrise de la structure  AUTOMATE************************/

/* Question 1. Manipuler un AEF :

            - Saisir un AEF.
            - Importer un AEF à partir d'un fichier.
            - Modifier un AEF.
            - Sauvegarder un AEF dans un fichier.
            - Supprimer un AEF. 
*/

/*Bloc de fonctions mobilisées  (menu déroulant): */

    /* /*Allocation des états finaux
    int *allocation_tab_1D(int t1);

    /* La fonction qui affiche un tableau_1D
    void affichage_1D(int *tab, int dim_tab_1D);


    /*  La fonction qui affiche une case d'un tableau_1D
    void affichage_case_tab_1D(int *tab, int position, int dim_tab_1D);


    /* Allocation nombre d'arcs par état
    int **allocation_tab_2D(int t2, int t3);


    /* La fonction qui affiche un tableau_2D
    void affichage_2D(int **tab, int dim_tab_2D_ligne, int dim_tab_2D_col);


    /* La fonction qui affiche un élément d'un tableau_2D
    void affichage_case_tab_2D(int **tab, int position_line, int position_col, int dim_tab_2D_ligne, int dim_tab_2D_col);

    /*La fonction qui alloue de la mémoire
    int *** allocation_mat_vide(int d1, int d2);


    /* La fonction qui affiche une ligne donnée d'une matrice
    void affichage_ligne_mat(int ***tab, int position_line, int dim_tab_3D_ligne, int dim_tab_3D_col);


    /* La fonction qui affiche une colonne donnée d'une matrice
    void affichage_col_mat(int ***tab, int position_col, int dim_tab_3D_ligne, int dim_tab_3D_col);


    /* La fonction qui affiche une case d'une matrice
    void affichage_case_mat(int ***tab, int position_line, int position_col, int dim_tab_3D_ligne, int dim_tab_3D_col);

    /* La fonction qui génère la matrice nulle d'un automate dit nul
    automate generate_automate_null(int d1, int d2, int d3);


    /* La fonction qui récupère le nombre d'états et le nombres de symboles et génère un automate
    automate generate_automate();


    /* La fonction qui remplis une matrice avec les réponses fournies par un utilisateur
    automate remplir_automate(automate m, int val);


    /* La fonction teste si un état est un final
    int est_un_etat_final(automate a, int etat);


    /* La fonction qui les états finaux
    void lecture_etats_finaux(automate a);


    /*La fonction qui affiche tous les attributs d'un automate
    void  affichage_automate(automate a);


    /*La fonction qui importe un automate depuis un fichier txt
    automate import_automae(char path);


    /*La fonction qui modifie un automate
    automate modify_automate(automate a);


    /*La fonction qui sauvegarde un automate dans un fichier
    automate save_automate(automate a);


    /*La fonction qui supprime un automate
    automate del_automate(automate a);

*/




/* Question 3. Vérifier si un automate est complet.*/

/*Bloc de fonctions mobilisées  (menu déroulant): */

    /*/*La fonction qui examine si l'automate est complet
    int est_complet(automate a);
*/





/* Question 4. Rendre un automate complet.*/

/*Bloc de fonctions mobilisées  (menu déroulant): */
    /*/*La fonction qui examine si l'automate est complet
    int est_complet(automate a);
    /*La fonction qui rend complet un automate
    automate rendre_complet(automate a);
*/






/* Question 5. Vérifier si un automate est déterministe.*/

/*Bloc de fonctions mobilisées  (menu déroulant): */
    /*La fonction qui teste si un automate est déterministe ou pas
    int est_deterministe(automate a);
    /*La fonction qui alloue de la mémoire
    int *** allocation_mat_vide(int d1, int d2);
    /* La fonction qui contruit la table des transitions d'un automate passé en paramètre sans imprimer
    int ***Tab_transition_automate_not_print(automate a)
*/





/* Question 6. Rendre un AEF déterministe (voir le cours les langages réguliers).*/

/*Bloc de fonctions mobilisées  (menu déroulant): */
    /* La fonction qui retrouve tous les états atteints par application d'un symbole à un état donnée
    int *Next_states_touch_not_print(automate a, int start_state, int symbol_apply);

    /* La fonction qui vérifie si un éatat existe dans la table des transition passée en paramètre
    int exist_state_in_tab_transi(automate a, int state_touch, int ***tab1);


    /* La fonction qui ajoute un état composite dans une table des états composites
    int **add_state_to_composite_table(automate a, int **tab, int composite_state, int position)


    /* La fonction qui contrtui la table des états obtenus à partir de l' état initial par application
    d'un symbole donné usage pour la fonction rendre déterministe
    int *Tab_states_from_q0_not_print(automate a, int symbol_apply);


    /* la fonction  qui ajoute un état  dans une table des états renommés
    int ***add_state_to_rename_table_state(automate a, int ***tan_rename, int new_state, int position)

*/



/* Question 7. Réaliser les opérations suivantes sur les AEFs :

                -Complément d'un AEF : Le complément d'un AEF est un nouvel AEF obtenu en
                    inversant les états finaux et non finaux de l'AEF d'origine. Si un état était final
                    dans l'AEF d'origine, il devient non final dans le complément, et vice versa.
                    
                -Miroir d'un AEF : Le miroir d'un AEF est un nouvel AEF obtenu en inversant la
                    direction des transitions de l'AEF d'origine. Autrement dit, si l'AEF d'origine avait
                    une transition de l'état A vers l'état B avec un symbole donné, le miroir aura une
                    transition de l'état B vers l'état A avec le même symbole. Les états finaux (resp.
                    initiaux) sont initiaux (resp. finaux) dans le nouvel AEF.-Produit de deux AEFs : Le produit de deux AEFs A et B, noté A * B, est un nouvel
                    AEF dont les états sont toutes les combinaisons d'états possibles de A et B. Les
                    états finaux du produit sont ceux pour lesquels les états correspondants de A et B
                    sont tous deux finaux. Les transitions sont définies de manière similaire, où les
                    transitions du produit relient les états en fonction des transitions des AEFs
                    d'origine.

                -Produit de deux AEFs : Le produit de deux AEFs A et B, noté A * B, est un nouvel
                    AEF dont les états sont toutes les combinaisons d'états possibles de A et B. Les
                    états finaux du produit sont ceux pour lesquels les états correspondants de A et B
                    sont tous deux finaux. Les transitions sont définies de manière similaire, où les
                    transitions du produit relient les états en fonction des transitions des AEFs
                    d'origine.

                -Concaténation de deux AEFs : La concaténation de deux AEFs A et B, notée
                    A.B, est un nouvel AEF où les états et transitions de A sont suivis immédiatement
                    par les états et transitions de B. Les états finaux de A.B sont les états finaux de
                    B, et l'état initial de A.B est l'état initial de A.Pour plus d’informations, vous
                    pouvez consulter le site suivant : https://www.lirmm.fr/~lafourcade/ML-
                    ensei

*/

/*Bloc de fonctions mobilisées  (menu déroulant): */
    /* La fonction qui génère le complément d'un automate
    automate complement_automate(automate a)
    /*La concaténatiion 
    automate concat(automate a, automate b)
*/

/**************************FIN DE LA PARTIE I**********************************************/


/*************************PARTIE II: Objectif Déterminisme************************/

/**************************FIN DE LA PARTIE : II **********************************************/


/*************************PARTIE III: BLOC DE PROTOTYPAGE DE FONCTIONS************************/

//Sous-bloc de fonction qui ne retourne rien

/* La fonction qui affiche un tableau_1D*/
/**
 * @brief 
 * 
 * @param tab 
 * @param dim_tab_1D 
 */
void affichage_1D(int *tab, int dim_tab_1D);

/*  La fonction qui affiche une case d'un tableau_1D*/
/**
 * @brief 
 * 
 * @param tab 
 * @param position 
 * @param dim_tab_1D 
 */
void affichage_case_tab_1D(int *tab, int position, int dim_tab_1D);

/* La fonction qui affiche un tableau_2D*/
/**
 * @brief 
 * 
 * @param tab 
 * @param dim_tab_2D_ligne 
 * @param dim_tab_2D_col 
 */
void affichage_2D(int **tab, int dim_tab_2D_ligne, int dim_tab_2D_col);

/* La fonction qui affiche un élément d'un tableau_2D*/
/**
 * @brief 
 * 
 * @param tab 
 * @param position_line 
 * @param position_col 
 * @param dim_tab_2D_ligne 
 * @param dim_tab_2D_col 
 */
void affichage_case_tab_2D(int **tab, int position_line, int position_col, int dim_tab_2D_ligne, int dim_tab_2D_col);

/* La fonction qui affiche une ligne donnée d'une matrice*/
/**
 * @brief 
 * 
 * @param tab 
 * @param position_line 
 * @param dim_tab_3D_ligne 
 * @param dim_tab_3D_col 
 */
void affichage_ligne_mat(int ***tab, int position_line, int dim_tab_3D_ligne, int dim_tab_3D_col);

/* La fonction qui affiche une colonne donnée d'une matrice*/
/**
 * @brief 
 * 
 * @param tab 
 * @param position_col 
 * @param dim_tab_3D_ligne 
 * @param dim_tab_3D_col 
 */
void affichage_col_mat(int ***tab, int position_col, int dim_tab_3D_ligne, int dim_tab_3D_col);

/* La fonction qui affiche une case d'une matrice*/
/**
 * @brief 
 * 
 * @param tab 
 * @param position_line 
 * @param position_col 
 * @param dim_tab_3D_ligne 
 * @param dim_tab_3D_col 
 */
void affichage_case_mat(int ***tab, int position_line, int position_col, int dim_tab_3D_ligne, int dim_tab_3D_col);

/*La fonction qui affiche la matrice 3D*/
/**
 * @brief 
 * 
 * @param a 
 */
void  affichage_automate(automate a);

/* La fonction qui les états finaux*/
/**
 * @brief 
 * 
 * @param a 
 */
void lecture_etats_finaux(automate a);

/*La fonction qui permute deux valeurs*/
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 */
void echange(int *a, int *b);

/* La fonciton qui affiche le mot*/
/**
 * @brief 
 * 
 * @param mot 
 */
void affichage_mot(mot *mot);

/* La fonction qui lie un mot et remmplie une matrice D*/
/**
 * @brief 
 * 
 * @param m 
 */
void  lecture_mot(mot m);



//Sous-bloc de fonction qui ne retourne un entier
/*La fonction qui teste si un automate est déterministe ou pas*/
/**
 * @brief 
 * 
 * @param a 
 * @return int 
 */
int est_deterministe(automate a);

/*La fonction qui examine si l'automate est complet*/
/**
 * @brief 
 * 
 * @param a 
 * @return int 
 */
int est_complet(automate a);

/* La fonction teste si un état est un final*/
/**
 * @brief 
 * 
 * @param a 
 * @param etat 
 * @return int 
 */
int est_un_etat_final(automate a, int etat);

/* La fonction qui vérifie si un éatat existe dans la table des transition passée en paramètre*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_touch 
 * @param tab1 
 * @return int 
 */
int exist_state_in_tab_transi(automate a, int state_touch, int ***tab1);

/* La fonction qui retourne la position de l'état atteint par application d'un symbole partant d'un état donné*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_start 
 * @param symbol_apply 
 * @return int 
 */
int Next_one_state_touch(automate a, int state_start, int symbol_apply);

/* La fonction qui fait la somme d'apparution du chiffre 1 par appel de la fonction Next_states_touch_not_print*/
/**
 * @brief 
 * 
 * @param a 
 * @param tab_states_touch 
 * @return int 
 */
int calculte_number_states_touch(automate a, int *tab_states_touch);

/* La fonction qui commence avec deux états initaux de deux automates dont on fera le produit*/
/**
 * @brief 
 * 
 * @param etat_initial_a 
 * @param etat_initial_b 
 * @return int 
 */
int start_with_tow(int etat_initial_a, int etat_initial_b);

/* La fonction qui retourne l'état courant dans la lecture d'un automate*/
/**
 * @brief 
 * 
 * @param a 
 * @param curent_state 
 * @param curent_symbol 
 * @return int 
 */
int retourne_etat_couant(automate a, int curent_state, int curent_symbol);

/* La fonction qui dit si un mot est reconnu ou pas par un automate*/
/**
 * @brief 
 * 
 * @param m 
 * @param a 
 * @return int 
 */
int est_reconnu(mot m, automate a);

/* La fonction qui réalise un certains nombres de test de la reconnaissance de mots*/
/**
 * @brief 
 * 
 * @param a 
 * @param n_fois 
 * @return int 
 */
int serie_test_reconnaissance(automate a, int n_fois);

/* La fonction qui teste si un mot est reconnu Version 2*/
/**
 * @brief 
 * 
 * @param m 
 * @param a 
 * @return int 
 */
int reconnu_v2(mot m, automate a);

/* La fonction qui retrouve un état par application d'un symbole du mot*/
/**
 * @brief 
 * 
 * @param a 
 * @param m 
 * @return int 
 */
int find_next_state(automate a, mot m);



//Sous-bloc de fonction qui ne retourne un tableau_1D
/*Allocation des états finaux*/
/**
 * @brief 
 * 
 * @param t1 
 * @return int* 
 */
int *allocation_tab_1D(int t1);

/* La fonction qui produit tous les états atteints par application d'un symbole à un état donnée*/
/**
 * @brief 
 * 
 * @param a 
 * @param start_state 
 * @param symbol_apply 
 * @return int* 
 */
int *Next_states_touch(automate a, int start_state, int symbol_apply);

/* La fonction qui retrouve tous les états atteints par application d'un symbole à un état donnée*/
/**
 * @brief 
 * 
 * @param a 
 * @param start_state 
 * @param symbol_apply 
 * @return int* 
 */
int *Next_states_touch_not_print(automate a, int start_state, int symbol_apply);

/* La fonction qui contrtui la table des états obtenus à partir de l' état initial*/
/**
 * @brief 
 * 
 * @param a 
 * @param symbol_apply 
 * @return int* 
 */
int *Tab_states_from_q0(automate a, int symbol_apply);

/* La fonction qui contrtui la table des états obtenus à partir de l' état initial par application d'un symbole donné usage pour la fonction rendre déterministe*/
/**
 * @brief 
 * 
 * @param a 
 * @param symbol_apply 
 * @return int* 
 */
int *Tab_states_from_q0_not_print(automate a, int symbol_apply);

/* La fonction qui regoupe les états atteints par le même symbole depuis l'état initial*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_apply 
 * @param symbol_fix 
 * @return int* 
 */
int *group_states_by_same_symbol(automate a, int state_apply, int symbol_fix);

/* La fonction qui regoupe les états atteints par le même symbole depuis l'état initial*/
/* La fonction qui est appelée dans la fonction Tab_transition car elle n'imprime rien*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_apply 
 * @param symbol_fix 
 * @return int* 
 */
int *group_states_by_same_symbol_not_print(automate a, int state_apply, int symbol_fix);

/*La fonction qui réalise la réunion d'états obtenus par application d'un symbole identique partant d'un état donné*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_apply 
 * @param symbol_fix 
 * @return int* 
 */
int *union_states_of_same_symbol(automate a, int state_apply, int symbol_fix);

/*La fonction qui réalise la réunion d'états obtenus par application d'un symbole identique partant d'un état donné*/
/* La fonction qui est appelée dans la fonction Tab_transition car elle n'imprime rien*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_apply 
 * @param symbol_fix 
 * @return int* 
 */
int *union_states_of_same_symbol_not_print(automate a, int state_apply, int symbol_fix);


//Sous-bloc de fonction qui ne retourne un tableau_2D
/* La fonction qui ajoute un état composite dans une table des états composites*/
/**
 * @brief 
 * 
 * @param a 
 * @param tab 
 * @param composite_state 
 * @param position 
 * @return int** 
 */
int **add_state_to_composite_table(automate a, int **tab, int composite_state, int position);

/* La fonction qui copie la ligne d'une matrice*/
/**
 * @brief 
 * 
 * @param a 
 * @param mat 
 * @param position_line 
 * @return int** 
 */
int **copy_line_mat(automate a, int ***mat, int position_line);

/* Allocation nombre d'arcs par état*/
/**
 * @brief 
 * 
 * @param t2 
 * @param t3 
 * @return int** 
 */
int **allocation_tab_2D(int t2, int t3);



//Sous-bloc de fonction qui ne retourne un tableau_3D
/*La fonction qui alloue de la mémoire*/
/**
 * @brief 
 * 
 * @param d1 
 * @param d2 
 * @return int*** 
 */
int *** allocation_mat_vide(int d1, int d2);

/* La fonction qui lie un automate à ne pas trop utiliser car il va lister tous les chemins possibles*/
/**
 * @brief 
 * 
 * @param a 
 * @return int*** 
 */
int ***lecture_automate_court(automate a);

/* la fonction  qui ajoute un état  dans une table des états renommés*/
/**
 * @brief 
 * 
 * @param a 
 * @param tan_rename 
 * @param new_state 
 * @param position 
 * @return int*** 
 */
int ***add_state_to_rename_table_state(automate a, int ***tan_rename, int new_state, int position);

/* La fonction qui contruit la table des transitions de l'autome*/
/**
 * @brief 
 * 
 * @param a 
 * @return int*** 
 */
int ***Tab_transition_automate(automate a);

/* La fonction qui contruit la table des transitions d'un automate passé en paramètre sans imprimer*/
/**
 * @brief 
 * 
 * @param a 
 * @return int*** 
 */
int ***Tab_transition_automate_not_print(automate a);

/* La fonction qui retourne les états atteints par application simultannée d'un symbole partant d'une paire  états ou pas*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_1 
 * @param state_2 
 * @param symbol_1 
 * @param symbol_2 
 * @return int*** 
 */
int ***twos_symbol_apply(automate a,  int state_1, int state_2, int symbol_1, int symbol_2);



//Sous-bloc de fonction qui ne retourne un automate
/* La fonction qui génère la matrice nulle d'un automate dit nul*/
/**
 * @brief 
 * 
 * @param d1 
 * @param d2 
 * @param d3 
 * @return automate 
 */
automate generate_automate_null(int d1, int d2, int d3);

/* La fonction qui récupère le nombre d'états et le nombres de symboles et génère un automate*/
/**
 * @brief 
 * 
 * @return automate 
 */
automate generate_automate();

/* La fonction qui remplis une matrice avec les réponses fournies par un utilisateur*/
/**
 * @brief 
 * 
 * @param m 
 * @param val 
 * @return automate 
 */
automate remplir_automate(automate m, int val);

/*La fonction qui importe un automate depuis un fichier txt*/
/**
 * @brief 
 * 
 * @param path 
 * @return automate 
 */
automate import_automae(char path);

/*La fonction qui modifie un automate*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate modify_automate(automate a);

/*La fonction qui sauvegarde un automate dans un fichier*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate save_automate(automate a);

/*La fonction qui supprime un automate*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate del_automate(automate a);

/*La fonction qui copie l'automate dans le but d'en faire une copie*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate copie_automate(automate a);

/*La fonction qui rend complet un automate*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate rendre_complet(automate a);

/*La concaténatiion */
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return automate 
 */
automate concat(automate a, automate b);

/* La fonction qui génère le complément d'un automate*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate complement_automate(automate a);

/* La fonction qui rend un automate déterministe*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate rendre_deterministe(automate a);

/* La fonction qui fait le produit de deux automates et retourne une automate*/
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return automate 
 */
automate producte_a_b(automate a, automate b);

/**********Fonction reposant sur une structure intermediaire*******************************************/
/*-----------------------------------------------------------------------------------------------------*/
/*Ajout d'une structute lecture automate avec trois attributs*/

/* La fonction qui lie un automate à ne pas trop utiliser car il va lister tous les chemins possibles*/
/* Sa nautre : etats_lus*/
/**
 * @brief 
 * 
 * @param a 
 * @return etats_lus 
 */
etats_lus lecture_automate_long(automate a);



//Sous-bloc de fonction qui ne retourne un mot
/*************************FIN DU BLOC DE PROTOTYPAGE DE FONCTIONS************************/

#endif