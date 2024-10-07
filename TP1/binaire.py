# Fonction pour convertir un nombre entier en binaire
def convertir_binaire(n):
    bits = []  # Liste pour stocker les bits

    # Utilisation d'une boucle pour traiter chaque bit
    while n > 0:
        bits.append(str(n % 2))  # Ajoute le reste de la division par 2 (0 ou 1)
        n = n // 2  # Divise par 2 pour passer au prochain bit

    # Les bits sont stockés à l'envers, donc on les inverse pour l'affichage correct
    bits.reverse()

    # Joint les bits en une chaîne de caractères
    return ''.join(bits)

# Demande à l'utilisateur d'entrer un nombre entier
nombre = int(input("Entrez un nombre entier : "))

# Appelle la fonction et affiche la représentation binaire
print(f"La représentation binaire de {nombre} est : {convertir_binaire(nombre)}")
