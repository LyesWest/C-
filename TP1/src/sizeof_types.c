#include <stdio.h>
#include <limits.h>

int main() {
    // Calcule et affiche la taille de chaque type de base
    float taille = sizeof(char);
    printf("la taille du char est : %.2f\n", taille);
    printf("la taille du short est : %ld\n", sizeof(short));
    printf("la taille du int est : %ld\n", sizeof(int));
    printf("la taille du long int est : %ld\n", sizeof(long int));
    printf("la taille du long long int est : %ld\n", sizeof(long long int));
    printf("la taille du float est : %ld\n", sizeof(float));
    printf("la taille du double est : %ld\n", sizeof(double));
    printf("la taille du long double est : %ld\n", sizeof(long double));

    // Affiche les limites des types char
    printf("la version signé de char min est : %d\n", SCHAR_MIN);
    printf("la version signé char max est : %d\n", SCHAR_MAX);
    printf("la version unsigned char max est : %u\n", UCHAR_MAX);

}
