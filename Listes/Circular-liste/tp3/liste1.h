#include "base.h"

#define S Nat

typedef struct strliste{
		S v;
		struct strliste *s;
		}Strliste, *Liste;

Liste listenouv();

Liste ajoutt(Liste l,S x);

Liste supt(Liste l);

S tete(Liste l);

Bool vide(Liste l);

Nat longueur(Liste l);

Bool app(Liste l,S x);

Nat reche1
