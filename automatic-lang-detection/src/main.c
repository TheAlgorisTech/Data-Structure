#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "trie.h"


#define MAX_LANGUAGE 3
#define PHRASE_MAX 100
/*
 * Copy this function template to construct either a DAWG or a trie 
 * based on the dictionary filename given
 * 
 * Don't forget to change the void return type of this function 
 */
TrieArbre *constructTrie(char *dict) {
    // Instantiate either a Trie or a DAWG here
    // ...
		
		TrieArbre *arbre = arbre_vide();


    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *fp;
    
    // open file 
    fp = fopen(dict, "r"); // read mode
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    // read file
    while ((read = getline(&line, &len, fp)) != -1) {
        // remove newline
        size_t length = strlen(line);
        if((length > 0) && (line[length-1] == '\n'))
        {
            line[length-1] ='\0';
        }
        
        // here insert the word in the trie or in the DAWG
        // To complete ... 
				arbre = insert(arbre, line);
    }

    fclose(fp);
    free(line);

		return arbre;
}




int max_index(int *array)
{
    int max = array[0];
    int location = 0;
    for(int idx=1; idx < MAX_LANGUAGE; idx ++)
    {
        if (array[idx] > max)
        {
            max = array[idx];
            location = idx; 
        }
    }
    return location;

}



char *language(int *array)
{
    int lg_idx = max_index(array);

    switch(lg_idx)
    {
        case 0:
            return "French";
        case 1:
            return "German";
        case 2:
            return "English";
        case 3:
            return "Unknown";
        default:
            perror("Empty words belongs to all languages");
            exit(EXIT_FAILURE);
    }
}


int main() {

    TrieArbre *french, *german, *english;
    french = constructTrie("../dict/french-wordlist.txt");
    german = constructTrie("../dict/german-wordlist.txt");
    english = constructTrie("../dict/english-wordlist.txt");

    while (1)
    {
		    printf("Choose language detection by typing technique number\n");
		    printf("Menu:\n1.Trie detection\n2. Dawg detection\n");
	      printf("Type -1 to exit\n");
		    int choice;
        
		    scanf("%d", &choice);
		
        char phrase[PHRASE_MAX];
		    if (choice == 1)
		    {
            printf("Enter full phrase: ");
            // flush new line 
            fgetc(stdin);
            scanf("%[^\n]s",phrase);

            if (strlen(phrase) == 0){
                perror("Empty words belong to all language");
                exit(EXIT_FAILURE);
            }



            char *token;
            token = strtok(phrase, " ");
            int counts[4];
            int total=0;
            while(token != NULL)
            {
                printf("%s\n", token);
                total += 1;
                // Decouper la phrase avec dans des mots
                // Iterer sur chaque mots de la phrase et verifier à quelle langue appartient
                if (search(french, token))
                {
                    counts[0] +=1;
                }
                else if (search(german, token))
                {
                    counts[1] +=1;
                }
                else if (search(english, token))
                {
                    counts[2] += 1;
                }
                else
                {
                    counts[3] += 1;
                }
                token = strtok(NULL, " ");

            }
            printf("Phrase is: %s\n", language(counts));
            printf("General statistics:\nWords count: %d, french: %.2f%%, german: %.2f%%, english: %.2f%%, unkown: %.2f%%\n", total, (double) counts[0]*100/total, (double) counts[1]*100/total, (double) counts[2]*100/total, (double)  counts[3]*100/total);
		    }

		    if (choice == 2)
		    {
			      printf("Dawg technique\n");
			      printf("Enter phrase: \n");
		    }
	
		    if (choice == -1) exit(EXIT_SUCCESS);

	}
    return 0;
}
