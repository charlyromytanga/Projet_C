#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Automate.h"


// Déclaration des constantes
// Déclaration de variables globales

// Déclaration des fonctions prototypées dans le fichier.H

/* La fonction qui récupère le nombre d'états et le nombres de symboles*/
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
    printf("Votre automate aura %d Etat(s) et %d Symbole(ss). \n", d1, d2);
    return tab_infos;
};


/* La fonction qui génère la matrice nulle*/
automate generate_automate_null(int d1, int d2, int d3){
    /* Déclaration de variables locales*/
    automate vide;
    int ***m;

    /* Instructions*/
    m = vide.matrice;
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

    /* La valeur retournée par la fonction*/
    return vide;
}



/* La fonction qui remplis une matrice avec les réponses fournies par un utilisateur*/
automate remplir_automate(automate a, int val){
    /* Déclaration de variables locales*/
    int nb_Etats, nb_Symboles;
    int etat_suivant, symbole_associe, nb_arcs;
    int ***m = a.matrice;

    nb_Etats = a.nb_Etats, nb_Symboles = a.nb_Symboles;

    /*Instructions*/
    /*Remplacement des Zeros par des états d'arrivés*/
    for(int i=0; i<nb_Etats; i++){
        printf("Pour l'état q%d, quel est le nombre d'arc(s) ? : ", i);
        scanf("%d", &nb_arcs);
        printf("\n");

        for(int j=0; j<nb_arcs; j++){
            printf("Pour l'arc %d, quel est l'état suivant ? : ", j);
            scanf("%d", &etat_suivant);
            printf("\n");

            printf("Quel est le symbole associé ? : ");
            scanf("%d", &symbole_associe);
            printf("\n");

            for(int k=0; k<nb_arcs; k++){

                m[i][symbole_associe][etat_suivant] = val;
            }
        }
    }

    /* La valeur retournée par la fonction*/
    return a;
}



/*La fonction qui génère une matrice 3D*/
automate  saisir_automate(){

    /*Déclaration de variables locales*/
    automate resultat;
    int *** m_remplie;

    int *tab_infos= information_automate();
    // d1 nb Etat (nb de lignes), d2 nb symbole (nb de colonnes)
    int nb_Etats = tab_infos[0], nb_Symboles = tab_infos[1];


    /*Valeur de remplissae*/
    int val = 1;

    /*Instructions*/

    // Appel de la fonction création d'une matrice nulle
    resultat = generate_automate_null(nb_Etats, nb_Symboles, nb_Etats);

    // Appel de la fonction remplissage.
    resultat = remplir_automate(resultat, val);
   
   
    resultat.matrice=m_remplie;
    resultat.nb_Etats=nb_Etats;
    resultat.nb_Symboles= nb_Symboles;

    /*La fonction retourne : */
    return  resultat;
}


/*La fonction qui affiche la matrice 3D*/
void  affichage_3D(automate a){

    /*Déclaration de variables locales*/
    int d1 = a.nb_Etats, d2=a.nb_Symboles;
    int ***m = a.matrice;

    /*Instructions*/
    //printf(" cet automate a pour matrice : \n");
    //printf("La matrice de l'automate est : \n");
    for(int i=0; i<d1; i++){
        printf(" { "); 
        printf(" %d:", i);
        for(int j=0; j<d2; j++){
            
            for(int k=0; k<d1; k++){

                printf(" [q%d--(a%d)--q%d:%d] ", i, j, k, m[i][j][k]);

            }
            //printf(" } ");
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
    // Lecture de la réponse donnée par l'utilisateur
    char reponse;

    // L'automate retourné 
    automate a_c_ok;
    // Ses paramètres
    a_c_ok.nb_Etats = a.nb_Etats+1; // Ajout de l'état phi pour le rendre complet
    a_c_ok.nb_Symboles = a.nb_Symboles; // Les symboles restent les mêmes

    // On garde le même vocabulaire pour vaire les parcours de la matrice
    int nb_Etats = a_c_ok.nb_Etats, nb_Symboles = a_c_ok.nb_Symboles;

    // La matrice de l'automate retourné
    int ***m_ok = a.matrice;

    /*Instructions*/
    if( val==0){

        /*L'automate est non complet et l'utisateur peut s'il le souhaites le rendre complet*/
        printf("Souhaitez-vous le rendre complet ? : [Y] / [N] \n");
        scanf("%s", &reponse);

        if(reponse == 'Y' || reponse == 'y'){
            
            return a_c_ok = rendre_complet(a);
        }
        else{

            printf("Votre automate est déjà complet !\n");
            return a;
        };
    }

    
    nb_Etats = a_c_ok.nb_Etats;
    nb_Symboles = a_c_ok.nb_Symboles;
    m_ok = a_c_ok.matrice;

    /*La fonction retourne*/
    
};


/*La fonction qui permute deux valeurs*/
void echange(int *a, int *b){
    /*Déclaration de variable locales*/
    int *tps;

    /*Instructions*/
    
    *tps = *a;
    *a = *b; 
    *b = *tps;

    /*La fonction retourne */
}



/*La fonction qui copie l'automate dans le but d'en faire une copie*/
automate copie_automate(automate a, automate b){
    /*Déclaration de vairables locales*/
    automate copie;

    /*Mise à jour de la nouvelle matrice*/
    copie.nb_Etats = a.nb_Etats;

    int nb_Etats = copie.nb_Etats;
    int nb_Symboles = a.nb_Symboles;
    int ***copie_m, ***m_depart;

    int *p1, *p2;


    /*Instructions*/
    copie = generate_automate_null(nb_Etats, nb_Symboles, nb_Etats);

    m_depart = a.matrice, copie_m = copie.matrice; 

    for(int i=0; i<nb_Etats; i++){

        for(int j=0; j<nb_Symboles; j++){

            for(int k=0; k<nb_Etats; k++){

                printf("k_départ = %d | k_copie = %d |\n", m_depart[i][j][k], copie_m[i][j][k]);
            }
        }
    }
    
    nb_Etats = copie.nb_Etats;
    nb_Symboles = copie.nb_Symboles;

    /*La fonction retourne*/
    return copie;

}



/*La fonction qui rend complet un automate*/
automate rendre_complet(automate a){

    // Déclaration des vairables locales
    automate complet, permute1, permute2; // La copie des valeurs de la matrice se fait par permutation


    /* Détails des étapes: */
    /* Etape 1 : Création de tous les automates avec leur structures */
    /* Etape 2 : Les valeurs de la matrice de l'automate non complet sont copier par perumtation 
    /*appel de la fonction copie qui appel la fonction échange*/

    /* Etape 3 : Des arcs sont crés avec pour départ tous les états autres que  l'état initial et pour arrivé l'état phi*/
    /* Etape 4 : Enfin création des acrs bouclant sur l'état phi crée par toutes les transitions */

    

    int ***cm = complet.matrice;
    int ***m = a.matrice;
    int ***pmte1 = permute1.matrice, ***pmte2 = permute2.matrice;

    /*Mise à jour de la nouvelle matrice*/
    complet.nb_Etats = a.nb_Etats +1;

    permute1.nb_Etats=complet.nb_Etats;
    permute2.nb_Etats = complet.nb_Etats;

    /*Taille du parcours pour la copie des valeurs de la matrice de l'automate non complet*/
    int old_nb_Etats = a.nb_Etats;

    /* Les variables de parcours restantes*/
    complet.nb_Symboles = a.nb_Symboles;
    permute1.nb_Symboles = complet.nb_Symboles;
    permute2.nb_Symboles = complet.nb_Symboles;

    /* Les variables mise au bon vocabulaire */
    int nb_Etats = complet.nb_Etats;
    int nb_Symboles = complet.nb_Symboles;
    
    /*Etat phi pour rendre complet*/

    /*Compteur*/
    int cpt=0;


    /* Etape 1 : Création de tous les automates avec leur structures */
    printf("Etape 1 : Création de tous les automates avec leurs structures \n");
    
    /*Remplissage des trois matrices*/
    printf("Création des trois matrices. \n");

    /* Matrice de l'automate retourné*/
    complet = generate_automate_null(nb_Etats, nb_Symboles, nb_Etats);

    /* Matrices pour la copie par perumetation*/
    permute1 = generate_automate_null(nb_Etats, nb_Symboles, nb_Etats);
    permute2 = generate_automate_null(nb_Etats, nb_Symboles, nb_Etats);



    /* Etape 2 : Les valeurs de la matrice de l'automate non complet sont copier par perumtation*/
    /*appel de la fonction copie qui appel la fonction échange*/
    complet = copie_automate(a, complet);


    /* Etape 3 : Des arcs sont crés avec pour départ tous les états autres que  l'état initial et pour arrivé l'état phi*/
    

    /*cm = malloc((nb_Etats +1)*sizeof(int **));
    pmte1 = malloc((nb_Etats +1)*sizeof(int **));
    pmte2 = malloc((nb_Etats +1)*sizeof(int **));

    Test d'allocation de méroire 1
    if(cm==NULL & pmte1==NULL & pmte2==NULL){
        printf("L'allocation de mémoire a échoué !!!\n");
        exit(1);
    }
    for(int i=0; i<nb_Etats; i++){

        cm[i] = malloc((nb_Symboles +1)*sizeof(int *));
        pmte1[i] = malloc((nb_Symboles +1)*sizeof(int *));
        pmte2[i] = malloc((nb_Symboles +1)*sizeof(int *));

        printf(" { "); 
        printf(" %d:", i);

        if( cm[i]==NULL & pmte1[i]==NULL & pmte2[i]==NULL){
            printf("L'allocation de mémoire a échoué !!!");
            exit(1);
        }
        for(int j=0; j<nb_Symboles; j++){

            cm[i][j] = malloc((nb_Etats+1)*sizeof(int ));
            pmte1[i][j] = malloc((nb_Etats+1)*sizeof(int ));
            pmte2[i][j] = malloc((nb_Etats+1)*sizeof(int ));

            if(cm[i][j]==NULL & pmte1[i][j]==NULL & pmte2[i][j]==NULL){
                printf("L'allocation de mémoire a échoué !!!");
                exit(1);
            }
            for(int k=0; k<nb_Etats; k++){

                // Des nb_Etats + 2  pour les matrices de permutations 
                pmte1[i][j][k] = nb_Etats + 2;
                pmte2[i][j][k] = nb_Etats + 2;

                // Idem pour la matrice de l'automate retourné
                cm[i][j][k]= nb_Etats +2;
                
                //Test du bon remplissages
                printf(" [q%d--(a%d)--q%d:%d] ", i, j, k, m[i][j][k]);
                //printf("i = %d  j = %d  k= %d | Permute1 = %d | Permute2 = %d\n", i, j, k, pmte1[i][j][k], pmte2[i][j][k]);
                //printf("i = %d  j = %d  k= %d | complet = %d | non complet = %d\n", i, j, k, cm[i][j][k], m[i][j][k]);

            }
            //printf("\n");
            
        }
        printf(" }\n");
        //printf("\n");
    };
    //printf("Fin du remplissage\n");
    printf("Lors de cette étapes, les matrices des trois automates crés sont : \n");
    printf("La matrice de l'automate retourné : \n");

    //Les paramètres de chaque automates
    nb_Etats = complet.nb_Etats;
    permute1.nb_Etats = nb_Etats;
    permute2.nb_Etats = nb_Etats;

    nb_Symboles = complet.nb_Symboles;
    permute1.nb_Symboles = nb_Symboles;
    permute2.nb_Symboles = nb_Symboles;

    //affichage_3D(complet);
    //affichage_3D(permute1);
    //affichage_3D(permute2);


    /*Copie des valeurs de la matrice de l'automate non complet de taille n */
    /*Dans la matrice de l'automate complet créé*/
    /*for(int i=0; i<nb_Etats; i++){

        for(int j=0; j<nb_Symboles; j++){

            for(int k=0; k<nb_Etats; k++){

                pmte1[i][j][k] = m[i][j][k];
                cm[i][j][k] = pmte1[i][j][k];
            }
            printf("i = %d  j = %d   | Permute1 = %d | Permute2 = %d\n", i, j, pmte1[i][j], pmte2[i][j]);
            printf("i = %d  j = %d   | complet = %d | non complet = %d\n", i, j, cm[i][j], m[i][j]);

        }
        printf("\n"); 
    }


    
    /*Etape 2 : */
    //Création des transitions manquates pour les états compris entre l'état initial et
    // l'état final de l'automate non complet en destination du dernier état phi de 
    // l'automate complet

    /***************************************C'est-à-dire : ************************************/
    /*Etape 2 : Pour les états compris entre l'état initial et l'état final de l'automate*/
    /*non complet, faire un test pour chaque transition (for(int k=0...) pour savoir si)*/
    /*pour cet état et pour chaque symbole il y a un état de destination. Sinon il faut */
    /*assigner l'état phi de la matrice de l'automate complet pour état de destination*/
    /*Cet état phi n'a que des 1 pour toue les */

    /*printf("Rajout des transitions\n");
    for(int i=0; i<nb_Etats; i++){

        for(int j=0; j<nb_Symboles; j++){

            for(int k=0; k<old_nb_Etats; k++){

             
                /*Si pour l'état i par le symbole j, k n'est pas un état de destination*/
                /*if(k>0 && m[i][j][k]==0){

                    /*Alors k : doit être l'etat final de la matrice de l'automate complet k=1*/
                    /*cm[i][j][k]=1;
        
                }
                /*printf("i = %d  j = %d  k= %d Non complet : %d  | Complet : %d", i, j, k,  m[i][j][k], cm[i][j][k]);

            }
            printf("\n");
        }
        printf("\n");
    }
    printf("Fin du rajout\n");

    /*La fonction retourne une copie de l'automate complété*/
    /*printf("Caractéristique de l'automate complet : ");
    printf( "Nombre d'états : %d  Nombre de symbole : %d\n", complet.nb_Etats, complet.nb_Symboles);
    */
    
    /* La fonction retourne*/
    return complet;
};






int main(){
    // Déclaration des varaibles pour test
    automate a_test, a_result;
    int *Tab;
    int val;

    // --Test de chaque fonction du mains--
    // 1- La fonction : generate_automate_null
    a_test = generate_automate_null(2, 2, 2);
    affichage_3D(a_test);
    
    
    
    
    
    // 1- Ok pour cette section d'appels de fonctions
    //Tab = information_automate(); 
    //a_test = saisir_automate();
    //affichage_3D(a_test);
    /*val = est_complet(a_test);

    a_result = question(a_test, val);*/

    /*Test de la permutation OK*/
    /*int a=0, b=3;
    printf("Avant a=%d et b=%d \n", a, b);
    echange(&a, &b);
    printf("Après a=%d et b=%d \n", a, b);*/

    /*Test de la fonction copier*/
    //automate a, b, c;
    /*a = generate_3D();
    b.matrice = generate_mat_null(2, 2, 2);
    c.matrice = generate_mat_null(2, 2, 2);*/

    /*automate copie;
    int nb_Etats = a_test.nb_Etats, nb_Symboles = a_test.nb_Symboles; 

    copie = generate_automate_null(nb_Etats, nb_Symboles, nb_Etats);
    affichage_3D(copie);

    //a_result = copie_automate(a_test, copie);
    


    /*Le main retourne la valeur 1*/
    return 0;

}

