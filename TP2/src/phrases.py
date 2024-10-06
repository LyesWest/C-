# Fonction pour compter le nombre d'occurrences d'une phrase dans une ligne
def compter_occurrences(ligne, phrase):
    return ligne.count(phrase)

# Demander à l'utilisateur le nom du fichier
nom_fichier = input("Entrez le nom du fichier : ")

# Demander à l'utilisateur la phrase à rechercher
phrase = input("Entrez la phrase que vous souhaitez rechercher : ")

# Ouvrir le fichier en mode lecture
try:
    with open(nom_fichier, 'r') as fichier:
        lignes = fichier.readlines()
        
        # Parcourir chaque ligne du fichier
        for num_ligne, ligne in enumerate(lignes, start=1):
            occurrences = compter_occurrences(ligne, phrase)
            
            # Si la phrase est présente, afficher le numéro de la ligne et le nombre d'occurrences
            if occurrences > 0:
                print(f"Ligne {num_ligne}, {occurrences} fois")
except FileNotFoundError:
    print(f"Erreur : Impossible d'ouvrir le fichier {nom_fichier}")
