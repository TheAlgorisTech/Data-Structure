/**
 * \file files_ch.c
 * \brief Source pour les files chaînées.
 */

#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "util.h"

////////////////////////////////////////////////////////////////////////////////
// struct
////////////////////////////////////////////////////////////////////////////////

struct file
{
  S element;
  struct file* suivant;
};

////////////////////////////////////////////////////////////////////////////////
// Constructeurs
////////////////////////////////////////////////////////////////////////////////

file* file_nouv(void)
{
  /* (Peut-être) À modifier ou compléter. */
  return NULL;
}


// file* file_adjq(file* const f, const S x)
// {
//   file* const nouveau_chainon = malloc(sizeof *nouveau_chainon);
//   if (!nouveau_chainon)
//     ERREUR("malloc");

//   /* (Peut-être) À modifier ou compléter. */
//   return f;
// }

file* file_supt(file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  file * f1 = f;
  free(f->suivant);
  return f1;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeurs
////////////////////////////////////////////////////////////////////////////////

void file_detruit(file* const f)
{
  /* (Peut-être) À modifier ou compléter. */

  free(f);
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs
////////////////////////////////////////////////////////////////////////////////

S file_tete(const file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  return f->element;
}

bool file_estvide(const file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  return (f==NULL);
}

size_t file_taille(const file* const f)
{
  /* (Peut-être) À modifier ou compléter. */
  if (file_estvide(f)) return 0;
  else return 1+(file_taille(f->suivant));

}

// S file_ieme(const file* const f, const size_t ieme)
// {
//    (Peut-être) À modifier ou compléter.
//   return 0;
// }

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

  for (const file* courant = f; courant; courant = courant->suivant)
  {
    const S ieme = file_tete(courant);
    code = fprintf(stream, "%"PRI_S" ", ieme);
    if (code >= 0)
      total += code;
    else
      return code;
  }
  code += fprintf(stream, "\n");
  return code >= 0 ? total + code : code;
}
