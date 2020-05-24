#include "pile_char2.h"
#include"base.h"

Pile pilenouv(){
  return NULL;
}

Pile empiler(Pile p,S x){
  Pile p1=MALLOC(Spile);
  p1->v=x;
  p1->s=p;
  return p1;
}

Pile depiler(Pile p){
  return p->s;
}

Pile remplacer(Pile p,S x){
  return empiler(depiler(p),x);
}

S sommet(Pile p){
  return p->v;
}

Bool vide(Pile p){
  return  p==NULL;
}

Nat hauteur(Pile p){
  return vide(p)?0:1+hauteur(p->s);
}


