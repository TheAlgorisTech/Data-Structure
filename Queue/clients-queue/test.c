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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "clients.h"
#include "queue.h"



int main()
{
	Client cl_1 = clientnouv("Joey", "Jbou",1);
	Client cl_2 = clientnouv("Joey1", "Jbou1",0);
	Client cl_3 = clientnouv("Joey2", "Jbou2",1);
	Client cl_4 = clientnouv("Joey3", "Jbou3",0);

	// Construct new queue
	Queue nq = newqueue();
	nq = adjc(nq, cl_1);
	nq = adjc(nq, cl_2);
	nq = adjc(nq, cl_3);
	nq = adjc(nq, cl_4);

	printClient(head(nq));
	printClient(tailc(nq));
	printClient(tailp(nq));


	// Create 1000 Clients with status ~ Bernoulli distribution
	// Add Clients to the queue
	// Access Head of the queue
	// Acces

	return 0;
}

