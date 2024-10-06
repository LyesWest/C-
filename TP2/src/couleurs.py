# Définition de la classe Couleur
class Couleur:
    def __init__(self, r, g, b, a):
        self.r = r
        self.g = g
        self.b = b
        self.a = a

    # Méthode pour comparer deux objets de la classe Couleur
    def __eq__(self, other):
        return self.r == other.r and self.g == other.g and self.b == other.b and self.a == other.a

    # Méthode pour afficher la couleur en format RGBA
    def __repr__(self):
        return f"ff 0x{self.r:02x} 0x{self.g:02x} 0x{self.b:02x} 0x{self.a:02x}"

# Liste pour stocker les 100 couleurs (ici limité à 5 pour l'exemple)
couleurs = []

# Demander à l'utilisateur de saisir 5 couleurs
for i in range(5):  # Limité à 5 pour simplifier l'exemple
    print(f"Entrez les valeurs RGBA pour la couleur {i + 1} (format hexadécimal 0xXX) :")
    r = int(input("R : "), 16)
    g = int(input("G : "), 16)
    b = int(input("B : "), 16)
    a = int(input("A : "), 16)
    couleurs.append(Couleur(r, g, b, a))

# Dictionnaire pour stocker les couleurs distinctes et leur nombre d'occurrences
occurences = {}

# Parcourir la liste de couleurs pour compter les occurrences
for couleur in couleurs:
    if couleur in occurences:
        occurences[couleur] += 1
    else:
        occurences[couleur] = 1

# Affichage des couleurs distinctes et de leur nombre d'occurrences
print("\nCouleurs distinctes et occurrences :")
for couleur, count in occurences.items():
    print(f"{couleur} : {count} fois")
