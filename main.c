#include<stdio.h>
#include<stdlib.h>
#include"liste.h"
#include"pile.h"


void main(){

Liste NPI;
Liste NPIresultat;
Liste L3;
char op;

printf("Premier entiers signés \n");
Liste L1=CreerLL();
L1=inverse(L1);

printf("Deuxième entiers signés\n");
Liste L2=CreerLL();
L2=inverse(L2);

printf("Opération ( + , - , * , /, p ) \n");
op=getchar();

if(op=='+'){
	L3=Addition(L1,L2);
	AfficheListe(L3);
}
if(op=='-'){
	L3=Soustraction(L1,L2);
	AfficheListe(L3);
}
if(op=='*'){
	L3=Multiplication(L1,L2);
	AfficheListe(L3);
}
if(op=='/'){
	L3=Division(L1,L2);
	AfficheListe(L3);
}
if(op=='p'){
	printf("Calculatrice Polonaise inversée : Donnez l'équation à effectuer (en entiers signés) \n");
	NPI=CreerLL();	
	NPI=inverse(NPI);
	NPIresultat=PolonaiseInverse(NPI);	
	AfficheListe(NPIresultat);
}
}




