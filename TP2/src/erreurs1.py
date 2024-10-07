from typing import List
import pdb

def double_values(tableau: List[int]) -> None:
    # Parcourt chaque élément du tableau
    for compteur in range(len(tableau)):
        # Erreur 
        if compteur % 2 == 0:
            tableau[compteur] *= 2
        else:
            tableau[compteur] *= 3
        # point d'arrêt
        pdb.set_trace()

    return tableau


tableau: List[int] = [1, 2, 3, 4, 5]
resultat = double_values(tableau)
print(resultat)
