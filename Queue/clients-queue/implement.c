/*
 * =====================================================================================
 *
 *       Filename:  implement.c
 *
 *    Description:  Implementation des Clients & files Clients
 *
 *        Version:  1.0
 *        Created:  19/05/2020 10:35:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fayssal Abdallah, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>



typedef struct {
	char nom;
	char prenom;
	int status;
} Client;


Client clientnouv(char n,char p,int s){
	Client new_c;
	new_c.nom = n;
	new_c.prenom = p;
	new_c.status = s;
	return new_c;	
}

char nom(Client c){
	return c.nom;
}
char prenom(Client c){
	return c.prenom;
}

int status(Client c){
	return c.status;
}

bool estprime(Client c){
	return (c.status == 1);
}
bool estclassique(Client c){



typedef struct clfile
{
    Client c;
    struct clfile * s;
} Clfile;


typedef struct cfile {
    Clfile *tete; //Pointeur tête de file
    Clfile *queuep; //Pointeur cleint propritaire queuep
    Clfile *queuec; //Pointeur cleint classique queuep
} File;


File filenouv(){
    File f;
    f.tete = NULL;
    f.queuep = NULL;
    f.queuec = NULL;
    return f;
}


File adjc(File f, Client nc){
	// 
	Clfile *c1 = MALLOC(Clfile);
	f1->c = nc;
	f1->s = NULL;
	if (f == NULL){
		// Si file d'attente est file donc le client
		// est en même temps classique et propritaire
		f.tete = f1;
		f.queuec = f1;
		f.queuep = f1;
	}
	if (estprime(c)){
	  // Si le client est prime 
	  // File queueprimaire pointe vers le client
	  f.queuep->s = f1;
	  f.queuep = f1;
	  
	}
	else if (estclassique(c)){
	// Si le client est classique
	// File queuerclassique pointe vers le client	
	  f.queuec->s = f1;
	  f.queuec = f1;
	}
	return f;
}

Client tete(File f){
	return f.tete->c;
}

Client queue(File f){
	Client rest;
	// Retourne le client propritaire s'ils exist
	if (f.queuep != NULL){
		rest = f.queuep->c;
	}
	else{
		// Sinon retourn le dernier client classique
		rest = f.queuec->c;
	}
	return rest;
}

Client queuep(File f){
	return f.queuep->c;
}

Client queuep(File f){
	return f.queuec->c;
}

bool vide(File f){
	// Verifier si non tete existant dont la file est vide
	return (f.tete == NULL);
}

File supt(File f) {
	Clfile *f1;
	if (f.tete == f.queuec || f.tete == f.queuep) {
	   FREE(f); // Supprimer tête
	   return NULL;
	}
	else {
		if (f.queuep != NULL){
		// S'il existe des client prioritaire
		// Supprimer le dernier client prioritaire
		f1 = f.queuep-> s;
		f.queuep-> s = f.queuep-> s -> s;
		FREE(f1);
		return f;
		}
		else{
		f1 = f.queuec-> s;
		f.queuec-> s = f.queuec-> s -> s;
		FREE(f1);
		return f;
		}
	}
}
