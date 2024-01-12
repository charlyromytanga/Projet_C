/**
 * @file automate.c
 * @author Charly romy TANGA - Abdoulaye MBAYE - Berkehan USLU (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "Automate.h"
#include "main.c"

/* Code de chaque fonction prototypée dans le .h*/

//Sous-bloc de fonction qui ne retourne rien

/* La fonction qui affiche un tableau_1D*/
/**
 * @brief 
 * 
 * @param tab 
 * @param dim_tab_1D 
 */
void affichage_1D(int *tab, int dim_tab_1D){

    // Déclaration de variables locales

    // Instructions
    printf("Tab_1D : [");
    for(int i=0; i<dim_tab_1D; i++){
        printf("%d", tab[i]);
    }
    printf("]\n");
    // La fonction retourne :
}

/*  La fonction qui affiche une case d'un tableau_1D*/
/**
 * @brief 
 * 
 * @param tab 
 * @param position 
 * @param dim_tab_1D 
 */
void affichage_case_tab_1D(int *tab, int position, int dim_tab_1D){

    // Déclaration de variables locales

    // Instructions
    for(int i=0; i<dim_tab_1D; i++){
        printf("Tab_1D[%d]=%d\n", position, tab[position]);
    }
    // La fonction retourne :
}

/* La fonction qui affiche un tableau_2D*/
/**
 * @brief 
 * 
 * @param tab 
 * @param dim_tab_2D_ligne 
 * @param dim_tab_2D_col 
 */
void affichage_2D(int **tab, int dim_tab_2D_ligne, int dim_tab_2D_col){

    // Déclaration de variables locales

    // Instructions
    printf("Tab_2D:\n");
    printf("\n");

    for(int i=0; i<(dim_tab_2D_ligne); i++){

        printf("%d: [ ", i);
        for(int j=0; j<(dim_tab_2D_col); j++ ){

            printf(" %d ", tab[i][j]);
        }
        printf(" ]\n"); 
    }
    // La fonction retourne :
}

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
void affichage_case_tab_2D(int **tab, int position_line, int position_col, int dim_tab_2D_ligne, int dim_tab_2D_col){

    // Déclaration de variables locales

    // Instructions
    printf("Elémént recherché dans Tab_2D:");
    for(int i=0; i<(dim_tab_2D_ligne); i++){

        for(int j=0; j<(dim_tab_2D_col); j++ ){

            printf("tab_2D[%d]=%d\n", position_line, tab[position_line][j]);

        }
        printf("\n");
        
    }
    // La fonction retourne :
}

/* La fonction qui affiche une ligne donnée d'une matrice*/
/**
 * @brief 
 * 
 * @param tab 
 * @param position_line 
 * @param dim_tab_3D_ligne 
 * @param dim_tab_3D_col 
 */
void affichage_ligne_mat(int ***tab, int position_line, int dim_tab_3D_ligne, int dim_tab_3D_col){

    // Déclaration de variables locales

    // Instructions
    printf("Ligne sélectionnée dans mat_3D : \n");
    printf("\n");
    for(int i=0; i<(dim_tab_3D_ligne); i++){

        printf("ligne_mat[q%d]:\n", position_line);
        for(int j=0; j<(dim_tab_3D_col); j++ ){

            for(int k=0; k<dim_tab_3D_ligne; k++){

                printf("q%d ",  tab[position_line][j][k]);

            }

        }
        printf("\n");
        
    }
    // La fonction retourne :
}

/* La fonction qui affiche une colonne donnée d'une matrice*/
/**
 * @brief 
 * 
 * @param tab 
 * @param position_col 
 * @param dim_tab_3D_ligne 
 * @param dim_tab_3D_col 
 */
void affichage_col_mat(int ***tab, int position_col, int dim_tab_3D_ligne, int dim_tab_3D_col){

    // Déclaration de variables locales

    // Instructions
    printf("Colonne sélectionnée dans mat_3D : \n");
    printf("\n");
    // Instructions
    for(int j=0; j<(dim_tab_3D_col); j++ ){

        printf("Colonne_mat[q%d]:\n", position_col);
        for(int i=0; i<(dim_tab_3D_ligne); i++){

            for(int k=0; k<dim_tab_3D_col; k++){
                
                printf("q%d ", tab[position_col][i][k]);

            }
            
        }
        printf("\n");
        
    }
    // La fonction retourne :
}

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
void affichage_case_mat(int ***tab, int position_line, int position_col, int dim_tab_3D_ligne, int dim_tab_3D_col){

    // Déclaration de variables locales

    // Instructions
    affichage_1D(tab[position_line][position_col], dim_tab_3D_ligne);



    /*     printf("Case sélectionnée dans mat_3D : \n");
    printf("\n");
    for(int i=0; i<(dim_tab_3D_ligne); i++){

        for(int j=0; j<(dim_tab_3D_col); j++){

            for(int k=0; k<(dim_tab_3D_ligne); k++){

                printf("case_mat[q%d][a%d]= q%d \n", position_line, position_col, tab[position_line][position_col][k]);
            }
        }
        
    } */
    // La fonction retourne :
}

/*La fonction qui affiche la matrice 3D*/
/**
 * @brief 
 * 
 * @param a 
 */
void  affichage_automate(automate a){

    // Déclaration de variables locales

    // Instructions
    // Caractéristiques de l'automate
    printf("\n");
    printf("Les caractéristiques de l'automate sont : \n");
    printf("\n");
    printf("Nombre d'état(s) : %d et Nombre de symboles : %d\n", a.nb_Etats, a.nb_Symboles);
    
    
    printf("\n");
    printf("Sa matrice est : \n");
    printf("\n");

    // Sa matrice
    for(int i=0; i<a.nb_Etats; i++){
        printf(" { "); 
        printf(" %d:", i);
        
        for(int j=0; j<a.nb_Symboles; j++){
            
            for(int k=0; k<a.nb_Etats; k++){

                printf(" [q%d--(a%d)--q%d:%d] ", i, j, k, a.matrice[i][j][k]);

            }
        }
        printf(" }\n");
    }
    printf("\n");


    /* Sa table des transition */
    a.Table_transition = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);
    a.Table_transition = Tab_transition_automate(a);

    /*Les Etats finaux*/
    if(a.nb_Etats_finaux==0){
        printf("L'automate n'a aucun état final\n");
        printf("\n");

    }else{
        lecture_etats_finaux(a);
    }
    printf("\n");

    /*Le nombre d'états finaux*/
    printf("\n");
    if(a.nb_Etats_finaux==1){
        printf("L'automate a un état final\n");
        printf("\n");
    }else{
        printf("L'automate a %d états finaux\n", a.nb_Etats_finaux);
        printf("\n");
    }
    // La fonction retourne :
}

/* La fonction qui les états finaux*/
/**
 * @brief 
 * 
 * @param a 
 */
void lecture_etats_finaux(automate a){

    // Déclaration de variables locales

    // Instructions
    /*Option 1 en commit*/
        /*printf("Les états finaux sont :\n");
        for(int i =0; i<a.nb_Etats; i++){
            printf("[ i:%d . %d ]", i, a.Etats_finaux[i]);
        }
        printf("\n");
    */

    /*Si un état finale*/
    if(a.nb_Etats_finaux==1){

        for(int i=1; i<a.nb_Etats; i++){

            if(a.Etats_finaux[i]==1){

                printf("L'état final est: q%d ", i);

            }
        }
            
    }else{
        printf("Les états finaux sont : ");
        printf("\n");
        for(int i=1; i<a.nb_Etats; i++){

            if(a.Etats_finaux[i]==1){

                printf(" q%d ", i);
            }
            
        }
        // La fonction retourne : RIEN

    }
    // La fonction retourne :
}

/*La fonction qui permute deux valeurs*/
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 */
void echange(int *a, int *b){

    // Déclaration de variables locales

    // Instructions
    int tmp =*a;

    *b = *a;

    *b=tmp;
    // La fonction retourne :
}

/* La fonciton qui affiche le mot*/
/**
 * @brief 
 * 
 * @param mot 
 */
void affichage_mot(mot *mot){

    // Déclaration de variables locales

    // Instructions

    // La fonction retourne :
}

/* La fonction qui lie un mot et remmplie une matrice D*/
/**
 * @brief 
 * 
 * @param m 
 */
void  lecture_mot(mot m){

    // Déclaration de variables locales
    
    // Instructions
    // La valeur 100 est mis pour la limte de mot
    printf(" Le mot saisi est : ");
    for(int i=0; i<(m.size_mot); i++){

        /* code */
        printf("a%d", m.Tab_caract[i]);

        
    }
    printf("\n");
    
    // La fonction retourne :
}



//Sous-bloc de fonction qui ne retourne un entier
/*La fonction qui teste si un automate est déterministe ou pas*/
/**
 * @brief 
 * 
 * @param a 
 * @return int 
 */
int est_deterministe(automate a){

    // Déclaration de variables locales
    int res;
    int count=0;

    // Instructions
    int ***tab = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);

    a.Table_transition = tab;
    tab = Tab_transition_automate_not_print(a);

    /*Il faut parcourir sa table des transition*/
    for(int j=0; j<a.nb_Symboles; j++){

        for(int i=0; i<a.nb_Symboles; i++){

            /*A un symbole fixé, compter le nombre d'apparition de 1 */
            for(int k=0; k<a.nb_Etats; k++){

                /*Avec la condition sur la présence du chiffre 1*/
                if(tab[i][j][k]==1){
                    count +=1;
                    //printf("t=%d\n",tab[i][j][k]);
                    //printf("count=%d\n", count);
                }
            }
            /*Avant de passer à un autre état on vérifie d'abord si le compte est bon*/
            /*Une valeur de 2 pour count prouve que l'auotmate est non déterministe*/
            if(count==2){
                printf("L'automate est NON déteministe\n");
                printf("\n");
                return 0;
            }
            //count=0;
        }
    }
    // La fonction retourne :
    printf("L'automate est déterministe\n");
    printf("\n");
    return 1;
}

/*La fonction qui examine si l'automate est complet*/
/**
 * @brief 
 * 
 * @param a 
 * @return int 
 */
int est_complet(automate a){

    // Déclaration de variables locales
   int nb_Etats = a.nb_Etats, nb_Symboles = a.nb_Symboles;
    int res;

    // Instructions
    for(int i=0; i<nb_Etats; i++){

        for(int j=0; j<nb_Symboles; j++){

            for(int k=0; k<nb_Etats; k++){

                if(a.matrice[i][j][k]==0){

                    printf("L'automate n'est pas complet\n");
                    return 0;
                }
            }
        }
    }
    printf("\n");
    //printf("L'automate est déjà complet\n");

    // La fonction retourne :
    return res;
}

/* La fonction teste si un état est un final*/
/**
 * @brief 
 * 
 * @param a 
 * @param etat 
 * @return int 
 */
int est_un_etat_final(automate a, int etat){

    // Déclaration de variables locales
    int res;

    // Instructions
    for(int i = 0; i<a.nb_Etats; i++){

        if((a.Etats_finaux[i])==etat){

            return 1;
        }
    }
    return 0;
    // La fonction retourne :


}

/* La fonction qui vérifie si un éatat existe dans la table des transition passée en paramètre*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_touch 
 * @param tab1 
 * @return int 
 */
int exist_state_in_tab_transi(automate a, int state_touch, int ***tab1){

    // Déclaration de variables locales
    int res;

    // Instructions
    for(int i=0; i<a.nb_Etats; i++){

        for(int j=0; j<a.nb_Symboles; j++){

            for(int k=0; k<a.nb_Etats; k++){

                if(tab1[i][j][state_touch]==1){

                    return 0;
                }
                
            }
        }
        
    }
    // La fonction retourne :
    return 1;
}

/* La fonction qui retourne la position de l'état atteint par application d'un symbole partant d'un état donné*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_start 
 * @param symbol_apply 
 * @return int 
 */
int Next_one_state_touch(automate a, int state_start, int symbol_apply){

    // Déclaration de variables locales
    int state_result;
    int cpt_state_touch = 0;

    // Instructions
    for(int k=0; k<a.nb_Etats; k++){

        if(a.matrice[state_start][symbol_apply][k]==1){
            
            state_result=k;
            //printf("state_touch = %d\n", state_result);
        }
    }
    // La fonction retourne :
    return state_result;
}

/* La fonction qui fait la somme d'apparution du chiffre 1 par appel de la fonction Next_states_touch_not_print*/
/**
 * @brief 
 * 
 * @param a 
 * @param tab_states_touch 
 * @return int 
 */
int calculte_number_states_touch(automate a, int *tab_states_touch){

    // Déclaration de variables locales
    /*Décompte du nombre d'états atteint pour chaque symbole considéré*/
    int total_states=0;

    // Instructions
    for(int i1=0; i1<a.nb_Etats; i1++){
        
        for(int i2=0; i2<a.nb_Etats; i2++){

            if(tab_states_touch[i1]==1){

                total_states += total_states ;
                printf("totale_states=%d\n", total_states);
            }
        }
    }
    
    // La fonction retourne :
    return total_states;
}

/* La fonction qui commence avec deux états initaux de deux automates dont on fera le produit*/
/**
 * @brief 
 * 
 * @param etat_initial_a 
 * @param etat_initial_b 
 * @return int 
 */
int start_with_tow(int etat_initial_a, int etat_initial_b){

    // Déclaration de variables locales
    int s_a_b = etat_initial_a + etat_initial_b;

    // Instructions

    // La fonction retourne :
    return s_a_b;
}

/* La fonction qui retourne l'état courant dans la lecture d'un automate*/
/**
 * @brief 
 * 
 * @param a 
 * @param curent_state 
 * @param curent_symbol 
 * @return int 
 */
int retourne_etat_couant(automate a, int curent_state, int curent_symbol){

    // Déclaration de variables locales
    int etat_courant = curent_state, symbole_courant = curent_symbol;
    

    // Instructions
    int *States = a.matrice[etat_courant][symbole_courant];

    int state = 0;

    /*Si l'état passé en arg est déjà le dernier de l'automate*/
    if(curent_state == (a.nb_Etats-1)){
        state = a.nb_Etats;
    }
    
    for( int i =0; i<a.nb_Etats; i++){

        if(States[i]==1){

            state = i;
        }
    }
    // La fonction retourne :
    return state;
}

/* La fonction qui dit si un mot est reconnu ou pas par un automate*/
/**
 * @brief 
 * 
 * @param m 
 * @param a 
 * @return int 
 */
int est_reconnu(mot m, automate a){

    // Déclaration de variables locales
    int curent_state = 0, curent_symbol = m.Tab_caract[0];

    // Instructions
    int i=0;
    while (/* condition */ 1==1)
    {
        /* code */
        curent_state = retourne_etat_couant(a, curent_state, curent_symbol);
        printf("état suivant : %d | symbole associé %d\n", curent_state, curent_symbol);
        

        if(curent_state == 0){

            printf("Mot non reconnu\n");
            return 0;
        }
        int final = est_un_etat_final(a, curent_state);
        if((curent_state == (a.nb_Etats-1)) || final==1){

            printf("val : %d\n", final);
            if(final==1){

                printf("Mot reconnu\n");
                printf("Final = %d\n", final);
                return 1;
            }
            printf("Le mot n'est pas reconnu\n");
            printf("Final = %d\n", final);
            return 0;   
        }
        i += 1;
        curent_symbol = m.Tab_caract[i];
        printf("curent syombol avant tour suivant : %d\n", curent_symbol);
        printf("Etat suivant avant tout : %d\n", curent_state);
        final=0;
    }
    // La fonction retourne :

}

/* La fonction qui réalise un certains nombres de test de la reconnaissance de mots*/
/**
 * @brief 
 * 
 * @param a 
 * @param n_fois 
 * @return int 
 */
int serie_test_reconnaissance(automate a, int n_fois){

    // Déclaration de variables locales
    mot *m;
    int res;

    // Instructions
    for(int i=0; i<n_fois; i++){

        m = mot_saisi_avant(a);
        if(est_reconnu(*m, a)==1){

            printf("Le mot : ");
            affichage_mot(m);
            printf("est reconnu\n");
        }
        printf("Le mot : ");
        affichage_mot(m);
        printf("n'est pas reconnu\n");
        

    }
    // La fonction retourne :
    return 1;
}

/* La fonction qui teste si un mot est reconnu Version 2*/
/**
 * @brief 
 * 
 * @param m 
 * @param a 
 * @return int 
 */
int reconnu_v2(mot m, automate a){

    // Déclaration de variables locales
    int curent_state = 0;
    int next_state;
    int symbole_mot = m.Tab_caract[0];

    // Instructions
    if(m.size_mot==1){
        for(int i=0; i<a.nb_Etats; i++){

            if((a.Etats_finaux[i]==1) || i==m.Tab_caract[0]){
                printf("Oui\n");
                return 1;
            }
            printf(" Là reconnu\n");
            return 0;
        }

    }

    int last_symbol_mot = m.Tab_caract[m.size_mot-1];

    int proba_state_final = find_next_state(a, m);

    if(m.size_mot>=2 || a.nb_Etats>=3){

        if(est_un_etat_final(a, proba_state_final)==0){
            printf("Le mot non \n");
            return 0;
        }
        else if (est_un_etat_final(a, proba_state_final)==1){
            
            for(int i=0; i<m.size_mot-1; i++){
                
                next_state = retourne_etat_couant(a, curent_state, m.Tab_caract[i]);
                if(next_state==1){
                    
                    /* Si val =1, alors cet état est attient on continue*/
                    curent_state = i;
                }

                else{
                    /* Ce i-ème état n'est pas ettient ce qui fait que le mot n'est pas reconnu*/
                    printf("Pas reconnu\n");
                    return 0;
                }
                
            }
            printf("Finalement OUI\n");
            return 1;
        }
    }
    // La fonction retourne :

}

/* La fonction qui retrouve un état par application d'un symbole du mot*/
/**
 * @brief 
 * 
 * @param a 
 * @param m 
 * @return int 
 */
int find_next_state(automate a, mot m){

    // Déclaration de variables locales
    int res;

    // Instructions

    // La fonction retourne :
    return res;
}







//Sous-bloc de fonction qui ne retourne un tableau_1D

/*Allocation des états finaux*/
/**
 * @brief 
 * 
 * @param t1 
 * @return int* 
 */
int *allocation_tab_1D(int t1){

    // Déclaration de variables locales
    int *Tab_1D;

    // Instructions
    Tab_1D = malloc(t1*sizeof(int));
    // Test d'allocation de mémoire
    if(Tab_1D==NULL){
        printf("L'allocation de mémoire_1D a échoué !!!\n");
        exit(1);
    }
    for(int i=0; i<t1; i++){

        Tab_1D[i] = 0;
    }
    // La fonction retourne :
    return Tab_1D;
}

/* La fonction qui produit tous les états atteints par application d'un symbole à un état donnée*/
/**
 * @brief 
 * 
 * @param a 
 * @param start_state 
 * @param symbol_apply 
 * @return int* 
 */
int *Next_states_touch(automate a, int start_state, int symbol_apply){

    // Déclaration de variables locales
    int state_result;
    int *tab_all_states_touch;
    int cpt_state_touch = 0;

    // Instructions
    /*On compte dans un premier temps pour les états attients par le symbole passé en paramètre*/
    int *tab_memory_state_get = allocation_tab_1D(a.nb_Etats);


    /*On alloue de la mémoire au tableau de tous les états atteints*/
    tab_all_states_touch = allocation_tab_1D(a.nb_Etats);



    for(int k=0; k<a.nb_Etats; k++){

        if(a.matrice[start_state][symbol_apply][k]==1){
            cpt_state_touch +=1;
            tab_memory_state_get[k]=k;
            /*On la remplis avec les états atteints*/
            tab_all_states_touch[k] = 1;
            //printf("%d\n", k);
        }
    }
    
    //printf("%d\n", cpt_state_touch);


    /*Cas d'un seul état atteint*/
    if(cpt_state_touch==1){

        for(int i=0; i<a.nb_Etats; i++){

            if(tab_all_states_touch[i]==1){
                printf("L'état attient pas q%d est : q%d\n", start_state, i);
    
            }

        }
    /*Cas de plus d'un état attient*/
    }else{

        printf("\n");
        printf("Les états attient(s) depuis q%d par le symbole a%d sont : \n", start_state, symbol_apply);   
        
        for(int i=0; i<a.nb_Etats; i++){

            if(tab_all_states_touch[i]==1){

                printf(" q%d ", i);
            }
            
        }
        printf("\n");

    }
    printf("\n");
    printf("\n");
    // La fonction retourne :
    return tab_all_states_touch;
}

/* La fonction qui retrouve tous les états atteints par application d'un symbole à un état donnée*/
/**
 * @brief 
 * 
 * @param a 
 * @param start_state 
 * @param symbol_apply 
 * @return int* 
 */
int *Next_states_touch_not_print(automate a, int start_state, int symbol_apply){

    // Déclaration de variables locales
    int *tab_all_states_touch;
    int cpt_state_touch = 0;

    // Instructions
    /*Position de l'état atteint*/
    int *tab_memory_state_get = allocation_tab_1D(a.nb_Etats);


    /*On alloue de la mémoire au tableau de tous les états atteints*/
    tab_all_states_touch = allocation_tab_1D(a.nb_Etats);



    for(int k=0; k<a.nb_Etats; k++){

        if(a.matrice[start_state][symbol_apply][k]==1){
            
            tab_memory_state_get[k]=k;

            /*On la remplis avec les états atteints*/
            tab_all_states_touch[k] = k;


            cpt_state_touch +=1;
            //printf("%d\n", k);
        }
    }
    

    /*Cas d'un seul état atteint*/
    if(cpt_state_touch==1){

        return tab_memory_state_get;

    /*Cas de plus d'un état attient*/
    }else{

        return tab_all_states_touch;
    }
    // La fonction retourne :

}

/* La fonction qui contrtui la table des états obtenus à partir de l' état initial*/
/**
 * @brief 
 * 
 * @param a 
 * @param symbol_apply 
 * @return int* 
 */
int *Tab_states_from_q0(automate a, int symbol_apply){

    // Déclaration de variables locales
    int start_state = 0;
    int * tab_all_states_touched = allocation_tab_1D(a.nb_Etats);


    // Instructions
    tab_all_states_touched = Next_states_touch(a, start_state, symbol_apply );

    // La fonction retourne :
    return tab_all_states_touched;
}

/* La fonction qui contrtui la table des états obtenus à partir de l' état initial par application d'un symbole donné usage pour la fonction rendre déterministe*/
/**
 * @brief 
 * 
 * @param a 
 * @param symbol_apply 
 * @return int* 
 */
int *Tab_states_from_q0_not_print(automate a, int symbol_apply){

    // Déclaration de variables locales
    int start_state = 0;
    int * tab_all_states_touched = allocation_tab_1D(a.nb_Etats);


    // Instructions
    tab_all_states_touched = Next_states_touch_not_print(a, start_state, symbol_apply );

    // La fonction retourne :
    return tab_all_states_touched;
}

/* La fonction qui regoupe les états atteints par le même symbole depuis l'état initial*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_apply 
 * @param symbol_fix 
 * @return int* 
 */
int *group_states_by_same_symbol(automate a, int state_apply, int symbol_fix){

    // Déclaration de variables locales
    int *Tab_global_by_same_symbol = allocation_tab_1D(a.nb_Etats);
    int cpt_state_get=0;
    int state_get;

    // Instructions
    /*Capture des états atteint pur le symbole fixé*/
    for(int j=0; j<a.nb_Symboles; j++){

        if((j==symbol_fix)){

            for(int k=0; k<a.nb_Etats; k++){

                /*La capture se fait ic :*/
                if( (a.matrice[state_apply][symbol_fix][k]==1)){
                    
                    /*Décompte du nombre d'état capturés*/
                    cpt_state_get +=1;

                    /*Capture d'un état à chaque itération*/
                    state_get=k;

                    /*Remplissage du tableau global à chaque itération*/
                    Tab_global_by_same_symbol[state_get] = 1;
                }
                
                
            }
        }

    }

    /*Cas d'un état attient*/
    if(cpt_state_get==1){

        for (int i = 0; i < a.nb_Etats; i++)
        {
            /* code */
            if(Tab_global_by_same_symbol[i] == 1){
                printf("L'état attient par le symbole a%d depuis l'état q%d est : q%d\n", symbol_fix, state_apply, Tab_global_by_same_symbol[i]);
    
            }
        }
        return Tab_global_by_same_symbol;

    }else{
        /*Cas de plus d'un état atteint*/
        printf("\n");
        printf("Les états atteints depuis q%d par le symbole a%d sont: \n", state_apply, symbol_fix);
        
        for(int i=0; i<a.nb_Etats; i++){

            if(Tab_global_by_same_symbol[i]==1){

                printf(" q%d ", i);
            }
        }
        printf("\n");
        return Tab_global_by_same_symbol;
    }
    // La fonction retourne :

}

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
int *group_states_by_same_symbol_not_print(automate a, int state_apply, int symbol_fix){

    // Déclaration de variables locales
    int *Tab_global_by_same_symbol = allocation_tab_1D(a.nb_Etats);


    // Instructions
    /*Capture des états atteint pur le symbole fixé*/
    for(int k=0; k<a.nb_Etats; k++){

        if(a.matrice[state_apply][symbol_fix][k]==1){

            Tab_global_by_same_symbol[k]=1;
            //printf("k=%d\n", k);
        }
    }
    // La fonction retourne :
    return Tab_global_by_same_symbol;
}

/*La fonction qui réalise la réunion d'états obtenus par application d'un symbole identique partant d'un état donné*/
/**
 * @brief 
 * 
 * @param a 
 * @param state_apply 
 * @param symbol_fix 
 * @return int* 
 */
int *union_states_of_same_symbol(automate a, int state_apply, int symbol_fix){

    // Déclaration de variables locales
    int *state_construction = allocation_tab_1D(a.nb_Etats);
    int state_position_get;

    int cpt=0;

    int *tab_union = allocation_tab_1D(a.nb_Etats);


    // Instructions
    /*Table de traitement*/
    int *tab_traitement = allocation_tab_1D(a.nb_Etats);
    tab_traitement = group_states_by_same_symbol(a, state_apply, symbol_fix);

    for(int i=0; i<a.nb_Etats; i++){

        if(tab_traitement[i]==1){

            cpt +=1;
            state_position_get = i;
            state_construction[i] = 1;
            tab_union[i] = state_construction[i];
        }
        
    }
    /*Cas d'une réunion avec un seul état en entrée*/
    if(cpt==1){

        printf("L'état composite partant de l'état q%d par application du symbole a%d est : {q%d}\n", state_apply, symbol_fix, tab_traitement[state_position_get]);
    
    }else{

        /*Cas d'une réunion de plus d'un état*/
        printf("L'état composite partant de l'état q%d par application du symbole a%d est : \n", state_apply, symbol_fix);
        printf("{");
        for(int i=0; i<a.nb_Etats; i++){

            if(state_construction[i]==1){

                printf(" q%d ", i);
            }
        }
        printf("}");
        printf("\n");
    }

    // La fonction retourne :
    return tab_union;
}

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
int *union_states_of_same_symbol_not_print(automate a, int state_apply, int symbol_fix){

    // Déclaration de variables locales
    int *state_construction = allocation_tab_1D(a.nb_Etats);
    int state_position_get;

    int cpt=0;

    int *tab_union = allocation_tab_1D(a.nb_Etats);

    // Instructions
    /*Table de traitement*/

    int *tab_traitement = allocation_tab_1D(a.nb_Etats);

    tab_traitement = group_states_by_same_symbol_not_print(a, state_apply, symbol_fix);

    for(int i=0; i<a.nb_Etats; i++){

        if(tab_traitement[i]==1){

            cpt +=1;
            state_position_get = i;
            state_construction[i] = 1;
            tab_union[i] = state_construction[i];
        }
        
    }
    /*Cas d'une réunion avec un seul état en entrée*/
    if(cpt==1){

        return tab_union;

    }else{

        /*Cas d'une réunion de plus d'un état*/
        return tab_union;
    }
    // La fonction retourne :

}





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
int **add_state_to_composite_table(automate a, int **tab, int composite_state, int position){

    // Déclaration de variables locales
    int **tab_res = allocation_tab_2D(a.nb_Etats, a.nb_Etats);

    // Instructions
    for(int i1=0; i1<a.nb_Etats; i1++){

        int tmp=0;
        for(int i2=0; i2<a.nb_Etats; i2++){

            tmp = tab[i1][i2];

            tab[i1][i2] = tab_res[i1][2];

            tab_res[i1][2] = tmp;

            if(i2==position){

                tab_res[position][composite_state]=composite_state;
            }

        }
    }
    // La fonction retourne :
    return tab_res;
}

/* La fonction qui copie la ligne d'une matrice*/
/**
 * @brief 
 * 
 * @param a 
 * @param mat 
 * @param position_line 
 * @return int** 
 */
int **copy_line_mat(automate a, int ***mat, int position_line){

    // Déclaration de variables locales
    automate a_traitement;
    int **tab_line = allocation_tab_2D(a.nb_Etats, a.nb_Symboles);


    // Instructions
    /*Par prudence on réalision une copie de cet automate avant de le manipuler*/
    //a_traitement = copie_automate(a);


    /*Puis on copie donc la ligne */
    for(int i=0; i<a.nb_Etats; i++){

        for(int j=0; j<a.nb_Symboles; j++){

            int permute=0;
            for(int k=0; k<a.nb_Etats; k++){

                permute = mat[position_line][j][k]; 

                mat[position_line][j][k] = tab_line[j][k];

                tab_line[j][k] = permute;

                //printf("matrice:%d et ligne:%d\n", a.matrice[0][j][k], tab_line[k]);
            }
        }
    }
    // La fonction retourne :
    // La fonction retourne : un tableau
    //affichage_2D(tab_line, a.nb_Etats, a.nb_Symboles);
    return tab_line;
}



/* Allocation nombre d'arcs par état*/
/**
 * @brief 
 * 
 * @param t2 
 * @param t3 
 * @return int** 
 */
int **allocation_tab_2D(int t2, int t3){

    // Déclaration de variables locales
    int **res;

    // Instructions

    // La fonction retourne :
    return res;
}


//Sous-bloc de fonction qui ne retourne un tableau_3D
/*La fonction qui alloue de la mémoire*/
/**
 * @brief 
 * 
 * @param d1 
 * @param d2 
 * @return int*** 
 */
int *** allocation_mat_vide(int d1, int d2){

    // Déclaration de variables locales
    int ***m;
    
    // Instructions
    m= malloc(d1*sizeof(int **));
    
    // Test d'allocation de mémoire
    if(m==NULL){
        printf("L'allocation de mémoire_3D** a échoué !!!\n");
        exit(1);
    }
    for(int i=0; i<d1; i++){
        
        m[i] = malloc(d2*sizeof(int *));
        if(m[i]==NULL){
            printf("L'allocation de mémoire_3D* a échoué !!!\n");
            exit(1);
        }
        for(int j=0; j<d2; j++){

            m[i][j] = malloc(d1*sizeof(int));
            if(m[i][j]==NULL){
                printf("L'allocation de mémoire_3D a échoué !!!\n");
                exit(1);
            }
            for(int k=0; k<d1; k++){

                /*Que des Zero pour le moment : on ne va nul part*/
                m[i][j][k] = 0;
            }
        }
    }
    // La fonction retourne :
    return m;
}


/* La fonction qui lie un automate à ne pas trop utiliser car il va lister tous les chemins possibles*/
/**
 * @brief 
 * 
 * @param a 
 * @return int*** 
 */
int ***lecture_automate_court(automate a){

    // Déclaration de variables locales
    automate m_au;
    int nb_Etats = a.nb_Etats, nb_Symboles = a.nb_Symboles;
    int etat_initial = a.etat_initial;
    int *Tab_Etats_finaux = a.Etats_finaux;
    
    int ***Tab_start, ***Tab_end, ***Tab_stage;

    // Instructions
    Tab_start = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);
    Tab_stage = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);
    Tab_end = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);

    printf("Lecture de la matrice de l'automate : \n");
    printf("\n");

    // Lecture de départ uniquement l'état initial
    printf("Pour l'état inital :\n");
    for(int i=0; i<a.nb_Etats; i++){

        for(int j=0; j<a.nb_Symboles; j++){

            for(int k=0; k<a.nb_Etats; k++){

                // Lecture de départ uniquement l'état initial
                if(a.matrice[0][j][k]==1 && i==0){
                    printf("via a%d on peut aller à  q%d\n", j,  k);
                    
                    // Ajout dans Tab_start uniquement si la valeur 1 est lu pour a.matrice[i][j][k]
                    if(a.matrice[0][j][k]==1){

                        Tab_start[0][j][k] = a.matrice[0][j][k];
                    }
                    
                }
            }
        }   
    }
    printf("\n");
    


    // Lecture intermédiaire
    printf("Pour les états intermédiaires : \n");
    if(a.nb_Etats==2){
        printf("Pas d'états intermédidaires\n");
    }
    else{

        for(int i=1; i<(a.nb_Etats); i++){
            
            for(int j=0; j<a.nb_Symboles; j++){

                
                for(int k=0; k<a.nb_Etats; k++){

                    // Lecture intermédiaire
                    if(a.matrice[i][j][k]==1){
                        printf("De l'état q%d : via a%d on peut aller à q%d\n", i, j, k);
                        Tab_stage[i][j][k] = a.matrice[i][j][k];
                    }
                }
            }
        }
    }
    printf("\n");


    // Lecture de la fin uniquement l'état final de l'automate qn
    printf("Enfin pour l'état final de l'automate q%d: \n", (a.nb_Etats-1));
    
    for(int i=0; i<a.nb_Etats; i++){
    
        for(int j=0; j<a.nb_Symboles; j++){

            for(int k=0; k<a.nb_Etats; k++){

                // Lecture de la fin uniquement l'état final de l'automate qn
                

                if(( a.matrice[i][j][k] == 1) && (k=(nb_Etats-1) )){

                    printf("De l'état q%d via a%d on arrive à q%d \n", i,  j, (a.nb_Etats-1));
                    Tab_start[i][j][k] = a.matrice[i][j][a.nb_Etats];
                }
            }
        }
    }
    printf("\n");

    // La fonction retourne :
    return Tab_start; 
}

/* la fonction  qui ajoute un état  dans une table des états renommés*/
/**
 * @brief 
 * 
 * @param a 
 * @param tab_rename 
 * @param new_state 
 * @param position 
 * @return int*** 
 */
int ***add_state_to_rename_table_state(automate a, int ***tab_rename, int new_state, int position){

    // Déclaration de variables locales
    int ***tab_res = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);

    // Instructions
    for(int i1=0; i1<a.nb_Etats; i1++){

        int tmp=0;
        for(int i2=0; i2<a.nb_Etats; i2++){

            tmp = tab_rename[i1][i2];

            tab_rename[i1][i2] = tab_res[i1][2];

            tab_res[i1][2] = tmp;

            if(i2==position){

                tab_res[position][new_state]=new_state;
            }

        }

    }
    // La fonction retourne :
    return tab_res;
}

/* La fonction qui contruit la table des transitions de l'autome*/
/**
 * @brief 
 * 
 * @param a 
 * @return int*** 
 */
int ***Tab_transition_automate(automate a){

    // Déclaration de variables locales
    int ***tab_transition = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);


    // Instructions
    automate a_manip  = copie_automate(a);
    //int *tab_manip = allocation_tab_1D(a_manip.nb_Etats);

    /*Pour chaque symbole, retrouver tous les états attient depuis chaque état donné de l'automate manip*/
    
    for(int i=0; i<a.nb_Etats; i++){

        for(int j=0; j<a.nb_Symboles; j++){

            for(int k=0; k<a.nb_Etats; k++){

                if(a.matrice[i][j][k]==1){
                   
                   tab_transition[i][j][k]=1;
                }
            }

        }

    }

    //La fonction retourne

    printf("\n");
    printf("La table des transitions de l'automate est :\n");
    printf("\n");

    /* Entête des symboles*/
    for(int j=0; j<a.nb_Symboles; j++){
        printf("      a%d|", j);
    }
    printf("\n");
    for(int j=0; j<(((a.nb_Symboles)*(a.nb_Etats)+1)); j++){
        printf("******");
    }
    printf("\n");
    /*Fin entête*/

    /*Début affichage de table des transition*/
    for(int j=0; j<(((a.nb_Symboles)*(a.nb_Etats)+1)); j++){
        printf("------");
    }
    printf("\n");
    for(int i=0; i<a.nb_Etats; i++){
        printf("%d : ", i);

        for(int j=0; j<a.nb_Symboles; j++){
            printf("{");
            for(int k=0; k<a.nb_Etats; k++){

                if(tab_transition[i][j][k]!=0){
                    
                    printf("a%dq%d ", j, k);
                    
                }
                else{
                    printf("  ");
                }
            }
            printf("}");
            printf("|");
        }
        printf("\n");
        for(int j=0; j<(((a.nb_Symboles)*(a.nb_Etats)+1)); j++){
            printf("------");
        }
        printf("\n");
    }
    printf("\n");
    /* Fin affichage de la table des transitions*/

    // La fonction retourne :
    return tab_transition;
}

/* La fonction qui contruit la table des transitions d'un automate passé en paramètre sans imprimer*/
/**
 * @brief 
 * 
 * @param a 
 * @return int*** 
 */
int ***Tab_transition_automate_not_print(automate a){

    // Déclaration de variables locales
   int ***tab_transition = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);

    // Instructions
    //automate a_manip  = copie_automate(a);
    int *tab_manip = allocation_tab_1D(a.nb_Etats);

    /*Pour chaque symbole, retrouver tous les états attient depuis chaque état donné de l'automate manip*/
    
    for(int i=0; i<a.nb_Etats; i++){

        for(int j=0; j<a.nb_Symboles; j++){

            for(int k=0; k<a.nb_Etats; k++){

                if(a.matrice[i][j][k]==1){
                   
                   tab_transition[i][j][k]=1;
                }
            }

        }

    }

    /*printf("\n");
    printf("La table des transitions de l'automate est :\n");
    printf("\n");*/

    for(int i=0; i<a.nb_Etats; i++){
        //printf("%d : ", i);

        for(int j=0; j<a.nb_Symboles; j++){
            //printf("{");
            for(int k=0; k<a.nb_Etats; k++){

                if(tab_transition[i][j][k]!=0){
                    
                    //printf("a%dq%d ", j, k);
                    
                }
                else{
                    //printf("  ");
                }
            }
            //printf("}");
            //printf("|");
        }
        //printf("\n");
    }
    //printf("\n");

    // La fonction retourne :
    return tab_transition;
}

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
int ***twos_symbol_apply(automate a,  int state_1, int state_2, int symbol_1, int symbol_2){

    // Déclaration de variables locales
    int ***res;

    // Instructions

    // La fonction retourne :
    return res;
}



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
automate generate_automate_null(int d1, int d2, int d3){

    // Déclaration de variables locales
    automate a_null;
    int nb_Etats= d1;
    int nb_Symboles= d2;

    int etat_initial=0;
    int *Etats_finaux = allocation_tab_1D(nb_Etats);
    int nb_Etats_finaux=0;
    int *** matrice = allocation_mat_vide(d1, d2);

    int *** Table_transition = allocation_mat_vide(d1, d2);

    // Instructions
    a_null.etat_initial = etat_initial;
    a_null.nb_Etats = nb_Etats;
    a_null.nb_Symboles = nb_Symboles,
    a_null.Etats_finaux = Etats_finaux;
    a_null.matrice = matrice;
    a_null.Table_transition = Table_transition;

    // La fonction retourne :
    return a_null;
}

/* La fonction qui récupère le nombre d'états et le nombres de symboles et génère un automate*/
/**
 * @brief 
 * 
 * @return automate 
 */
automate generate_automate(){

    // Déclaration de variables locales
    int d1, d2;
    int ***m;
    automate a;

    // Instructions
    //Nombre total d'arcs via un compteur nombre d'arcs par état de l'automate et
    //int *nb_Arcs_tot;
    //int cpt=0;

    //Restitutions détaillée des arcs de l'automate saisi
    //int **Les_arcs_par_etat;
    
    //int *nb_arcs_tot; // Pour chaque état
    //nb_arcs_tot = allocation_tab_1D(d1);
    //a.nb_Arcs_tot = nb_Arcs_tot;


    //int Arc_total; // la somme de tous les arcs de l'automate

    //int **les_arcs_par_etat; // Enumération de tous les arcs pour chaque état
    //a.Les_arcs_par_etat = Les_arcs_par_etat;
    

    // Prince d'allocation de mémoire : un état a au max nb_symbole de transition sur elle même
    // puis au max nb_etas -1 (1 = hormis d'elle même) de transitions vers d'autres états
    
    // Chaque case du Tab (Tot_nb_arcs_etat) d'état pointera vers un tab qui listera tous 
    //les acrs partant de cet etat

    // La taille de l'allocation :
    printf("Création d'une matrice : \n");
    printf("Quel est le nombre d'états ? : ");
    scanf("%d", &d1);
    printf("\n");

    printf("Quel est le nombre de symboles ? : ");
    scanf("%d", &d2);
    printf("\n");

    
    a.nb_Etats=d1;
    a.nb_Symboles=d2;
    a.etat_initial = 0;

    int *Tab_Etats_finaux = allocation_tab_1D(d1);;
    a.Etats_finaux = Tab_Etats_finaux;

    int cpt_etat_finaux;
    a.nb_Etats_finaux = cpt_etat_finaux;

    int ***Tab_transition = allocation_mat_vide(d1, d2);
    a.Table_transition = Tab_transition;

    int nb_arcs,etat_suivant,symbole_associe;

    m = allocation_mat_vide(d1, d2);
    a.matrice=m;
    //Les_arcs_par_etat a pour dimension une : le nombre d'état;
    //les_arcs_par_etat = allocation_tab_1D(d1);
  
    for(int i=0; i<d1; i++){
        printf("Pour l'état q%d, quel est le nombre d'arc(s) ? : ", i);
        scanf("%d", &nb_arcs);
        printf("\n");

        // la seconde dimension dépend fortement du nombre d'arcs total de chaque état
        //les_arcs_par_etat[i] = allocation_tab_1D(nb_arcs*sizeof(int));
        // Nombre d'arcs au total par état
        //nb_arcs_tot[i] = nb_arcs;


        // Additionne le nombre total d'arcs par état pour donner le nombre
        // d'arcs au total pour l'automate
        //cpt += nb_arcs;
        
        // Les_arcs_par_etat a pour seconde dimension le nombdre d'arcs par état
        // C'est une solution pour faire une allocation dynamique pour tenir compte
        // de la variabilité de nombdre d'arcs de chaque état.
        //Les_arcs_par_etat[i] = allocation_tab_1D(nb_arcs);
        
    
        for(int j=0; j<nb_arcs; j++){
            printf("Pour l'arc %d, quel est l'état suivant ? : ", j);
            scanf("%d", &etat_suivant);
            printf("\n");
            //les_arcs_par_etat[i][j] = etat_suivant;
            

            printf("Quel est le symbole associé ? : ");
            scanf("%d", &symbole_associe);
            printf("\n");
            
            m[i][symbole_associe][etat_suivant] = 1;
            
        }
    }


    /* Mise à jour de la table des transitions de l'automate*/

    Tab_transition = Tab_transition_automate_not_print(a);

    /* La mise à jour de la structure de l 'automate saisi*/
    

    //a.Arc_total =  cpt; // la somme de tous les arcs de l'automate

    /* Une énumération par états*/
    //a.nb_Arcs_tot = nb_arcs_tot;

    //a.Les_arcs_par_etat = les_arcs_par_etat; // Enumération de tous les arcs pour chaque état


    // Mise à jour des états finaux :
    for(int i=1; i<d1; i++){
        
        printf("L'état q%d est-il finat ? [0/1]: ", i);
        int val;
        scanf("%d", &val);
        printf("\n");

        if(val==1){

            Tab_Etats_finaux[i]=1;
            
        }
        
    }
    
    // Décompte du nombre d'états finaux
    int cpt=0;
    for(int i=1; i<a.nb_Etats; i++){
        if(a.Etats_finaux[i]==1){
            cpt +=1;
        }
    }
    a.nb_Etats_finaux = cpt;

    // La fonction retourne :
    return a;
}

/* La fonction qui remplis une matrice avec les réponses fournies par un utilisateur*/
/**
 * @brief 
 * 
 * @param m 
 * @param val 
 * @return automate 
 */
automate remplir_automate(automate m, int val){

    // Déclaration de variables locales
    automate res;
    // Instructions

    // La fonction retourne :
    return res;
}

/*La fonction qui importe un automate depuis un fichier txt*/
/**
 * @brief 
 * 
 * @param path 
 * @return automate 
 */
automate import_automae(char path){

    // Déclaration de variables locales
    automate res;

    // Instructions

    // La fonction retourne :
    return res;
}

/*La fonction qui modifie un automate*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate modify_automate(automate a){

    // Déclaration de variables locales
    automate res;
    // Instructions

    // La fonction retourne :
    return res;
}

/*La fonction qui sauvegarde un automate dans un fichier text*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate save_automate(automate a){

    // Déclaration de variables locales
    automate res;
    // Instructions

    // La fonction retourne :
    return res;
}

/*La fonction qui supprime un automate*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate del_automate(automate a){

    // Déclaration de variables locales
    automate res;
    // Instructions

    // La fonction retourne :
    return res;
}

/*La fonction qui copie l'automate dans le but d'en faire une copie*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate copie_automate(automate a){

    /*******IDEE******************************/
    // Afin d'anticiper toutes modifications des données sur l'automate
    // de départ lorsqu'on effectue des opérations une tentative de copie
    // consiste à faire un copie res de l'automate de départ puis une seconde
    // copie à partir de l'automate res et tester si ça marche


    // Déclaration de variables locales
    /* Automate retourné ; b*/
    automate b;
    int nb_Etats_b = b.nb_Etats, nb_Symboles_b=b.nb_Symboles;

    int etat_initial_b = b.etat_initial, nb_Etats_finaux_b = b.nb_Etats_finaux;

    /*  Automate de la copie intermédiaire */
    automate midel; 

    int nb_Etats_midel =midel.nb_Etats, nb_Symboles_midel = midel.nb_Symboles;

    int etat_initial_midel = midel.etat_initial, nb_Etats_finaux_midel = midel.nb_Etats_finaux;

    // Instructions
    /*1ere copie orgine vers intermédiaire*/

    /*Des attributs de types entiers*/
    nb_Etats_midel = a.nb_Etats, nb_Symboles_midel = a.nb_Symboles;

    nb_Etats_finaux_midel=a.nb_Etats_finaux, etat_initial_midel = a.etat_initial;


    /*Allocation après prise d'informations*/

    int *Etats_finaux_midel = allocation_tab_1D(nb_Etats_finaux_midel);

    int ***m_midel = allocation_mat_vide(nb_Etats_midel, nb_Symboles_midel);
  

    int ***Tab_transi_midel = allocation_mat_vide(nb_Etats_midel, nb_Symboles_midel);



    /*Des attributs de types tableaux_2D*/
    for(int i=0; i<nb_Etats_midel; i++){
        
        Etats_finaux_midel[i]=a.Etats_finaux[i];
    }

    /*Des attributs de types tableaux_3D*/
    for(int i=0; i<nb_Etats_midel; i++){

        for(int j=0; j<nb_Symboles_midel; j++){

            for(int k=0; k<nb_Etats_midel; k++){
                
                /*Copie de la matrice*/
                m_midel[i][j][k] = a.matrice[i][j][k];

                /*Copie de la table des transision*/
                Tab_transi_midel[i][j][k] = a.Table_transition[i][j][k];

            }
        }
    }
    midel.matrice=m_midel;
    Tab_transi_midel=midel.Table_transition;




    /*2e copie :  intermédiaire vers b */

    /*Des attributs de types entiers*/
    nb_Etats_b = nb_Etats_midel, nb_Symboles_b = nb_Symboles_midel;

    nb_Etats_finaux_b= nb_Etats_finaux_midel, etat_initial_b = etat_initial_midel;

    /* Allocation après prise d'informations*/
    int *Etats_finaux_b = allocation_tab_1D(nb_Etats_b);

    int ***m_b = allocation_mat_vide(nb_Etats_b, nb_Symboles_b);


    int ***Tab_transi_b=allocation_mat_vide(nb_Etats_b, nb_Symboles_b);



    /*Des attributs de types tableaux_2D*/
    for(int i=0; i<nb_Etats_midel; i++){
        
        Etats_finaux_b[i]=Etats_finaux_midel[i];
    }

    /*Des attributs de types tableaux_3D*/
    for(int i=0; i<nb_Etats_midel; i++){

        for(int j=0; j<nb_Symboles_midel; j++){

            for(int k=0; k<nb_Etats_midel; k++){
                
                /*Copie de la matrice*/
                m_b[i][j][k] = m_midel[i][j][k];

                /*Copie de la table des transision*/
                //Tab_transi_b[i][j][k] = Tab_transi_midel[i][j][k];

            }
        }
    }
    m_b = b.matrice;
    Tab_transi_b = b.Table_transition;

    // La fonction retourne :
    return b;
}

/*La fonction qui rend complet un automate*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate rendre_complet(automate a){

    if(est_complet(a)){
        printf("L'automate est complet\n");
        return a;
    }

    // Déclaration de variables locales
    automate copie; 
    int nb_Etats = a.nb_Etats+1, nb_Symboles = a.nb_Symboles;
    int etat_initial;
    int *Tab_Etats_finaux;
    int ***m_copie = allocation_mat_vide(nb_Etats, nb_Symboles);

    copie.matrice = m_copie;
    copie.nb_Etats = nb_Etats;
    copie.nb_Symboles = nb_Symboles;
    copie.Etats_finaux = Tab_Etats_finaux;
    copie.etat_initial = etat_initial;

    // Instructions
    for(int i=0; i<nb_Etats-1; i++){

        for(int j=0; j<nb_Symboles; j++){
            int cpt=0;

            for(int k=0; k<nb_Etats-1; k++){

                if(a.matrice[i][j][k]!=0){
                    cpt=1;
                }
            }
            if(cpt==0){
                copie.matrice[i][j][nb_Etats-1]=1;

            }
        }
    }
    for(int j=0; j<nb_Symboles; j++){

        for(int k=0; k<nb_Etats-1; k++){
            //printf("-*****%d\n",nb_Etats);
            copie.matrice[nb_Etats-1][j][k]=0;
        }
        // Les transitions qui boucles sur l'état phi
        copie.matrice[nb_Etats-1][j][nb_Etats-1]=1;

    }
    copie.Etats_finaux = allocation_tab_1D(nb_Etats);
    for(int i=0; i<nb_Etats-1; i++){
        copie.Etats_finaux[i] = a.Etats_finaux[i];
    }

    // La fonction retourne :
    return copie;
}

/*La concaténatiion */
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return automate 
 */
automate concat(automate a, automate b){


    // Déclaration de variables locales
    automate res;
    int nb_Etats = a.nb_Etats + b.nb_Etats;
    int nb_Symboles = (a.nb_Symboles, b.nb_Symboles) +1;

    int ***m_concat = allocation_mat_vide(nb_Etats, nb_Symboles);
    res.matrice = m_concat;

    // Instructions
    for(int i=0; i<nb_Etats-1; i++){

        for(int i_1=0; i<a.nb_Etats; );
    }
    // La fonction retourne :
    return res;
}

/* La fonction qui génère le complément d'un automate*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate complement_automate(automate a){

    // Déclaration de variables locales
    automate a_complement;
    if(est_complet(a)==0){
        a_complement = rendre_complet(a);
    }

    int nb_Etats = a.nb_Etats;
    int nb_Symboles = a.nb_Symboles;
    a_complement.Etats_finaux = allocation_tab_1D(a_complement.nb_Etats);

    a_complement.matrice = allocation_mat_vide(a_complement.nb_Etats, a_complement.nb_Symboles);

    // Copie de la matrice de l'automate de départ
    for(int i=0; i<nb_Etats; i++){

        for(int j=0; j<nb_Symboles; j++){

            for(int k=0; k<nb_Etats; k++){

                a_complement.matrice[i][j][k] = a.matrice[i][j][k];
            }
        }
    }
    // Instructions
    // Changement des états finaux en états initaux
    for(int i=0; i<a_complement.nb_Etats; i++){

        //printf("i = %d\n", i);
        if(a.Etats_finaux[i]== 0){

            a_complement.Etats_finaux[i]= 1;
            //printf("start******\n");
        }
        

    }
    // La fonction retourne :
    return a_complement;
}

/* La fonction qui rend un automate déterministe*/
/**
 * @brief 
 * 
 * @param a 
 * @return automate 
 */
automate rendre_deterministe(automate a){

    // Déclaration de variables locales
    automate res;

    // Instructions

    // La fonction retourne :
    return res;
}

/* La fonction qui fait le produit de deux automates et retourne une automate*/
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return automate 
 */
automate producte_a_b(automate a, automate b){

    // Déclaration de variables locales
    automate a_b;

    /* a structure*/
    int curent_state_a = a.etat_initial;

    /* b structure */
    int curent_state_b = b.etat_initial;

    /* a_b structure */
    /* L'état initial de l'automate produit, la taille de chaque état de l'automate produit se donc de trois*/
    int *s_0 = allocation_tab_1D(3);
    for(int i=0; i<3; i++){

        /* Par convention le premier zéro c'est l'indice de l'état initial de l'automate a*/
        s_0[i]=0;
    }

    /*L'état courant de l'automate produit à trois cases*/
    int *curent_state_a_b = allocation_tab_1D(3);
    for(int i=0; i<3; i++){

        /* On met provisoirement tout à zéro*/
        curent_state_a_b[i]=0;
    }

    /* La matrice de l'automate produit initialisé avec des zéro*/
    int ***m_a_b = allocation_mat_vide((a.nb_Etats+b.nb_Etats), (a.nb_Symboles+b.nb_Symboles));

    /* La table des états de lautomate produit contruit de manière dynamique*/
    int ***tab_state_a_b = allocation_tab_2D(((a.nb_Etats+b.nb_Etats)-2), (3));



    /* On inscrit dans cette table le premier état initial (0, 0, 0)*/
    for(int i=0; i<((a.nb_Etats+b.nb_Etats)-2); i++){

        for(int j=0; i<3; i++){

            /* On met provisoirement tout à zéro*/
            tab_state_a_b[0][j]=0;
        }
        
    }

    // Instructions
    while (1==1)
    {
        /* code */
        
        
    }
    
    // La fonction retourne :
    return a_b;
}

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
etats_lus lecture_automate_long(automate a){

    // Déclaration de variables locales
    etats_lus res;
    // Instructions

    // La fonction retourne :
    return res;
}




//Sous-bloc de fonction qui ne retourne un mot

/*La fonction qui saisi le mot deux version*/
/**
 * @brief 
 * 
 * @param a 
 * @return mot 
 */
mot mot_saisi_avant(automate a){

    // Déclaration de variables locales
    mot mot_saisi;

    // Instructions
    printf("Quelle est la taille de votre mot : ");
    scanf("%d", &mot_saisi.size_mot);
    printf( "\n");
    
    // Traitons les mots à un caractère
    if(mot_saisi.size_mot == 1){

        mot_saisi.Tab_caract = allocation_tab_1D(((mot_saisi.size_mot)+1));
        printf("Veillez saisir votre mot : \n"); 
        scanf("%d", ((mot_saisi.Tab_caract)));
    }

    // Mot avec plus d'un caractère
    else{
        printf("La taille de votre mot est : %d\n", mot_saisi.size_mot);
        mot_saisi.Tab_caract = allocation_tab_1D(((mot_saisi.size_mot)+1));

        printf("Veillez saisir votre mot : \n"); 

        printf("L'indice de chaque caractère est à chosisr entere [ %d et %d ]\n",0 ,((mot_saisi.size_mot)-1));
        printf("Après chaque caractère appyez sur la touche Entrer\n");

        int cpt=mot_saisi.size_mot;

        while (cpt!=0)
        {
            /* code */
            for(int i=0; i<(mot_saisi.size_mot); i++){
            // chaque saisi est sauvegardé dans le tableau
            scanf("%d", ((mot_saisi.Tab_caract) +i));
            cpt -= 1;
            }
            
        }
        printf("\n");

        // Pour marquer la fin du mot dans sa table de caractère
        mot_saisi.Tab_caract[(mot_saisi.size_mot)+1] =-1;

        // Mise à jour de la structure mot
    }

    // La fonction retourne :
    return mot_saisi;
}
/**
 * @brief 
 * 
 * @param a 
 * @return mot 
 */
mot  mot_saisi(automate a){

    // Déclaration de variables locales
    mot m;
    int taille;

    // Instructions
    printf("Entrer la taille du mot à lire\n");
    scanf("%d", &taille);
    m.Tab_caract = allocation_tab_1D(taille);
    m.size_mot = taille;

    printf("Les symboles à saisir sont dans l'intervalle : [ 0, %d]\n", a.nb_Symboles-1);

    for(int i =0; i<taille; i++){
        while (1==1)
        {
            /* code */
            int x;
            printf("Entrez le %d-ieme caractère\n", i);
            scanf("%d", &x);

            if(x>=0 && x<a.nb_Symboles){
                m.Tab_caract[i] = x;
                break;
            }

        }
        
    }
    // La fonction retourne :
    return m;
}



