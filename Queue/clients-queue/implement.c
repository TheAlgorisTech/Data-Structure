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

#include "clients.h"

int main()
{
	Client new_cl = clientnouv("Joey", "Jbou",1);
	Client newcl = clientnouv("Joey1", "Jbou",0);
	Client newl = clientnouv("Joey2", "Jbou",1);
	Client new = clientnouv("Joey2", "Jbou",0);
	printClient(new_cl);
	printClient(newcl);
	printClient(newl);
	printClient(new);
	
	return 0;
}

