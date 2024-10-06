#include <stdio.h>
#include <string.h>

// Définition de la structure pour représenter un étudiant
struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float notes[2]; // On suppose que chaque étudiant a deux notes.
};

int main() {
    struct Etudiant etudiants[5];  // Tableau de 5 étudiants
    int i;

    // Saisie des informations pour les 5 étudiants
    for (i = 0; i < 5; i++) {
        printf("Étudiant %d:\n", i + 1);
        
        // Saisie du nom
        printf("Nom: ");
        scanf("%s", etudiants[i].nom);
        
        // Saisie du prénom
        printf("Prénom: ");
        scanf("%s", etudiants[i].prenom);
        
        // Saisie de l'adresse
        printf("Adresse: ");
        scanf(" %[^\n]s", etudiants[i].adresse); // %[^\n] permet de lire des chaînes avec des espaces.
        
        // Saisie des deux notes
        printf("Note 1: ");
        scanf("%f", &etudiants[i].notes[0]);
        printf("Note 2: ");
        scanf("%f", &etudiants[i].notes[1]);
        
        printf("\n");  // Saut de ligne entre les étudiants
    }

    // Affichage des informations des 5 étudiants
    printf("Informations des 5 étudiant.e.s:\n");
    for (i = 0; i < 5; i++) {
        printf("Étudiant %d:\n", i + 1);
        printf("Nom: %s\n", etudiants[i].nom);
        printf("Prénom: %s\n", etudiants[i].prenom);
        printf("Adresse: %s\n", etudiants[i].adresse);
        printf("Note 1: %.2f\n", etudiants[i].notes[0]);
        printf("Note 2: %.2f\n", etudiants[i].notes[1]);
        printf("\n");  // Saut de ligne entre les étudiants
    }

    return 0;
}
