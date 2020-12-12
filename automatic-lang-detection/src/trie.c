/*
 * =====================================================================================
 *
 *       Filename:  trie.c
 *
 *    Description:  Implémentation de la structure Trie :
 *    		    vous devez proposer une implémentation complète de la structure
 *    		    d’arbre Trie contenant les fonctions d’initialisation,
 *    		    d’insertion d’un élément dans l’arbre, et de recherche d’un mot
 *
 *         Author:  Algoristech
 *   Organization:  
 *
 * =====================================================================================
 */

#include "trie.h"



TrieArbre *arbre_vide(void)
{
	/*
	 * Créer une trie vide
	 *
	 */

	// if os unable to give more memory, NULL pointer is returned
	TrieArbre *trie=(TrieArbre *) malloc(sizeof(TrieArbre)); 

	if (trie)
	{
	   // Initialiser l'arbre préfixe
			trie->finNoeud = false;
			for (int i=0; i<TAILLE_ALPHABET;i++) trie->fils[i] = NULL;
	}

	return trie;
}


TrieArbre *insert(TrieArbre *racine, const char *cles)
{
	/*
	 * Inserer un clés dans une Trie, chaque caractère du clés est insérer individuellement dans une Trie noeud
	 * le fils c'est une liste de pointeur pour le noeud trie suivant, le caractère du clés jouent le role d'un index vers la list fils, 
	 * if the input key is new or an extension of the existing key, we need to construct non-existing nodes of the key,
	 * and mark end of the word for the last node. If the input key is a prefix of the existing key in Trie, 
	 * we simply mark the last node of the key as the end of a word.
	 */

	int taille = strlen(cles); // key length determines trie depth


	TrieArbre *tcrawl=racine;

	/* Remove all char from given string that aren't a-z parse_work(char *word) */


	for (int level=0; level < taille; level++)
	{
		/*Change ASCCI char (a-z) to array index */
		int index = (int) ascii_to_index(cles[level]); 
		/* 
		 * if trie child pointer at this index is NULL, assigned it to new trienode
		 *
		 * */
    if (!tcrawl->fils[index]) tcrawl->fils[index] = arbre_vide();

		/* move pointer from previous node to the new trienode children */
		tcrawl = tcrawl->fils[index]; 
  } 
   	// mark last node as leaf 
   	tcrawl->finNoeud = true; 
} 

// Returns true if key presents in trie, else false 
bool search(TrieArbre *racine, const char *cles) 
{ 
    int length = strlen(cles); 
    int index; 
    TrieArbre *pCrawl = racine; 
  
    for (int level = 0; level < length; level++) 
    { 
        index = (int) ascii_to_index(cles[level]); 
  
        if (!pCrawl->fils[index]) 
            return false; 
  
        pCrawl = pCrawl->fils[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->finNoeud); 
} 




int main(){

	TrieArbre *tree = arbre_vide();
	insert(tree, "faysal");

	bool exist = search(tree,"faysal");

	if (exist) printf("found value in tree");

	

	return EXIT_SUCCESS;

}


