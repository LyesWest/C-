#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/**
 * Programme qui simule un interpréteur de commandes simple.
 * Il lit les commandes utilisateur et les traite en fonction de leur contenu.
 */

// Déclarations des fonctions
void afficher_version();
void afficher_aide();
void traiter_echo(char *commande);
void traiter_quit();

// Structure pour associer les commandes et les fonctions
struct Commande {
    const char *nom;
    void (*fonction)(char *);
};

// Fonction principale
int main()
{
    int continuer = 1; // Variable pour contrôler la boucle principale

    // Tableau des commandes et des fonctions associées
    struct Commande commandes[] = {
        {"quit", (void (*)(char *))traiter_quit},
        {"quitter", (void (*)(char *))traiter_quit},
        {"version", afficher_version},
        {"help", afficher_aide},
        {"aide", afficher_aide},
        {"echo", traiter_echo},
        {"date", NULL}
    };
    int nombre_commandes = sizeof(commandes) / sizeof(commandes[0]);

    // Boucle principale qui lit et traite les commandes utilisateur
    while (continuer)
    {
        printf("> "); // Affiche le prompt de commande

        // Buffer pour stocker la commande utilisateur
        char commande[1024];

        // Lit la commande utilisateur et la stocke dans le buffer
        fgets(commande, sizeof(commande), stdin);

        // Enlève le caractère de fin de ligne ajouté par fgets
        commande[strcspn(commande, "\n")] = 0;

        // Convertit la commande en minuscules pour éviter les problèmes de casse
        for (int i = 0; commande[i]; i++) {
            commande[i] = tolower((unsigned char)commande[i]);
        }

        // Traite la commande en fonction de son contenu
        int commande_reconnue = 0;
        for (int i = 0; i < nombre_commandes; i++) {
            if (strncmp(commande, commandes[i].nom, strlen(commandes[i].nom)) == 0) {
                commande_reconnue = 1;
                if (strcmp(commandes[i].nom, "date") == 0) {
                    // Traite la commande "date" pour afficher la date actuelle
                    time_t t;
                    struct tm *tm;

                    // Obtient l'heure actuelle
                    time(&t);
                    tm = localtime(&t);

                    // Affiche la date actuelle au format standard
                    printf("Date actuelle : %02d/%02d/%d %02d:%02d:%02d\n",
                           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900,
                           tm->tm_hour, tm->tm_min, tm->tm_sec);
                } else if (strcmp(commandes[i].nom, "quit") == 0 || strcmp(commandes[i].nom, "quitter") == 0) {
                    traiter_quit();
                    continuer = 0;
                } else {
                    commandes[i].fonction(commande);
                }
                break;
            }
        }

        if (!commande_reconnue) {
            // Affiche un message d'erreur si la commande est inconnue
            printf("Commande non reconnue. Essayez 'echo <texte>' pour afficher du texte, 'date' pour la date actuelle, 'aide' ou 'help' pour les commandes disponibles, ou tapez 'quitter' ou 'quit' pour quitter.\n");
        }

        printf("\n"); // Saut de ligne après la sortie
    }

    return 0;
}

// Fonction pour afficher la version
void afficher_version()
{
    printf("Version de l'interpréteur de commandes : 1.0.0\n");
}

// Fonction pour afficher l'aide
void afficher_aide()
{
    printf("Commandes disponibles :\n");
    printf("  quit / quitter - Quitter l'interpréteur de commandes\n");
    printf("  echo          - Répéter le texte saisi\n");
    printf("  date          - Afficher la date actuelle\n");
    printf("  version       - Afficher la version de l'interpréteur de commandes\n");
    printf("  help / aide   - Afficher cette aide\n");
}

// Fonction pour traiter la commande echo
void traiter_echo(char *commande)
{
    printf("Echo: ");
    for (int i = 5; commande[i] != '\0'; i++)
    {
        printf("%c", commande[i]);

        // Ajoute un saut de ligne entre chaque mot si espace
        if (commande[i] == ' ')
        {
            printf("\n");
        }
    }
    printf("\n");
}

// Fonction pour traiter la commande quit
void traiter_quit()
{
    printf("Arrêt...\n");
}
