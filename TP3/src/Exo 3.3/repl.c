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
