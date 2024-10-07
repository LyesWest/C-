
from typing import List

def double_values(tableau: List[int]) -> None:
    # Parcourt chaque élément du tableau
    for compteur in range(len(tableau)):
        # Erreur : parfois multiplier par 3 au lieu de 2
        if compteur % 2 == 0:
            tableau[compteur] *= 2
        else:
            tableau[compteur] *= 3

    return tableau

# Création d'un tableau d'exemple
tableau: List[int] = [1, 2, 3, 4, 5]

# Appel de la fonction et stockage du résultat
resultat = double_values(tableau)

# Affichage du résultat final
print(resultat)

