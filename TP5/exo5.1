#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_OUTPUT_SIZE 1024
#define MAX_VARS 100

// Enum pour les types de données
typedef enum {
    ENTIER,
    REEL,
    CHAINE
} TypeVariable;

// Structure pour représenter une variable
typedef struct {
    char nom[50];
    TypeVariable type;
    union {
        int valeurEntier;
        float valeurReel;
        char valeurChaine[50];
    } valeur;
} Variable;

// Table des symboles
Variable tableSymboles[MAX_VARS];
int nombreVariables = 0;

// Fonction pour rechercher une variable dans la table des symboles
int find_variable(const char* nom) {
    for (int i = 0; i < nombreVariables; i++) {
        if (strcmp(tableSymboles[i].nom, nom) == 0) {
            return i;
        }
    }
    return -1;
}

// Fonction pour ajouter une variable dans la table des symboles
void add_variable(const char* nom, TypeVariable type, const void* valeur) {
    int index = find_variable(nom);

    if (index == -1 && nombreVariables < MAX_VARS) {
        // Ajout d'une nouvelle variable
        strcpy(tableSymboles[nombreVariables].nom, nom);
        tableSymboles[nombreVariables].type = type;

        if (type == ENTIER) {
            tableSymboles[nombreVariables].valeur.valeurEntier = *((int*)valeur);
            printf("Variable %s définie avec la valeur %d (entier)\n", nom, *((int*)valeur));
        } else if (type == REEL) {
            tableSymboles[nombreVariables].valeur.valeurReel = *((float*)valeur);
            printf("Variable %s définie avec la valeur %.2f (nombre réel)\n", nom, *((float*)valeur));
        } else if (type == CHAINE) {
            strcpy(tableSymboles[nombreVariables].valeur.valeurChaine, (char*)valeur);
            printf("Variable %s définie avec la valeur \"%s\" (chaîne de caractères)\n", nom, (char*)valeur);
        }
        nombreVariables++;
    } else if (index != -1) {
        // Vérifier le type pour empêcher le changement de type
        if (tableSymboles[index].type != type) {
            printf("Erreur : changement de type non autorisé pour la variable %s\n", nom);
        } else {
            // Mise à jour de la variable
            if (type == ENTIER) {
                tableSymboles[index].valeur.valeurEntier = *((int*)valeur);
                printf("Variable %s mise à jour avec la valeur %d (entier)\n", nom, *((int*)valeur));
            } else if (type == REEL) {
                tableSymboles[index].valeur.valeurReel = *((float*)valeur);
                printf("Variable %s mise à jour avec la valeur %.2f (nombre réel)\n", nom, *((float*)valeur));
            } else if (type == CHAINE) {
                strcpy(tableSymboles[index].valeur.valeurChaine, (char*)valeur);
                printf("Variable %s mise à jour avec la valeur \"%s\" (chaîne de caractères)\n", nom, (char*)valeur);
            }
        }
    }
}

// Fonction pour obtenir la valeur d'une variable
void get_variable_value(const char* nom) {
    int index = find_variable(nom);
    if (index == -1) {
        printf("Erreur : la variable %s n'est pas définie\n", nom);
        return;
    }

    if (tableSymboles[index].type == ENTIER) {
        printf("Valeur de %s : %d (entier)\n", nom, tableSymboles[index].valeur.valeurEntier);
    } else if (tableSymboles[index].type == REEL) {
        printf("Valeur de %s : %.2f (nombre réel)\n", nom, tableSymboles[index].valeur.valeurReel);
    } else if (tableSymboles[index].type == CHAINE) {
        printf("Valeur de %s : \"%s\" (chaîne de caractères)\n", nom, tableSymboles[index].valeur.valeurChaine);
    }
}

// Fonction principale pour interpréter les commandes
int main() {
    char commande[MAX_OUTPUT_SIZE];
    char nomVar[50];
    char valeurVar[50];

    while (1) {
        printf("> ");
        fgets(commande, sizeof(commande), stdin);
        commande[strcspn(commande, "\n")] = 0; // Supprime le saut de ligne

        // Détecter la commande "quit" ou "quitter"
        if (strcmp(commande, "quit") == 0 || strcmp(commande, "quitter") == 0) {
            printf("Arrêt...\n");
            break;
        }

        // Traitement des affectations de variables
        if (sscanf(commande, "%s = %s", nomVar, valeurVar) == 2) {
            if (isdigit(valeurVar[0]) || (valeurVar[0] == '-' && isdigit(valeurVar[1]))) {
                // Gestion des entiers et réels
                if (strchr(valeurVar, '.')) {
                    float fValue = atof(valeurVar);
                    add_variable(nomVar, REEL, &fValue);
                } else {
                    int iValue = atoi(valeurVar);
                    add_variable(nomVar, ENTIER, &iValue);
                }
            } else if (valeurVar[0] == '"' && valeurVar[strlen(valeurVar) - 1] == '"') {
                // Gestion des chaînes de caractères
                valeurVar[strlen(valeurVar) - 1] = '\0';  // Retire la dernière guillemet
                add_variable(nomVar, CHAINE, valeurVar + 1);
            } else {
                printf("Erreur : type de valeur non supporté.\n");
            }
        } else if (sscanf(commande, "%s", nomVar) == 1) {
            // Affichage de la valeur de la variable
            get_variable_value(nomVar);
        } else {
            printf("Commande non reconnue.\n");
        }
    }

    return 0;
}

