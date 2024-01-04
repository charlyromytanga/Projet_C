#ifndef H_AUTOMATE_H
#define H_AUTOMATE_H

#include "automate.c"
#include "main.c"


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


/* La fonction qui affiche un tableau_1D*/
void affichage_1D(int *tab, int dim_tab_1D);

/*  La fonction qui affiche une case d'un tableau_1D*/
void affichage_case_tab_1D(int *tab, int position, int dim_tab_1D);

/* La fonction qui affiche un tableau_2D*/
void affichage_2D(int **tab, int dim_tab_2D_ligne, int dim_tab_2D_col);

/* La fonction qui affiche un élément d'un tableau_2D*/
void affichage_case_tab_2D(int **tab, int position_line, int position_col, int dim_tab_2D_ligne, int dim_tab_2D_col);

/* La fonction qui affiche une ligne donnée d'une matrice*/
void affichage_ligne_mat(int ***tab, int position_line, int dim_tab_3D_ligne, int dim_tab_3D_col);

/* La fonction qui affiche une colonne donnée d'une matrice*/
void affichage_col_mat(int ***tab, int position_col, int dim_tab_3D_ligne, int dim_tab_3D_col);

/* La fonction qui affiche une case d'une matrice*/
void affichage_case_mat(int ***tab, int position_line, int position_col, int dim_tab_3D_ligne, int dim_tab_3D_col);

/*La fonction qui affiche la matrice 3D*/
void  affichage_automate(automate a);

/* La fonction qui les états finaux*/
void lecture_etats_finaux(automate a);

/*La fonction qui permute deux valeurs*/
void echange(int *a, int *b);



/*La fonction qui teste si un automate est déterministe ou pas*/
int est_deterministe(automate a);

/*La fonction qui examine si l'automate est complet*/
int est_complet(automate a);

/* La fonction teste si un état est un final*/
int est_un_etat_final(automate a, int etat);

/* La fonction qui vérifie si un éatat existe dans la table des transition passée en paramètre*/
int exist_state_in_tab_transi(automate a, int state_touch, int ***tab1);

/* La fonction qui retourne la position de l'état atteint par application d'un symbole partant d'un état donné*/
int Next_one_state_touch(automate a, int state_start, int symbol_apply);

/* La fonction qui fait la somme d'apparution du chiffre 1 par appel de la fonction Next_states_touch_not_print*/
int calculte_number_states_touch(automate a, int *tab_states_touch);

/* La fonction qui commence avec deux états initaux de deux automates dont on fera le produit*/
int start_with_tow(int etat_initial_a, int etat_initial_b);

/*Allocation des états finaux*/
int *allocation_tab_1D(int t1);

/* La fonction qui produit tous les états atteints par application d'un symbole à un état donnée*/
int *Next_states_touch(automate a, int start_state, int symbol_apply);

/* La fonction qui retrouve tous les états atteints par application d'un symbole à un état donnée*/
int *Next_states_touch_not_print(automate a, int start_state, int symbol_apply);

/* La fonction qui contrtui la table des états obtenus à partir de l' état initial*/
int *Tab_states_from_q0(automate a, int symbol_apply);

/* La fonction qui contrtui la table des états obtenus à partir de l' état initial par application d'un symbole donné usage pour la fonction rendre déterministe*/
int *Tab_states_from_q0_not_print(automate a, int symbol_apply);

/* La fonction qui regoupe les états atteints par le même symbole depuis l'état initial*/
int *group_states_by_same_symbol(automate a, int state_apply, int symbol_fix);

/* La fonction qui regoupe les états atteints par le même symbole depuis l'état initial*/
/* La fonction qui est appelée dans la fonction Tab_transition car elle n'imprime rien*/
int *group_states_by_same_symbol_not_print(automate a, int state_apply, int symbol_fix);

/*La fonction qui réalise la réunion d'états obtenus par application d'un symbole identique partant d'un état donné*/
int *union_states_of_same_symbol(automate a, int state_apply, int symbol_fix);

/*La fonction qui réalise la réunion d'états obtenus par application d'un symbole identique partant d'un état donné*/
/* La fonction qui est appelée dans la fonction Tab_transition car elle n'imprime rien*/
int *union_states_of_same_symbol_not_print(automate a, int state_apply, int symbol_fix);




/* La fonction qui ajoute un état composite dans une table des états composites*/
int **add_state_to_composite_table(automate a, int **tab, int composite_state, int position);

/* La fonction qui copie la ligne d'une matrice*/
int **copy_line_mat(automate a, int ***mat, int position_line);



/*La fonction qui alloue de la mémoire*/
int *** allocation_mat_vide(int d1, int d2);

/* Allocation nombre d'arcs par état*/
int **allocation_tab_2D(int t2, int t3);

/* La fonction qui lie un automate à ne pas trop utiliser car il va lister tous les chemins possibles*/
int ***lecture_automate_court(automate a);

/* la fonction  qui ajoute un état  dans une table des états renommés*/
int ***add_state_to_rename_table_state(automate a, int ***tan_rename, int new_state, int position);

/* La fonction qui contruit la table des transitions de l'autome*/
int ***Tab_transition_automate(automate a);

/* La fonction qui contruit la table des transitions d'un automate passé en paramètre sans imprimer*/
int ***Tab_transition_automate_not_print(automate a);

/* La fonction qui retourne les états atteints par application simultannée d'un symbole partant d'une paire  états ou pas*/
int ***twos_symbol_apply(automate a,  int state_1, int state_2, int symbol_1, int symbol_2);




/* La fonction qui génère la matrice nulle d'un automate dit nul*/
automate generate_automate_null(int d1, int d2, int d3);

/* La fonction qui récupère le nombre d'états et le nombres de symboles et génère un automate*/
automate generate_automate();

/* La fonction qui remplis une matrice avec les réponses fournies par un utilisateur*/
automate remplir_automate(automate m, int val);

/*La fonction qui importe un automate depuis un fichier txt*/
automate import_automae(char path);

/*La fonction qui modifie un automate*/
automate modify_automate(automate a);

/*La fonction qui sauvegarde un automate dans un fichier*/
automate save_automate(automate a);

/*La fonction qui supprime un automate*/
automate del_automate(automate a);

/*La fonction qui copie l'automate dans le but d'en faire une copie*/
automate copie_automate(automate a);

/*La fonction qui rend complet un automate*/
automate rendre_complet(automate a);

/*La concaténatiion */
automate concat(automate a, automate b);

/* La fonction qui génère le complément d'un automate*/
automate complement_automate(automate a);

/* La fonction qui rend un automate déterministe*/
automate rendre_deterministe(automate a);

/* La fonction qui fait le produit de deux automates et retourne une automate*/
automate producte_a_b(automate a, automate b);

/**********Fonction reposant sur une structure*********************************************************/
/*-----------------------------------------------------------------------------------------------------*/
/*Ajout d'une structute lecture automate avec trois attributs*/

/* La fonction qui lie un automate à ne pas trop utiliser car il va lister tous les chemins possibles*/
/* Sa nautre : etats_lus*/

etats_lus lecture_automate_long(automate a);
/*-----------------------------------------------------------------------------------------------------*/
/***************************************FIN Ajout d'une structure intermediaire*************************/


/*************************FIN DU BLOC DE PROTOTYPAGE DE FONCTIONS************************/



/**************************FIN POUR L'AUTOMATE**********************************************/
/*############################################################################################################*/










/*############################################################################################################*/
/*************************DEBUT MOT*******************************************************/



/*************************PARTIE I: Objectif maîtrise de la structure  MOT************************/

/*--> Question 2 : Reconnaissance d'un mot par un automate*/
/**************************FIN DE LA PARTIE I**********************************************/






/*************************PARTIE II: Objectif Aller un peu plus loin************************/

/**************************FIN DE LA PARTIE : II **********************************************/








/*************************PARTIE III: BLOC DE PROTOTYPAGE DE FONCTIONS************************/

/* La fonciton qui affiche le mot*/
void affichage_mot(mot *mot);

/* La fonction qui lie un mot et remmplie une matrice D*/
void  lecture_mot(mot m);



/* La fonction qui retourne l'état courant dans la lecture d'un automate*/
int retourne_etat_couant(automate a, int curent_state, int curent_symbol);

/* La fonction qui dit si un mot est reconnu ou pas par un automate*/
int est_reconnu(mot m, automate a);

/* La fonction qui réalise un certains nombres de test de la reconnaissance de mots*/
int serie_test_reconnaissance(automate a, int n_fois);

/* La fonction qui teste si un mot est reconnu Version 2*/
int reconnu_v2(mot m, automate a);

/* La fonction qui retrouve un état par application d'un symbole du mot*/
int find_next_state(automate a, mot m);



/*La fonction qui saisi le mot*/
mot *mot_saisi_avant(automate a);

mot  *mot_saisi(automate a);

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

/*************************FIN DU BLOC DE PROTOTYPAGE DE FONCTIONS************************/



/**************************FIN MOT**********************************************************/
/*############################################################################################################*/



#endif
