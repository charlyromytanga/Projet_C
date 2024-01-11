#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Automate.h"


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
    printf("Quel est le nombre d'états ? : ");
    scanf("%d", &d1);
    printf("\n");

    printf("Quel est le nombre de symboles ? : ");
    scanf("%d", &d2);
    printf("\n");

    tab_infos = malloc(2*sizeof(int));
    tab_infos[0]=d1, tab_infos[1]=d2;

  /*La fonction retourne un tableau*/
    printf("Votre automate aura %d états et %d symboles. \n", d1, d2);
    return tab_infos;
};


/*La fonction qui génère une matrice 3D*/
automate  generate_3D(){
    /*Déclaration de variables locales*/

    automate resultat;

    int *tab_infos= information_automate();
    int d1 = tab_infos[0], d2=tab_infos[1];

    
    int etat_suivant, symbole_associe, nb_arcs, nb_etat_atteint;
    int ***m;
    int size_etat, size_symbole;

    /*Instructions*/  
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
                remplissage(resultat, 0);
                m[i][j][k] = 0;
            }
        }
    }
    /*Remplacement des Zeros par des états d'arrivés*/
    for(int i=0; i<d1; i++){
        printf("Pour l'état q%d, quel est le nombre d'arcs ? : ", i);
        scanf("%d", &nb_arcs);
        printf("\n");

        for(int j=0; j<nb_arcs; j++){
            printf("Pour l'arc %d, quel est l'état suivant ? : ", j);
            scanf("%d", &etat_suivant);
            printf("\n");
        
            printf("Quel est le symbole associé ? : ");
            scanf("%d", &symbole_associe);
            printf("\n");

            for(int k=0; k<d1; k++){

                m[i][symbole_associe][etat_suivant] = 1;
            }
        }
    }
    resultat.matrice=m;
    resultat.nb_Etats=d1;
    resultat.nb_Symboles= d2;

    /*La fonction retourne : */
    return  resultat;
}


/*La fonction qui affiche la matrice 3D*/
void  affichage_3D(automate a){

    /*Déclaration de variables locales*/
    int d1 = a.nb_Etats, d2=a.nb_Symboles;
    int ***m_a = a.matrice;

    /*Instructions*/
    //printf("La matrice de l'automate est : \n");
    for(int i=0; i<d1; i++){
        printf(" { ");
        for(int j=0; j<d2; j++){
            printf(" { ");
            for(int k=0; k<d1; k++){

                printf("{ %d --(a%d)--> %d }", i, j, m_a[i][j][k]);
            }
            printf(" } ");
        }
        printf(" }\n");
    }
    /*La fonction retourne : */
}


/*La fonction qui examine si l'automate est complet*/
int est_complet(automate a){

    /*Déclaration de varaibles locales*/
    int nb_Etats = a.nb_Etats, nb_Symboles = a.nb_Symboles;

    /*Instructions*/
    for(int i=0; i<nb_Etats; i++){

        for(int j=0; j<nb_Symboles; j++){

            for(int k=0; k<nb_Etats; k++){

                if(a.matrice[i][j][k]==0){

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


/*La fonction qui questionne l'utilisateur avant de rendre complet*/
automate question(automate a, int val){
    /*Déclaration de variables locales*/
    char reponse;

    automate ac_ok;
    ac_ok.nb_Etats = a.nb_Etats+1, ac_ok.nb_Symboles = a.nb_Symboles;

    int nb_Etats = ac_ok.nb_Etats, nb_Symboles = ac_ok.nb_Symboles;

    int ***m_a = a.matrice;

    /*Instructions*/
    if( val==0){

        /*L'automate est non complet et l'utisateur peut s'il veut le rendre complet*/
        printf("Souhaitez-vous le rendre complet ? : [Y] / [N] \n");
        scanf("%s", &reponse);

        if(reponse == 'Y' || reponse == 'y'){
            
            /*La taille a augmenté car on va vouloir la rendre complet et il faut en tenir compte*/
            //nb_Etats += 1;
            printf("Vous avez choisi de rendre l'automate complet.\n");
            ac_ok = rendre_complet(a);
        }
        else{

            printf("Aucun changement !\n");
            return a;
        };
    }
    /*La fonction question l'utilisateur s'il veut rendre l'automate complet et le fait*/
    return ac_ok;
};



/*La fonction qui rend complet un automate*/
automate rendre_complet(automate a){

    // Déclaration des vairables locales
    automate complet, tmp1, tmp2;

    /*Attributs des automates crés*/
    int ***cm_m = complet.matrice;
    int ***ma_m= a.matrice;
    int ***m1 = tmp1.matrice, ***m2 = tmp2.matrice;


    /*Mise à jour de la nouvelle matrice*/
    complet.nb_Etats = a.nb_Etats +1;

    /*Taille pour parcourir la portion identique avec l'automate à compléter*/
    int old_nb_Etats = a.nb_Etats;

    complet.nb_Symboles = a.nb_Symboles;


    int nb_Etats = old_nb_Etats + 1;
    int nb_Symboles = complet.nb_Symboles;
    nb_Etats = complet.nb_Etats;

    
    /*Allocation mémoire*/
    m1 = malloc(nb_Etats*sizeof(int **));
    m2 = malloc(nb_Etats*sizeof(int **));
    cm_m =  malloc(nb_Etats*sizeof(int **));

    /*Test d'allocation de méroire 1*/
    if(m1==NULL & m2==NULL & cm_m==NULL){
        printf("L'allocation de mémoire a échoué !!!\n");
        exit(1);
    }

    /*Parcours 1 = Pour faire le remplissage des matrices crées avec des zé*/
    for(int i=0; i<nb_Etats; i++){

        m1[i] = malloc(nb_Symboles*sizeof(int *));
        m2[i] = malloc(nb_Symboles*sizeof(int *));
        cm_m[i] = malloc(nb_Symboles*sizeof(int *));

        if( m1[i]==NULL & m2[i]==NULL & cm_m[i]==NULL){
            printf("L'allocation de mémoire a échoué !!!");
            exit(1);
        }
        for(int j=0; j<nb_Symboles; j++){

            m1[i][j] = malloc(nb_Etats*sizeof(int));
            m2[i][j] = malloc(nb_Etats*sizeof(int));
            cm_m[i][j] = malloc(nb_Etats*sizeof(int));

            if(m1[i][j]==NULL & m2[i][j]==NULL & cm_m[i][j]==NULL){
                printf("L'allocation de mémoire a échoué !!!");
                exit(1);
            }
            for(int k=0; k<nb_Etats; k++){

                /*Remplissage de toutes les matrices de l'automates*/
                printf("remplissage de tmp1 :\n");
                remplissage(tmp1, 0);
                printf("L'automate tmp1 a pour martice  : \n");
                affichage_3D(tmp1);

                printf("remplissasge de tmp2 : \n");
                remplissage(tmp2, 0);
                printf("L'automate tmp2 a pour matrice : \n");
                affichage_3D(tmp2);

                printf("remplissage de complet : \n");
                remplissage(complet, 0); 
                printf("Fait\n");
                /*Copie de la matrice de l'automate non complet*/

            }
        }
    }

    /*Parcours 2 = Copie de toutes les valeurs de la matrice de l'automate non complet*/
    printf("Parcours 2 = copie des valeurs de la matrice de l'automate non complet\n");
    for(int i=0; i<old_nb_Etats; i++){
        
        for(int j=0; j<nb_Symboles; j++){
            
            for(int k= old_nb_Etats; k<nb_Etats; k++){

                /* a automate de départ, complet d'arrivé, tmp1 pour asssurer la copie*/
                copie_automate(a, complet, tmp1);
            }
        }
    }


    /*Parcours 3 = Tous les états hormis de l'état initial de l'automate non complet*/
    /*arrivent à l'état phi(dernier état de l'automate complet) via tous les symboles*/

    for(int i = 0; i<nb_Etats; i++){

        for(int j=0; j<nb_Symboles; j++){

            for(int k=0; k<nb_Etats; k++){

                /*Trouver les états concernés et les lier à l'état final phi de l'automate complet*/
                complet = creation_arc(complet);

            }
        }
    }

    /*La fonction retourne une copie de l'automate complété*/
    return complet;
};




int main(){
    automate test, result;
    int b;

    test = generate_3D();
    affichage_3D(test);

    //b = est_complet(test);

    //result = question(test, b);


  
    //affichage_3D(result);

    //free(test.matrice);
    //free(result.matrice);

    return 1;
}

