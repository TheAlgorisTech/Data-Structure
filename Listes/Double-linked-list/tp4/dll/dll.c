#include <stdio.h> 
#include <stdlib.h> 
  
#define MALLOC(t)      ((t*)malloc(sizeof(t)))
#define FREE(t) free(t)
/* a node of the doubly linked list */
struct Node { 
    int data; 
    struct Node* next; 
    struct Node* prev; 
}; 

typedef struct Node Node;


Node* liste_nouvelle(){
    Node *l = MALLOC(Node);
    return l;
}

Node* liste_inserer(Node* const l, const int t)
{
  Node* const nouveau = MALLOC(Node);
  nouveau->data = t;

  if (l==NULL){
      nouveau->next = nouveau; //point sur lui même
      nouveau->prev = nouveau;
  }
  else{
      //Le suivant de nouvelle liste point verre tête de l
      //et sont précédent est NULL
      nouveau->next=l;
      //Changer le precedent de l
      l->prev=nouveau; 
  }
  return nouveau;
}
/*
 brief Supprimer le maillon pointé.
 param[in,out] l Une liste
 return La maillon suivant s'il y en a un sinon le maillon précédent.
*/

Node* liste_supprimer(Node* l)
{
  /* Pour supprimer la tête il faut que le suivant existe */
    if (l==NULL){
        return NULL;
    }
    // Create A pointer that point at the same list;
    // Manipulate the pointer as work arround for const value
    Node* temp = l;
    temp = temp->next;
    temp->prev = NULL;

  return temp;
}
		
/**
 * \brief Échanger un monôme avec le monôme suivant.
 * \param[in,out] l une liste (position courante)
 * \return La liste
 *
 * \pre \code !liste_est_vide(l) && !liste_est_vide(liste_suivant(l)) \endcode
 * \memberof liste
**/

Node* liste_echanger(Node* const l)
{
  /* C'est similaire à l'insertion de la tête entre le deuxieme et le troisieme element. */
    if (l==NULL && l->next==NULL) return NULL;
    Node* temp =l;
    Node* temp1 = l->next;

    if (temp1->next != NULL){ //so there is more than three element; Swapping
              
        temp->next= temp1->next;
        temp1->next->prev =temp;
        temp1->next = temp;

    }
    else{
        temp1=l;
    }

    return temp1;
    
}  


void liste_free(Node* const l){
    //free a list
    //Check if list is null
    
    Node* tmp=l; //To save temporary head

    while (tmp){
        Node* tmp2 =tmp;
        tmp = tmp2->next;
        free(tmp2);
    }
    free(l);
}





/**
 * \brief Déterminer si une liste est vide.
 * \param[in] l Liste à éxaminer.
 * \return Un booléen qui indique si la liste est vide.
 * \retval true Si la liste est vide,
 * \retval false sinon.
 *
 * \memberof liste
 * \ingroup liste_selecteurs
 */
int liste_est_vide(const Node* l){
    return (l->next == NULL && l->prev == NULL) ? 1:0;
}



/**
 * \brief Déterminer si un maillon est le début de sa liste.
 * \param[in] l Liste à éxaminer.
 * \return Un booléen qui indique si le maillon est le début de sa liste.
 * \retval true Si le maillon est le début de sa liste.
 * \retval false sinon.
 *
 * \memberof liste
 * \ingroup liste_selecteurs
 */
int liste_est_debut(const Node* l){
    return (l->prev == NULL) ? 1 : 0;
}


/**
 * \brief Obtenir le maillon suivant dans la liste.
 * \param[in] l Une liste
 * \return Maillon suivant dans la liste.
 *
 * \pre !liste_est_vide(l)
 *
 * \memberof liste
 * \ingroup liste_selecteurs
 */

Node* liste_suivant(const Node* const l)
{
  // S'il n'y a pas un suivant output la même liste
  // constant pointer ver list l
  //const Node * temp=l->next;
  return l->next;
}

/** \memberof liste
 * \brief Obtenir le ième maillon de la liste chaînée.
 * \param[in] l Liste à éxaminer.
 * \param[in] i Position du maillon.
 * \return ième maillon de la liste chaînée.
 *
 * \pre 0 <= i < liste_longueur(l)
 * \note liste_debut(l) == liste_ieme(l, 0)
 *
 * \memberof liste
 * \ingroup liste_selecteurs
 */
Node* liste_ieme(const Node* l, int i){
    Node* temp= l;
    int j=0;
    while(j!=i && temp->next != l){
        j++;
        temp=temp->next;
    }
    return temp;
}

/**
 * \brief Déterminer la longueur d'une liste.
 * \param[in] l La liste à éxaminer.
 * \return Longueur de la liste.
 *
 * \memberof liste
 * \ingroup liste_selecteurs
 */
int liste_longueur(const Node* l){
    Node* temp=l->next;
    int j=0;
    do{
        temp=temp->next;
        j++;
    } while (temp->next!= NULL);
    return j;
}

int main(){
    Node *l = NULL;
    Node *l1 = liste_nouvelle();


    printf("Address of null list, %p\n",l);
    printf("Address of new list, %p\n", l1);

    l1 = liste_inserer(l1,5);
    printf("Insert First New Element %d\n", l1->data);
    
    l1 = liste_inserer(l1,9);
    printf("Insert Second New Element %d\n", l1->data);
    l1 = liste_inserer(l1,8);
    printf("Insert Second New Element %d\n", l1->data);
    l1 = liste_inserer(l1,8);
    l1 = liste_inserer(l1,10);
    l1 = liste_inserer(l1,11);
    l1 = liste_inserer(l1,12);

    printf("Longeur liste %d\n", liste_longueur(l1)); 

    printf("Idx %d, Element %d\n",2, liste_ieme(l1,2)->data); 
    printf("Idx %d, Element %d\n",3, liste_ieme(l1,3)->data); 

    printf("Before Swap Head: %d, Next: %d\n", l1->data, l1->next->data);
    l1 = liste_echanger(l1);
    printf("Before Swap Head: %d, Next: %d\n", l1->data, l1->next->data);

    printf("List Head %d\n", l1->data);
    l1 = liste_supprimer(l1);
    printf("List Head after deletion, %d\n", l1->data);

    //liste_free(l1);

    //printf("List after free, %p \n", &l1);
    printf("%d", liste_suivant(l1)->data); 


    //Create new list
    Node *l2 = liste_nouvelle(); 
    printf("%d", liste_est_vide(l2));
    return 0;

}

