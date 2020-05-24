


/*

    -Chaque fois on ajoute un élément il faut créer un place dans la mémoire

*/
typedef int Nat;
#define S Nat;

typedef struct strlistecirc { S v; struct strlistecirc *s;} StrListecir, *Listecir;


ListeCir lnouv_cir(){
    return NULL;
}

S tete_cir(Listecir l){
    return l-> v;
}


Listecir adjt_circ(Listecir l, S x){
    Listecir l1 = Malloc(StrListecir);
    l1->v = x;

    Listecir l2 = l; //Une nouvelle liste qui pointe sur la même liste
    if (l == NULL) {
        l1->s = l1; // Le pointeur pointe sur lui même
        return l1;
    }else{
        l1->s = l2;
        while (l2->s != l){
            l2 = l2->s;
        }
        l2->s = l1;
        return l1;
    }
}



Listecir supt_circ(Listecir l){
    Listecir l1 = l; //point to the same pointer
    if (l == NULL){return NULL;}
    else{
        Listecir l2 = l;
        free(l1);
        while (l2->s != l){
            l2 = l2->s;
        }
        l = l->s;
        l2->s =l;
        return l;
    }
}



Nat lgr(Listecir l){
    Listecir l2 = l;
    Nat i;
    if (l == NULL) {return 0;}
    else{
        do{
            i++;
            l2 = l2-> s;
        } while (l2->s != NULL);
    }
    return i;
}

bool vide_circ(Listecir l){
    return (l == NULL)
}


bool app_circ(Listecir l, S x){

    if (l == NULL) {return false;}
    else{
        Listecir l1 = l;
        while (l1->s != l){ //tant que ce n'est par retourne au premier element
            if (l1->v == x){
                return true;
            }
            l1 = l1->s;
        }
    }

}


S queu_circ(Listecir l){
    Listecir l2 = l;
    if (l == NULL){return 0;}
    else{
        while (l2->s != l){
            l2 = l2->s;
        }
        return l2->v;
    }
}



Listecir adjt_circ_queue(Listecir l, S x){
        Listecir l1 = Malloc(StrListecir);
        l1->v = x;
        if (l == NULL){return l1;}
        else{
            Liste l2 = l;
            while (l2->s != l){
                l2 = l2->s;
            }
            l2->s = l1;
            l1->s = l;
            return l;
        }
}



Listecir sup_circ_queu(Listecir l){
    S s = queu_circ(l);
    Listecir l1 = l;

    if (l == NULL) {return NULL;}
    else{
        while (l1->s->v != s){
            l1 = l1->s;
        }
        l1->s = l1->s->s;
        return l;
    }

}


Listecir chang_circ_queue(Listecir l, S x){
    Listecir l1 = Malloc(StrListecir);
    l1->v = x;
    S s = queu_circ(l);

    if (l == NULL) {return l1;}
    else {
        while (l1->s->v !=s){
            l1 = l1->s;
        }
        l1->s->v = x;
        return l;
    }

}
