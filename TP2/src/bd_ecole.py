# Définition de la classe pour représenter un étudiant
class Etudiant:
    def __init__(self, nom, prenom, adresse, note1, note2):
        self.nom = nom
        self.prenom = prenom
        self.adresse = adresse
        self.notes = [note1, note2]

# Liste pour stocker les 5 étudiants
etudiants = []

# Saisie des informations pour les 5 étudiants
for i in range(5):
    print(f"Étudiant {i + 1}:")
    
    # Saisie des informations
    nom = input("Nom: ")
    prenom = input("Prénom: ")
    adresse = input("Adresse: ")
    note1 = float(input("Note 1: "))
    note2 = float(input("Note 2: "))
    
    # Création d'une instance de la classe Etudiant
    etudiant = Etudiant(nom, prenom, adresse, note1, note2)
    
    # Ajout de l'étudiant à la liste
    etudiants.append(etudiant)
    print()  # Saut de ligne entre les étudiants

# Affichage des informations des 5 étudiants
print("Informations des 5 étudiant.e.s:")
for i, etudiant in enumerate(etudiants):
    print(f"Étudiant {i + 1}:")
    print(f"Nom: {etudiant.nom}")
    print(f"Prénom: {etudiant.prenom}")
    print(f"Adresse: {etudiant.adresse}")
    print(f"Note 1: {etudiant.notes[0]:.2f}")
    print(f"Note 2: {etudiant.notes[1]:.2f}")
    print()  # Saut de ligne entre les étudiants
