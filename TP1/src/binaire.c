#include <stdio.h>

int main() {
    int number;
    int bits[32];  // Un tableau pour stocker les bits (on suppose un entier de 32 bits)
    int i = 0;

    // Demander à l'utilisateur d'entrer un nombre entier
    printf("Entrez un nombre entier : ");
    scanf("%d", &number);

    // Si le nombre est 0, afficher simplement 0 en binaire
    if (number == 0) {
        printf("La representation binaire de %d est : 0\n", number);
        return 0;
    }

    // Convertir le nombre en binaire
    while (number > 0) {
        bits[i] = number % 2;  // Stocker le reste (0 ou 1)
        number = number / 2;   // Diviser par 2 pour continuer la conversion
        i++;
    }

    // Afficher le résultat en binaire (à l'envers)
    printf("La representation binaire est : ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bits[j]);
    }
    printf("\n");

}
