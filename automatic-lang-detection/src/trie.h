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



/// @brief Create a trie.
/// @return On success allocated empty TrieArbre is returned.

TrieArbre *arbre_vide(void);


/// @brief Insert key in the Trie.
/// @param ArbreTrie. The initial Trie.
/// @param cles The key to be inserted in the Trie.
/// @return On success return AbreTrie with additional key.
///
/// Note that the key or the Trie  must not be empty, and
TrieArbre *insert(TrieArbre *racine, const char *cles);

/// @brief Check if a key belong to the Trie.
/// @param ArbreTrie. The initial Trie.
/// @param cles The key to be checked it's existence in the Trie.
/// @return On success true is returned.
bool search(TrieArbre *racine, const char *cles);

