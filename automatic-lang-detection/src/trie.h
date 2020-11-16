/*
 * =====================================================================================
 *
 *       Filename:  trie.h
 *
 * =====================================================================================
 */

#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAILLE_ALPHABET 26

typedef struct TrieArbre {
	struct TrieArbre *fils[TAILLE_ALPHABET];
	/* Element de la structure indiquant si noeud est la fin du mots  */
	bool finNoeud;
	} TrieArbre;

TrieArbre *arbre_vide(void);
TrieArbre *insert(TrieArbre *racine, const char *cles);
bool search(TrieArbre *racine, const char *cles);

