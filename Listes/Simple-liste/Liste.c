


/*Implementation des listes*/
/*
    Contiguité: - Element ranger dans un tab static/dynamique
                - Longeur de la liste
                - Indice de la tête

    Chaînage:   -Allocation dynamique des cellules
                -Entête la longueur de la liste


    supt: suppression en tête
    tete: element en tête
    vide: teste de vacuité
    Long: longueur
    egalite:
    difference:
    App: appartenance
    Conc: concatenation de 2 listes
    Queue: dernier élément

    Variante de spécification des opérations en queu de liste
    ajdq: ajouter en queue
    supq: suppression du dernier


    Itération sur la 1ere occurence d'un élément dans la liste:
    supl: suppression 1er occ d'un élément
    chgl: remplacement de la 1er occ d'un element
    rechl: plus petit rang d'un élément
    rech2: liste commençant à cet élement

    Opérations sur le i-ème élément d'une liste
    Ieme: sous liste débutant au ieme élément
    ins: insertion en i-ème position
    Sup: suppresion du i-ème élément
    chg:
    lig: sous liste terminant au i-ème élément sans lui
    lid: ---------- débutant -------------------------


    Liste triées:
    listet: sous-sprte des listes triées
    triee: test de trie d'une liste quelconque
    Adjt: ajouter un element sur une liste triées et trier de nouveau

    insav: adjonction juste avant les élément >=
    insap: ---------------- aprés ----------- <=
*/

typedef char S;

typedef struct strliste
{
    S v; //valeur
    struct strliste *s; //suivant

} Strliste, *Liste;



Liste listnouv(){
    return NULL; //Parce que le pointeur point dans le vide
}


/*Ajouter un èlèment x dans une liste:
    -il faut créer un éspace dans la mémoire
*/
Liste ajout(Liste l, S x){
    Liste l1 = Malloc(Strliste);
    l1->v = x; //associer la valeur à x
    if (l == NULL){
        return l1;
    }
    else{
        l1->s = l;
        return l;
    }
}



S tete(Liste l){
    return l->v;
}


Liste supt(Liste l){
    Liste l1;
    if (l == NULL){return listnouv();}
    else{
        l = l->s;
        free(l1);
        return l;
    }
}


Nat lgr(Liste l){
    return (l==NULL) ? 0 : 1 + lgr(l->s);
}

bool vide(Liste l){
    return (lgr(l) == 0);
}

bool app(Liste l, S x){
    Liste l1 = l;

    if (l == NULL){
        return false;
    }
    else{
        if (f->v == x){ return true:}
    }
    else{
        app(supt(l1),x);
    }
}



// Liste rechl(Liste l, S x){

//     if (l==NULL){
//         return l;
//     }
//     else{
//         if (f->v ==x){
//             return l;
//         }
//     }else{
//         rech1(supt1(l),x);
//     }
// }

Liste chgl(Liste l, S x, S z){
    if (l == NULL){
        return l;
    }else{
        if (l->v == x){
            l->v =z;
            return l;
        }
    }else{
        Liste l1=l;
        ajout(chgl(l1,y,z), l1->v);
    }
}


Liste supt1(Liste l, S x){
    Liste l1 = l;
    if (l == NULL){
        return listnouv();
    }else{
        if (l->v ==x){
            l = l->s; //passe au suivant
            return l1->s;
        }
    }else{
        sup1(l1->s, x);
    }
}

S queue(Liste l){
    while (l->s != NULL){
        l = l->s;
    }
    return l->v;
}


Liste adjq(Liste l, S x){
    Liste l1 = Malloc(Strliste);
    l1->v = x;
    if (l == NULL){
        return l1;
    }else{
        Liste l2 = l;
        while (l2->s != NULL){
            l2 = l2->s;
        }
        l2 ->s =l1;
        return l;
    }
}

Liste suprq(Liste l){
    if (l == NULL){
        return l;
    }else{
        Liste l2 = l;
        while (l2->s !=NULL){
            l2 = l2->s;
        }
        l2->s = NULL;
        free(l2);
        return l;
    }
}




S ieme(Liste l, Nat idx){
    Liste l1 = l ;
    for (int i =0; i <(int) x; i++){
        l1 = l1->s;
    }
    return l1->v;
}


Liste inser(Liste l, Nat idx, S x)
    Liste l1 = Malloc(Strliste);
    l1->v = x;

    Liste l2 = l;

    if (l == NULL){
        return l2;
    }else{
        for (int i=0; i < (int) idx; i++){
            l2 = l2->s;
        }
        l2->s = l1->s->s;
        l1->s =l2;
        return l;
    }


Liste sup_eme(Liste l, Nat idx){
    if (l == NULL){return l}
    else{
        Liste l2 = l;
        for (int i=0; i < (int) x; i++){
            l2 = l2->s;
        }
        l2= l2->s->s;
        return l2;
    }
}





















