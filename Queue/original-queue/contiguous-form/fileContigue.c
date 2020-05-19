#define MAX_P 50

typedef int Nat;
typedef char S;

typedef struct {
    Nat tab[MAX_P];
    Nat h;/* tête de la File */
    Nat l;/* longueur de la File */
} File;


File filenouv(){
    File f;
    f.h = 0;
    f.l = 0;
    return f;
}

Bool vide(File f){
    return f.l == 0;
}

File adjq(File f, S x){
    f.tab[f.l] = x;
    f.l = f.l +1;
    return f;
}


File supt(File f){
    f.h++;
    f.l--;
    return f;
}


Nat tete(File f){
    return f.tab[f.h]
}
