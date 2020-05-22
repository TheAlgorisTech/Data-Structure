/*
 * =====================================================================================
 *
 *       Filename:  queue.c 
 *
 *    Description:  Clients Queue (Premium & Non-Premium)
 *
 *
 *         Author:  Fayssal404, 
 *
 * =====================================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "clients.h"
#include "queue.h"

Queue newqueue(){
	//
	Queue f;
    	f.head = NULL;
    	f.tailp = NULL;
    	f.tailc = NULL;
   	return f;
}

bool empty(Queue f){
 	//
	return (f.head == NULL);
}


Queue adjc(Queue f, Client c){
	// 
	Clfile *c1 = MALLOC(Clfile); // Client BOX
	c1->c = c; 
	c1->next = NULL;

	if (f.head == NULL){
		//f.head = c1->next;
		f.head = c1;
		if (estprime(c)){
			f.tailp=f.head;
		}
		else{
			f.tailc=f.head;
		}
	}
	if (estprime(c)){
		f.tailp = c1->next;
		f.tailp = c1;
	}
	else{
		f.tailc = c1->next;
		f.tailc = c1;
	}
	return f;
}

Client head(Queue f){
	return f.head->c;
}


Client tail(Queue f){
	Client rest;
	// Retourne le client propritaire s'ils exist
	if (f.tailp != NULL){
		rest = f.tailp->c;
	}
	else{
		// Sinon retourn le dernier client classique
		rest = f.tailc->c;
	}
	return rest;
}

Client tailp(Queue f){
	return f.tailp->c;
}

Client tailc(Queue f){
	return f.tailc->c;
}

bool emptyQueue(Queue f){
	// Verifier si non tete existant dont la file est vide
	return (f.head == NULL);
}
Queue supt(Queue f){
	//
	Clfile *c1 = f.head;
	// Delete Client from Premium Client Queue
	f.head = f.head->next; //Pass to the next element
       	free(c1);

	return f;

}
