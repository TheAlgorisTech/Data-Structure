/**
 * \file files_ch.c
 * \brief Source pour les files chaînées alternatives.
 */



#include "file.h"

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

////////////////////////////////////////////////////////////////////////////////
// struct
////////////////////////////////////////////////////////////////////////////////

struct chainon
{
  /** \brief Élément de type S */
  S element;
  /** \brief Pointeur sur le suivant */
  struct chainon* suivant;
};
typedef struct chainon chainon;

struct file
{
  /** \brief Tête de file chainée */
  chainon* tete;
  /** \brief Queue de file chainée */
  chainon* queue;
  /** \brief Nombre d'éléments dans la file */
  size_t taille;
};

////////////////////////////////////////////////////////////////////////////////
// Constructeurs
////////////////////////////////////////////////////////////////////////////////

file* file_nouv(void)
{
  file* const f = MALLOC(file);
  //if (!f)
  //ERREUR("malloc");
  /* (Peut-être) À modifier ou compléter. */
  //else{
    f->tete->suivant = NULL;
    f->queue->suivant = NULL;
    f->taille = 0;
  //}
  return f;
}

file* file_adjq(file* const f, const S x)
{
  chainon* const nouveau_chainon = MALLOC(chainon);
  //if (!nouveau_chainon)
   // ERREUR("malloc");
  /* (Peut-être) À modifier ou compléter. */
 /* If empty f->h = nouveau_chain f->q = nouveau_chainon*/
  //else{
    nouveau_chainon->element = x;
    nouveau_chainon ->suivant = NULL;
    f->queue = nouveau_chainon->suivant;
    f-> queue = nouveau_chainon;
    f->taille +=1;

  //}

  return f;
}

file* file_supt(file* const f)
{
  /* (Peut-être) À modifier ou compléter. */

  chainon* f1 = f->tete;

    if (f->tete == f->queue) {
        f->tete = NULL;
        f->queue = NULL;
    }
    else{
        f->tete = f->tete -> suivant; //Pass to the next element
        f->taille--;
        free(f1);
    }
    return f;

}

////////////////////////////////////////////////////////////////////////////////
// Destructeurs
////////////////////////////////////////////////////////////////////////////////

void file_detruit(file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  (void) f;
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs
////////////////////////////////////////////////////////////////////////////////

S file_tete(const file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  return f->tete->element;
}

bool file_estvide(const file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  return (f->taille == 0) ? true: false;
}

size_t file_taille(const file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  return f->taille;
}


////////////////////////////////////////////////////////////////////////////////
// Divers
////////////////////////////////////////////////////////////////////////////////

int file_affiche(FILE* const stream, const file* const f)
{
  /*
   * Pas besoin de modifier cette fonction.
   * Mais l'affichage sera étrange si certaines fonctions sont incorrectes ou
   * si la file n'a pas bien été construite (si les autres fonctions sont
   * fausses).
   */
  int total = 0, code = 0;

  for (const chainon* courant = f->tete; courant; courant = courant->suivant)
  {
    const S ieme = courant->element;
    code = fprintf(stream, "%"PRI_S" ", ieme);
    if (code >= 0)
      total += code;
    else
      return code;
  }
  code += fprintf(stream, "\n");
  return code >= 0 ? total + code : code;
}
