#ifndef pile_char2_h
#define pile_char2_h
#include"base.h"
#define S char

typedef struct Spile{
		char v;
		struct Spile *s;} Spile, *Pile;



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
