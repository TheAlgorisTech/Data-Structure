/**
 * \file liste.c
 * \brief Listes doublement chaînées de monomes
 */

#include "liste.h"

#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>


#define MALLOC(t)      ((t*)malloc(sizeof(t)))

/**
 * \brief Liste
 */
struct liste {
  /** \brief Feves. */
  unsigned int graines;
  /** \brief Élément suivant dans la liste. */
  struct liste* suivant;
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions locales
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Retourne le ième maillon d'une liste.
 * \param[in] l Liste d'entrée.
 * \param[in] i Indice du maillon recherché.
 * \return ième maillon de la liste.
 *
 * \pre liste_est_vide(l) == false
 * \pre 0 <= i < liste_longueur(l)
 */
static inline liste* liste_ieme_maillon(const liste* const l, const size_t i) {
  const liste* courant = l;
  for (size_t j = 0; j < i; ++j)
    courant = courant->suivant;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
  return (liste*) courant;
#pragma GCC diagnostic pop
}

////////////////////////////////////////////////////////////////////////////////
// Constructeurs
////////////////////////////////////////////////////////////////////////////////

liste* liste_vide(void) {
  /* (Peut-être) À modifier ou compléter. */
  liste* l = MALLOC(liste);
  l->suivant = l;
  return l;
}

liste* liste_inserer_tete(liste* const l, const unsigned int graines) {

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





liste* liste_supprimer(liste* const l, const size_t i) {
    liste* temp = l;
    if (i==0){
          if(l->suivant == l) {
         temp = NULL;
        }
        temp = temp->suivant;
        return temp;
    }
    else{
        for(int j=0; j < i-1; j++) temp = temp->suivant;
        temp->suivant = temp->suivant->suivant;
    }

    return temp;
}



liste* liste_egrainer(liste* const l, const size_t ieme) {
  /* (Peut-être) À modifier ou compléter. */

  return l;
}

liste* liste_modifier(
    liste* const l, const size_t i, const unsigned int graines) {
  liste* const li = liste_ieme_maillon(l, i);
  li->graines = graines;
  return l;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeurs
////////////////////////////////////////////////////////////////////////////////

void liste_detruire(liste* const l) {
  if (liste_est_vide(l)) {
    return;
  }
    liste* copy=l;
    int len = liste_longueur(l);
    int i=0;
    while (i<=len){
        copy=liste_supprimer(copy, i);
        i++;
    }
    return;
  /* (Peut-être) À modifier ou compléter. */
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs
////////////////////////////////////////////////////////////////////////////////

bool liste_est_vide(const liste* const l) {
  return l ? false : true;
}

unsigned int liste_ieme(const liste* const l, const size_t ieme) {
  /* (Peut-être) À modifier ou compléter. */
  const liste* temp=l;
  for (size_t j=0; j < ieme; j++) {
    temp = temp->suivant;
  }
    return temp->suivant->graines;
}

size_t liste_longueur(const liste* const l) {
    return (l->suivant == l) ? 0: 1+liste_longueur(l->suivant);
}

////////////////////////////////////////////////////////////////////////////////
// Divers
////////////////////////////////////////////////////////////////////////////////

void liste_afficher(FILE* const stream, const liste* const l) {
  if (liste_est_vide(l)) {
    fprintf(stream, "graines:\n");
    fprintf(stream, "index:\n");
    return;
  }

  fprintf(stream, "graines: ");
  fprintf(stream, "%2u", l->graines);
  for (const liste* p = l->suivant; p != l; p = p->suivant) {
    fprintf(stream, "  %2u", p->graines);
  }
  fprintf(stream, "\n");

  if (isatty(fileno(stream))) {
    fprintf(stream, "\033[2m");
  }
  fprintf(stream, "index: ");
  size_t i = 0;
  fprintf(stream, "%2zu", i);
  for (const liste* p = l->suivant; p != l; p = p->suivant) {
    ++i;
    fprintf(stream, "  %2zu", i);
  }
  fprintf(stream, "\n");
  if (isatty(fileno(stream))) {
    fprintf(stream, "\033[0m");
  }
}
