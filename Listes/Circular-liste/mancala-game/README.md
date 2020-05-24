# Mancala Game (Circular Linked List)

The game board is composed of 2 rows of 6 fields (or holes) which contain seeds
to which are added two special fields: the attics (or houses) of the players.
Each player has one of the two rows. The score of a player corresponds to the total number of seeds in the fields in its row.

![gif](http://ehess.modelisationsavoirs.fr/marc/publi/awele/images/piege.gif)

### Rules
If the fields are numbered counterclockwise from the left (see also
Figure 1) :
- field 0 is the attic of player 2 and field 7 is the attic of player 1.
- Fields 1 to 6 are the fields of player 1.
- Fields 8 to 13 are the fields of player 2.

At the beginning of the game, all the fields except the granaries contain 3 seeds. Each in turn, players take turns to hull (or
move seeds from a field of their choice according to the following rules:
- the movement is counterclockwise.


- the displacement empties the starting field.
- the seeds are distributed at the rate of one seed per field or granary located after the starting field.
- a player cannot initiate a move from an attic.
- a player cannot initiate a move from a field in his opponent's row.

Therefore, the seeds in an attic belong definitively to the corresponding player while
that the other seeds are likely to pass to the opponent if a move involves too high an amount of
seeds.
The game ends when at least one of the two players can no longer play.


### Advanced Rules
The game described above is a very basic version of the Mancala game. The best known version has the rules
additional information :
- if the last seed deposited is placed in an attic, the player plays again.
- if the last seed deposited is deposited in an empty field and the opposite field contains seeds, all those seeds are returned to the field.
seeds are moved to the player's attic.
Finally, here's an alternative move that can spice up the game: field fire. A player can decide to sacrifice 3
seeds from his attic (provided he has at least 3 in his attic) to burn a column of fields provided that
the number of fields per player is greater than 3. These fields become unusable and are removed from the game board.



### Implementation

First, implement the circular lists. The chosen structure is similar to the structure used for classic linked lists:

```
struct liste
{
	/** \brief attics. */
	unsigned int feves;
	/** \brief next element of the list. */
	struct liste* suivant;
};

```

The difference with classic lists lies in the fact that in a circular list, all the links, including the last link, point to another link in the chain.

![gif](https://mohtashims.files.wordpress.com/2010/07/cir-q-caseiii.gif)



### Basic Logic of the Game of Mancala
Once the lists are implemented, the game logic must be implemented. The proposed structure is as follows:

```
struct mancala
{
	liste* plateau;
	unsigned int joueur;
	size_t selection;
};

```
The player field is used to determine which player should play. The behaviour of certain functions must change according to the value of this field:

```
bool mancala_coup_valide(const mancala* m, size_t i);
unsigned int mancala_joueur(const mancala* m);
mancala* mancala_egrainer(mancala* m, size_t i);
```
For example, if it is player 1 to play, mancala_valid_stroke() must always 
return false for field 13 (it is a field of the player 2) and return true 
for field 2 if, and only if, it contains seeds (otherwise it is necessary to
return false ). Another example, mancala_egrainer() must change the value of
the player field and reset the selection field has an appropriate value for
the player.

The selection field is used to store the player's selection in the interface:

```
size_t mancala_selection(const mancala* m);
mancala* mancala_selection_gauche(mancala* m);
mancala* mancala_selection_droite(mancala* m);
```
Care must be taken to ensure that a player cannot make a selection
from his opponent's row.

__Note:__
The rules state that the granaries do not contain seeds at the start of the game. To start, you can initialize all fields (including attics) in the same way (it doesn't change the players score).


### Additional Features

- Implement field fire in the following functions :

```
bool mancala_peut_bruler(const mancala* m);
mancala* mancala_bruler(mancala* m, size_t i);

```
