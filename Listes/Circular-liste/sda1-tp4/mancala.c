#include "mancala.h"

#include <inttypes.h>
#include <stdlib.h>

#include "attributes.h"

////////////////////////////////////////////////////////////////////////////////
// Struct
////////////////////////////////////////////////////////////////////////////////

struct mancala {
  liste* plateau;
  unsigned int joueur;
  size_t selection;
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions locales (déclarations)
////////////////////////////////////////////////////////////////////////////////

sda1_attribute((unused)) static inline size_t
    mancala_grenier(const mancala* m, unsigned joueur);

sda1_attribute((unused)) static inline size_t
    mancala_premier_champ(const mancala* m, unsigned joueur);

sda1_attribute((unused)) static inline size_t
    mancala_dernier_champ(const mancala* m, unsigned joueur);

sda1_attribute(
    (unused,
     warn_unused_result)) static inline mancala* mancala_changer_tour(mancala*
                                                                          m);

sda1_attribute((unused)) static inline unsigned mancala_score_joueur(
    const mancala* m, unsigned joueur);

////////////////////////////////////////////////////////////////////////////////
// Constructeurs
////////////////////////////////////////////////////////////////////////////////

mancala* mancala_init(const size_t champs, const unsigned int graines) {
  mancala* const m = malloc(sizeof *m);

  /* (Peut-être) À modifier ou compléter. */

  return m;
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs
////////////////////////////////////////////////////////////////////////////////

mancala* mancala_egrainer(mancala* const m, const size_t i) {
  /* (Peut-être) À modifier ou compléter. */
  return m;
}

mancala* mancala_bruler(mancala* const m, const size_t i) {
  /* (Peut-être) À modifier ou compléter. */
  return m;
}

mancala* mancala_selection_gauche(mancala* const m) {
  /* (Peut-être) À modifier ou compléter. */
  return m;
}

mancala* mancala_selection_droite(mancala* const m) {
  /* (Peut-être) À modifier ou compléter. */
  return m;
}

void mancala_free(mancala* const m) {
  /* (Peut-être) À modifier ou compléter. */
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs
////////////////////////////////////////////////////////////////////////////////

bool mancala_partie_finie(const mancala* const m) {
  /* (Peut-être) À modifier ou compléter. */
  return false;
}

unsigned int mancala_score_joueur_1(const mancala* const m) {
  /* (Peut-être) À modifier ou compléter. */
  return 0;
}

unsigned int mancala_score_joueur_2(const mancala* const m) {
  /* (Peut-être) À modifier ou compléter. */
  return 0;
}

const liste* mancala_plateau(const mancala* const m) {
  return m->plateau;
}

unsigned int mancala_joueur(const mancala* const m) {
  return m->joueur;
}

bool mancala_coup_valide(const mancala* const m, const size_t i) {
  return false;
}

size_t mancala_selection(const mancala* const m) {
  /* (Peut-être) À modifier ou compléter. */
  return m->selection;
}

bool mancala_peut_bruler(const mancala* const m) {
  /* (Peut-être) À modifier ou compléter. */
  return false;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions locales (définitions)
////////////////////////////////////////////////////////////////////////////////

size_t mancala_grenier(const mancala* m, const unsigned int joueur) {
  const liste* const plateau = mancala_plateau(m);
  const size_t longueur = liste_longueur(plateau);
  return joueur == 0 ? (longueur / 2) : 0;
}

size_t mancala_premier_champ(const mancala* m, const unsigned int joueur) {
  const liste* const plateau = mancala_plateau(m);
  const size_t longueur = liste_longueur(plateau);
  return joueur == 0 ? 1 : ((longueur / 2) + 1);
}

size_t mancala_dernier_champ(const mancala* m, const unsigned int joueur) {
  const liste* const plateau = mancala_plateau(m);
  const size_t longueur = liste_longueur(plateau);
  return joueur == 0 ? ((longueur / 2) - 1) : (longueur - 1);
}

mancala* mancala_changer_tour(mancala* const m) {
  const liste* const plateau = mancala_plateau(m);
  const size_t longueur = liste_longueur(plateau);
  m->joueur = m->joueur ? 0 : 1;
  m->selection = m->joueur ? (longueur - 1) : 1;
  return m;
}

unsigned int mancala_score_joueur(
    const mancala* const m, const unsigned int joueur) {
  /* (Peut-être) À modifier ou compléter. */
  return 0;
}
