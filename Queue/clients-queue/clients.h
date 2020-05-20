/*
 * =====================================================================================
 *
 *       Filename:  clients.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/05/2020 12:57:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


typedef struct Client Client;
struct Client {
	char nom[50];
	char prenom[50];
	int status_; //1 if premium else 0
};

Client clientnouv(char n[50], char p[50], int s);

void printClient(Client c);
char nom(Client c);
char prenom(Client c);
int status(Client c);
//bool estprime(Client c);
//bool estclassique(Client c);
