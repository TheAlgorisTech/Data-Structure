# Contiguously Stacks (Pile)
C character stacks and contiguous implementation with the data structure are considered:

```
#define MAX_P 50
typedef struct {
	char tab[MAX_P];
	Nat h;
	} Pile;
```
pile_char.h with the data structures and profiles of the functions, and the file containing the source of the functions, named pile_char.c.
A file named test.c a program to test all operations on stacks. Also the Makefile allowing to compile these functions separately.
files.

# Linked Stacks
Same exercise as in the previous section but using a chained implementation. Therefore, consider the data structure:

```
typedef struct spile {
	char v;
	struct spile *s;
	} Spile, *Pile;
```

The file names will be respectively pile_char2.h, pile_char2.c.
