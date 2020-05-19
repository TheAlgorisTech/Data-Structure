# Double Linked List


# Normalization
La normalization est implementer d'une maniére non optimiser pour résoudre le probléme,
il fallait itérer en premier sur la liste double chaîner pour identifier le degrée
maximale. Aprés avoire identifier le degrées maximale, il faut itérer sur la liste
pour identifier les maillons ayants les degrées identiques la sommes des coefficient
sera inserer dans une nouvelle liste associée a sont degrée, le maillon ayant 
coefficient null sera exclus. C'est une méthode brute force qui n'est pas
optimise parce qu'ont traverse la liste plusieurs fois.




# Advantages
    - Can be traversed in both forward & backward direction 
    - Delete operation in DLL is more efficient if pointer to the node to be deleted is given
    - Insert new node befor a given node

# Disadvantages
    - Every node in DLL require extra space for an previous pointer
    - All operations require an extra pointer *previous* to be maintained

```C
//Doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}
```

```C
//Create empty double linked list
#define MALLOC(t)      ((t*)malloc(sizeof(t)))
Node* liste_vide(void){
    Node* l = MALLOC(Node);
    return l;
}

```
