#include "pile_char.h"


#include "base.h"
int main()
{
Pile p1 = remplacer(depiler(empiler(empiler(empiler(pilenouv(),'B'),'C'),'P')),'D');


printf ("la sommet est = %c\n", sommet (p1));
printf("l'hauteur est=%d\n", hauteur(p1));



}
