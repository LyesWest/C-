#include <stdio.h>

// Fonction pour dessiner un triangle de taille donnée
void triangle(int taille)
{
    // Boucle pour chaque ligne du triangle
    for (int i = 1; i <= taille; i++)
    {
        // Boucle pour chaque caractère dans la ligne actuelle
        for(int j = 0; j < i; j++)
        {
            // Affiche un '*' sur les bords ou la dernière ligne, sinon affiche '#'
            if (j == 0 || j == i - 1 || i == taille)
            {
                printf("* ");
            }
            else
            {
                printf("# ");
            }
        }
        printf("\n"); // Aller à la ligne suivante
    }
}

int main()
{
    int taille;

    // Demande à l'utilisateur de saisir une taille pour le triangle
    printf("Entrez une valeur pour la taille (strictement inférieure à 10) : ");
    while (scanf("%d", &taille) != 1 || taille >= 10 || taille < 1) {
        printf("Veuillez entrer un entier valide entre 1 et 9 : ");
        while (getchar() != '\n'); // Vider le buffer d'entrée
    }

    triangle(taille);

}
