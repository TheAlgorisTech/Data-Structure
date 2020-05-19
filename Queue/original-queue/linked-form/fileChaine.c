




/*
    file représenté par:
    - un tableau v de N éléments
    - h l'indice de tête
    - l la longeur de la file
*/

#define N 100

typedef int Nat;
typedef char S;

typedef struct strfile
{
    S v;
    struct strfile * s;
} Strfile;


typedef struct sfile {
    Strfile *h; //Pointeur tête de file
    Strfile *q; //Pointeur queu de file
} File;


File Filenouv(){
    File f;
    f->h = NULL;
    f->l = NULL;
    return f;
}


File adjq(File f, S x){
    Strfile *f1 = Malloc(Strfile);
    f1->v = x;
    f1->s = NULL; //New element doesn't point yet

    if (f.h == NULL){
        f.h = f1;
        f.q = f1;
    }
    else{
        f.q -> s = f1;
        f.q = f1;
    }
    return f;
}



File supt(File f){

    Strfile *f1 = f.h;

    if (f.h == f.q) {
        f.h = NULL;
        f.q = NULL;
    }
    else{
        f.h = f.h -> s; //Pass to the next element
        free(f1);
    }
    return f;
}


S tete(File f){
    return f.h ->v;
}

Bool vide(File f){
    return f.h == NULL;
}

Nat lgr(File f){
    return vide(f) ? 0 : lrgb(f.h, h.q);
}

Nat lrgb(Strfile *f1, Strfile *f2){
    return f1==f2 ? 1 : 1 +lrgb(f1->s, f2);
}









