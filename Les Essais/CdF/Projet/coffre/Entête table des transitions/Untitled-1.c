    /*Proposition d'un affichage*/
    /*Entête*/
    for(int i_0=0; i_0<((a.nb_Symboles)*2); i_0++){

        if(i_0==((a.nb_Symboles)*2)){
            printf("a%d ", i_0);
            printf("|");
        }

    }
    
    printf("\n");

    for(int i_0=0; i_0<((a.nb_Symboles)*(a.nb_Etats)+1); i_0++){

        printf("------");
    }
    printf("\n");
    /*Fin Etête*/

    for(int i=0;  i<a.nb_Etats; i++ ){
        printf("\n");
        printf("q%d:  ", i);



        for(int j=0; j<a.nb_Symboles; j++){
            
            for(int k=0; k<a.nb_Etats; k++){

                if(tab_transition[i][j][k]==1){

                    printf("(q%d) ", k);
                }else{
                    printf("(%d)  ", 0);
                }
            }
            printf("|");
        }
        printf("\n");
        for(int i_0=0; i_0<((a.nb_Symboles)*(a.nb_Etats)+1); i_0++){
            printf("------");
        }  
    }