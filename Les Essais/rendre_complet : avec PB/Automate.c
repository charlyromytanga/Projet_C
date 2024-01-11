# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# include "Automate.h"
# include "Generate_3D.h"

// Déclaration des constantes
// Déclaration de variables globales

// Déclaration des fonctions prototypées dans le fichier.H

/*La fonction qui examine si l'automate est complet*/
int est_complet(automate a){
    /*Déclaration de varaibles locales*/
    int nb_ligne = a.nb_Etats, nb_col = a.nb_Symboles;

    /*Instructions*/
    for(int i=0; i<nb_ligne; i++){

        for(int j=0; j<nb_col; j++){

            for(int k=0; k<nb_ligne; k++){
                if(parcourir_val_matrice(a)==0){
                    printf("L'automate n'est pas complet\n");
                    return 0;
                }
            }
        }
    }
    printf("L'automate est déjà complet\n");

    /*La fonction retroune : */
    return 1;

};

/*La fonction qui rend complet un automate non complet*/
automate rendre_complet(automate a){
    /*Déclaration de variables locales*/
    automate ac;
    ac.nb_Etats = a.nb_Etats+1;
    int ac_nb_col= a.nb_Symboles;
    int ***ac_m;
    int phi=ac.nb_Etats -1;

    /*Instructions*/
    int size_ac1 = ac.nb_Etats;
    ac_m = malloc(size_ac1*sizeof(int **));

    for(int i=0; i<a.nb_Etats; i++){
        int size_ac2 = ac.nb_Symboles;
        ac_m[i] = malloc(size_ac2*sizeof(int *));

        for(int j=0; j<ac_nb_col; j++){
            ac_m[i][j] = malloc(size_ac1*sizeof(int));

            for(int k=0; k<ac.nb_Etats; k++){
                /*Recopie de la matrice de départ*/
                ac_m[i][j][k] = a.matrice[i][j][k];
		
                /*Remplacement des états non atteint par l'état vide=phi*/
                if(parcourir_val_matrice(a)==0){
                    /*Itérateur début après l'état itiale il n' pas une destination à phi*/
                    ac_m[i+1][j][phi] = 1;
                }
            }
        }
    }
    /*Etat phi : Bouclage par tous les symboles sur l'état phi*/
    for(int j=0; j<a.nb_Symboles; j++){

        for(int k=0; k<ac.nb_Etats; k++){
            /*Au dernier phi, par tous les symboles on atteint l'état phi*/
            ac_m[ac.nb_Etats][j][ac.nb_Etats]=phi;
        }
    }

    /*La fonctions retourne : */
    return ac;

};
