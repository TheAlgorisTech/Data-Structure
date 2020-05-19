
/*


*/


typedef char S;
typedef struct sldc {
        S v; //valeur
        struct sldc *s; //suivant
        struct sldc *p; //précédent
    } *Liste;


Liste nouvelle(){
    return NULL; //ni précédent ni suivant
}


S tete(Liste l){
    return l->v;
}


Liste adjt_tete(Liste l, S x){
    Liste l1 = Malloc(sldc);
    l1-> v = x;

    if (l == NULL) {
        l1->p = l1;
        l1->s = l1;
        return l1;}
    else{

        l1->s = l;
        l1->p = l->p;
        l->p->s = l1;
        l->p = l1;
    }
    return l1;

}

Liste sup_tete(Liste l){
    Liste l1 = l;
    if (l == NULL){return NULL;}
    else{
        l->p->s = l->s;
        l->s->p = l->p;
        free(l1);
        return l->s;
    }

}


Nat lgr(Liste l){
    Liste l1 = l;
    Nat i;
    if (l== NULL) {i = 0;}
    else{
        do {
            i++;
            l1 = l1->s;
        } while (l1 !=l);
        return i;
    }
}

bool vide(Liste l){
    return (l == NULL);
}


bool app(Liste l, S x){
    Liste l1 = l;
    bool b;
    if (l == NULL) {b =false;}
    else{
        while (l1->s !=l){
            if (l1->s->v == x){
                b =true;
                break;
            }
            else{
                l1 = l1->s;
            }
        }
    }
    return b;
}




S ieme(Liste l, int x){
    Liste l1 = l;

    if (l == NULL){return "-1";}
    else{
        for(int i=0; i< x-1; i++, l1 = l1->s);
        return l1->v;
    }
}


Liste adjt_ieme(Liste l, Nat x, S x){
    Liste l1 = Malloc(sldc);
    l1->v = x;
    Liste l2 = l;
    if (l == NULL) {return NULL;}
    else{
        for(int i =0; i<(int) x-1; i++, l2 = l2->s){
            l1->p = l2->p;
            l1->s = l2;
            l2->p->s = l2;
            l2->p = l1;
            if (x == 1){
                return l1;
            }
            else{
                return l;
            }

        }
    }
}




Liste sup_ieme(Liste l, Nat idx){
    Liste l1 = l;
    Liste l2 = l;
    if (l == NULL){return NULL;}
    else{
        for(int i=0; i<(int) idx -1; i++, l1=l1->s){
            l2=l1;
            l1->p->s = l1->s;
            l1->s->p =l1->p;
            free(l2);
            return l;
        }
    }
}


















