#include <stdio.h>
#include <stdbool.h>

int main() {
    int a = 16;
    int b = 3;

    // Opérations de base
    int addition = a + b;
    int soustraction = b - a;
    int multiplication = a * b;
    float division = (float)a / (float)b; // Division de 'a' par 'b' (convertie en flottant)
    int reste = a % b;

    // Vérifie si 'a' est égal à 'b'
    if (a == b) {
        bool vrai = true;
        printf("la condition est %d\n", vrai); // Affiche 1 pour vrai
    } else {
        bool faux = false;
        printf("la condition est %d\n", faux); // Affiche 0 pour faux
    }

    // Vérifie si 'a' est supérieur à 'b'
    if (a > b) {
        bool vrai = true;
        printf("la condition est %d\n", vrai); // Affiche 1 pour vrai
    } else {
        bool faux = false;
        printf("la condition est %d\n", faux); // Affiche 0 pour faux
    }

    // Affichage des résultats des opérations
    printf("l'addition est égal à : %d\n", addition);
    printf("la soustraction est égal à : %d\n", soustraction);
    printf("la multiplication est égal à : %d\n", multiplication);
    printf("la division est égal à : %lf\n", division); // Affiche la division en flottant
    printf("le reste de la div est égal à : %d\n", reste);

}



