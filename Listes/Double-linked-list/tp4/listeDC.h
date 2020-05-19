#include "base.h"
#define S Nat

typedef struct sldc{
	S v; //valeur
	struct sldc *s; //suivant
	struct sldc *p; //précédent
}sldc *Liste;


Liste listenouv();

S tete(Liste l);

Liste ajoutt(Liste l,S x);

Liste supprimet(Liste l);

Nat longueur(Liste l);

Bool vide(Liste l);

Bool app(Liste l,S x);

S acces_ieme(Liste l,Nat i);

Liste insection_ieme(Liste l,S x,Nat i);

Liste supprime_ieme(Liste l, Nat i);

Liste changement(Liste l,S x,Nat i);


