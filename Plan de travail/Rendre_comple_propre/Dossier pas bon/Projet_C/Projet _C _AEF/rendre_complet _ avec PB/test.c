# include <stdio.h>
# include <string.h>
# include <stdlib.h>


# include "Automate.h"
# include "Generate_3D.h"


int main(){
    // Déclaration des varaibles pour test

    /*Initialisetaion des compteurs*/
    int ***matrice_test, ***matrice_result;

    automate a_test, ac_reslut;

    // Appels de fonctions pour rendre un automate complet
    a_test = generate_3D();
    //a_test.nb_Etats = d1, a_test.nb_Symboles=d2;

    printf("Votre automate a pour matrice : \n");
    affichage_3D(a_test);

    /*printf("PB*********\n");
    //printf("hello\n");
    
    // Mise à jour de l'attribu matrice de l'automate  d'entré : a_test
    a_test.matrice = matrice_test;

    // Mise à jour de l'attribu matrice de l'automate de sortie : ac_result
    ac_reslut.matrice = matrice_result;

    //Enregistrement de la valeur du test sur le caractère complet ou pas de l'automate
    result = est_complet(a_test);
    printf("%d\n", result);

    // Test pour savoir si l'automate est non complet, auquel cas il faut le rendre complet
    if (result == 0){
        // Est non complet donc il faut la compléter
        ac_reslut = rendre_complet(a_test);
    }else{
        // Elle est déjà complet il ne faut rien
        printf("Votre automate est déjà complet\n");
    }
    

    // Les résultats finaux
    printf("l'automate d'entré : \n");
    affiche(matrice_test, d1, d2);

    printf("\n------------------------------------------\n");

    printf("\nl'automate de sortie est : \n");
    affiche(matrice_result, d1, d2);
    */
    

}

