# include <stdio.h>
# include <string.h>
# include <stdlib.h>


# include "Automate.h"
# include "Generate_3D.h"

// Déclaration des constantes

// Déclaration de variables globales

// Déclaration des fonctions prototypées dans le fichier.H

/*La fonction qui récupère le nombre d'états et le nombres de symboles*/
int *information_automate(){
    /*Déclaration des variables locales*/
    int d1, d2;
    int *tab_infos;

    /*Instructions*/
    printf("Création d'une matrice : \n");
    printf("Quel est le nombre d'états ? : \n");
    scanf("%d", &d1);

    printf("Quel est le nombre de symboles ? : \n");
    scanf("%d", &d2);

    tab_infos = malloc(2*sizeof(int));
    tab_infos[0]=d1, tab_infos[1]=d2;

  /*La fonction retourne un tableau*/
    printf("Votre automate aura %d états et %d symboles. \n", d1, d2);
    return tab_infos;
};

/*La fonction qui génère une matrice 3D*/
automate  generate_3D(){
    automate resultat;
    int *tab_infos= information_automate();
    int d1 = tab_infos[0], d2=tab_infos[1];
    /*Déclaration de variables locales*/
    int etat_suivant, symbole_associe, nb_arcs, nb_etat_atteint;
    int ***m;
    int size_etat, size_symbole;

    /*Initialisation des compteurs*/


    /*Instructions*/
    /*Récupération des informations chez l'utilisateur*/


    /*Remplissage de la matrice avec que des Zeros*/
    //size = *d1;
   
    m= malloc(d1*sizeof(int **));
    
    // Test d'allocation de mémoire
    if(m==NULL){
        printf("L'allocation de mémoire a échoué !!!\n");
        exit(1);
    }
    
    for(int i=0; i<d1; i++){
        m[i] = malloc(d2*sizeof(int *));
        
        for(int j=0; j<d2; j++){

            m[i][j] = malloc(d1*sizeof(int));
            for(int k=0; k<d1; k++){

                /*Que des Zero pour le moment : on ne va nul part*/
                m[i][j][k] = 0;
            }
        }
    }
    /*Remplacement des Zeros par des états d'arrivés*/
    for(int i=0; i<d1; i++){
        printf("Pour cet état %d, quel est le nombre d'arcs ? : \n", i);
        scanf("%d", &nb_arcs);

        for(int j=0; j<nb_arcs; j++){
            printf("Pour l'arc a_%d, combien d'états sont atteint ? : \n", j);
            scanf("%d", &nb_etat_atteint);

            for(int k=0; k<nb_etat_atteint; k++){
                printf("pour l'arc_%d, quel est l'état suivant ? : \n", j);
                scanf("%d", &etat_suivant);

                printf("Quel est le symbole associé ? : \n");
                scanf("%d", &symbole_associe);

                m[i][symbole_associe][etat_suivant] = 1;
            }
        }
    }
    resultat.matrice=m;
    resultat.nb_Etats=d1;
    resultat.nb_Symboles= d2;

    /*La fonction retourne : */
    return  resultat;
};

/*int parcourir_val_matrice(automate a){
    /*Déclartation de variables locales
    int **val;
    int nb_ligne = a.nb_Etats, nb_col = a.nb_Symboles;

    /*Instructions
    for(int i=0; i<nb_ligne; i++){
        
        for(int j=0; j<nb_col; j++){

            for(int k=0; k<nb_ligne; k++){
                val = a.matrice[i][j][k];
                return val;
            }
        }
    }

}
La fonction qui affiche un tableau
void affichage_1D(int *tab, int d1){
    for (int i=0; i<d1; i++){
        printf("tab[%d]=%d\n", i, tab[i]);
    }
    
}

La fonction qui affice une matrice 2D
void affichage_2D(int **m, int d1, int d2){
    /*Déclaration de variables locales
    for (int i=0; i<d1; i++){

        for (int j=0; j<d2; j++){
            printf("%d", m[i][j]);
            printf("\n");
        }
    }
}*/
/*La fonction qui affiche la matrice 3D*/
void  affichage_3D(automate a){
    /*Déclaration de variables locales*/
    int d1 = a.nb_Etats, d2=a.nb_Symboles;
    int ***m = a.matrice;

    /*Instructions*/
    printf("La matrice de l'automate est : \n");
    for(int i=0; i<d1; i++){

        for(int j=0; j<d2; j++){

            for(int k=0; k<d1; k++){
                printf("%d\n", m[i][j][k]);
            }
        }
    }

    /*La fonction retourne : */
}







