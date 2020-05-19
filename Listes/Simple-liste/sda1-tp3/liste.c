/**
 * \file liste.c
 * \brief Listes doublement chaînées de monomes
 */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sysexits.h>

#include "monome.h"
#include "liste.h"

#define MALLOC(t)      ((t*)malloc(sizeof(t)))
/**
 * \brief Liste
 */
struct liste
{
  /** \brief Terme. */
  monome terme; // monome type (degre,coeff)
  /** \brief Élément suivant dans la liste. */
  struct liste* suivant;
  /** \brief Élément précédent dans la liste. */
  struct liste* precedent;
};

////////////////////////////////////////////////////////////////////////////////
// Constructeurs
////////////////////////////////////////////////////////////////////////////////

liste* liste_vide(void)
{
  /* Forme 2: par mutation avec forme fonctionelle  */
    liste *l=MALLOC(liste); //Allocation memoire nouvelle liste
    l->precedent = NULL;
    l->suivant=NULL;
    return l; //list pointer
}

liste* liste_inserer(liste* const l, const monome t)
{
  liste* const nouveau = MALLOC(liste);
  nouveau->terme = t;

  if (l==NULL){
      nouveau->precedent = nouveau; //point sur lui même
      nouveau->suivant = nouveau;
  }
  else{
      //Le suivant de nouvelle liste point verre tête de l
      //et sont précédent est NULL
      nouveau->suivant=l;
      //Changer le precedent de l
      l->precedent=nouveau; 
  } 
  return nouveau;
}



liste* liste_supprimer(liste* const l)
{
  /* Pour supprimer la tête il faut que le suivant existe */
    if (l==NULL){
        return NULL;
    }
    // Create A pointer that point at the same list;
    // Manipulate the pointer as work arround for const value
    liste* temp = l;
    temp = temp->suivant;
    temp->precedent = NULL;
  return temp;
}

liste* liste_echanger(liste* const l)
{
    if (l==NULL && l->suivant==NULL) return NULL;
    liste* temp =l;//point vers la tête
    liste* temp1 = l->suivant; //point vers le deuxiéme element

    if (temp1->suivant != NULL){ //so there is more than three element; Swapping
              
        temp->suivant= temp1->suivant;
        temp1->suivant->precedent =temp;
        temp1->suivant = temp;

    return temp1;
    
    }
}

liste* liste_normaliser(liste* const l){
  size_t size_liste = liste_longueur(l);
  liste* max = l; // Stocker degrée maximal
  liste* temp = l;

  //traverser la liste double chaîneé 
  //pour trouver la degrée maximale 
  
  while (temp != NULL){
     if (temp->terme.degre > max->terme.degre) max = temp; 
     temp = temp->suivant; 
    } 
      
  liste* resultats=liste_vide();
  int i = 0;

  // Maximum degree
  while (i <= max->terme.degre){ 
      liste* curr=l;
      monome m1;
      m1.degre = i;
      m1.coefficient=0;
     int j =0; 
     
     //#printf("%d\n", m1.degre);
     while( j <= size_liste && curr != NULL){ 

         if (curr->terme.degre ==m1.degre) m1.coefficient += curr->terme.coefficient;
         curr = curr->suivant;
         j++;
     }
     if (m1.coefficient != 0) resultats = liste_inserer(resultats, m1);
      // Fetch All Maillon with the same coefficient
      // Add Coefficient
      // Inserter monome in the result list
      // Pass To Next Degree
      i++; 
  } 
  
  return resultats;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeurs
////////////////////////////////////////////////////////////////////////////////

void liste_free(liste* l){

   liste* tmp=l; //To save temporary head

    while (tmp){
        liste* tmp2 =tmp;
        tmp = tmp2->suivant;
        free(tmp2);
    }
    free(l);
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs
////////////////////////////////////////////////////////////////////////////////

monome liste_monome(const liste* const l)
{
  /* (Peut-être) À compléter ou modifier. */
  return l->terme;
}

liste* liste_suivant(const liste* const l)
{
  // S'il n'y a pas un suivant output la même liste
  liste* temp = l->suivant;
  return (temp==NULL) ? NULL : temp;
}

liste* liste_precedent(const liste* const l)
{
  // S'il n'y a pas un précedent output la même liste  
  liste* temp = l->precedent;
  return (temp==NULL) ? NULL: temp;
}

bool liste_est_vide(const liste* const l)
{
  /* (Peut-être) À compléter ou modifier. */
  return (l->suivant == NULL && l->precedent == NULL) ? true:false;
}

bool liste_est_debut(const liste* const l)
{
  /* Les maillons interne sont inter-connetée
   * pourcela le pointeur precedent d'un maillon
   * doit être null au début de la liste
   * */
  return (l->precedent == NULL) ? true : false;
}

liste* liste_debut(const liste* const l)
{
  if (!l)
    return 0;

  const liste* courant = l;
  while (courant->precedent)
    courant = courant->precedent;

  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wcast-qual"
  return (liste*) courant;
  #pragma GCC diagnostic pop
}

liste* liste_ieme(const liste* const l, const size_t ieme)
{
  liste* courant = liste_debut(l);

  /* (Peut-être) À compléter ou modifier. */
  size_t j=0;
  while(j!=ieme && courant->suivant != l){
        j++;
        courant=courant->suivant;
  }

  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wcast-qual"
  return (liste*) courant;
  #pragma GCC diagnostic pop
}

size_t liste_longueur(const liste* const l)
{
  /* (Peut-être) À compléter ou modifier. */
  // Longueur de la liste indexée à 0
  liste* temp=l->suivant;
  size_t j=0;
  do{
     temp=temp->suivant;
     j++;
  } while (temp->suivant!= NULL);
  return j;
}

////////////////////////////////////////////////////////////////////////////////
// Divers
////////////////////////////////////////////////////////////////////////////////

static inline void entree_incorrecte(
    const char* message, const char* ligne, const char* chaine_erronee,
    const size_t shifted)
{
  const bool couleurs = isatty(fileno(stderr));

  char buffers[3][2048] = { { 0 }, { 0 }, { 0 } };
  sscanf(ligne, "%2047[^\n]", buffers[0]);
  snprintf(buffers[1], shifted + 1, "%s", buffers[0]);
  sscanf(chaine_erronee, "%2047[^\n]", buffers[2]);
  const size_t size = strlen(buffers[2]);

  if (couleurs)
    fprintf(stderr, "\033[7m Avertissement \033[0m ");
  else
    fprintf(stderr, "[Avertissement] ");

  fprintf(stderr, "%s :\n", message ? message : "Entrée incorrecte");
  if (couleurs)
    fprintf(stderr, "%s\033[1m\033[33m%s\033[0m\n", buffers[1], buffers[2]);
  else
    fprintf(stderr, "%s%s\n", buffers[1], buffers[2]);
  for (size_t i = 0; i < shifted; ++i)
    fprintf(stderr, " ");
  if (size)
  {
    if (couleurs)
      fprintf(stderr, "\033[1m\033[33m^");
    else
      fprintf(stderr, "^");
    for (size_t i = 0; i < (size - 1); ++i)
      fprintf(stderr, "~");
  }
  if (couleurs)
    fprintf(stderr, "\033[0m\n");
  else
    fprintf(stderr, "\n");
}

liste* liste_sread(const char* const input)
{
  int read = 0;
  size_t shifted = 0;
  const char* remainder = input;

  liste* l = liste_vide();
  while (true)
  {
    for ( ; *remainder == ' ' || *remainder == '\t' || *remainder == '+'; ++remainder)
      ++shifted;
    if (*remainder == '\n' || *remainder == '\0')
      break;

    monome m = { .degre = 0, .coefficient = .0, };
    int scanned = sscanf(
        remainder,
        MONOME_COEFFICIENT_SCN"*%*[a-zA-Z]^"MONOME_DEGRE_SCN"%n",
        &m.coefficient, &m.degre, &read);
    if (scanned == 2)
    {
      l = liste_inserer(l, m);
      remainder += read;
      shifted += (size_t) read;
    }
    else if (scanned == 1)
    {
      entree_incorrecte("Degré non reconnu", input, remainder, shifted);
      break;
    }
    else
    {
      entree_incorrecte("Coefficient non reconnu", input, remainder, shifted);
      break;
    }
  }

  return l;
}

liste* liste_fread(FILE* const stream)
{
  char buffer[8192] = { 0 };

  liste* l = NULL;
  if (fgets(buffer, 8191, stream))
    l = liste_sread(buffer);
  else
    l = liste_vide();

  return l;
}

void liste_fwrite(FILE* const stream, const liste* const l)
{
  if (liste_est_vide(l))
  {
    monome_fprint(stream, (monome) { .coefficient = 0, .degre = 0, });
    fprintf(stream, "\n");
  }
  else
  {
    const liste* parcours = l;
    while (!liste_est_vide(liste_suivant(parcours)))
    {
      const monome m = liste_monome(parcours);
      monome_fprint(stream, m);
      fprintf(stream, " + ");
      parcours = liste_suivant(parcours);
    }
    const monome m = liste_monome(parcours);
    monome_fprint(stream, m);
    fprintf(stream, "\n");
  }
}
