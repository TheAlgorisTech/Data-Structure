#include "pile_char.h"
#include"base.h"

Pile pilenouv(){
  Pile p;
  p.h=0;
  return p;
}

Pile empiler(Pile p,S x){
  p.tab[p.h]=x;
  p.h++;
  return p;
}

Pile depiler(Pile p){
  p.h=p.h-1;
  return p;
}

Pile remplacer(Pile p,S x){
  p.tab[p.h-1]=x;
  return p;
}

S sommet(Pile p){
  return p.tab[p.h-1];
}

Bool vide(Pile p){
  return  p.h==0;
}

Nat hauteur(Pile p){
  return p.h;
}


