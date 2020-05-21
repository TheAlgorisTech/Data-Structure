# Dynamic Linked Queue
This time the idea is to implement these queues in the form of chains.
The Makefile contains the rules necessary to compile two interactive programs respectively called chain and chain-optimized.

```
$ make
$ ./chaine # ou ./chaine-optimisee
```

### Linked Queue Data Structure
- Element 
- Pointer to the next node
When representing a queue in the form of chained structures, it is customary to represent an empty queue with a
zero pointer.

![gif](https://www.cs.grinnell.edu/~walker/courses/195.fa01/queues1.gif)


### Function & Mutational vs Simple Linked
The shortcoming of the functional & mutation implementation is that it is often necessary to go completely through the chain of structures created in
memory, which can be relatively slow. The purpose of this exercise is to make performance measurements in order to put
this in evidence. Start by creating a bigtest 1 text file that contains the commands for :
- add 10000 elements to the queue
- delete these items
- while asking for a "status" after each order (!)
To do this, you can use, for example, the printf(1) , seq(1) commands and the for
of your shell:

```
$ rm -rf bigtest
$ for i in $(seq 10000); do printf "ajoute ${i}\netat\n" >> bigtest; done
$ for i in $(seq 10000); do printf "supprime\netat\n" >> bigtest; done
```
The time(1) command is used to measure the execution time of a program. Recompile functional & mutational queues programs by setting MAX_SIZE to 50000 then use the time(1) command.
Note: the -C option of the make(1) command to execute it from another directory.

```
$ make -C <répertoire du TP1> clean
$ make -C <répertoire du TP1> CPPFLAGS='-DTAILLE_MAX=50000'
$ time <répertoire du TP1>/mutation bigtest >/dev/null
$ time ./chaine bigtest >/dev/null

```

### Optimisation
Queues with static size tables have the advantage of very fast execution time compared to chained queues,
in particular due to the need to fully traverse the chained structures in memory during certain calls.
However, they have the disadvantage of being limited in size, which can be problematic when you want to write an
generic program, whose number of elements to be stored in the queue is not limited a priori.

#### Optimal Data Structure
This time, the queue points to an intermediate structure that contains pointers to both the head and the tail end of the line.
##### 1. Box/Node Data Structure
- Element
- Pointer to next element

##### 2. Queue Data Structure
- Pointer to queue head
- Pointer to queue tail
- Queue maximum size

#### Opaque types

By looking at the code provided, you will see that the structure struct file is defined in the files file_chaine.c
and file_chain_optimized.c files while the file.h file contains only the following lines :

```
struct file;
typedef struct file file;
```

It' s an opaque type. The choice of the implementation is made in the Makefile, when editing links, depending on the
object file provided :

```
chaine: main.o file_chaine.o
chaine-optimisee: main.o file_chaine_optimisee.o
```


There are several advantages to doing so:
- The customer code cannot directly change the structure.
- The customer code is forced to use the functions associated with the structure.
- Changing the implementation requires replacing only one .c file (or .o object file).


### Memory Leakage
As a reminder or for information, you can check the absence of memory leaks using tools such as valgrind(1) or by activating instrumentation options.

#### Valgrind

```
$ make -B CFLAGS="-Og -ggdb"
$ valgrind ./chaine <tests/jeutest1.txt
$ valgrind --leak-check=full ./chaine <tests/jeutest1.txt
```

#### Instrumentation

```
$ make -B CFLAGS="-fsanitize=address" LDFLAGS="-fsanitize=address"
$ ./chaine <tests/jeutest1.txt
```
