#include <stdio.h>
#include <string.h>

// Fonction pour compter le nombre d'occurrences d'une phrase dans une ligne donnée
int compter_occurrences(char *ligne, char *phrase) {
    int count = 0;
    char *pos = ligne;
    
    // Recherche de la phrase dans la ligne
    while ((pos = strstr(pos, phrase)) != NULL) {
        count++;
        pos += strlen(phrase); // Avancer le pointeur pour éviter les répétitions sur la même occurrence
    }
    
    return count;
}

int main() {
    char nom_fichier[100], phrase[100], ligne[256];
    FILE *fichier;
    int num_ligne = 0, occurrences;

    // Demande du nom du fichier
    printf("Entrez le nom du fichier : ");
    scanf("%s", nom_fichier);

    // Demande de la phrase à rechercher
    printf("Entrez la phrase que vous souhaitez rechercher : ");
    scanf(" %[^\n]s", phrase);  // %[^\n] permet de lire une chaîne avec des espaces

    // Ouverture du fichier en mode lecture
    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return 1;
    }

    // Lecture du fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        num_ligne++;
        // Compter le nombre d'occurrences de la phrase dans la ligne
        occurrences = compter_occurrences(ligne, phrase);

        // Si la phrase est présente, afficher le numéro de la ligne et le nombre d'occurrences
        if (occurrences > 0) {
            printf("Ligne %d, %d fois\n", num_ligne, occurrences);
        }
    }

    // Fermeture du fichier
    fclose(fichier);

    return 0;
}
