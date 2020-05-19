//On place en queu l'adresse de la cellule en tête
//On a plus besoin que du pointeur de queue qui est la file F elle même

typedef char S;

typedef struct strfile {
    S v;
    struct strfile *s;
} Strfile, *File;


File filenouv(){
    return NULL;
}


File adjq(File f, S x){

    File f1 = Malloc(Strfile);
    f1->v = x;
    if (vide(f)){
        f1->s = f1;
    }
    else{
        f1-> s = f->s; //Bouger le pointeur
        f->s = f1;
    }
    return f1;
}

Bool vide(File f){
    return f== NULL;
}


S tete(File f){
    return f->s->v;
}

Nat lgrb(File f1, File f2){
    return (f1 == f2) ? 1 : 1 + lgrb(f1->s, f2);
}

Nat lgr(File f){
    return vide(f) ? 0 : lgrb(f->s, f);
}


File suprt(File f){
    File f1;
    if (f == f->s){
        free(f);
        f = NULL;
    }
    else{
        f1 = f->s;
        f->s = f->s->s;
        free(f1);
    }
    return f;
}



