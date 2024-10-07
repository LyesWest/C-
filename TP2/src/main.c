#include <stdio.h>
#include "sphere.h"

int main() {
    float rayon = 5.0;
    
    float surface = calculer_surface(rayon);
    printf("La surface de la sphère de rayon %.2f est %.2f\n", rayon, surface);

    float volume = calculer_volume(rayon);
    printf("Le volume de la sphère de rayon %.2f est %.2f\n", rayon, volume);

    return 0;
}
