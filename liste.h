

//STRUCTURE DE LA LISTE
struct cellule
{
	int valeur;
	struct cellule *suivant;

};

typedef struct cellule * Liste ;


//FONCTIONS DE LA LISTE 

Liste CreerListe(int premier, Liste reste);

Liste CreerLL();

int tete(Liste L);

Liste insertTete(int x,Liste L);

Liste queue(Liste L);

int estVide(Liste L);

void AfficheListe(Liste L);

Liste PushBack(int elt, Liste L);

int TailleListe(Liste L);

int PlusGrand(Liste L1,Liste L2);

Liste inverse(Liste l);

Liste Addition (Liste L1,Liste L2);

Liste Soustraction (Liste L1,Liste L2);

Liste Multiplication(Liste L1,Liste L2);

Liste Division(Liste L1,Liste L2);

Liste PolonaiseInverse(Liste NPI);