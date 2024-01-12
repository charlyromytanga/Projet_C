#include "Automate.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>






//Sous-bloc de fonction qui ne retourne un tableau_1D

/// @brief 
/// @return 
int *alloc_tab_1D(int t1){

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





//Sous-bloc de fonction qui ne retourne un tableau_3D
/*La fonction qui alloue de la mémoire*/
int *** alloc_mat_vide(int d1, int d2){

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



/* La fonction qui récupère le nombre d'états et le nombres de symboles et génère un automate*/
automate generator_automate(){

    // Déclaration de variables locales
    int d1, d2;
    int ***m;
    automate a;


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
