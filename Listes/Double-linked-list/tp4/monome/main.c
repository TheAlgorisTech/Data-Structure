/*
 * 
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28/03/2020 20:29:28
 *       Revision:  nonggugg
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#define MALLOC(t)      ((t*)malloc(sizeof(t)))
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct monome
{
  /** \brief Degré du monome. */
  unsigned int degre;
  /** \brief Coefficient du monome. */
  int coefficient;
};
typedef struct monome monome;

struct liste
{
  /** \brief Terme. */
  monome terme; // monome type (degre,coeff)
  /** \brief Élément suivant dans la liste. */
  struct liste* suivant;
  /** \brief Élément précédent dans la liste. */
  struct liste* precedent;
};
typedef struct liste liste;


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


void display_list(liste* l){
   
    do {
        printf("Polynom Degree: %d, Coefficient: %d\n", l->terme.degre, l->terme.coefficient);
        l = l->suivant;
    } 
    while(l);
        
}

 
liste* insert_sort(liste* head_ref){
        /* Sort DLL using insertion sort techniques
       1.Create an empty sorted (or result) doubly link list
       2.Removing the last element from original DLL
       3.Inserting it at the correct position in the new linked list
       Change head of given linked list to head of sorted DLL
       4.Repeating set 3 till there are no elements in DLL
       */
      
      liste* sorted=liste_vide();
      
      liste* newNode = head_ref; 
      while (newNode != NULL){
          liste* next=newNode->suivant; //fetch next element
          newNode->precedent = NULL; //Detach it's next links
          newNode->suivant = NULL; //Detach It's previous links
          
          /* Insertion Sort Algorithm */
          liste* current; //Current Pointer

          //Sorted point into first element of the original list
          if (sorted == NULL) sorted = newNode;

          // If the node is to be inserted at the begining
          // of the doubly linked list
          else if (sorted->terme.degre >= newNode->terme.degre){
                newNode->suivant=sorted;
                newNode->suivant->precedent = newNode;
                sorted = newNode;
          }
          else{
              current = sorted;
              while (current->suivant != NULL &&  current->suivant->terme.degre < newNode->terme.degre) {
                
                  current = current->suivant; 
                  newNode->suivant = current->suivant; 
  
                   // if the new node is not inserted 
                   // at the end of the list 
                  if (current->suivant != NULL) newNode->suivant->precedent = newNode; 
                  current->suivant = newNode; 
                  newNode->precedent = current; 
                    } 
            /*  */
            newNode = next;
            } 
        head_ref=sorted;
        }

        return head_ref;
}


int liste_longueur(const liste* const l)
{
  /* (Peut-être) À compléter ou modifier. */
  // Longueur de la liste indexée à 0
  liste* temp=l->suivant;
  int j=0;
  do{
     temp=temp->suivant;
     j++;
  } while (temp->suivant!= NULL);
  return j;
}

liste* max_gree(liste* const l){ 
    liste* max =l;
    liste* temp=l; 
  
    // traverse the whole doubly linked list 
    while (temp != NULL) { 
  
        /* if temp's data is greater than 
           max's data, then put max = temp 
           and return max->data */
        if (temp->terme.degre > max->terme.degre) 
            max = temp; 
  
        temp = temp->suivant; 
    } 
    return max; 
}

liste* liste_normaliser(liste* const l){
 
  int size_liste = liste_longueur(l);
  liste* max = l;
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
     while( j < size_liste && curr->suivant != NULL){ 
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
  // Le degrer maximale si existant d'un polynom est au maximum sa taille
  return resultats;
}



int main(){
   //Each element of the list represent a pair of
   //coefficients & values
   //Stored in a double linked list  
   //To normalise a list we should sort list by degree 
   //and sum all coefficients for equal degree
   monome m1, m2, m3, m4, m11, m44, m22;
   m1.degre = 7;
   m1.coefficient = 2;
   m11.degre = 7;
   m11.coefficient = 4;
   m2.degre = 2;
   m2.coefficient = 4;
   m22.degre = 2;
   m22.coefficient = 4;
   m3.degre = 4;
   m3.coefficient = 6;
   m4.degre = 8;
   m4.coefficient = 10;
   m44.degre = 8;
   m44.coefficient = 7;
//   printf("Mono1: degre: %d, coeff: %d\n",m1.degre, m1.coefficient);     
//   printf("Mono2: degre: %d, coeff: %d\n",m2.degre, m2.coefficient);     
//   printf("Mono3: degre: %d, coeff: %d\n",m3.degre, m3.coefficient);     
//   printf("Mono4: degre: %d, coeff: %d\n",m4.degre, m4.coefficient);     

   // Create new list
   liste* l1 = liste_vide();

   l1=liste_inserer(l1, m1);
   l1=liste_inserer(l1, m2);
   l1=liste_inserer(l1, m3);
   l1=liste_inserer(l1, m4);
   l1=liste_inserer(l1, m11);
   l1=liste_inserer(l1, m44);
   l1=liste_inserer(l1, m22);

   printf("Before Sort\n");
   display_list(l1);
   
   printf("After Sort\n");
   //liste* l2 = insert_sort(l1);
   //display_list(l2);
//   liste* l2 = normaliser(l1);
//   display_list(l2);
   
   liste* l2 = liste_normaliser(l1);
   display_list(l2);
   printf("Nothing Displayed?");
   return 0;
}


