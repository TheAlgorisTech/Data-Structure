#ifndef _FILE_H_
#define _FILE_H_

/**
 * \file files_fct.h
 * \brief Header pour les files fonctionnelles.
 */
 
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "sorte.h"

/**
 * \defgroup file_module File
 * \copydetails file
 */

/**
 * \brief Taille max d'une file
 * \ingroup file_module
 */
#ifndef TAILLE_MAX
  #define TAILLE_MAX 100
#endif

/**
 * \brief files fonctionnelles
 * 
 * # Introduction
 * 
 * ::file représente des files de type FIFO. Les élements dans une ::file sont
 * de type ::S et la taille de la ::file est bornée par #TAILLE_MAX.
 *
 * # Constructeurs
 * \see \ref file_constructeurs
 *
 * \copydetails file_constructeurs
 *
 * # Destructeurs
 * \see \ref file_destructeurs
 *
 * \copydetails file_destructeurs
 *
 * # Sélecteurs
 * \see \ref file_selecteurs
 *
 * \copydetails file_selecteurs
 *
 * # Divers
 * \see \ref file_divers
 *
 * \copydetails file_divers
 *
 * # Exemple
 *
 * \code
 * file f = file_nouv();
 * f = file_adjq(f, S_C(0));
 * f = file_adjq(f, S_C(1));
 * f = file_adjq(f, S_C(2));
 * f = file_affiche(f);
 * file_detruit(f);
 * \endcode
 *
 * \ingroup file_module
 */
struct file
{
  /** \brief Tableau d'éléments de type S. */
  S elements[TAILLE_MAX];
  /** \brief Position du premier élément dans le tableau file::x. */
  size_t debut;
  /** \brief Nombre d'éléments dans la file. */
  size_t taille;
};
typedef struct file file;

////////////////////////////////////////////////////////////////////////////////
// Constructeurs
////////////////////////////////////////////////////////////////////////////////

/**
 * \defgroup file_constructeurs Constructeurs
 * \brief Constructeurs pour file.
 *
 * La création d'une nouvelle file se fait à l'aide de la fonction file_nouv().
 * Un élément peut être ajouté en fin de file en utilisant file_adjq() tandis
 * que file_supt() supprime l'élément en tête de file.
 *
 * \ingroup file_module
 */

/**
 * \brief Construire une ::file vide.
 * \return Une nouvelle ::file vide.
 *
 * \post \code file_taille(f) == 0 \endcode
 * \post \code file_estvide(f) == true \endcode
 * \see file_detruit
 *
 * \memberof file
 * \ingroup file_constructeurs
 */
file file_nouv(void);

/**
 * \brief Ajouter un élément au queue de ::file. 
 * \param[in,out] f File à ajouter un élément.
 * \param[in]     x S.
 * \return Une nouvelle ::file.
 *
 * \pre \code file_taille(f) < file_taille_max(f) \endcode.
 * \post \code f.elements[f.taille] = x \endcode. 
 *
 * \memberof file
 * \ingroup file_constructeurs
 */
file file_adjq(file f, S x);

/**
 * \brief Supprimer l’élément de tête de ::file.
 * \param[in,out] f ::file à modifier.
 * \return f ::file où le premier élément est supprimer.
 *
 * \pre f ::file non vide. 
 *
 * \memberof file
 * \ingroup file_constructeurs
 */
file file_supt(file f);

////////////////////////////////////////////////////////////////////////////////
// Destructeurs
////////////////////////////////////////////////////////////////////////////////

/**
 * \defgroup file_destructeurs Destructeurs
 * \brief Destructeurs pour ::file.
 *
 * Une ::file peut être détruite avec file_detruit().
 *
 * \ingroup file_module
 */

/**
 * \brief Détruire la ::file f.
 * \param[in] f ::file à détruire.
 * \see file_nouv
 *
 * \memberof file
 * \ingroup file_destructeurs Destructeurs
 */
void file_detruit(file f);

////////////////////////////////////////////////////////////////////////////////
// Selecteurs
////////////////////////////////////////////////////////////////////////////////

/**
 * \defgroup file_selecteurs Sélecteurs
 * \brief Sélecteurs pour ::file.
 *
 * file_estvide() permet de vérifier si une ::file est vide tandis que
 * file_taille() retourne la taille d'une ::file. L'élément en tête de ::file
 * peut être obtenu avec la fonction file_tete() et le i-ième élément d'une
 * ::file peut être récupéré avec file_ieme().
 *
 * \ingroup file_module
 */

/**
 * \brief Sélecteur du tête d'un ::file  
 * \param[in] f ::file à selectionner la tête 
 * \return  x S valeur de tête
 *
 * \pre ::file non vide.
 *
 * \memberof file
 * \ingroup file_selecteurs
 */
S file_tete(file f);

/**
 * \brief Tester si une ::file est vide.
 * \param[in] f ::file à inspecter.
 * \return Un booléen indiquant si la ::file est vide.
 * \retval true  si la ::file \a f est vide.
 * \retval false si la ::file \a f n'est pas vide.
 *
 * \memberof file
 * \ingroup file_selecteurs
 */
bool file_estvide(file f);

/**
 * \brief taille f ::file
 * \param[in] f ::file
 * \return Un entier indiquant la taille de la ::file. 
 *
 * \memberof file
 * \ingroup file_selecteurs
 */
size_t file_taille(file f);

/**
 * \brief élément de la ::file à la iéme position 
 * \param[in] f File 
 * \param[in] i size_t 
 * \return une valeur de type \c ::S.
 *
 * \pre ::file non vide. 
 * \pre position i supérieur ou égale au f.debut.
 * \pre position i inférieur ou égale au f.taille - 1.
 *
 * \memberof file
 * \ingroup file_selecteurs
 */
S file_ieme(file f, size_t i);

////////////////////////////////////////////////////////////////////////////////
// Divers
////////////////////////////////////////////////////////////////////////////////

/**
 * \defgroup file_divers Divers
 * \brief Fonctions diverses pour ::file.
 *
 * Une ::file peut-être affichée à l'aide de la fonction file_affiche().
 *
 * \ingroup file_module
 */

/**
 * Affichage du contenu d'une ::file dans le fichier passé en paramètre
 * \param[in] stream Fichier de sortie.
 * \param[in] f      File à afficher.
 * \return Nombre de caractères écrits dans \a stream.
 *
 * \memberof file
 * \ingroup file_divers
 */
int file_affiche(FILE* stream, file f);

#endif
