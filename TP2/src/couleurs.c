#include <stdio.h>
#include <string.h>

// Définition de la structure pour représenter une couleur
struct Couleur {
    unsigned char r, g, b, a;  // Valeurs R, G, B, A, chacune sur 1 octet
};

// Définition de la structure pour représenter une couleur distincte avec un compteur
struct CouleurOccurence {
    struct Couleur couleur;
    int occurrences;
};

// Fonction pour comparer deux couleurs
int comparer_couleurs(struct Couleur c1, struct Couleur c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}

int main() {
    struct Couleur couleurs[100];  // Tableau pour stocker 100 couleurs
    struct CouleurOccurence couleurs_distinctes[100];  // Tableau pour stocker les couleurs distinctes et leurs occurrences
    int total_couleurs = 5;  // Nombre total de couleurs à entrer (pour l'exemple, on limite à 5)
    int distinct_count = 0;  // Compteur pour les couleurs distinctes
    int i, j;
    
    // Saisie des couleurs (pour l'exemple, nous saisissons 5 couleurs)
    for (i = 0; i < total_couleurs; i++) {
        printf("Entrez les valeurs RGBA pour la couleur %d (format hexadécimal 0xXX) :\n", i + 1);
        printf("R : "); scanf("%hhx", &couleurs[i].r);
        printf("G : "); scanf("%hhx", &couleurs[i].g);
        printf("B : "); scanf("%hhx", &couleurs[i].b);
        printf("A : "); scanf("%hhx", &couleurs[i].a);
    }

    // Compter les occurrences des couleurs distinctes
    for (i = 0; i < total_couleurs; i++) {
        int trouve = 0;  // Flag pour savoir si la couleur est déjà dans la liste des distinctes
        for (j = 0; j < distinct_count; j++) {
            if (comparer_couleurs(couleurs[i], couleurs_distinctes[j].couleur)) {
                couleurs_distinctes[j].occurrences++;
                trouve = 1;
                break;
            }
        }
        // Si la couleur n'a pas été trouvée dans les distinctes, on l'ajoute
        if (!trouve) {
            couleurs_distinctes[distinct_count].couleur = couleurs[i];
            couleurs_distinctes[distinct_count].occurrences = 1;
            distinct_count++;
        }
    }

    // Affichage des couleurs distinctes et de leur nombre d'occurrences
    printf("\nCouleurs distinctes et occurrences :\n");
    for (i = 0; i < distinct_count; i++) {
        printf("ff 0x%02x 0x%02x 0x%02x 0x%02x : %d fois\n",
               couleurs_distinctes[i].couleur.r,
               couleurs_distinctes[i].couleur.g,
               couleurs_distinctes[i].couleur.b,
               couleurs_distinctes[i].couleur.a,
               couleurs_distinctes[i].occurrences);
    }

    return 0;
}
