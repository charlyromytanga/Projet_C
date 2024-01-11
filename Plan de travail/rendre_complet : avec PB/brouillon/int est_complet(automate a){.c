int est_complet(automate a){
    // Déclaration de variables locales
    int ligne = a.nb_Etats;
    int col = a.nb_Symboles;

    // Mise à jour de la codification des vide et phi
    //int phi = a.nb_Etats + 1;
    int vide = -1;

    // Instructions 
    // Parcours de la matrice 
    for (int i=0; i<ligne; i++){
        for (int j=0; j<col; j++){
            /*for (int k=0; k<ligne; k++){
                if (a.matrice[i][j][k] == 0){
                // Donc l'automate n'est pas complet
                printf("l'automate est non complet\n");
                return 0;
                }
            }*/
            if(a.matrice[i][j] == 0){
                // Donc elle à 2D n'est pas complète
                printf("L'automate n'est pas complet\n");
                return 0;
            }

        }
    }
    // L'automate dest complet
    printf("L'automate est complet\n");
    return 1;
};

automate rendre_complet(automate a){
    // Déclaration des vairables locales
    automate ac;
    ac.nb_Etats = a.nb_Etats +1;
    
    int ligne = ac.nb_Etats;
    int col = ac.nb_Symboles;

    int phi = -1;

    // Instructions
    // Parcours de la nouvelle matrice pour remplacer les vides par des phi
    for (int i=0; i<ligne; i++){
        for (int j=0; j<col; j++){

            // Création de la fonction qui fait la somme du nombre d'entier présent dans le tableau
            // Avant de trouver la fonction on mets en place un compteur de manière provisorie

            // Un test pour savoir si dans {, , ...., nb_Etats fois }, il y a des 0
            for (int k=0; k<ligne; k++){

                // Test s'il n'y a pas de destination
                if (ac.matrice[i][j][k]==0){

                    // On remplace l'abscence de destination par la destination phi
                    ac.matrice[i][j][k] = 1;
                }
            }
            // Test de la valeur du compteur, elle retourne le compte de vide trouvé
            

        }
    };
    return ac;
}
