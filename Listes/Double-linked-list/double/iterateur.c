


typedef struct{
    Liste first; //premier element de la liste
    Liste cur; //element courant
} It, *Iter;


Iter init(Liste l){
    Iter itr = MALLOC(Iter);
    if (l == NULL){
        itr.first = NULL;
        itr.cur = NULL;
    }
    else{
        itr.first = l;
        itr.cur = l;
    }
    return itr;
}


bool end(Iter i){
    Liste l1 = i->first;
    bool b=false;

    if (i->first == NULL){b=true;}
    else{
        while (l1->s != i->first){
            l1 = l1->s;
        }
        if (l1 == i->cur){
            b = true;
        }
    }
    return b;
}



Iter next(Iter i){

    if (i->first == NULL){
        Liste l = listenouvel();
        return init(l);}
    else{
        if (end(i)){
            return i;
        }
    }else{
        i->cur = i->cur->s;
        return i;
    }
}


Iter prev(Iter i){
    if (i->first == NULL){
        Liste l = listenouvel();
        return init(l);
    }else{
        if (i->first == i->cur){
            return i;
        }
    }else{
        i->cur = i->cur->p;
        return i;
    }

}
