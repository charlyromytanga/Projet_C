
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "Automate.h"
#include "automate.c"




int main(){

    /**************Debut automate*************/
    // Déclaration des varaibles pour test
    
    automate a_test, a_result, a_complement, a_copie, res;
    int ***m_test, ***m_res;
    int *Tab;
    int val;


    // Instructions


    a_test = generate_automate();
    affichage_automate(a_test);


    //a_copie = copie_automate(a_test);
    //printf("Puis la copie : \n");
    //affichage_automate(a_copie);
    //val = est_complet(a_test);
    //a_result = rendre_complet(a_test);
    //affichage_automate(a_result);
    
    //printf("a : %d\n", a_test.Etats_finaux[1]);

    //a_complement = complement_automate(a_test);
    //affichage_automate(a_complement);
    
    /*m = allocation(2, 2);

    a_test = generate_automate();

    affichage_automate(a_test);

    a_result = rendre_complet(a_test);
    affichage_automate(a_result);*/

    //m_res = lecture_automate(a_test);


    //val = est_un_etat_final(a_test, 3);
    //printf("final : %d\n", val);

    /*Afficher les états finaux*/
    //lecture_etats_finaux(a_test);
    

    /**************Fin automate*************/





    /**************Debut mot****************/

    // Déclaration de variables de tests
    mot mot_test, mot_test2;
    int nb_test, res1 ;

    // Instructions : 

    /* La saisi du mot*/

    /* Version Prof simple et efficace*/
    //mot_test = mot_saisi(a_test);
    //affichage_mot(mot_test);

    /*Vesion longue moi*/
    //mot_test2 = mot_saisi_avant(a_test);
    //affichage_mot(mot_test2);

    //lecture_mot(*mot_test2);
   
    /* Test si le mot est reconnu*/
    //res1 = est_reconnu(*mot_test2, a_test);
    //res1 = reconnu_v2(*mot_test2, a_test);

    /* Test de mots reconnus*/
    //nb_test = 5;

    //res1 = test_reconnaissance(a_test, nb_test);

    //int find = find_next_state(a_test, *mot_test2);
    //printf("%d\n", find);


    


    /**************Fin Mot****************/




    return 0;

}
