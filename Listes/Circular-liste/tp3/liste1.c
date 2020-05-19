#include "liste1.h"

Liste listenouv(){
	return NULL;
}

Liste ajoutt(Liste l,S x){
	Liste l1=MALLOC(Strliste);
	if(l==NULL){
		l1->v=x;
		l1->s=NULL;
		l=l1;
	}
	else {
		l1->v=x;
		l1->s=l;
		l=l1;
	}
*	return l;
}

S tete(Liste l){
	return l->v;
}

Bool vide(Liste l){
	return l==NULL;
}


//recursive
Nat longueur(Liste l){
	return vide(l)?0:1+longueur(l->s);
}

//iteratif
/*
Nat longeur(Liste l){
	int lgr=0;
	while(l-s!=NULL)	
	{
		lgr++;
	}
}
	
*/


Liste supt(Liste l){
	Strliste l1=l;
	if (l->s==NULL){
		FREE(l1);
		return l;
	}
	else {
		Strliste l2=l->s;
		FREE(l1);
		l=l2;
		return l;
	}
}

//recursive
/*Bool app(Liste l,S x){
	if(l->v==x) return Vrai;
	else {
		l=l->s;
		return app(l,x);
	}
} 
*/

//iteratif
Bool app(Liste l,S x){
	
	
	while(l->s!=NULL && l->v!=x)
	{
		l=l->s;
	}
	if (l->v==x) return Vrai;
        else Faux;

}


/*Nat rech1(Liste l,S x){
	int rech=0;
	if (l==NULL) return rech;
	else{
 		while(l-v!=x && l->s!=NULL)
		{
			rech++;
		}
	return rech;	
	}
}
*/	
//renvoyer le liste commencant par cette élement

Liste rech2(Liste l,S x){
	if (l==NULL) return NULL;
	else {
		while (l->v!=x && l->s!=NULL)
		{
			l=l->s;
		}
		return (l->v==x)?l:NULL;
	}
}


//version recursive
Liste changement(Liste l,S x,S y){
	if (l==NULL) return l;
	else if (l->v==x){
		l->v=y;
		return l;
	}
	else{
		l=l->s;
		return changement(l,x,y);
	}
}	



Liste avantrech(Liste l,S x){
	while(l->s!=NULL &&l->v!=x){
		l=l->s;
	}
	return l;
}

Liste supr1ocerence(Liste l, S x){
	Liste l1;
	if(l!=NULL)
	{
		if(l->v==x)
			l=supt(l);
		else{
			l1=avantrech(l);
			if (l1!=NULL)
			{
				Strliste *l2=l1->s;
				l1->s=l1->s->s;
				FREE(l2);
			}
		}

	}
	return l;
}



Liste dernier(Liste l){
	while(l->s!=NULL)
	l=l->s;
	return l;
}
Liste ajoutq(Liste l,S x){
	Liste der=dernier(l);
	Liste l1=MALLOC(Strliste);
	l1->v=x;
	l1->s=NULL;
	der->s=l1;
	return l;

}


Liste avantdernier(Liste l){
	Liste l2=l;
	while(l2->s->s!=NULL)
		l2=l2->s;
	return l2;
}



Liste supq(Liste l){
	Liste l1=avantdernier(l);
	Liste l2=dernier(l);
	l1->s=NULL;
	FREE(l2);

	return l;
}


	



