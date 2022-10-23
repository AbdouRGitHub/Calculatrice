

//STRUCTURE DE LA PILE
struct Pile
{
	int valeur;
	struct Pile *suivant;

};


//FONCTIONS DE LA PILE 

typedef struct Pile * Pile;

typedef struct cellule * Liste ;

int PileVide(Pile L);

void AffichePile(Pile L);

Pile empiler (int a,Pile P);

Pile depiler(Pile P);

int sommet(Pile P);

Pile inversePile(Pile l);