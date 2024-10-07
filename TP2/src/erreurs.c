#include <stdio.h>

int main() {
    // Tableau de taille 100
    int tableau[100];
    // La boucle dépasse la taille réelle du tableau.
    for (int compteur = 0; compteur < sizeof(tableau); compteur++) { // Erreur
        tableau[compteur] = tableau[compteur] * 2;
    }

    return (0);
}
