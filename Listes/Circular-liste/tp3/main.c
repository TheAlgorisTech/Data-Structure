int main(){
	//Déclaration 2 listes chainées de façons differentes

	Liste l1=NULL;
	//Strliste *l2=NULL;
	
	for(int i=1;i<=10;i++)
	{
		l1=ajoutt(l1,i);
		l1=ajoutq(l1,i);
	}
	afficheListe(l1);
	
	if(vide(l1))
		printf("la liste est vide\n");
	else 
		afficheListe(l1);

return 0;
}


void afficheListe(Liste l){
	Liste l1=l;
	while(l1->s!=NULL)
	{
		printf("%d",l1->v);
		l1=l1->s;
	}
}	
