#include<stdio.h>
#include<stdlib.h>
#include"liste.h"
#include"pile.h"

//CREATION LISTE
Liste CreerListe(int premier, Liste reste){
	
	Liste L=malloc(sizeof(Liste));
	L->valeur=premier;
	L->suivant=reste;
	return L;
}

//Liste de "Grands Entiers"
Liste CreerLL() 
{
    Liste maListe = malloc(sizeof(Liste));
    int saisie=-1;
    while (saisie >9 || saisie <0)              
    {
        saisie=(int)getchar()-48;
    }
     maListe=CreerListe(saisie, NULL);  
    while(saisie !=-38)
    {
        saisie=-1;
        while(saisie !=-38 && (saisie >9 || saisie <0))     //tant que le caractère saisie = 10 (saut à la ligne en ascii) et associé à un chiffre entre 0 et 9
        {
            saisie=(int)getchar()-48;                       //Cast du caractère saisie (pour gérer la touche entrée)
            if (saisie<=9 && saisie >=0)
            {
                if(maListe->valeur == 0)
                {
                    maListe = CreerListe(saisie, NULL);
                }
                else
                {
                    maListe=PushBack(saisie, maListe);     //Met la valeur saisie en fin de liste 
                }
                
            }
        }
        
    }
    return maListe;                                         
}


//TETE DE LISTE
int tete(Liste L){
	return(L->valeur);
}

//INSERTION EN TETE DE LISTE
Liste insertTete(int x,Liste L){
	return CreerListe(x,L);
}


//PASSAGE A LA VALEUR SUIVANTE
Liste queue(Liste L){
	return(L->suivant);
}

//FONCTION SI LISTE VIDE
int estVide(Liste L){
	if (L==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

//AFFICHAGE LISTE
void AfficheListe(Liste L) {
    Liste P = L;
    while(P != NULL){
        printf("%d", P->valeur);
        P = P->suivant;
    }
}

//Fonction permettant d'insérer un élément à la fin d'une liste
Liste PushBack(int elt, Liste L){      
    Liste P = L;
    Liste Q = malloc(sizeof(Liste));
    Q->valeur = elt;
    Q->suivant = NULL;
    	while(P->suivant != NULL) {
       	 P = P->suivant;
		}
    P->suivant = Q;
    return L;
}


//GESTION TAILLE DE LISTE :

//Taille liste
int TailleListe(Liste L){
	Liste temp = L;
	int taille = 0;
	while(estVide(temp)!=1){
		temp = queue(temp);
		taille++;
	}
	return taille;
}

//Determine si La liste 2 est plus grande que la liste 1
int PlusGrand(Liste L1,Liste L2){
	int a = TailleListe(L1);
	int b = TailleListe(L2);
	if(L2>L1){
		return 1;
	}
	if (L2<L1){
		return 0;
	}
}
//Invese les éléments de la liste
Liste inverse(Liste l){
	Liste temp = NULL;
	Liste resultat = NULL;

	while(estVide(l)!=1){
		temp = l->suivant;
		l->suivant = resultat;
		resultat = l;
		l = temp;
	}
return resultat;
}

//ADDITION

Liste Addition (Liste L1,Liste L2){
	
	int retenu=0;
	int calcul=0;
	Liste Li1 = L1;
	Liste Li2 = L2;
	int x,y;
	Liste somme;

	while(estVide(Li1)!=1 && estVide(Li2)!=1){
        x = Li1->valeur ;
        y = Li2->valeur ;
        calcul = x + y + retenu ;                  //addition des deux nombres avec la retenue

        retenu=0;
        if (calcul>=10){                           //Si le calcul est supérieur à 10 : mettre la retenue à 1 
               calcul=calcul-10;                   //Soustraction pour la décimal
               retenu=1;    
        }

        somme = insertTete(calcul,somme);           //insertion de la décimal dans la longue liste
        Li1 = Li1->suivant;
        Li2 = Li2->suivant;

    }
    if (Li1==NULL){                                //si la liste Li1 est vide       
    	while(estVide(Li2)!=1){                    //si la liste Li2 n'est pas vide: continuer le calcul jusqu'à ce quelle le soit 

    		y = Li2->valeur ;
    		calcul =  y + retenu ;
    		
    		somme = insertTete(calcul,somme);      //insertion de la décimal dans la longue liste
    		Li2 = Li2->suivant;	
    		retenu=0;

    	}
    }
    if (Li2==NULL){                               //si la liste Li2 est vide 
    	while(estVide(Li1)!=1){                   //si la liste Li1 n'est pas vide: continuer le calcul jusqu'à ce quelle le soit

    		x = Li1->valeur;
    		calcul = x+retenu;
    		
    		somme = insertTete(calcul,somme);     //insertion de la décimal dans la longue liste
    		Li1 = Li1->suivant;
    		retenu=0;
    	}
    }

    if(retenu==1){                                //si il ne reste qu'une retenu à mettre
		somme = insertTete(retenu,somme);         //insertion de la décimal dans la longue liste
	}
   		 return somme;
}
	
//SOUSTRACTION    
Liste Soustraction (Liste L1,Liste L2){
	
	int retenu=0;
	int calcul=0;
	Liste Li1 = L1;
	Liste Li2 = L2;
	int x,y;
	Liste somme;


	while(estVide(Li1)!=1 && estVide(Li2)!=1){
        x = Li1->valeur ;
        y = Li2->valeur ;
        calcul = x - y - retenu ;                //soustraction des deux nombres avec retenue

        retenu=0;
        if (calcul<0){                          //Si la soustraction est inférieur à 0 : retenu à 1
               calcul=calcul+10;                //addition pour la décimal
               retenu=1;    
        }

        somme = insertTete(calcul,somme);       //insertion de la décimal dans la longue liste
        Li1 = Li1->suivant;
        Li2 = Li2->suivant;

    }
    if (Li1==NULL){
    	while(estVide(Li2)!=1){

    		y = Li2->valeur ;
    		calcul =  y - retenu ;
    		
    		somme = insertTete(calcul,somme);  //insertion de la décimal dans la longue liste
    		Li2 = Li2->suivant;	
    		retenu=0;

    	}
    }
    if (Li2==NULL){
    	while(estVide(Li1)!=1){

    		x = Li1->valeur;
    		calcul = x-retenu;
    		
    		somme = insertTete(calcul,somme); //insertion de la décimal dans la longue liste
    		Li1 = Li1->suivant;
    		retenu=0;
    	}
    }

    if(retenu==1){
		somme = insertTete(retenu,somme);     //insertion de la décimal dans la longue liste
	}
   
   		 return somme;
}

//MULTIPLICATION
Liste Multiplication(Liste L1,Liste L2){

	int retenu=0;
	int calcul=0;
	int cpt=1;
	Liste Li1 = L1;
	Liste Li2 = L2;
	Liste temp;
	int x,y;
	Liste somme;

    while(estVide(Li2) !=1){     
       Li1 = L1;
       while(estVide(Li1)!=1){
        x = Li1->valeur ;
        y = Li2->valeur ;
        
        calcul =(int) y*x + retenu ;                //Multiplication des deux nombres : retenue à 1;
        retenu=0;

        if (calcul>=10){                            
               calcul=calcul-10;                    //Soustraction pour la décimal
               retenu=1;      
        }

        somme = insertTete(calcul,somme);           //insertion de la décimal dans la longue liste
        Li1 = Li1->suivant;
	   }			
   		Li2 = Li2->suivant;
   
   }
   return somme;
}

//DIVISION
Liste Division(Liste L1, Liste L2){


    Liste Li1 = L1;
    Liste Li2 = L2;
    int calcul;
    int x,y;
    Liste somme;


        x = Li1->valeur ;
        y = Li2->valeur ;
        
        calcul =(int)x/y ;              
        somme = insertTete(calcul,somme);           //insertion de la décimal dans la longue liste
   
   
   return somme;
}


//FONCTION CALCULATRICE POLONAISE INVERSEE
Liste PolonaiseInverse(Liste NPI){

Liste a= malloc(sizeof(Liste));
Liste b= malloc(sizeof(Liste));
Liste npi=NPI;
Liste temp= malloc(sizeof(Liste));
Liste resultat=malloc(sizeof(Liste));
Pile operande;

while(estVide(npi)!=1){                         //Extrait de la liste les éléments pour la pile
    operande=empiler(npi->valeur,operande);
    npi=npi->suivant;
}
    while (PileVide(operande)!=1){
        if(a==NULL){
         a->valeur=0;
        }
        if(b==NULL){
         b->valeur=0;
        }
        if(operande->valeur != '+' && operande->valeur !='-' && operande->valeur != '*' && operande->valeur !='/'){     //insert l'élément dans la liste a si ce n'est pas un opérateur
            a=insertTete(operande->valeur,a);                           
            operande=depiler(operande);
        }
        if(operande->valeur != '+' && operande->valeur !='-' && operande->valeur != '*' && operande->valeur !='/'){      //insert l'élément dans la liste b si ce n'est pas un opérateur
            b=insertTete(operande->valeur,b);
            operande=depiler(operande);
        }
        if(operande->valeur = '+'){       //Si opérateur "+", éxecute l'addition
            temp=Addition(a,b);           //ajoute le résultat dans temp

        }
        else {
            if (operande->valeur = '*'){    //Si opérateur "*", éxecute la multiplication
                temp=Multiplication(a,b);
            }
                else {
                    if (operande->valeur = '-'){   //Si opérateur "-", éxecute la soustraction
                        temp=Soustraction(a,b);
                }
                        else {
                            if (operande->valeur = '/'){   //Si opérateur "/", éxecute la division
                                temp=Division(a,b);
                            }
                        }
                }
        }
    resultat=insertTete(temp->valeur,resultat);
    temp->valeur=0;
    operande=depiler(operande);
    }
    while(estVide(resultat)!=1){
    npi=insertTete(resultat->valeur,npi);
    resultat=resultat->suivant;
}
    return npi;
}



