// liste_doublement_chainee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Element_entier {

	int n_entier;
	Element_entier* p_suivant;
	Element_entier* p_precedent;

}Element_entier;

typedef struct Liste_entiers {

	Element_entier* element_debut;
	Element_entier* element_fin;
	int n_taille;

}Liste_entiers;


void initialisation(Liste_entiers* liste);
int insertListeVide(Liste_entiers* liste, int n_val);
int insertDebutListe(Liste_entiers* liste, int n_val);
int insertFinListe(Liste_entiers* liste, int n_val);
int insertAvant(Liste_entiers* liste, int n_val, int n_pos);
int insertApres(Liste_entiers* liste, int n_val, int n_pos);
int suppPosListe(Liste_entiers* liste, int n_pos);
void afficheListe(Liste_entiers* liste);
void detruire(Liste_entiers* liste);


int main()
{
	Liste_entiers* liste = NULL;
	liste = (Liste_entiers*)malloc(sizeof(Liste_entiers));

	initialisation(liste);

	if (insertListeVide(liste, 1)) {

		printf("insertion dans liste vide ok\n");
	}
	else {

		printf("insertion impossible\n");
	}

	if (insertDebutListe(liste, 2)) {

		printf("insertion en début de liste ok\n");
	}
	else {

		printf("insertion impossible\n");
	}

	if (insertFinListe(liste, 3)) {

		printf("insertion en début de liste ok\n");
	}
	else {

		printf("insertion impossible\n");
	}

	if (insertAvant(liste, 4, 3)) {

		printf("insertion en début de liste ok\n");
	}
	else {

		printf("insertion impossible\n");
	}

	if (insertApres(liste, 5, 2)) {

		printf("insertion en début de liste ok\n");
	}
	else {

		printf("insertion impossible\n");
	}

	afficheListe(liste);

	suppPosListe(liste, 3);

	afficheListe(liste);

	detruire(liste);



	free(liste);

	return 0;
}



void initialisation(Liste_entiers* liste) {

	liste->element_debut = NULL;
	liste->element_fin = NULL;
	liste->n_taille = 0;

}



int insertListeVide(Liste_entiers* liste, int n_val) {

	Element_entier* elem = NULL;
	elem = (Element_entier*)malloc(sizeof(Element_entier));

	if (elem == NULL) {
		return 0;
	}
	else {
		elem->n_entier = n_val;

		elem->p_precedent = liste->element_debut;
		elem->p_suivant = liste->element_debut;
		liste->element_debut = elem;
		liste->element_fin = elem;
		liste->n_taille++;
		return 1;

	}

}

int insertDebutListe(Liste_entiers* liste, int n_val)
{
	Element_entier* elem = NULL;
	elem = (Element_entier*)malloc(sizeof(Element_entier));

	if (elem == NULL) {
		return 0;
	}
	else {
		elem->n_entier = n_val;
		elem->p_precedent = NULL;
		elem->p_suivant = liste->element_debut;
		liste->element_debut->p_precedent = elem;
		liste->element_debut = elem;
		liste->n_taille++;
		return 1;
	}


}

int insertFinListe(Liste_entiers* liste, int n_val)
{
	Element_entier* elem = NULL;
	elem = (Element_entier*)malloc(sizeof(Element_entier));

	if (elem == NULL) {
		return 0;
	}
	else {
		elem->n_entier = n_val;
		elem->p_suivant = NULL;
		elem->p_precedent = liste->element_fin;
		liste->element_fin->p_suivant = elem;
		liste->element_fin = elem;
		liste->n_taille++;
		return 1;
	}

}

int insertAvant(Liste_entiers* liste, int n_val, int n_pos)
{



	Element_entier* elem = NULL;
	Element_entier* courant = NULL;
	elem = (Element_entier*)malloc(sizeof(Element_entier));
	int n_i = 0;

	courant = liste->element_debut;

	if (elem == NULL) {
		return 0;
	}
	else {
		elem->n_entier = n_val;
		for (n_i = 1; n_i < n_pos; n_i++) {

			courant = courant->p_suivant;

		}
		elem->p_suivant = courant;
		elem->p_precedent = courant->p_precedent;

		if (courant->p_precedent == NULL) {
			liste->element_debut = elem;
		}
		else {
			courant->p_precedent->p_suivant = elem;
		}

		if (courant)
			courant->p_precedent = elem;

		liste->n_taille++;

		return 1;

	}
}


int insertApres(Liste_entiers* liste, int n_val, int n_pos)
{

	Element_entier* elem = NULL;
	Element_entier* courant = NULL;
	elem = (Element_entier*)malloc(sizeof(Element_entier));
	int n_i = 0;

	courant = liste->element_debut;

	if (elem == NULL) {
		return 0;
	}
	else {
		elem->n_entier = n_val;
		for (n_i = 1; n_i < n_pos; n_i++) {

			courant = courant->p_suivant;

		}
		elem->p_suivant = courant->p_suivant;
		elem->p_precedent = courant;

		if (courant->p_suivant == NULL) {
			liste->element_fin = elem;
		}
		else {
			courant->p_suivant->p_precedent = elem;
		}

		if (courant)
			courant->p_suivant = elem;

		liste->n_taille++;

		return 1;

	}
}


int suppPosListe(Liste_entiers* liste, int n_pos)
{
	if (liste->n_taille == 0)
		return 0;

	int n_i = 0;
	Element_entier* courant = NULL;
	Element_entier* supp = NULL;


	if (n_pos == 1) {
		supp = liste->element_debut;
		liste->element_debut = liste->element_debut->p_suivant;
		if (liste->element_debut == NULL)
			liste->element_fin = NULL;
		else
			liste->element_fin->p_precedent = NULL;

	}
	else if (n_pos == liste->n_taille) {
		supp = liste->element_fin;
		liste->element_fin->p_precedent->p_suivant = NULL;
		liste->element_fin = liste->element_fin->p_precedent;
	}
	else {

		courant = liste->element_debut;
		for (n_i = 1; n_i < n_pos; n_i++) {
			courant = courant->p_suivant;
		}
		supp = courant;
		courant->p_precedent->p_suivant = courant->p_suivant;
		courant->p_suivant->p_precedent = courant->p_precedent;
	}
	free(supp);
	liste->n_taille--;

	return 1;

}


void afficheListe(Liste_entiers* liste) {

	Element_entier* courant = NULL;
	courant = liste->element_debut;
	while (courant != NULL)
	{
		printf("%d\n", courant->n_entier);
		courant = courant->p_suivant;

	}


}


void detruire(Liste_entiers* liste) {

	while (liste->n_taille > 0) {
		suppPosListe(liste, 1);
	}

}