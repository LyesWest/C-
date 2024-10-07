# Demande à l'utilisateur d'entrer un nombre pour la taille du triangle
taille = int(input("Entrez un nombre : "))

# Boucle pour chaque ligne du triangle, de 1 à 'taille'
for i in range(1, taille + 1, 1):
    line = ""  # Initialisation d'une chaîne

    # Boucle pour ajouter des caractères à la ligne en cours
    for j in range(i):
        # Si c'est le début, la fin de la ligne, ou la dernière ligne du triangle, ajouter *
        if(j == 0 or j == i-1 or i == taille):
            line += "*"
        else:
            # Sinon, ajouter #
            line += "#"
    # Affiche la ligne après avoir supprimé les éventuels espaces inutiles
    print(line.strip())
