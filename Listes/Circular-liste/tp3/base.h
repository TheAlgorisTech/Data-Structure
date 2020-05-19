// fichier base.h

#ifndef BASE
#define BASE 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <stdbool.h>
typedef bool Bool;
#define faux false
#define vrai true
//#define vrai 1
//#define faux 0
//typedef unsigned char Bool;

typedef unsigned int Nat;
typedef int Ent;
typedef float Reel;
typedef float Rat;
typedef char Car;
typedef Car * Chaine;

#define MALLOC(t)      ((t*)malloc(sizeof(t)))
#define MALLOCN(n, t)  ((t*)calloc(n, sizeof(t)))
#define CALLOCN(n, t)  ((t*)malloc(n * sizeof(t)))
#define REALLOC(p,n,t) ((t*)realloc(p, n * sizeof(t)))
#define FREE(t) free(t)

#endif

