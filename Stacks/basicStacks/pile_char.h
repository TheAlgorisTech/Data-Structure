
#ifndef pile_char_h
#define pile_char_h
#include"base.h"

#define S char
#define MAX_P 50
typedef struct {
		char tab[MAX_P];
		Nat h;} Pile;

//creer une pilenouv
Pile pilenouv(); 

//empiler une pile
Pile empiler(Pile p,S x);

//depiler une pile
Pile depiler(Pile p);

//remplacer d'un sommet
Pile remplacer(Pile p,S x);

//element en sommet
S sommet(Pile p);

//test de vaccuité
Bool vide(Pile p);

//nombre d'element
Nat hauteur(Pile p);

#endif

