#include "liste_avancee.h"

#include <stdlib.h>

liste* liste_range(S debut, S fin, S pas)
{
  /* (Peut-être) À modifier ou compléter. */
  liste* l=liste_vide();

  for(S i = debut; i < fin; i+=pas){
	l = liste_insertion_tete(l, i);
	}
  return liste_debut(l);
}


liste* liste_reverse(const liste* l)
{ 
  liste* copy=liste_fin(l);
  liste* resultat = liste_vide();
  if (liste_est_vide(copy)){
	return liste_vide(); 
	}
   while (copy){
	resultat = liste_insertion_tete(resultat, liste_element(copy));
	copy = liste_precedent(copy);
	}
   return liste_debut(resultat);
}

liste* liste_map(const liste* l, S (*f)(S))
{
  /* (Peut-être) À modifier ou compléter. */
  liste* copy=liste_debut(l);
  liste* resultat = liste_vide();
  if (liste_est_vide(copy)){
	return resultat;
	}
   while (copy){
         resultat = liste_insertion_tete(resultat,f(liste_element(copy)));	
	 copy = liste_suivant(copy); 
	}  
    return liste_debut(resultat);
}

liste* liste_filter(const liste* l, bool (*f)(S))
{
  /* (Peut-être) À modifier ou compléter. */

  liste* copy=liste_debut(l);
  liste* resultat = liste_vide();
  if (liste_est_vide(copy)){
	return copy;
	}
   while (copy){
	 if (f(liste_element(copy))) 
	    resultat = liste_insertion_tete(resultat, liste_element(copy));
	 copy = liste_suivant(copy);
	}
   return resultat;
}

S liste_reduce(const liste* l, S (*f)(S, S))
{
  /* (Peut-être) À modifier ou compléter. */
  liste* copy=liste_debut(l);
  size_t len = liste_longueur(l);
  if (liste_est_vide(copy)){
	return (S) 0;
	}
  if (len==1) return liste_element(copy);
  S result = f(liste_element(liste_ieme(l,0)), liste_element(liste_ieme(copy,1)));
  for (size_t i=2; i < len; i++){
        result = f(result, liste_element(liste_ieme(copy,i)));  	
	}
  return result;

}

void liste_fold_left(const liste* l, void (*f)(void*, S), void* resultat)
{
  /* (Peut-être) À modifier ou compléter. */
  liste* copy = liste_debut(l);
  size_t len = liste_longueur(copy);
  if (liste_est_vide(copy)) return ;
  
  for (size_t i=0; i < len; i++){
	f(resultat, liste_element(liste_ieme(copy,i)));
	}
}

void liste_fold_right(const liste* l, void (*f)(S, void*), void* resultat)
{
  /* (Peut-être) À modifier ou compléter. */
  liste* copy = liste_fin(l);
  size_t len = liste_longueur(copy);
  if (liste_est_vide(copy)) return ;
  
  for (size_t i=1; i <= len; i++){
	f(liste_element(liste_ieme(copy,len-i)), resultat);
	}
}

S liste_somme(const liste* l)
{
  
  liste* copy=liste_debut(l);
  size_t len = liste_longueur(copy);
  if (liste_est_vide(copy)){
	return (S) 0; // 0
	}

  if (len==1) return liste_element(copy);
  S result=0;
  for (size_t i=0; i < len; i++){
        result += liste_element(liste_ieme(copy,i));  	
	}
  return result;

}

S liste_produit(const liste* l)
{
  /* (Peut-être) À modifier ou compléter. */
  liste* copy=liste_debut(l);
  size_t len = liste_longueur(copy);
  if (liste_est_vide(copy)){
	return (S) 0; // 0
	}

  if (len==1) return liste_element(copy);
  S result=1;
  for (size_t i=0; i < len; i++){
        result *= liste_element(liste_ieme(copy,i));  	
	}
  return result;
}

S liste_minimum(const liste* l)
{
  liste* copy=liste_debut(l);
  if (liste_est_vide(copy)){
	return liste_element(copy);
	}
  liste* p2=liste_suivant(copy);
  S min = liste_element(copy);
  while (p2){
	if (min > liste_element(p2)) min = liste_element(p2);
	p2 = liste_suivant(p2);
	}
   return min;
}

S liste_maximum(const liste* l)
{
  /* (Peut-être) À modifier ou compléter. */
  liste* copy=liste_debut(l);
  if (liste_est_vide(copy)){
	return liste_element(copy);
	}
  liste* p2=liste_suivant(copy);
  S max = liste_element(copy);
  while (p2){
	if (max < liste_element(p2)) max = liste_element(p2);
	p2 = liste_suivant(p2);
	}
  return max;
}

liste* liste_carre(const liste* l)
{
  /* (Peut-être) À modifier ou compléter. */
  liste* copy=liste_debut(l);
  liste* resultat = liste_vide();
  if (copy == NULL) return copy;  
  while(copy){
	resultat = liste_insertion_tete(resultat, liste_element(copy) * liste_element(copy));
	copy = liste_suivant(copy);
	}
  return resultat;
}

bool liste_any(const liste* l, bool (*f)(S))
{
  /* (Peut-être) À modifier ou compléter. */
  liste* copy=liste_debut(l);
  
  if (copy == NULL) return false;  
  while (copy){
	if (f(liste_element(copy))){
	 return true;
	}
	copy = liste_suivant(copy);
	}
	return false;
}

bool liste_all(const liste* l, bool (*f)(S))
{
  /* (Peut-être) À modifier ou compléter. */
  liste* copy=liste_debut(l);
  if (copy == NULL) return false;  
  while (copy){
	if (!f(liste_element(copy))) {
	 return false;
	}
	copy = liste_suivant(copy);
	}
	return true;
}

