/**
 * \file files_mut.c
 * \brief Source pour les files par mutation.
 */

#include "files_mut.h"

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

////////////////////////////////////////////////////////////////////////////////
// struct
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief File
 *
 * La struct pour le type opaque ::file.
 *
 */
struct file
{
  /** \brief Tableau d'éléments de type ::S et de taille #TAILLE_MAX. */
  S elements[TAILLE_MAX];
  /** \brief Position du premier élément dans le tableau file::x. */
  size_t debut;
  /** \brief Nombre d'éléments dans la file. */
  size_t taille;
};

////////////////////////////////////////////////////////////////////////////////
// Constructeurs
////////////////////////////////////////////////////////////////////////////////

file* file_nouv(void)
{
  /* (Peut-être) À modifier ou compléter. */
  file *f = MALLOC(file);
  f->debut =0;
  f->taille =0;
  return f;
}

file* file_adjq(file* const f, S x)
{
  /* (Peut-être) À modifier ou compléter. */
  f->elements[f->taille] = x;
  f->taille +=1;
  return f;
}

file* file_supt(file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  f->debut +=1;
  f->taille--;
  return f;

}

////////////////////////////////////////////////////////////////////////////////
// Destructeurs
////////////////////////////////////////////////////////////////////////////////

void file_detruit(file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  free(f);
  return ;
}


////////////////////////////////////////////////////////////////////////////////
// Selecteurs
////////////////////////////////////////////////////////////////////////////////

S file_tete(const file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  return f->elements[f->debut];
}

bool file_estvide(const file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  return f->taille==0;
}

size_t file_taille(const file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  return f->taille;
}

S file_ieme(const file* const f, size_t i)
{
  /* (Peut-être) À modifier ou compléter. */
  return f->elements[i];
}

////////////////////////////////////////////////////////////////////////////////
// Divers
////////////////////////////////////////////////////////////////////////////////

int file_affiche(FILE* const stream, const file* const f)
{
  /*
   * Pas besoin de modifier cette fonction.
   * Mais l'affichage sera étrange si file_ieme() ou file_taille() sont
   * incorrectes ou si la file n'a pas bien été construite (si les autres
   * fonctions sont fausses).
   */
  int total = 0, code = 0;

  for (size_t i = 0; i < file_taille(f); ++i)
  {
    const S ieme = file_ieme(f, i);
    code = fprintf(stream, "%"PRI_S" ", ieme);
    if (code >= 0)
      total += code;
    else
      return code;
  }
  code += fprintf(stream, "\n");
  return code >= 0 ? total + code : code;
}
