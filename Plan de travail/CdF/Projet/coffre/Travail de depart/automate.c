#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "Automate.h"




/*************************DEBUT AUTOMATE******************************/

// Déclaration des constantes
// Déclaration de variables globales

// Déclaration des fonctions prototypées dans le fichier.H


/*Allocation des états finaux*/
int *allocation_tab_1D(int t1){

    // Déclartion de variables locales
    int *Tab;


    // Instructions
    Tab = malloc(t1*sizeof(int));
    for(int i=0; i<t1; i++){

        Tab[i] = 0;
    }

        // La fonction retourne

    return Tab;
};


/* Allocation nombre d'arcs par état*/
int **allocation_tab_2D(int t2, int t3){
    // Déclaration de varibles locales
    int **Tab_2D;

    // Instructions
    Tab_2D = malloc(t2*sizeof(int *));
    // Test d'allocation de mémoire
    if(Tab_2D==NULL){
        printf("L'allocation de mémoire a échoué !!!\n");
        exit(1);
    }
    for(int i=0; i<t2; i++){
        
        Tab_2D[i] = malloc((t3*t2)*sizeof(int));
        // Test d'allocation de mémoire
        if(Tab_2D==NULL){
            printf("L'allocation de mémoire a échoué !!!\n");
            exit(1);
        }
        for(int j=0; j<(t3*t2); j++){
            
            Tab_2D[i][j] = 0;
            
        }
    }
    // La fonction retourne un tableau 2D
    return Tab_2D;
}
;

/*La fonction qui alloue de la mémoire*/
int *** allocation_mat_vide(int d1, int d2){

    // Déclartion de variables locales
    
    int ***m;

    // Instructions 
    
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

    // La fonction retourne
    return m;
}


/* La fonction qui génère la matrice nulle d'un automate dit nul*/
automate generate_automate_null(int d1, int d2, int d3){

    // Déclaration de variables locales
    automate a_null;

    // Instructions

    // La fonction retourne un automate null au sens de sa matrice
    return a_null;
}


/* La fonction qui remplis uniquement la matrice d'un automate */
automate remplir_automate(automate m, int val){

    // Déclaration de variables locales

    // Instructions

    // La fonction retourne le même automate avec sa matrice mis à jour
    return m;
}
;



/* La fonction qui récupère le nombre d'états et le nombres de symboles et génère un automate*/
automate generate_automate(){

    /*Déclaration des variables locales*/
    int d1, d2;
    int ***m;
    automate a;

    /*Instructions*/
    //Nombre total d'arcs via un compteur nombre d'arcs par état de l'automate et
    //int *nb_Arcs_tot;
    //int cpt=0;

    //Restitutions détaillée des arcs de l'automate saisi
    //int **Les_arcs_par_etat;
    
    //int *nb_arcs_tot; // Pour chaque état
    //nb_arcs_tot = allocation_tab_1D(d1);
    //a.nb_Arcs_tot = nb_Arcs_tot;


    //int Arc_total; // la somme de tous les arcs de l'automate

    //int **les_arcs_par_etat; // Enumération de tous les arcs pour chaque état
    //a.Les_arcs_par_etat = Les_arcs_par_etat;
    

    // Prince d'allocation de mémoire : un état a au max nb_symbole de transition sur elle même
    // puis au max nb_etas -1 (1 = hormis d'elle même) de transitions vers d'autres états
    
    // Chaque case du Tab (Tot_nb_arcs_etat) d'état pointera vers un tab qui listera tous 
    //les acrs partant de cet etat

    // La taille de l'allocation :
    


    printf("Création d'une matrice : \n");
    printf("Quel est le nombre d'états ? : ");
    scanf("%d", &d1);
    printf("\n");

    printf("Quel est le nombre de symboles ? : ");
    scanf("%d", &d2);
    printf("\n");
    a.nb_Etats=d1;
    a.nb_Symboles=d2;

    int nb_arcs,etat_suivant,symbole_associe;

    m = allocation_mat_vide(d1, d2);
    //Les_arcs_par_etat a pour dimension une : le nombre d'état;
    //les_arcs_par_etat = allocation_tab_1D(d1);
  
    for(int i=0; i<d1; i++){
        printf("Pour l'état q%d, quel est le nombre d'arc(s) ? : ", i);
        scanf("%d", &nb_arcs);
        printf("\n");

        // la seconde dimension dépend fortement du nombre d'arcs total de chaque état
        //les_arcs_par_etat[i] = allocation_tab_1D(nb_arcs*sizeof(int));
        // Nombre d'arcs au total par état
        //nb_arcs_tot[i] = nb_arcs;


        // Additionne le nombre total d'arcs par état pour donner le nombre
        // d'arcs au total pour l'automate
        //cpt += nb_arcs;
        
        // Les_arcs_par_etat a pour seconde dimension le nombdre d'arcs par état
        // C'est une solution pour faire une allocation dynamique pour tenir compte
        // de la variabilité de nombdre d'arcs de chaque état.
        //Les_arcs_par_etat[i] = allocation_tab_1D(nb_arcs);
        
    
        for(int j=0; j<nb_arcs; j++){
            printf("Pour l'arc %d, quel est l'état suivant ? : ", j);
            scanf("%d", &etat_suivant);
            printf("\n");
            //les_arcs_par_etat[i][j] = etat_suivant;
            

            printf("Quel est le symbole associé ? : ");
            scanf("%d", &symbole_associe);
            printf("\n");
            
            m[i][symbole_associe][etat_suivant] = 1;
            
        }
    }

    /* La mise à jour de la structure de l 'automate sais*/
    a.matrice=m;

    //a.Arc_total =  cpt; // la somme de tous les arcs de l'automate

    /* Une énumération par états*/
    //a.nb_Arcs_tot = nb_arcs_tot;

    //a.Les_arcs_par_etat = les_arcs_par_etat; // Enumération de tous les arcs pour chaque état

    // Mise à jour des états finaux :
    int *Tab_Etats_finaux;
    Tab_Etats_finaux = allocation_tab_1D(d1);

    for(int i=0; i<d1; i++){

        printf("L'état q%d est-il finat ? [0/1]: ", i);
        int val;
        scanf("%d", &val);
        printf("\n");

        if(val==1){
            Tab_Etats_finaux[i]=i;
        }
    }

    a.Etats_finaux = Tab_Etats_finaux;
    a.etat_initial = 0;
    //a.nb_Arcs_tot = nb_Arcs_tot;
    //a.Les_arcs_par_etat = Les_arcs_par_etat;
    
    /* La valeur retournée par la fonction*/
    return a;
}



/* La fonction qui les états finaux*/
void lecture_etats_finaux(automate a){
    //Déclaration de varibales locales

    // Instructions
    printf("Les états finaux sont :\n");
    for(int i =0; i<a.nb_Etats; i++){
        printf("[ i:%d -> %d ]", i, a.Etats_finaux[i]);
    }
    printf("\n");

    // La fonction retourne
}
;


/*La fonction qui affiche la matrice 3D*/
void  affichage_automate(automate a){
   
    /*Déclaration de variables locales*/
    int d1 = a.nb_Etats, d2 = a.nb_Symboles;

    /*int arc_total;
    arc_total = a.Arc_total;*/

    //int *nb_les_arc;
    //a.nb_Arcs_tot = nb_les_arc;

 

    // La taille du tab nombre d'arc par état
    //int size = d2*d1;
    
    int ***m = a.matrice;

    //int **les_arcs_par_etat;
    //les_arcs_par_etat = a.Les_arcs_par_etat;

    int * Tab_Etats_finaux;    
    a.Etats_finaux = Tab_Etats_finaux;


    // Caractéristiques de l'automate
    printf("Les caractéristiques de l'automate sont : \n");
    printf("\n");
    printf("Nombre d'état(s) : %d et Nombre de symboles : %d\n", d1, d2);
    printf("\n");
    printf("Sa matrice est : \n");

    // Sa matrice
    for(int i=0; i<d1; i++){
        printf(" { "); 
        printf(" %d:", i);
        
        for(int j=0; j<d2; j++){
            
            for(int k=0; k<d1; k++){

                printf(" [q%d--(a%d)--q%d:%d] ", i, j, k, m[i][j][k]);

            }
        }
        printf(" }\n");
    }
    printf("\n");

    // Caractéristique de la matrice : 
    //printf("Cette matrice a %d arc(s) au total(s)\n", arc_total);

    //Nombre d'arcs par état:
    //for(int i=0; i<d1; i++){
        //printf("L'état q%d a %d arc(s) : \n", i, nb_les_arc[i]);
        //printf("Soit : ");
        
        // Détails des arcs par chaque état 
        // a.nb_Arcs_tot[i] represente le nombre d'arcs pour cet état
        //for(int arc=0; arc<(d1*nb_les_arc[i]); arc++){

            //printf(" q%d-->q%d ", i, les_arcs_par_etat[i][arc]); 
            
            
        //}
        //printf("\n");

    //}
    
    /*Les Etats finaux*/
    printf("Les états finaux sont : ");
    printf("\n");
    for(int i=0; i<d1; i++){

        if(Tab_Etats_finaux[i]!=0){

            printf(" q%d ", Tab_Etats_finaux[i]);
        }
        
    }
    printf("\n");
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
    printf("\n");
    //printf("L'automate est déjà complet\n");

    /*La fonction retroune : */
    return 1;

};



/*La fonction qui questionne l'utilisateur avant de rendre complet*/
automate question(automate a, int val){

    // Déclaration de varaibles locales
    automate res;
    // Instructions


    // La fonction retourne
    return res;

}


/*La fonction qui permute deux valeurs*/
void echange(int *a, int *b){

    // Déclaration de varaibles locales

    // Instructions


    // La fonction retourne

}


/*La fonction qui copie l'automate dans le but d'en faire une copie*/
automate copie_automate(automate a){

    /*******IDEE******************************/
    // Afin d'anticiper toutes modifications des données sur l'automate
    // de départ lorsqu'on effectue des opérations une tentative de copie
    // consiste à faire un copie res de l'automate de départ puis une seconde
    // copie à partir de l'automate res et tester si ça marche

    // Déclaration de varaibles locales

    /* 1ere Automate */
    automate res; 
    int nb_Etats_1, nb_Symboles_1, etat_initial_1 ;
    int *Etats_finaux_1;
    
 
    res.nb_Etats = nb_Etats_1, res.nb_Symboles = nb_Symboles_1;
    res.etat_initial = a.etat_initial;
    res.Etats_finaux = a.Etats_finaux;

    res = generate_automate_null(a.nb_Etats, a.nb_Symboles, a.nb_Etats);
    int ***m_res = allocation_mat_vide(nb_Etats_1, nb_Symboles_1);
    res.matrice = m_res;

    /* 2ieme Automate */
    automate b;
    int nb_Etats_2, nb_Symboles_2, etat_initial_2;
    int *Etats_finaux_2;

    b.nb_Etats = nb_Etats_2, b.nb_Symboles = nb_Symboles_2;
    b.etat_initial = etat_initial_2;
    b.Etats_finaux = Etats_finaux_2;

    b = generate_automate_null(nb_Etats_2, nb_Symboles_2, nb_Etats_2);
    int ***m_b = allocation_mat_vide(nb_Etats_2, nb_Symboles_2);
    b.matrice = m_b;


    // Instructions

    // 1ere copie dans res
    a.nb_Etats = nb_Etats_1, a.nb_Symboles = nb_Symboles_1;
    a.etat_initial = etat_initial_1;

    res.Etats_finaux = allocation_tab_1D(nb_Etats_1);
    for(int i=0; i<nb_Etats_1-1; i++){
        res.Etats_finaux[i] = a.Etats_finaux[i];
    }

    for(int i=0; i<nb_Etats_1; i++){
        for(int j=0; j<nb_Symboles_1; j++){

            for(int k=0; k<nb_Etats_1; k++){
                
                m_res[i][j][k] = a.matrice[i][j][k];
                
            }
        }
    }

    // 2ieme copie de res vers automate b
    b.nb_Etats = nb_Etats_2, b.nb_Symboles = nb_Symboles_2;
    b.etat_initial = etat_initial_2;
    b.Etats_finaux = Etats_finaux_2;

    b.Etats_finaux = allocation_tab_1D(nb_Etats_2);

    for(int i=0; i<nb_Etats_2; i++){
       Etats_finaux_2[i] = Etats_finaux_1[i]; 
    }
    for(int i=0; i<nb_Etats_2; i++){
        for(int j=0; j<nb_Symboles_2; j++){
            for(int k=0; k<nb_Etats_2; k++){
                
                m_b[i][j][k] = m_res[i][j][k];
            }
        }
    }


    //mise à jour des structures automates
    etat_initial_2 = etat_initial_1;
    Etats_finaux_2 = Etats_finaux_1;
    nb_Etats_2 = nb_Etats_1, nb_Symboles_2 = nb_Symboles_1;
    m_b = m_res;


    // La fonction retourne
    return b;
}

/* La fonction qui lie un automate à ne pas trop utiliser car il va lister tous les chemins possibles*/
int ***lecture_automate(automate a){

    automate m_au;

    int nb_Etats = a.nb_Etats, nb_Symboles = a.nb_Symboles;
    int etat_initial = a.etat_initial;
    int *Tab_Etats_finaux = a.Etats_finaux;
    
    

    // Déclaration de variables locales
    int ***Tab_start, ***Tab_end, ***Tab_stage;

    // Instructions
    Tab_start = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);
    Tab_stage = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);
    Tab_end = allocation_mat_vide(a.nb_Etats, a.nb_Symboles);

    printf("Lecture de la matrice de l'automate : \n");
    printf("\n");

    // Lecture de départ uniquement l'état initial
    printf("Pour l'état inital :\n");
    for(int i=0; i<a.nb_Etats; i++){

        for(int j=0; j<a.nb_Symboles; j++){

            for(int k=0; k<a.nb_Etats; k++){

                // Lecture de départ uniquement l'état initial
                if(a.matrice[0][j][k]==1 && i==0){
                    printf("via a%d on peut aller à  q%d\n", j,  k);
                    
                    // Ajout dans Tab_start uniquement si la valeur 1 est lu pour a.matrice[i][j][k]
                    if(a.matrice[0][j][k]==1){

                        Tab_start[0][j][k] = a.matrice[0][j][k];
                    }
                    
                }
            }
        }   
    }
    printf("\n");
    


    // Lecture intermédiaire
    printf("Pour les états intermédiaires : \n");
    if(a.nb_Etats==2){
        printf("Pas d'états intermédidaires\n");
    }
    else{

        for(int i=1; i<(a.nb_Etats); i++){
            
            for(int j=0; j<a.nb_Symboles; j++){

                
                for(int k=0; k<a.nb_Etats; k++){

                    // Lecture intermédiaire
                    if(a.matrice[i][j][k]==1){
                        printf("De l'état q%d : via a%d on peut aller à q%d\n", i, j, k);
                        Tab_stage[i][j][k] = a.matrice[i][j][k];
                    }
                }
            }
        }
    }
    printf("\n");


    // Lecture de la fin uniquement l'état final de l'automate qn
    printf("Enfin pour l'état final de l'automate q%d: \n", (a.nb_Etats-1));
    
    for(int i=0; i<a.nb_Etats; i++){
    
        for(int j=0; j<a.nb_Symboles; j++){

            for(int k=0; k<a.nb_Etats; k++){

                // Lecture de la fin uniquement l'état final de l'automate qn
                

                if(( a.matrice[i][j][k] == 1) && (k=(nb_Etats-1) )){

                    printf("De l'état q%d via a%d on arrive à q%d \n", i,  j, (a.nb_Etats-1));
                    Tab_start[i][j][k] = a.matrice[i][j][a.nb_Etats];
                }
            }
        }
    }
    printf("\n");



    // La fonction retourne 3 tableaux
    return Tab_start; 
}



/* La fonction teste si un état est un final*/
int est_un_etat_final(automate a, int etat){
    // Déclartion de variable
    
    // Instructions
    for(int i = 0; i<a.nb_Etats; i++){

        if((a.Etats_finaux[i])==etat){

            return 1;
        }
    }
    return 0;

    // La fonctio retoune
}
;





/*La fonction qui rend complet un automate*/
automate rendre_complet(automate a){

    if(est_complet(a)){
        printf("L'automate est complet\n");
        return a;
    }
    /*Déclaration de varaibles locales*/
    automate copie; 

    int nb_Etats = a.nb_Etats+1, nb_Symboles = a.nb_Symboles;
    int etat_initial;
    int *Tab_Etats_finaux;
    int ***m_copie = allocation_mat_vide(nb_Etats, nb_Symboles);

    copie.matrice = m_copie;
    copie.nb_Etats = nb_Etats;
    copie.nb_Symboles = nb_Symboles;
    copie.Etats_finaux = Tab_Etats_finaux;
    copie.etat_initial = etat_initial;

    /*Instructions*/

    for(int i=0; i<nb_Etats-1; i++){

        for(int j=0; j<nb_Symboles; j++){
            int cpt=0;

            for(int k=0; k<nb_Etats-1; k++){

                if(a.matrice[i][j][k]!=0){
                    cpt=1;
                }
            }
            if(cpt==0){
                copie.matrice[i][j][nb_Etats-1]=1;

            }
        }
    }
    for(int j=0; j<nb_Symboles; j++){

        for(int k=0; k<nb_Etats-1; k++){
            //printf("-*****%d\n",nb_Etats);
            copie.matrice[nb_Etats-1][j][k]=0;
        }
        // Les transitions qui boucles sur l'état phi
        copie.matrice[nb_Etats-1][j][nb_Etats-1]=1;

    }
    copie.Etats_finaux = allocation_tab_1D(nb_Etats);
    for(int i=0; i<nb_Etats-1; i++){
        copie.Etats_finaux[i] = a.Etats_finaux[i];
    }

    return copie;

}

/*La concaténatiion */
automate concat(automate a, automate b){
    
    // Déclaration de varaibles locales
    automate res;
    int nb_Etats = a.nb_Etats + b.nb_Etats;
    int nb_Symboles = (a.nb_Symboles, b.nb_Symboles) +1;

    int ***m_concat = allocation_mat_vide(nb_Etats, nb_Symboles);
    res.matrice = m_concat;


    // Instructions 
    
    for(int i=0; i<nb_Etats-1; i++){

        for(int i_1=0; i<a.nb_Etats; );
    }

    // La fonction retourne un automate 
    return res;
};


/* La fonction qui génère le complément d'un automate*/
automate complement_automate(automate a){

    
    // Déclaraiton de varaibles locales
    automate a_complement;
    if(est_complet(a)==0){
        a_complement = rendre_complet(a);
    }

    int nb_Etats = a.nb_Etats;
    int nb_Symboles = a.nb_Symboles;
    a_complement.Etats_finaux = allocation_tab_1D(a_complement.nb_Etats);

    a_complement.matrice = allocation_mat_vide(a_complement.nb_Etats, a_complement.nb_Symboles);

    // Copie de la matrice de l'automate de départ
    for(int i=0; i<nb_Etats; i++){

        for(int j=0; j<nb_Symboles; j++){

            for(int k=0; k<nb_Etats; k++){

                a_complement.matrice[i][j][k] = a.matrice[i][j][k];
            }
        }
    }


    // Instructions
    // Changement des états finaux en états initaux
    for(int i=0; i<a_complement.nb_Etats; i++){

        //printf("i = %d\n", i);
        if(a.Etats_finaux[i]== 0){

            a_complement.Etats_finaux[i]= 1;
            //printf("start******\n");
        }
        

    }

    // La fonction retourne un automate
    return a_complement;
}
/*************************FIN POUR L'AUTOMATE******************************/




/*************************DEBUT MOT***************************************/

/*Saisir le mot*/
mot *mot_saisi_avant(automate a){
    // Déclaration de variables
    mot *mot_saisi;


    // Instructions

    printf("Quelle est la taille de votre mot : ");
    scanf("%d", &mot_saisi->size_mot);
    printf( "\n");
    
    // Traitons les mots à un caractère
    if(mot_saisi->size_mot == 1){

        mot_saisi->Tab_caract = allocation_tab_1D(((mot_saisi->size_mot)+1));
        printf("Veillez saisir votre mot : \n"); 
        scanf("%d", ((mot_saisi->Tab_caract)));
    }

    // Mot avec plus d'un caractère
    else{
        printf("La taille de votre mot est : %d\n", mot_saisi->size_mot);
        mot_saisi->Tab_caract = allocation_tab_1D(((mot_saisi->size_mot)+1));

        printf("Veillez saisir votre mot : \n"); 

        printf("L'indice de chaque caractère est à chosisr entere [ %d et %d ]\n",0 ,((mot_saisi->size_mot)-1));
        printf("Après chaque caractère appyez sur la touche Entrer\n");

        int cpt=mot_saisi->size_mot;

        while (cpt!=0)
        {
            /* code */
            for(int i=0; i<(mot_saisi->size_mot); i++){
            // chaque saisi est sauvegardé dans le tableau
            scanf("%d", ((mot_saisi->Tab_caract) +i));
            cpt -= 1;
            }
            
        }
        printf("\n");

        // Pour marquer la fin du mot dans sa table de caractère
        mot_saisi->Tab_caract[(mot_saisi->size_mot)+1] =-1;

        // Mise à jour de la structure mot
    }

    // La fonction retourne
    return mot_saisi;
};


/*Saisir le mot*/
mot *mot_saisi(automate a){
    // Déclaration de variables
    mot *mot;
    int taille;

    // Instructions
    printf("Entrer la taille du mot à lire\n");
    scanf("%d", &taille);
    mot->Tab_caract = allocation_tab_1D(taille);
    mot->size_mot = taille;

    printf("Les symboles à saisir sont dans l'intervalle : [ 0, %d]\n", a.nb_Symboles-1);

    for(int i =0; i<taille; i++){
        while (1==1)
        {
            /* code */
            int x;
            printf("Entrez le %d-ieme caractère\n", i);
            scanf("%d", &x);

            if(x>=0 && x<a.nb_Symboles){
                mot->Tab_caract[i] = x;
                break;
            }

        }
        
    }

    // La fonction retourne
    return mot;
};


/* La fonciton qui affiche le mot*/
void affichage_mot(mot *m){

    // Déclaration de variables locales

    // Instructions
    // La valeur 100 est mis pour la limte de mot
    printf(" Le mot saisi est : ");
    for(int i=0; i<(m->size_mot); i++){

        /* code */
        printf("a%d", m->Tab_caract[i]);

        
    }
    printf("\n");
    
    // La fonction retourne : rien
}


/* La fonction qui lie un mot et remmplie une matrice D*/
void  lecture_mot(mot m){
    // Déclaration de variable


    // Instructions
    printf("Les caractères du mot sont :\n");

    for(int i =0; i<(m.size_mot); i++){

        printf("[ a:%d -> %d ]", i, m.Tab_caract[i]);
    }
    printf("\n");


    // La fonction retourne
    
};


/* La fonction qui retourne l'état courant dans la lecture d'un automate*/
int retourne_etat_couant(automate a, int curent_state, int curent_symbol){

    // L'automate doit être déterministe

    // Déclaration de variables locales
    int etat_courant = curent_state, symbole_courant = curent_symbol;
    
    // Instructions
    int *States = a.matrice[etat_courant][symbole_courant];

    int state = 0;

    /*Si l'état passé en arg est déjà le dernier de l'automate*/
    if(curent_state == (a.nb_Etats-1)){
        state = a.nb_Etats;
    }
    
    for( int i =0; i<a.nb_Etats; i++){

        if(States[i]==1){

            state = i;
        }
    }

    return state;
}
;


/* La fonction qui dit si un mot est reconnu ou pas par un automate*/
int est_reconnu(mot m, automate a){

    // Il faut l'appeler avec un automate déterministe
    
    // Déclaration de variables locales
    int curent_state = 0, curent_symbol = m.Tab_caract[0];

    // Instructions
    int i=0;
    while (/* condition */ 1==1)
    {
        /* code */
        curent_state = retourne_etat_couant(a, curent_state, curent_symbol);
        printf("état suivant : %d | symbole associé %d\n", curent_state, curent_symbol);
        

        if(curent_state == 0){

            printf("Mot non reconnu\n");
            return 0;
        }
        int final = est_un_etat_final(a, curent_state);
        if((curent_state == (a.nb_Etats-1)) || final==1){

            printf("val : %d\n", final);
            if(final==1){

                printf("Mot reconnu\n");
                printf("Final = %d\n", final);
                return 1;
            }
            printf("Le mot n'est pas reconnu\n");
            printf("Final = %d\n", final);
            return 0;   
        }
        i += 1;
        curent_symbol = m.Tab_caract[i];
        printf("curent syombol avant tour suivant : %d\n", curent_symbol);
        printf("Etat suivant avant tout : %d\n", curent_state);
        final=0;
    }
          
    // La fonction retourne 
}


/* La fonction qui réalise un certains nombres de test de la reconnaissance de mots*/
int test_reconnaissance(automate a,  int n_fois){
    // Déclaration de variables locales
    mot *m;
    int res;

    // Instructions
    for(int i=0; i<n_fois; i++){

        m = mot_saisi_avant(a);
        if(est_reconnu(*m, a)==1){

            printf("Le mot : ");
            affichage_mot(m);
            printf("est reconnu\n");
        }
        printf("Le mot : ");
        affichage_mot(m);
        printf("n'est pas reconnu\n");
        

    }

    // La fonction retourne
    return 1;
}



/* La fonction qui retrouve un état par application d'un symbole du mot*/
int find_next_state(automate a, mot m){

    // Remarque ici on ne connait pas l'état courant

    // Déclaration de variables locales
    int get_state;
    int last_symbol_mot = m.Tab_caract[m.size_mot-1];
    

    // Instructions
    for(int i=0; i<a.nb_Etats; i++){

        for(int j=0; j<a.nb_Symboles; j++){

            for(int k=0; k<a.nb_Etats; k++){

                if(a.matrice[i][last_symbol_mot][a.nb_Etats-1]==1){

                    get_state=k;
                }
            }
        }
    }

    // La fonction retourne : déjà fait plus haut
    return get_state;
}




/* La fonction qui teste si un mot est reconnu Version 2*/
int reconnu_v2(mot m, automate a){

    //Déclaratoin de variables locales
    int curent_state = 0;
    int next_state;
    int symbole_mot = m.Tab_caract[0];

    //instructions
    if(m.size_mot==1){
        for(int i=0; i<a.nb_Etats; i++){

            if((a.Etats_finaux[i]==1) || i==m.Tab_caract[0]){
                printf("Oui\n");
                return 1;
            }
            printf(" Là reconnu\n");
            return 0;
        }

    }

    int last_symbol_mot = m.Tab_caract[m.size_mot-1];

    int proba_state_final = find_next_state(a, m);

    if(m.size_mot>=2 || a.nb_Etats>=3){

        if(est_un_etat_final(a, proba_state_final)==0){
            printf("Le mot non \n");
            return 0;
        }
        else if (est_un_etat_final(a, proba_state_final)==1){
            
            for(int i=0; i<m.size_mot-1; i++){
                
                next_state = retourne_etat_couant(a, curent_state, m.Tab_caract[i]);
                if(next_state==1){
                    
                    /* Si val =1, alors cet état est attient on continue*/
                    curent_state = i;
                }

                else{
                    /* Ce i-ème état n'est pas ettient ce qui fait que le mot n'est pas reconnu*/
                    printf("Pas reconnu\n");
                    return 0;
                }
                
            }
            printf("Finalement OUI\n");
            return 1;
        }
    }
    // La fonction retourne
}
;


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
    mot *mot_test, *mot_test2;
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

