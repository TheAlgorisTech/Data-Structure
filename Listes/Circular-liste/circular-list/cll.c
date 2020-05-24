#include "cll.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define MALLOC(t)      ((t*)malloc(sizeof(t)))







struct liste{
  /** \brief Feves. */
  int graines;
  /** \brief Élément suivant dans la liste. */
  struct liste* suivant;
};



liste* liste_vide(void) {
  /* (Peut-être) À modifier ou compléter. */
  liste* l = MALLOC(liste);
  l->suivant=l;
  return l;
}

liste* liste_inserer_tete(liste* const l, const unsigned int graines) {
  /* Inserer des graines en tete de liste;
    pour inserer une graine a la tête d'une liste, il faut traverser
    la liste entiére, pour éviter de traverser la liste entiére,
    on prend un pointeur dans la dernier node. D'où l'insertion
    dans la tête ou la queu de la liste est indépendante de la taille
    de la liste
    faire allocation mémoire pour le maillon à inserer dans la liste,
    initaliser le nouveau maillon avec la valeur de graine à inserer
    si la liste est nulle il suifit de pointer la liste vers la graine à inserer,

  */

   liste* copy=l;
  //create a link
   liste* link = MALLOC(liste);
   link->graines = graines;

   if (copy==NULL) {
      copy = link;
      copy->suivant = copy;
   } else {
      //point it to old first node
      link->suivant = copy;
      //point first to new first node
      copy = link;
   }
   return copy;
}

bool liste_est_vide(const liste* const l) {
  return l ? false : true;
}

int liste_longueur(const liste* const l) {
    return (l->suivant == l) ? 0: 1+liste_longueur(l->suivant);
}


liste* liste_supprimer(liste* const l, const int i) {
    /*
    Supprimer le ième élément d'une liste,

    Verifier que i est entre 0 et la taille de la liste, les préconditions
    que la valeur de l'indexe i soit plus petit que la taille
    */

    liste* temp = l;
    if (i==0){
          if(l->suivant == l) {
         temp = NULL;
        }

        //mark next to first link as first
        temp = temp->suivant;
    }
    else{
        for(int j=0; j < i-1; j++) temp = temp->suivant;
        temp->suivant = temp->suivant->suivant;
    }

    return temp;
}


void liste_detruire(liste* const l) {

    liste* copy=l;
    int len = liste_longueur(l);
    int i=0;
    while (i<=len){
        copy=liste_supprimer(copy, i);
        i++;
    }
    return;

}




void dcll(liste* l){
   liste* ptr = l;
   printf("\n[ ");

   //start from the beginning
   if (l != NULL) {

    do {
         printf("%d,",ptr->graines);
         ptr = ptr->suivant;
    }
      while(ptr->suivant != ptr);
   }

   printf(" ]\n");

}


int main(){

    liste* l=liste_vide();
    l=liste_inserer_tete(l, 1);
    l=liste_inserer_tete(l, 4);
    l=liste_inserer_tete(l, 5);
    l=liste_inserer_tete(l, 6);

    dcll(l);

    printf("Longeur L %d \n", liste_longueur(l));
    //l=liste_supprimer(l,0);
    // l=liste_supprimer(l,0);
    l=liste_supprimer(l,1);
    dcll(l);

    liste_detruire(l);
    dcll(l);
    // Ajouter element  a la liste
    return 0;
}
