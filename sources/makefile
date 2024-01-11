
#------------------------------------------------
#***********************************************
#AUTOMATISATION DE LA COMPILATION : MAKEFILE DYNAMIQUE 



#-----------------------------------------------
#__Dynamique :

#__Définition des varaibles : 
# $@ : pour ne plus écrire la variable
# $< : 1ere dépendance : ici l'unique dépendance Automate.h
# $^ : La liste des dépendances : utile pour lister tous les .o qui seront exécutés




#-----------------------------------------------------------------------------------------------
#__Liste des fichiers :

#__La variable joker : SRC pour les fichiers en .c dans le projet : Test.c et automate.c
#SRC = $(wildcard *.c)

#__La variables des fichiers en .o : Dans le projet : Test.o et automate.o
#OBJ = $(SRC: .c=.o)

#__Les fichiers .c et .h en MY_FILE
#MY_FILE=automate.c Automate.h

#__Le dossier build : sa variable est DIR
#DIR=/data/ECOLE/COURS_ECOLE/COURS/2023-2024/S1/UE-1 INFO  - ECT =9.5/Projet C - AEF/Using for Ubuntu/Plan de travail/Questions au Prof/Travail de depart pour échange

#__Création des .o et .exe dans le répertoire build avec une définition des chemin cible
#build/%.o : %.c Automate.h $(BUILD_DIR)
#				$(CC) -c $< -o $

#__Si le dossier build n'existe pas on le cré et on utilise la cible crée comme dépendance
# build/:
#	mkdir -p build/

#-----------------------------------------------------------------------------------------------
#__Les commandes Shell :

#__Pour utiliser les variales crées : $(nom_de_la_variable)

#__Les variables de commandes
#CC = gcc

#******************************
#__Avant : pas dynamique
#___Première cible : all
all : exec

#__Les autres cibles

Test.o: test_charly.c Automate.h
		gcc -c $< -o $@
	
automate.o: automate.c Automate.h
			gcc -c $< -o $@

exec: test_charly.o automate.o
		gcc $^ -o $@
#*********************************


#**********************************
#__Après : DYNAMIQUE 

#CC = gcc
#SRC = $(wildcard *.c)
#OBJ = $(SRC: .c =.o)

#nom repertoire
#BUILD_DIR = cytech@student-laptop:~/Projet_C/build

#mise à jour liste obj avec nom dossier
#OBJ2 = $(addprefix $(BUILD_DIR)/, $(OBJ))

#all : $(BUILD_DIR)/exec

#BUILD_DIR sert de dépendance
#$(BUILD_DIR)/%.o : %.c Automate.h $(BUILD_DIR)
#		$(CC) -c $< -o $@

#$(BUILD_DIR)/exec: $(OBJ2)
#		$(CC)  $^ -o $@

#creation repertoire
#$(BUILD_DIR):
#		mkdir -p $(BUILD_DIR)/



