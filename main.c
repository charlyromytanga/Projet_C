#include "Automate.h"
#include "automate.c"



int main(){

    /**************Debut automate*************/
    // Déclaration des varaibles pour test
    
    automate a, b, res1;
    int val;

    // Instructions
    a = generate_automate();
    b = generate_automate();

    affichage_automate(a);
    affichage_automate(b);



    /**************Fin automate*************/





    /**************Debut mot****************/

    // Déclaration de variables de tests
    mot m1, m2;
    int res2;

    // Instructions 
    m1 = mot_saisi(a);
    m2 = mot_saisi(b);

    affichage_mot(a);
    affichage_mot(b);
    /**************Fin Mot****************/




    return 0;

}
