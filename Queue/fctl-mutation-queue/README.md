# Functional and mutation type programming

The objective is to set up a FIFO (First In First Out) queue structure in the form of a functional queue and by mutation.

```
$ tar -xf sda1-tp1.tar.gz
$ cd sda1-tp1
```

__The Makefile contains the rules necessary to compile two interactive programs entitled functional
and mutation. For example:__

```
$ make
$ ./fonctionnel
```

### Queue Data Structure in functional programming
- Static Table/Array of type S (i.e char) 
- Index of first element in the table
- Maximum number of element in the queue
The elements table is used in a circular way: the first element in the row is in the position indicated.
in the start field while the size field contains the number of elements in the queue.

### Queue Data Structure Operations
Functional and mutation programs behave in the same way. The program creates an empty queue and then
is waiting for instructions in the form:
- help: Displays help.
- adds <x> : Adds the integer x to the queue.
- delete : Displays the integer at the top of the queue and removes it from the queue.
- status: Displays "empty" or "non-empty" depending on the state of the queue, and its size if it is not empty.
- display: Displays the contents of the queue.
- quit : Destroys the queue and ends the program.


### Usage
Once these programs are running, you can test them by hand or use the test sets provided in the test file.

```
$ ./fonctionnel <tests/jeutest1.txt
$ ./mutation tests/jeutest1.txt sortie
```


