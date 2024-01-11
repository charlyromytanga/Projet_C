# include <stdio.h>
# include <string.h>
# include <stdlib.h>


# include "Automate.h"



int main(){
    // Déclaration des varaibles pour test
    automate a_test, a_result;
    int b;

    // Appels de fonctions pour rendre un automate complet
    a_test = generate_3D();
    printf("Votre automate a pour matrice : \n");
    affichage_3D(a_test); 

    b = est_complet(a_test);
    printf("%d\n", b);

    a_result = question(a_test, b);
    //a_result = rendre_complet(a_test);
    affichage_3D(a_result);

    /*Le main retourne la valeur 1*/
    return 1;

}

