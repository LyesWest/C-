#include "sphere.h"

float calculer_volume(float rayon) {
    // Formule : (4/3) * pi * r^3
    return (4.0/3.0) * M_PI * rayon * rayon * rayon;
}
