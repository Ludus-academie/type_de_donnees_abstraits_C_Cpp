#include<stdio.h>
#include<stdlib.h>

#define TAILLE 10



int main() {

	//Les Tableaux (statiques)
	//Adressage dans la pile

	int n_tab[TAILLE] = { 0 };

	//affichage des @ du tableau
	printf("adr du tableau n_tab :%x\n ",(unsigned int)&n_tab);
	printf("adr du tableau n_tab :%x\n ",(unsigned int)&n_tab[0]);
	printf("adr du tableau n_tab :%x\n ",(unsigned int)&n_tab[1]);


	//Les Tableaux (dynamiques)

	int* pn_tab = NULL;

	pn_tab = (int*)calloc(TAILLE, sizeof(int));

	if (pn_tab != NULL) {
		printf("adr du tableau pn_tab :%x\n ", (unsigned int)&pn_tab);
		printf("adr du tableau pn_tab :%x\n ", (unsigned int)&pn_tab[0]);
		printf("adr du tableau pn_tab :%x\n ", (unsigned int)&pn_tab[1]);
	}

	free(pn_tab);


	int** ppn_tab = NULL;
	ppn_tab =(int**)calloc(TAILLE, sizeof(int*));

	if (ppn_tab != NULL) {

		for (int n_i = 0; n_i < TAILLE; n_i++) {

			ppn_tab[n_i] =(int*) calloc(TAILLE, sizeof(int));
		}
	}

	
	if (ppn_tab != NULL) {

		for (int n_i = 0; n_i < TAILLE; n_i++) {
			for (int n_j = 0; n_j < TAILLE; n_j++) {
				if (ppn_tab[n_i]) {
					printf("%d", ppn_tab[n_i][n_j]);
				}
				
			}

			puts("\n");
		}
	}

	if (ppn_tab != NULL) {

		for (int n_i = 0; n_i < TAILLE; n_i++) {

			free(ppn_tab[n_i]);
		}
	}

	free(ppn_tab);


	//Intro Listes chainées
	//Entiers

	typedef struct Element_entier {

		int n_entier;
		Element_entier* p_suivant;
	};


	//1er element de type entier
	Element_entier* element = NULL;

	element = (Element_entier*)calloc(1, sizeof(Element_entier));
	if (element) {
		element->n_entier = 1;
		element->p_suivant = NULL;
	}
	

	//2eme élement de type entier

	Element_entier* element2 = NULL;

	element2 = (Element_entier*)calloc(1, sizeof(Element_entier));
	if (element2) {
		element2->n_entier = 2;
		element2->p_suivant = NULL;
	}

	//3eme élement de type entier

	Element_entier* element3 = NULL;

	element3 = (Element_entier*)calloc(1, sizeof(Element_entier));
	if (element3) {
		element3->n_entier = 3;
		element3->p_suivant = NULL;
	}



	if (element) {

		element->p_suivant = element2;

	}

	if (element2)
	{
		element2->p_suivant = element3;
	}


	//Affichage

	/*while (element != NULL) {

		printf("%d\n", element->n_entier);
		element = element->p_suivant;
	}*/

	typedef struct Liste_entiers {

		Element_entier* element_debut;
		int n_taille;
	}Liste_entiers;

	//Création de la liste d'entiers
	Liste_entiers* Liste = NULL;
	Liste = (Liste_entiers*)malloc(sizeof(Liste));

	//Init Liste
	if (Liste) {
		Liste->element_debut = NULL;
		Liste->n_taille = 0;
	}

	//1) insert si liste vide
	if (element && Liste) {
		element->p_suivant = NULL;
		Liste->element_debut = element;
		Liste->n_taille++;
	}

	//2) insert en début Liste

	if (element2 && Liste) {
		element2->p_suivant = Liste->element_debut;
		Liste->element_debut = element2;
		Liste->n_taille++;
	}


	if (Liste) {
		Element_entier* tmp_element = Liste->element_debut;

		while (tmp_element != NULL) {
			printf("%d\n", tmp_element->n_entier);
			tmp_element = tmp_element->p_suivant;

		}

		free(tmp_element);
	}



	free(element);
	free(element2);
	free(element3);











	return 0;
}