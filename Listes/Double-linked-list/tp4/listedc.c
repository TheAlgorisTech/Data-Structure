liste listevide (){
return Null;}


S tete(liste l){
	return l->v;
}

liste ajoutt(liste l ,S x){
	liste l2=malloc(sldc);
	l2->v=x;
	l2->s=l;
	l2->p=l->p;
	l->p=l2;
	//l->p->s=l2;
	l=l2;
	return l;
	
}
liste supt(liste l){
	//liste non vide cas général
	liste l2=l
	l->s->p=l->p;
	l->p->s=l->s;
	l=l->s;
	
	free(l2);
}

Nat longueur(liste l){//liste vide 
 liste l2=l;
 Nat lg=1;//lg=1;
 while (l->s!=l2)
 {
	 l=l->s;
	lg++;
 }
 return lg;
	
bool ev(liste l);
return l==Null;


bool app(liste l,S x){//non liste vide
	liste l2;
	l2=l;
	while (l->v!=x)||(l->s!=l2){
		l=l->s;
		
	}
	return l->v==x;
}

S acces(liste l,Nat i){
	liste l2;
	l2=l;
	Nat p=1;
	while(p!=i)&&(l->s!=l2)
	{P++;
	l=l->s;}
	return l->v;
}
	
liste insert(liste l,S x,Nat i){
	//
	
	
}
liste sup_ieme(liste l,Nat i);
liste chg(liste l, S x,S y){
	liste l2=l;
	while ((l->s!=x) && (l->s!=l2))
	{			
	l=l->s; }
	l->v
