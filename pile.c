#include<stdio.h>
#include<stdlib.h>
#include"pile.h"
#include"liste.h"

//FONCTION SI PILE VIDE
int PileVide(Pile L){
	if (L==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

//AFFICHE LA PILE
void AffichePile(Pile L) {
    Pile P = L;
    while(P != NULL){
        printf("%d", P->valeur);
        P = P->suivant;
    }
}

//"EMPILE" UN ELEMENT DANS LA PILE 
Pile empiler (int premier,Pile reste){

	Pile P=malloc(sizeof(Pile));
	P->valeur=premier;
	P->suivant=reste;
	return P;
}

//"DEPILE UN ELEMENT DE LA PILE"
Pile depiler(Pile P){
	P=P->suivant;
	return P;
}

//SOMMET DE LA PILE 
int sommet(Pile P){
	return P->valeur;
}

//INVERSE LES ELEMENTS DE LA PILE
Pile inversePile(Pile l){
	Pile temp = NULL;
	Pile resultat = NULL;

	while(PileVide(l)!=1){
		temp = l->suivant;
		l->suivant = resultat;
		resultat = l;
		l = temp;
	}
return resultat;
}




