// bibliothèque mathématique
#include <math.h>  // Pour utiliser la constante M_PI

#include <stdio.h>

#define M_PI 3.14159265358979323846

float calculer_aire(float rayon) {
    // Utilisation de la constante 
    return M_PI * rayon * rayon;
}

int main() {
    float rayon = 5.0;
    float aire = calculer_aire(rayon);

    printf("L'aire du cercle de rayon %.2f est %.2f\n", rayon, aire);
    return 0;
}
