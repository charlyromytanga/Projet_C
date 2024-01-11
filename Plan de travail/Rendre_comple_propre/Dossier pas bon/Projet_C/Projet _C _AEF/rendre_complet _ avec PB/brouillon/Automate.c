//La fonction qui génère la matrice 3D
int ***generate_3D(int *d1, int *d2){

    
    // Déclaration de variables locales
    int nb_Etats, nb_Symboles;
    int nb_arcs, etat_suivant, symbol_associe;

    // La matrice vide à nb_Etats
    int ***mm;


    /*Saisi de la matrice vide*/
    // Les saisies
    printf("Veillez saisir le nombre d'états : ");
    scanf("%d", &nb_Etats);
    printf("%d\n", nb_Etats);

    printf("Veillez saisir le nombre de symboles :");
    scanf("%d", &nb_Symboles);
    printf("%d\n", nb_Symboles);

    // Allocation de la mémoire
    int size1=*d1;
    mm = malloc(size1*sizeof(int**));
    
    printf("pb****?\n");
    for (int i=0; i<d1; i++){

        int size2=*d2;
        mm[i]=malloc(size2*sizeof(int*));
        for(int j=0; j<d2; j++){

            mm[i][j]=malloc(size1*sizeof(int));
            for(int k=0; k<d1; k++){
                mm[i][j][k]=0;
            }
        }  
    }

    /*compléter ici la saisie des arcs*/
    for(int i=0; i< d1; i++){
        /*Récupération du nombre d'arc*/
        printf("Pour l'état : %d\n", i);
        printf("Veillez saisir le nombre d'arcs qui partent de cet état : \n");
        scanf("%d", &nb_arcs);

        /*Inventaire des états cibles par application de chaque symboles = transition*/
        for(int j=0; j< nb_arcs; j++){
            printf("Pour cet arc : a%d\n", j);
            printf("Quel est l'état suiant ? : \n");
            scanf("%d", &etat_suivant);
            
            /*Récupération du symbole aosscié*/
            printf("Quel est le symbole associé ? : \n");
            scanf("%d", &symbol_associe);
            for(int k=0; k<d1; k++){
            /*Remplissage de la matrice = etat cible*/
            mm[i][symbol_associe][etat_suivant]=1;
            }
            //printf("PB*********\n");
        }
        //printf("PB*********\n");
    }
    return mm;
    printf("PB*********\n");

    //Libération de l'espace mémoire après création de la matrice
    //free(mm);
    
}



// La fonction qui affiche la matrice
void affiche(int ***m,  int *d1, int *d2){ 
    // Déclaration de variable


    // Instruction
    printf("La matrice de votre automate est la suivante : \n");
    printf("{");
    for(int i=0; i< d1; i++){
        printf("  ");
        printf("{");
        for(int j=0; j<d2; j++){
            printf("{");
            for(int k=0; k<d1; k++){
                printf("%d", m[i][j][k]);
            }
            printf("}");
        }
        printf("}\n");
        printf(" \n");
        //printf("\n");
    }
    //printf("PB*********?\n");
    //printf("}\n");
}