#include "base.h"

typedef struct Striste{
	S v;
	struct Strliste *s;
}Strliste, *Liste;

#define S Nat

Liste listenouv(){
	return NULL;
}

S tete(Liste l){
	return f->s->v;
}


Bool vide(Liste l){
	return f->s==NULL;
}

Liste ajoutt(Liste l){
	Liste l1=(Strliste*)malloc(Strliste);
	l1->v=x;
	if(vide(l)) 
	{
		l1->s=l1
		l=l1;
	}
	else 
	{
		l1->s=l->s;
		l->s=l1;
	}
	return l;
}





Liste supt(Liste l){
	Strliste *l1;
	if(l==l->s)
	{
		FREE(l);
		return NULL;
	}
	else
	{
		l1=l->s;
		l->s=l->s->s;
		FREE(l1);
		return l;
	}
}
	











