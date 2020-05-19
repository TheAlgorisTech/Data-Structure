#include "base.h"



Liste listenouv(){
	return NULL;
}

S tete(Liste l){
	return l->v;
}

Bool vide(Liste l){
	return l==NULL;
}


Liste ajoutt(Liste l,S x){
	Liste l1=MALLOC(Sldc);
	l1->v=x;
	if(vide(l))
	{
		l1->p=l1;
		l1->s=l1;
		l=l1;
	}
	else
	{
		l1->s=l; //l1->s=l->s
		l1->p=l->p;




Liste supprimet(Liste l){
	
	sldc *l1;
	if(l==l->s &&l==l->p){
		FREE(l);
		return NULL;
	}
	else {
		l1=l->s;
		l->s=l->p;
		FREE(l1);
		
		

Nat longueur(Liste l){
	Nat lgr=0
	Liste l1=l;
	if(vide(l))
		return 0;
	else{

	while(l->s!=l1){
		l=l->s;
		lgr++;
	}
	return lgr;
	}
}



Bool app(Liste l,S x){
	Liste l1=l;
	if(vide(l))
		return faux;
	else{
	while(l->s!=l->v!=x){
		l=l->s;
	}
	return (l->v==x)?vrai:faux;
	}
}

S acces_ieme(Liste l,Nat i){
	Liste l1=l
	while(int j!=i,l->s!=l1){
		j++;
		l=l->s;
	}
	return l->v;
}


Liste insection_ieme(Liste l,S x,Nat i){
	





	
	
