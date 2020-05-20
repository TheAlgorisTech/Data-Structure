/*
 * =====================================================================================
 *
 *       Filename:  clients.c
 *
 *    Description:  Clients Structures 
 *
 * =====================================================================================
 */
#include <stdbool.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clients.h"


Client clientnouv(char n[50], char p[50], int s){
	Client c;
	strcpy(c.nom, n);
	strcpy(c.prenom,p);
	c.status_ = s;
	return c;
}

void printClient(Client c){
	printf("Last Name: %s\n", c.nom);
	printf("Fist Name: %s\n", c.prenom);
	printf("Status: %d\n", c.status_);
}
char nom(Client c){
	return c.nom;
}
char prenom(Client c){
	return c.prenom;
}

int status(Client c){
	return c.status_;
}


//bool estprime(Client c){
//	return (c.status_ == 1);
//}
//bool estclassique(Client c){
//	return (c.status_ == 0);
//}


