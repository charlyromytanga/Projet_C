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
automate  generate_automate(){
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
                m[i][j][k] = 0;
            }
        }
    }
    /*Remplacement des Zeros par des états d'arrivés*/
    for(int i=0; i<d1; i++){
        printf("Pour cet état %d, quel est le nombre d'arcs ? : \n", i);
        scanf("%d", &nb_arcs);

        for(int j=0; j<nb_arcs; j++){
            printf("Pour l'arc a_%d, quel état ou combient d'états sont atteints ? : \n", j);
            scanf("%d", &nb_etat_atteint);

            for(int k=0; k<nb_etat_atteint; k++){
                printf("Par le symbole a%d, quel est l'état atteint ? : \n", j);
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
}


/*La fonction qui affiche la matrice 3D*/
void  affichage_automate(automate a){

    /*Déclaration de variables locales*/
    int d1 = a.nb_Etats, d2=a.nb_Symboles;
    int ***m = a.matrice;

    /*Instructions*/
    //printf("La matrice de l'automate est : \n");
    for(int i=0; i<d1; i++){
        printf(" { ");
        for(int j=0; j<d2; j++){
            printf(" { ");
            for(int k=0; k<d1; k++){

                printf(" [q%d--(a%d)--q%d:%d] ", i, j, k, m[i][j][k]);
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

    automate a_c_ok;
    a_c_ok.nb_Etats = a.nb_Etats+1, a_c_ok.nb_Symboles = a.nb_Symboles;

    int nb_Etats = a_c_ok.nb_Etats, nb_Symboles = a_c_ok.nb_Symboles;

    int ***m_ok = a.matrice;

    /*Instructions*/
    if( val==0){

        /*L'automate est non complet et l'utisateur peut s'il veut le rendre complet*/
        printf("Souhaitez-vous le rendre complet ? : [Y] / [N] \n");
        scanf("%s", &reponse);

        if(reponse == 'Y' || reponse == 'y'){
            
            /*La taille a augmenté car on va vouloir la rendre complet et il faut en tenir compte*/
            //nb_Etats += 1;
            a_c_ok = rendre_complet(a);
        }
        else{

            printf("Aucun changement !\n");
            return a;
        };
    }
    /*La fonction question l'utilisateur s'il veut rendre l'automate complet et le fait*/
    return a_c_ok;
};


/*La fonction qui permute deux valeurs*/
 void echange(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
 }



/*La fonction qui rend complet un automate*/
automate rendre_complet(automate a){

    // Déclaration des vairables locales
    automate complet;

    /*Attributs de l'automate cré*/
    int ***cm = complet.matrice;
    int ***m = a.matrice;
    int ***permute1, ***permute2;

    /*Mise à jour de la nouvelle matrice*/
    complet.nb_Etats = a.nb_Etats +1;

    /*Taille pour parcourir la portion identique avec l'automate à compléter*/
    int old_nb_Etats = a.nb_Etats;

    complet.nb_Symboles = a.nb_Symboles;

    int nb_Etats = complet.nb_Etats;
    int nb_Symboles = complet.nb_Symboles;
    
    /*Etat phi pour rendre complet*/

    /*Compteur*/
    int cpt=0;
    printf("Compteur initialisé à zéro\n");
    /*Un pointeur*/

    
    /*Etape 1 : copy de valeur n-1 première valeur*/
    cm = malloc(nb_Etats*sizeof(int **));
    permute1 = malloc(nb_Etats*sizeof(int **));
    permute2 = malloc(nb_Etats*sizeof(int **));

    /*Test d'allocation de méroire 1*/
    if(cm==NULL & permute1==NULL & permute2==NULL){
        printf("L'allocation de mémoire a échoué !!!\n");
        exit(1);
    }
    for(int i=0; i<old_nb_Etats; i++){

        cm[i] = malloc(nb_Symboles*sizeof(int *));
        permute1[i] = malloc(nb_Symboles*sizeof(int *));
        permute2[i] = malloc(nb_Symboles*sizeof(int *));

        if( cm[i]==NULL & permute1[i]==NULL & permute2[i]==NULL){
            printf("L'allocation de mémoire a échoué !!!");
            exit(1);
        }
        for(int j=0; j<nb_Symboles; j++){

            cm[i][j] = malloc(nb_Etats*sizeof(int));
            permute1[i][j] = malloc(nb_Etats*sizeof(int));
            permute2[i][j] = malloc(nb_Etats*sizeof(int));

            if(cm[i][j]==NULL & permute1[i][j]==NULL & permute2[i][j]==NULL){
                printf("L'allocation de mémoire a échoué !!!");
                exit(1);
            }
            for(int k=0; k<old_nb_Etats; k++){

                /*Remplissage dans un premier temps avec des zéros*/
                permute1[i][j][k] = 0;
                
                /* Que des 1 pour la matrice permute2*/
                permute2[i][j][k] = 1;
                
                /*Copie de valeur*/
                permute1[i][j][k] = m[i][j][k];
                cm[i][j][k] = permute1[i][j][k];

                printf("cm : %d, p1 : %d\n", permute1[i][j][k], permute2[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    /*Etape 2 : Mise à jour de la dernière ligne de la matrice du nouvel état*/
    
    /*Le grand parcours*/
    for(int i=1; i<nb_Etats; i++){
 
        for(int j=0; j<nb_Symboles; j++){

            for(int k=0; k<nb_Etats; k++){
                /**/
                cpt+=1;

                if(cpt==nb_Etats){
                    
                    /*Remplace la valeur 0 par 1 : permutation*/
                    printf("cpt = %d\n", cpt);

                    echange(cm[i][j][k], permute2[i][j][k]);

                    printf("Pour a%d :  --> s_f : %d", j, cm[nb_Etats][j][nb_Etats]);
                }
            }
        }
        printf("\n");
    }
    printf("ça passe***\n");
    /*La fonction retourne une copie de l'automate complété*/
    return complet;
};



/*La fonction qui copie l'automate dans le but d'en faire une copie*/
automate copie(automate a){
    /*Déclaration de vairables locales*/
    automate copie;

    /*Mise à jour de la nouvelle matrice*/
    copie.nb_Etats = a.nb_Etats;

    int nb_Etats = copie.nb_Etats;
    int nb_Symboles = a.nb_Symboles;

    int ***copie_m, ***permute;


    /*Instructions*/
    /*Copie et remplacement des destinations vide l'automate non complet*/ 
    copie_m = copie.matrice;

    copie_m = malloc(nb_Etats*sizeof(int **));
    permute = malloc(nb_Etats*sizeof(int **));
    
    /*Test d'allocation mémoire 1*/
    if(copie_m==NULL & permute==NULL){
        printf("L'allocation de mémoire a échoué !!!\n");
        exit(1);
    };

    for (int i=0; i<nb_Etats; i++){

        copie_m[i] = malloc(nb_Symboles*sizeof(int *));
        permute[i] = malloc(nb_Symboles*sizeof(int *));
        //printf("%d", copie_m[i+1]);

        /*Test d'allocation mémoire 2*/
        if(copie_m==NULL & permute==NULL){
        printf("L'allocation de mémoire a échoué !!!\n");
        exit(1);
        };

        for (int j=0; j<nb_Symboles; j++){

            copie_m[i][j] = malloc(nb_Etats*sizeof(int));
            permute[i][j] = malloc(nb_Etats*sizeof(int));
            
            /*Test d'allocation mémoire 3*/
            if(copie_m==NULL & permute==NULL){
            printf("L'allocation de mémoire a échoué !!!\n");
            exit(1);
            };
            /*Il faut pouvoir des à l'adresse mémoire de phi k<=nb_Etats*/
            for (int k=0; k<=nb_Etats; k++){

                /*Mise à zeros les valeurs de la martice permute*/
                permute[i][j][k] = 0;

                /*Copie de valeur*/
                permute[i][j][k] = a.matrice[i][j][k];
                copie_m[i][j][k] = permute[i][j][k];
                //printf("k1 : %d, k2 : %d\n", copie_m[i][j][k], a.matrice[i][j][k])
            }
        }
    }
    /*La fonction retourne*/
    return copie;

};




int main(){
    automate test, result;
    int *Tab;

    test = generate_automate();
    affichage_automate(test);


    return 1;
}
